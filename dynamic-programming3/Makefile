all :
	g++ -o main dynamic3.cpp -g

testing :
	for number in `seq 1 8` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done