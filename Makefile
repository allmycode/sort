main:	main.cpp *.hpp
	g++ -o main main.cpp

test:	test-executor.cpp *.hpp
	g++ -o test test-executor.cpp

measure: measure.cpp *.hpp
	g++ -O3 -o measure measure.cpp
