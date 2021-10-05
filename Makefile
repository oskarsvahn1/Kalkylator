CCC=g++ -std=c++17
CFLAGS=-Wall -Wextra -pedantic

main: test_main.o expression_node_test.o Operators.o
	$(CCC) $(CFLAGS)  test_main.o expression_node_test.o Operators.o


# test_main.o: test_main.cc
# 	$(CCC) $(CFLAGS)  -c test_main.cc

expression_node_test.o: expression_node_test.cc
	$(CCC) $(CFLAGS)  -c expression_node_test.cc

Operators.o: Operators.cc
	$(CCC) $(CFLAGS)  -c Operators.cc

check: test_main.o expression_node_test.o Operators.cc
	$(CCC) $(CFLAGS)  test_main.o expression_node_test.cc Operators.cc
	./a.out

clean:
	\rm *.o a.out
