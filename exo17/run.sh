if [ -f lex.yy.c ] && [ -f analyser.tab.c ] && [ -f exo17 ] && [ -f analyser.h ]; then
    rm lex.yy.c analyser.tab.c exo17 analyser.h
fi

flex analyser.lex
bison --defines=analyser.h -v -o analyser.tab.c parser.y
gcc lex.yy.c analyser.tab.c -o exo17 -lfl
cat commande.mes | ./exo17