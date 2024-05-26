all :
	g++ -o main graphs4.cpp -g -O3

testing :
	for number in `seq 1 21` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done