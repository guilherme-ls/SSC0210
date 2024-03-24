all :
	g++ -o main backtracking3.cpp -g

testing :
	for number in `seq 1 2` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done