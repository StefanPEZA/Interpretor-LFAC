comp: interpretor.y interpretor.l
	yacc -d interpretor.y -Wno-yacc
	lex interpretor.l
	gcc lex.yy.c y.tab.c -o interpret

clean:
	rm lex.yy.c
	rm y.tab.c 
	rm y.tab.h
	rm interpret

push:
	git add .
	git commit -m "Second test"
	git push origin second