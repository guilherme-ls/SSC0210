all :
	g++ -o main dynamic5.cpp -g -O3

testing :
	for number in `seq 1 15` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done