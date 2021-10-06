CCC=g++ -std=c++17
CFLAGS=-Wall -Wextra -pedantic

main: test_main.o expression_node_test.o Operators2.o 
	$(CCC) $(CFLAGS)  test_main.o expression_node_test.o Operators2.o Expression2.cc


# test_main.o: test_main.cc
# 	$(CCC) $(CFLAGS)  -c test_main.cc
expression2.o: Expression2.cc
	$(CCC) $(CFLAGS)  -c Expression2.cc

expression_node_test.o: expression_node_test.cc
	$(CCC) $(CFLAGS)  -c expression_node_test.cc

Operators2.o: Operators2.cc
	$(CCC) $(CFLAGS)  -c Operators2.cc

check: test_main.o expression_node_test.o Operators.cc
	$(CCC) $(CFLAGS)  test_main.o expression_node_test.cc Operators.cc
	./a.out

clean:
	\rm *.o a.out
