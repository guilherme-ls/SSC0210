all :
	g++ -o main divide2.cpp -g

testing :
	for number in `seq 6 6` ; do \
	./main < test/$$number.in > test/$$number.out2; \
	diff -s test/$$number.out test/$$number.out2; \
	done