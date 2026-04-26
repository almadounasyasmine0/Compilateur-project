BeginProject M1_iv_2526;

Setup:
//*
    DECLARATIONS 

*//

%% variables simples
define x | y | z : integer;
define i | j | k : integer;
define a | b : float;

%% avec initialisation
define somme : integer = 0;
define moyenne : float = 0.0;

%% tableaux
define Tabint : [integer; 50];
define Tabfloat : [float; 30];

%% constantes
const Pi : float = 3.14159;
const Max : integer = 100;

Run:
{
    //*
    Instructions 
    *// 
    %%  AFFECTATIONS 
    x <-- 10;
    y <-- 5;
    z <-- 2;

    a <-- 2.5;
    b <-- (a + Pi) * 2.0;

    Tabint[0] <-- x + y * z;
    Tabfloat[1] <-- (b + 3.5) / 2.0;
 

    if ((x > y AND (z < x + y)) OR NON(y == 0)) then:
    {
        somme <-- x + y + z;

        for i in 0 to 10
        {
            Tabint[i] <-- Tabint[i] + i;
            
            if ((i < 5) AND (Tabint[i] > 10)) then:
            {
                Tabfloat[i] <-- Tabint[i] * 1.5;
            } else {
                Tabfloat[i] <-- Tabint[i] / 2.0;
            } endIf;
        } endfor;

    } else {
        somme <-- 0;
    } endIf;

    loop while ((x <= Max) AND ((y != 0) OR (z < 10)))
    {
        x <-- x + 1;

        %% boucle imbriquée
        loop while (NON(x == y))
        {
            y <-- y + 1;

            Tabint[x + 1] <-- (Tabint[0] + Tabint[1]) * (x - y);

        } endloop;

    } endloop;

    for j in 1 to 20
    {
        Tabfloat[j] <-- (Tabfloat[j-1] + Tabfloat[j]) / 2.0;
        moyenne <-- moyenne + Tabfloat[j];
    } endfor;

    moyenne <-- moyenne / 20.0;

    input(x);
    out("Valeur finale de x: ", x);
    out("Somme: ", somme);
    out("Moyenne: ", moyenne);

}
EndProject;