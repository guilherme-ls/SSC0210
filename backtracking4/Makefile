all :
	g++ -o main backtracking4.cpp -g

testing :
	for number in `seq 1 1` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done