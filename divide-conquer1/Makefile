all :
	g++ -o main divide1.cpp -g

testing :
	for number in `seq 3 3` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done