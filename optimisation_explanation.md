# Optimisation des quadruplets

## Fichiers ajoutés / modifiés

- `optimizationQdr.h` : nouvelle petite librairie d'optimisation des quadruplets.
- `syn.y` : appel de l'optimiseur juste après `yyparse()` et avant l'affichage final.
- `quad.h` : refactorisé pour exposer proprement les déclarations des quadruplets.
- `Lex.l` : garde l'implémentation réelle du tableau `quad[]` avec `#define QUAD_IMPLEMENTATION`.

## Les 2 fonctions principales

J'ai gardé l'optimisation autour de **2 fonctions principales** :

1. `optimiserQuadruplets()`
2. `nettoyerQuadrupletsInutiles()`

Les autres petites fonctions du fichier ne servent qu'à tester si un opérande est un temporaire, un nombre, un nom réutilisable, etc. Elles sont juste des helpers techniques.

## Ce qui est optimisé

L'optimiseur travaille **localement par bloc de base**.  
Autrement dit, il réinitialise ses informations aux entrées de blocs ciblés par `BR` et `BZ`, ce qui évite de casser la sémantique des `if`, `while` et `for`.

### 1. Propagation de copie

Quand on a une copie du style :

```text
T1 := x
y := T1
```

on remplace l'utilisation de `T1` par `x` quand c'est encore valide.

Cela permet aussi de simplifier beaucoup de quadruplets temporaires.

### 2. Propagation d'expression ciblée

J'ai ajouté une simplification utile qui suit directement l'idée du PDF :

```text
T0 = j + 1
T1 = T0 - 1
```

devient :

```text
T1 = j
```

Puis, si `T1` ne sert qu'à faire une affectation finale, le temporaire disparaît complètement.

Exemple vérifié :

```text
x <- (j + 1) - 1;
```

Après optimisation, les quadruplets deviennent simplement :

```text
0 - ( := , j , _ , x )
```

### 3. Élimination des expressions redondantes

Si une même expression réapparaît dans le même bloc sans modification de ses opérandes, on ne la recalcule pas.

Exemple logique :

```text
T0 = a + b
T1 = a + b
```

Le deuxième calcul est remplacé par une copie du premier résultat.

### 4. Simplification algébrique

Les règles suivantes sont prises en charge :

- `x + 0  => x`
- `x - 0  => x`
- `x * 1  => x`
- `1 * x  => x`
- `x * 0  => 0`
- `0 * x  => 0`
- `x / 1  => x`
- `x * 2  => x + x`

Cette dernière règle correspond à la simplification algébrique montrée dans le PDF.

### 5. Élimination du code inutile

Après les remplacements précédents :

- les copies devenues inutiles sont transformées en `NOP`
- les temporaires jamais relus sont supprimés
- les quadruplets sont compactés
- les cibles de sauts `BR` / `BZ` sont recalculées pour garder des indices corrects

## Exemple observé sur votre programme

Avant, on avait des séquences comme :

```text
14 - ( + , a , i , T5 )
15 - ( := , T5 , _ , a )
```

Après optimisation :

```text
12 - ( + , a , i , a )
```

Même chose pour :

```text
16 - ( + , i , 1 , T6 )
17 - ( := , T6 , _ , i )
```

qui devient :

```text
13 - ( + , i , 1 , i )
```

## Résultat final

L'optimiseur applique donc bien les idées du PDF :

- propagation de copie
- propagation d'expression sur un cas utile
- élimination des expressions redondantes
- simplification algébrique
- élimination de code inutile

Le tout reste volontairement simple et compact, ce qui correspond bien à la remarque du professeur sur le fait qu'il n'y avait pas besoin d'un gros module compliqué.
