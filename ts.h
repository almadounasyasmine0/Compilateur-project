#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 100

typedef struct Element {
    char nom[20];
    char code[20];
    char type[10];
    double valeur;
    int taille;
    struct Element *suivant;
} Element;

/* Déclaration de la table */
Element* table_symbole[TAILLE];

/* --- NOUVELLE FONCTION --- */
void initialiserTS() {
    int i; 
    for(i=0; i<100; i++) {
        table_symbole[i] = NULL;
    }
}

int hachage(char* nom) {
    int i = 0, somme = 0;
    while (nom[i] != '\0') {
        somme += nom[i];
        i++;
    }
    return somme % TAILLE;
}

Element* rechercher(char* nom) {
    int indice = hachage(nom);
    Element* courant = table_symbole[indice];
    while (courant != NULL) {
        if (strcmp(courant->nom, nom) == 0) return courant;
        courant = courant->suivant;
    }
    return NULL;
}

void inserer(char* nom, char* code, char* type, double val, int taille) {
    if (rechercher(nom) == NULL) {
        int indice = hachage(nom);
        Element* nouveau = (Element*)malloc(sizeof(Element));
        strcpy(nouveau->nom, nom);
        strcpy(nouveau->code, code);
        strcpy(nouveau->type, type);
        nouveau->valeur = val;
        nouveau->taille = taille;
        nouveau->suivant = table_symbole[indice];
        table_symbole[indice] = nouveau;
    }
}

void mettreAjourType(char* ancienType, char* nouveauType, int taille) {
    int i;
    for(i = 0; i < 100; i++) {
        Element* courant = table_symbole[i];
        while (courant != NULL) {
            if (strcmp(courant->type, ancienType) == 0) {
                strcpy(courant->type, nouveauType);
                courant->taille = taille;
                
                // Si la taille > 0, on s'assure que le code est "Tableau"
                if (taille > 0) {
                    strcpy(courant->code, "Tableau");
                }
            }
            courant = courant->suivant;
        }
    }
}

void afficherTS() {
    printf("\n/*************** Table des Symboles ***************/\n");
    printf("___________________________________________________________________\n");
    printf("| %-15s | %-12s | %-10s | %-8s | %-7s |\n", "Nom", "Code", "Type", "Valeur", "Taille");
    printf("|_________________|______________|____________|__________|_________|\n");
    
    int i;
    for(i=0; i<100; i++) {
        Element* courant = table_symbole[i];
        while (courant != NULL) {
            printf("| %-15s | %-12s | %-10s | ", courant->nom, courant->code, courant->type);
            
            // On adapte l'affichage selon le type
            if (strcmp(courant->type, "integer") == 0) {
                // On affiche comme un entier (on cast la valeur double)
                printf("%-8d | ", (int)courant->valeur);
            } else {
                // On affiche comme un float avec 2 décimales
                printf("%-8.2f | ", courant->valeur);
            }
            
            printf("%-7d |\n", courant->taille);
            courant = courant->suivant;
        }
    }
    printf("|_________________|______________|____________|__________|_________|\n");
}



#endif



