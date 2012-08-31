main:	main.cpp *.hpp
	g++ -o main main.cpp

test:	test-executor.cpp *.hpp
	g++ -o test test-executor.cpp

