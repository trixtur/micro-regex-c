.PHONY: build_test run_test clean


build_test:
	gcc -o test test.c -lcunit

run_test: 
	./test

clean: 
	rm test

test : | build_test run_test
