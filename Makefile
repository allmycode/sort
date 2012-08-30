main:		main.cpp
		g++ -o main main.cpp

test-gen:	test-generator.cpp
		g++ -o test-generator test-generator.cpp

test-exec:	test-executor.cpp
		g++ -o test test-executor.cpp
