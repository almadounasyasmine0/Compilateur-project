# Semantic Exceptions Handled in This Project

This file lists the semantic exceptions that are explicitly handled in the current parser implementation.

Scope:
- Included: semantic checks implemented in `syn.y` through `erreurSemantique(...)` or through explicit semantic error propagation.
- Excluded: lexical errors from `Lex.l` and syntax errors from `yyerror(...)`, because they are not semantic exceptions.

## 1. Declaration and symbol-table checks

| Exception message | When it happens | Location |
| --- | --- | --- |
| `Double declaration` | An identifier declared with `define` already exists in the symbol table. | `syn.y:95-99` |
| `Double declaration` | An identifier declared later in the same `define a | b | c` chain already exists. | `syn.y:102-106` |
| `Taille tableau doit etre > 0` | An array is declared with a size less than or equal to `0`. | `syn.y:113-117` |
| `Constante deja declaree` | A constant is declared more than once. | `syn.y:128-137` |
| `Valeur hors intervalle [-32768, 32767]` | A constant declared as `integer` has a value outside the allowed range. | `syn.y:131-135` |

## 2. Assignment checks

| Exception message | When it happens | Location |
| --- | --- | --- |
| `Variable non declaree` | A simple assignment targets an identifier that was never declared. | `syn.y:148-157` |
| `Interdit de modifier une constante` | A simple assignment tries to modify a constant. | `syn.y:153-155` |
| `Incompatibilite de types` | A simple assignment tries to assign an expression whose type does not match the target variable type. | `syn.y:155-157` |
| `Tableau non declare` | An indexed assignment targets an array name that does not exist. | `syn.y:160-169` |
| `Pas un tableau` | An indexed assignment uses `idf[...]` on a symbol that is not an array. | `syn.y:164-166` |
| `Incompatibilite` | An indexed assignment tries to assign a value whose type does not match the array element type. | `syn.y:166-169` |

## 3. Loop checks

| Exception message | When it happens | Location |
| --- | --- | --- |
| `Variable non declaree` | The control variable of a `for` loop does not exist. | `syn.y:234-250` |
| `Interdit de modifier une constante` | The control variable of a `for` loop is a constant. | `syn.y:245-247` |
| `Boucle for exige des entiers` | The `for` variable, start value, or end value is not of type `integer`. | `syn.y:247-250` |

## 4. Input / output checks

| Exception message | When it happens | Location |
| --- | --- | --- |
| `Variable non declaree` | `in(idf)` is used with an undeclared identifier. | `syn.y:285-290` |
| `Interdit de modifier une constante` | `in(idf)` tries to read into a constant. | `syn.y:288-290` |
| `Variable non declaree` | `out("text", idf)` uses an undeclared identifier as its second argument. | `syn.y:297-302` |
| `Variable non declaree` | `out(idf)` uses an undeclared identifier. | `syn.y:304-308` |

## 5. Expression and operand checks

| Exception message | When it happens | Location |
| --- | --- | --- |
| `Non declare` | An identifier is used inside an expression but is missing from the symbol table. | `syn.y:386-397` |
| `Erreur tableau` | An indexed access like `idf[index]` is used on an undeclared symbol or on a symbol that is not an array. | `syn.y:401-414` |
| `Incompatibilite types` on `+` | The two operands of addition do not have the same valid type. | `syn.y:312-327` |
| `Incompatibilite types` on `-` | The two operands of subtraction do not have the same valid type. | `syn.y:329-344` |
| `Incompatibilite types` on `*` | The two operands of multiplication do not have the same valid type. | `syn.y:349-364` |
| `Incompatibilite types` on `/` | The two operands of division do not have the same valid type. | `syn.y:366-381` |
| `Incompatibilite types` on comparison operator | The two operands of a comparison (`>`, `<`, `>=`, `<=`, `==`, `!=`) do not have the same valid type. | `syn.y:420-435` |

## 6. Silent semantic error propagation

These cases are handled semantically, but they do not emit a new explicit `erreurSemantique(...)` message.

| Behavior | What the code does | Location |
| --- | --- | --- |
| Error propagation in arithmetic expressions | If one operand already has type `error`, the expression result is marked as `error` and no arithmetic quadruplet is generated. | `syn.y:315-318`, `syn.y:332-335`, `syn.y:352-355`, `syn.y:369-372` |
| Error propagation in comparisons | If one side of a comparison already has type `error`, the condition result is marked as `error` and no comparison quadruplet is generated. | `syn.y:423-426` |
| Invalid `for` guard | If the `for` loop header is semantically invalid, `idf_for` stays empty and the end-of-loop quadruplet logic is skipped. | `syn.y:239-260`, `syn.y:270-280` |

## 7. Notes

- The project does have lexical checks in `Lex.l`, such as unknown characters and overly long identifiers, but those are lexical exceptions, not semantic ones.
- The project also has syntax error handling through `yyerror(...)`, but that is separate from semantic validation.

