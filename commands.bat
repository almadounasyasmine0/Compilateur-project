bison -d syn.y
flex Lex.l
gcc lex.yy.c syn.tab.c -o Lexer.exe
Lexer.exe<source.txt