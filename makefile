comp: interpretor.y interpretor.l
	bison -v -d interpretor.y
	flex interpretor.l
	gcc lex.yy.c interpretor.tab.c -o interpret

clean:
	rm lex.yy.c
	rm interpretor.tab.c 
	rm interpretor.tab.h
	rm interpret
	rm interpretor.output

push:
	git add .
	git commit -m "Versiunea 0.5.2"
	git push origin experimental

run: interpret input1.txt
	./interpret input1.txt