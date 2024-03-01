all :
	gcc -o main heranca2.c -g

testing :
	for number in `seq 1 3` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done