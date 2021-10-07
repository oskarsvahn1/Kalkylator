CCC=g++ -std=c++17
CFLAGS=-Wall -Wextra -pedantic


main: a.out


a.out: test_main.o expression_node_test.o Operators.o postfix.o
	$(CCC) $(CFLAGS)  test_main.o expression_node_test.o Operators.o Expression2.cc postfix.cc


# test_main.o: test_main.cc
# 	$(CCC) $(CFLAGS)  -c test_main.cc
expression2.o: Expression2.cc
	$(CCC) $(CFLAGS)  -c Expression2.cc

expression_node_test.o: expression_node_test.cc
	$(CCC) $(CFLAGS)  -c expression_node_test.cc

postfix.o: postfix.cc
	$(CCC) $(CFLAGS)  -c postfix.cc

Operators.o: Operators.cc
	$(CCC) $(CFLAGS)  -c Operators.cc

check: a.out
	./a.out

clean:
	\rm *.o a.out
