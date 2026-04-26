#ifndef OPTIMIZATION_QDR_H
#define OPTIMIZATION_QDR_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "quad.h"

#define OPT_MAX_NOMS 2000
#define OPT_MAX_INFOS 1000

typedef struct {
    char dest[100];
    char source[100];
    int version_dest;
    int version_source;
    int valide;
} OptCopieInfo;

typedef struct {
    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];
    int version_op1;
    int version_op2;
    int version_res;
    int valide;
} OptExpressionInfo;

typedef struct {
    char nom[100];
    char oper[100];
    char op1[100];
    char op2[100];
    int version_nom;
    int version_op1;
    int version_op2;
    int valide;
} OptDefinitionInfo;

static int opt_est_temporaire(const char *chaine) {
    return chaine != NULL &&
           chaine[0] == 'T' &&
           isdigit((unsigned char)chaine[1]) != 0;
}

static int opt_est_nombre(const char *chaine) {
    int i;
    int point = 0;
    int chiffre = 0;

    if (chaine == NULL || chaine[0] == '\0') {
        return 0;
    }

    i = 0;
    if (chaine[i] == '+' || chaine[i] == '-') {
        i++;
    }

    for (; chaine[i] != '\0'; i++) {
        if (isdigit((unsigned char)chaine[i]) != 0) {
            chiffre = 1;
        } else if (chaine[i] == '.' && point == 0) {
            point = 1;
        } else {
            return 0;
        }
    }

    return chiffre;
}

static int opt_est_nom_versionnable(const char *chaine) {
    if (chaine == NULL || chaine[0] == '\0') {
        return 0;
    }

    if (strcmp(chaine, "_") == 0 || strcmp(chaine, "vide") == 0) {
        return 0;
    }

    if (opt_est_nombre(chaine)) {
        return 0;
    }

    if (strchr(chaine, '[') != NULL || strchr(chaine, ']') != NULL || strchr(chaine, '"') != NULL) {
        return 0;
    }

    return isalpha((unsigned char)chaine[0]) != 0 || chaine[0] == '_';
}

static int opt_indice_nom(char noms[][100], int versions[], int *nb_noms, const char *nom) {
    int i;

    if (!opt_est_nom_versionnable(nom)) {
        return -1;
    }

    for (i = 0; i < *nb_noms; i++) {
        if (strcmp(noms[i], nom) == 0) {
            return i;
        }
    }

    if (*nb_noms >= OPT_MAX_NOMS) {
        return -1;
    }

    strcpy(noms[*nb_noms], nom);
    versions[*nb_noms] = 0;
    (*nb_noms)++;
    return (*nb_noms) - 1;
}

static int opt_version_courante(char noms[][100], int versions[], int *nb_noms, const char *nom) {
    int indice;

    if (opt_est_nombre(nom)) {
        return 0;
    }

    indice = opt_indice_nom(noms, versions, nb_noms, nom);
    if (indice == -1) {
        return -1;
    }

    return versions[indice];
}

static int opt_operateur_commutatif(const char *oper) {
    return strcmp(oper, "+") == 0 ||
           strcmp(oper, "*") == 0 ||
           strcmp(oper, "==") == 0 ||
           strcmp(oper, "!=") == 0 ||
           strcmp(oper, "AND") == 0 ||
           strcmp(oper, "OR") == 0;
}

static int opt_quad_pur(const char *oper) {
    return strcmp(oper, "+") == 0 ||
           strcmp(oper, "-") == 0 ||
           strcmp(oper, "*") == 0 ||
           strcmp(oper, "/") == 0 ||
           strcmp(oper, "<") == 0 ||
           strcmp(oper, ">") == 0 ||
           strcmp(oper, "<=") == 0 ||
           strcmp(oper, ">=") == 0 ||
           strcmp(oper, "==") == 0 ||
           strcmp(oper, "!=") == 0 ||
           strcmp(oper, "AND") == 0 ||
           strcmp(oper, "OR") == 0 ||
           strcmp(oper, "NOT") == 0 ||
           strcmp(oper, ":=") == 0;
}

