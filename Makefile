CCC=g++ -std=c++17
CFLAGS=-Wall -Wextra -pedantic


main: a.out


a.out:  expression_node_test.o Operators.o postfix.o  token.o  uppgift14.o Expression2.o
	$(CCC) $(CFLAGS)  expression_node_test.o  Operators.o Expression2.cc postfix.cc token.o uppgift14.o


# test_main.o: test_main.cc
# 	$(CCC) $(CFLAGS)  -c test_main.cc
expression2.o: Expression2.cc
	$(CCC) $(CFLAGS)  -c Expression2.cc

expression_node_test.o: expression_node_test.cc
	$(CCC) $(CFLAGS)  -c expression_node_test.cc

postfix.o: postfix.cc
	$(CCC) $(CFLAGS)  -c postfix.cc

postfix_test.o: postfix_test.cc
	$(CCC) $(CFLAGS)  -c postfix_test.cc

token.o: token.cc
	$(CCC) $(CFLAGS)  -c token.cc

Operators.o: Operators.cc
	$(CCC) $(CFLAGS)  -c Operators.cc

uppgift14.o: uppgift14.cc
	$(CCC) $(CFLAGS)  -c uppgift14.cc

check: a.out
	./a.out

clear: clean

clean:
	\rm *.o a.out
