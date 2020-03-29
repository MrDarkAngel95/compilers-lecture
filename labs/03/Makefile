all:
	python code_generator.py --stress > example.ac
	lex my_homework.l
	gcc lex.yy.c -o lexical_scan -lfl
	./lexical_scan example.ac
	nano lex.out

stresstest:
	./lexical_scan random_code.ac
	nano lex.out

clean:
	rm -rf *.ac
	rm -rf *.c
	rm -rf lexical_scan
	rm -rf *.out