static void nettoyerQuadrupletsInutiles(void) {
    int suppression[1000];
    int ancienne_qc;
    int correspondance[1001];
    int map_cible[1001];
    int i;
    int j;
    int k;
    int modifie;
    int nouvelle_qc;
    int cible;
    char tampon[20];

    for (i = 0; i < qc; i++) {
        suppression[i] = (strcmp(quad[i].oper, "NOP") == 0);
    }

    do {
        modifie = 0;
        for (i = 0; i < qc; i++) {
            int utilise = 0;

            if (suppression[i]) {
                continue;
            }

            if (!opt_est_temporaire(quad[i].res)) {
                continue;
            }

            if (!opt_quad_pur(quad[i].oper)) {
                continue;
            }

            for (j = 0; j < qc && !utilise; j++) {
                if (suppression[j] || i == j) {
                    continue;
                }

                if (strcmp(quad[j].op1, quad[i].res) == 0 || strcmp(quad[j].op2, quad[i].res) == 0) {
                    utilise = 1;
                }
            }

            if (!utilise) {
                suppression[i] = 1;
                modifie = 1;
            }
        }
    } while (modifie);

    ancienne_qc = qc;
    nouvelle_qc = 0;

    for (i = 0; i < ancienne_qc; i++) {
        if (suppression[i]) {
            correspondance[i] = -1;
        } else {
            correspondance[i] = nouvelle_qc++;
        }
    }

    map_cible[ancienne_qc] = nouvelle_qc;
    for (i = ancienne_qc - 1; i >= 0; i--) {
        if (correspondance[i] != -1) {
            map_cible[i] = correspondance[i];
        } else {
            map_cible[i] = map_cible[i + 1];
        }
    }

    k = 0;
    for (i = 0; i < ancienne_qc; i++) {
        if (!suppression[i]) {
            if (k != i) {
                quad[k] = quad[i];
            }
            k++;
        }
    }

    qc = nouvelle_qc;

    for (i = 0; i < qc; i++) {
        if (strcmp(quad[i].oper, "BR") == 0 || strcmp(quad[i].oper, "BZ") == 0) {
            cible = atoi(quad[i].op1);
            if (cible >= 0 && cible <= ancienne_qc) {
                sprintf(tampon, "%d", map_cible[cible]);
                strcpy(quad[i].op1, tampon);
            }
        }
    }
}

