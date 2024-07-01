if [ -f lex.yy.c ] && [ -f analyser.tab.c ] && [ -f exo18 ] && [ -f analyser.h ];; then
    rm lex.yy.c analyser.tab.c exo18 analyser.h
fi


flex analyser.lex
bison --defines=analyser.h -v -o analyser.tab.c parser.y
gcc lex.yy.c analyser.tab.c -o exo18 -lfl
cat commande.mes | ./exo18