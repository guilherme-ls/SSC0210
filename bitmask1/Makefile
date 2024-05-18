all :
	g++ -o main bitmask1.cpp -g -O3 -march=native

testing :
	for number in `seq 1 3` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done