static void optimiserQuadruplets(void) {
    int leaders[1001];
    char noms[OPT_MAX_NOMS][100];
    int versions[OPT_MAX_NOMS];
    OptCopieInfo copies[OPT_MAX_INFOS];
    OptExpressionInfo expressions[OPT_MAX_INFOS];
    OptDefinitionInfo definitions[OPT_MAX_INFOS];
    int nb_noms;
    int nb_copies;
    int nb_expressions;
    int nb_definitions;
    int i;
    int j;
    int indice;
    int version_res;

    for (i = 0; i <= qc; i++) {
        leaders[i] = 0;
    }

    leaders[0] = 1;
    for (i = 0; i < qc; i++) {
        if (strcmp(quad[i].oper, "BR") == 0 || strcmp(quad[i].oper, "BZ") == 0) {
            int cible = atoi(quad[i].op1);
            if (cible >= 0 && cible <= qc) {
                leaders[cible] = 1;
            }
            if (i + 1 < qc) {
                leaders[i + 1] = 1;
            }
        }
    }

    nb_noms = 0;
    nb_copies = 0;
    nb_expressions = 0;
    nb_definitions = 0;
    for (i = 0; i < OPT_MAX_NOMS; i++) {
        versions[i] = 0;
    }

    for (i = 0; i < qc; i++) {
        qdr *courant = &quad[i];

        if (strcmp(courant->oper, "NOP") == 0) {
            continue;
        }

        if (leaders[i]) {
            nb_copies = 0;
            nb_expressions = 0;
            nb_definitions = 0;
        }

        if (strcmp(courant->oper, "BR") != 0 && strcmp(courant->oper, "BZ") != 0) {
            char remplace[100];
            int profondeur = 0;

            strcpy(remplace, courant->op1);
            while (profondeur < 20 && opt_est_nom_versionnable(remplace)) {
                int trouve = 0;
                for (j = 0; j < nb_copies; j++) {
                    if (!copies[j].valide || strcmp(copies[j].dest, remplace) != 0) {
                        continue;
                    }

                    indice = opt_indice_nom(noms, versions, &nb_noms, copies[j].dest);
                    if (indice == -1 || versions[indice] != copies[j].version_dest) {
                        continue;
                    }

                    if (opt_est_nom_versionnable(copies[j].source)) {
                        int indice_source = opt_indice_nom(noms, versions, &nb_noms, copies[j].source);
                        if (indice_source == -1 || versions[indice_source] != copies[j].version_source) {
                            continue;
                        }
                    }

                    strcpy(remplace, copies[j].source);
                    trouve = 1;
                    break;
                }

                if (!trouve) {
                    break;
                }
                profondeur++;
            }
            strcpy(courant->op1, remplace);
        }

        if (strcmp(courant->oper, "BR") != 0) {
            char remplace[100];
            int profondeur = 0;

            strcpy(remplace, courant->op2);
            while (profondeur < 20 && opt_est_nom_versionnable(remplace)) {
                int trouve = 0;
                for (j = 0; j < nb_copies; j++) {
                    if (!copies[j].valide || strcmp(copies[j].dest, remplace) != 0) {
                        continue;
                    }

                    indice = opt_indice_nom(noms, versions, &nb_noms, copies[j].dest);
                    if (indice == -1 || versions[indice] != copies[j].version_dest) {
                        continue;
                    }

                    if (opt_est_nom_versionnable(copies[j].source)) {
                        int indice_source = opt_indice_nom(noms, versions, &nb_noms, copies[j].source);
                        if (indice_source == -1 || versions[indice_source] != copies[j].version_source) {
                            continue;
                        }
                    }

                    strcpy(remplace, copies[j].source);
                    trouve = 1;
                    break;
                }

                if (!trouve) {
                    break;
                }
                profondeur++;
            }
            strcpy(courant->op2, remplace);
        }

        if (strcmp(courant->oper, "-") == 0 && opt_est_nom_versionnable(courant->op1)) {
            for (j = 0; j < nb_definitions; j++) {
                if (!definitions[j].valide || strcmp(definitions[j].nom, courant->op1) != 0) {
                    continue;
                }

                indice = opt_indice_nom(noms, versions, &nb_noms, definitions[j].nom);
                if (indice == -1 || versions[indice] != definitions[j].version_nom) {
                    continue;
                }

                if (definitions[j].version_op1 != opt_version_courante(noms, versions, &nb_noms, definitions[j].op1) ||
                    definitions[j].version_op2 != opt_version_courante(noms, versions, &nb_noms, definitions[j].op2)) {
                    continue;
                }

                if (strcmp(definitions[j].oper, "+") == 0 && strcmp(courant->op2, "1") == 0) {
                    if (strcmp(definitions[j].op2, "1") == 0) {
                        strcpy(courant->oper, ":=");
                        strcpy(courant->op1, definitions[j].op1);
                        strcpy(courant->op2, "_");
                    } else if (strcmp(definitions[j].op1, "1") == 0) {
                        strcpy(courant->oper, ":=");
                        strcpy(courant->op1, definitions[j].op2);
                        strcpy(courant->op2, "_");
                    }
                }

                break;
            }
        }

        if (strcmp(courant->oper, "+") == 0) {
            if (strcmp(courant->op1, "0") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op1, courant->op2);
                strcpy(courant->op2, "_");
            } else if (strcmp(courant->op2, "0") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op2, "_");
            }
        } else if (strcmp(courant->oper, "-") == 0) {
            if (strcmp(courant->op2, "0") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op2, "_");
            }
        } else if (strcmp(courant->oper, "*") == 0) {
            if (strcmp(courant->op1, "0") == 0 || strcmp(courant->op2, "0") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op1, "0");
                strcpy(courant->op2, "_");
            } else if (strcmp(courant->op1, "1") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op1, courant->op2);
                strcpy(courant->op2, "_");
            } else if (strcmp(courant->op2, "1") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op2, "_");
            } else if (strcmp(courant->op1, "2") == 0) {
                char operande[100];
                strcpy(courant->oper, "+");
                strcpy(operande, courant->op2);
                strcpy(courant->op1, operande);
                strcpy(courant->op2, operande);
            } else if (strcmp(courant->op2, "2") == 0) {
                strcpy(courant->oper, "+");
                strcpy(courant->op2, courant->op1);
            }
        } else if (strcmp(courant->oper, "/") == 0) {
            if (strcmp(courant->op2, "1") == 0) {
                strcpy(courant->oper, ":=");
                strcpy(courant->op2, "_");
            }
        }

        if (opt_quad_pur(courant->oper) &&
            strcmp(courant->oper, ":=") != 0 &&
            strcmp(courant->oper, "READ") != 0 &&
            strcmp(courant->oper, "WRITE") != 0 &&
            strcmp(courant->oper, "BR") != 0 &&
            strcmp(courant->oper, "BZ") != 0) {
            for (j = 0; j < nb_expressions; j++) {
                int meme_expression;

                if (!expressions[j].valide || strcmp(expressions[j].oper, courant->oper) != 0) {
                    continue;
                }

                meme_expression =
                    (strcmp(expressions[j].op1, courant->op1) == 0 && strcmp(expressions[j].op2, courant->op2) == 0) ||
                    (opt_operateur_commutatif(courant->oper) &&
                     strcmp(expressions[j].op1, courant->op2) == 0 &&
                     strcmp(expressions[j].op2, courant->op1) == 0);

                if (!meme_expression) {
                    continue;
                }

                if (expressions[j].version_op1 != opt_version_courante(noms, versions, &nb_noms, expressions[j].op1) ||
                    expressions[j].version_op2 != opt_version_courante(noms, versions, &nb_noms, expressions[j].op2)) {
                    continue;
                }

                if (opt_est_nom_versionnable(expressions[j].res)) {
                    int indice_res = opt_indice_nom(noms, versions, &nb_noms, expressions[j].res);
                    if (indice_res == -1 || versions[indice_res] != expressions[j].version_res) {
                        continue;
                    }
                }

                strcpy(courant->oper, ":=");
                strcpy(courant->op1, expressions[j].res);
                strcpy(courant->op2, "_");
                break;
            }
        }

        if (strcmp(courant->oper, ":=") == 0 && strcmp(courant->op1, courant->res) == 0) {
            strcpy(courant->oper, "NOP");
            strcpy(courant->op1, "_");
            strcpy(courant->op2, "_");
            strcpy(courant->res, "_");
            continue;
        }

        if (i + 1 < qc &&
            strcmp(courant->oper, "NOP") != 0 &&
            strcmp(quad[i + 1].oper, "NOP") != 0 &&
            opt_est_temporaire(courant->res) &&
            strcmp(quad[i + 1].oper, ":=") == 0 &&
            strcmp(quad[i + 1].op1, courant->res) == 0 &&
            strchr(quad[i + 1].res, '[') == NULL) {
            int usages = 0;

            for (j = 0; j < qc; j++) {
                if (strcmp(quad[j].oper, "NOP") == 0) {
                    continue;
                }

                if (strcmp(quad[j].op1, courant->res) == 0) {
                    usages++;
                }
                if (strcmp(quad[j].op2, courant->res) == 0) {
                    usages++;
                }
            }

            if (usages == 1) {
                strcpy(courant->res, quad[i + 1].res);
                strcpy(quad[i + 1].oper, "NOP");
                strcpy(quad[i + 1].op1, "_");
                strcpy(quad[i + 1].op2, "_");
                strcpy(quad[i + 1].res, "_");
            }
        }

        if (strcmp(courant->oper, "BR") == 0 || strcmp(courant->oper, "BZ") == 0 || strcmp(courant->oper, "WRITE") == 0) {
            continue;
        }

        if (strcmp(courant->oper, ":=") == 0 && strchr(courant->res, '[') != NULL) {
            nb_copies = 0;
            nb_expressions = 0;
            nb_definitions = 0;
            continue;
        }

        version_res = -1;
        indice = opt_indice_nom(noms, versions, &nb_noms, courant->res);
        if (indice != -1) {
            versions[indice]++;
            version_res = versions[indice];
        }

        if (strcmp(courant->oper, ":=") == 0 &&
            indice != -1 &&
            (opt_est_nom_versionnable(courant->op1) || opt_est_nombre(courant->op1))) {
            int remplace = 0;
            for (j = 0; j < nb_copies; j++) {
                if (strcmp(copies[j].dest, courant->res) == 0) {
                    remplace = 1;
                    break;
                }
            }

            if (!remplace && nb_copies < OPT_MAX_INFOS) {
                j = nb_copies++;
            }

            if (j < OPT_MAX_INFOS) {
                strcpy(copies[j].dest, courant->res);
                strcpy(copies[j].source, courant->op1);
                copies[j].version_dest = version_res;
                copies[j].version_source = opt_version_courante(noms, versions, &nb_noms, courant->op1);
                copies[j].valide = 1;
            }
        }

        if (opt_quad_pur(courant->oper) &&
            strcmp(courant->oper, ":=") != 0 &&
            indice != -1 &&
            nb_expressions < OPT_MAX_INFOS) {
            strcpy(expressions[nb_expressions].oper, courant->oper);
            strcpy(expressions[nb_expressions].op1, courant->op1);
            strcpy(expressions[nb_expressions].op2, courant->op2);
            strcpy(expressions[nb_expressions].res, courant->res);
            expressions[nb_expressions].version_op1 = opt_version_courante(noms, versions, &nb_noms, courant->op1);
            expressions[nb_expressions].version_op2 = opt_version_courante(noms, versions, &nb_noms, courant->op2);
            expressions[nb_expressions].version_res = version_res;
            expressions[nb_expressions].valide = 1;
            nb_expressions++;
        }

        if (opt_quad_pur(courant->oper) &&
            strcmp(courant->oper, ":=") != 0 &&
            indice != -1) {
            int remplace = 0;
            for (j = 0; j < nb_definitions; j++) {
                if (strcmp(definitions[j].nom, courant->res) == 0) {
                    remplace = 1;
                    break;
                }
            }

            if (!remplace && nb_definitions < OPT_MAX_INFOS) {
                j = nb_definitions++;
            }

            if (j < OPT_MAX_INFOS) {
                strcpy(definitions[j].nom, courant->res);
                strcpy(definitions[j].oper, courant->oper);
                strcpy(definitions[j].op1, courant->op1);
                strcpy(definitions[j].op2, courant->op2);
                definitions[j].version_nom = version_res;
                definitions[j].version_op1 = opt_version_courante(noms, versions, &nb_noms, courant->op1);
                definitions[j].version_op2 = opt_version_courante(noms, versions, &nb_noms, courant->op2);
                definitions[j].valide = 1;
            }
        }
    }

    nettoyerQuadrupletsInutiles();
}

#endif
