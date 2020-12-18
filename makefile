comp: interpretor.y interpretor.l
	bison -d interpretor.y
	flex interpretor.l
	gcc lex.yy.c interpretor.tab.c -o interpret

clean:
	rm lex.yy.c
	rm interpretor.tab.c 
	rm interpretor.tab.h
	rm interpret

push:
	git add .
	git commit -m "Versiunea 0.5"
	git push origin experimental

run: interpret input.txt
	./interpret input.txt