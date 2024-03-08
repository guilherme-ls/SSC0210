all :
	g++ -o main stl3.cpp -g -std=c++11

testing :
	for number in `seq 1 5` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done