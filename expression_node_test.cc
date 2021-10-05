#include <limits>
#include <cmath> // abs
#include <memory>
#include "Operators.h"
#include "catch.hpp"

TEST_CASE("operand real")
{
  Operand* pi{ new Real{3.14} };

  CHECK( pi->evaluate() == 3.14 );
  CHECK( pi->postfix() == "3.140" );
}


TEST_CASE("addition")
{
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};
  Node* pluslr = new Addition{pi, e};
  Node* plusrl = new Addition{e, pi};

  CHECK( pluslr->evaluate() == 5.86 );
  CHECK( plusrl->evaluate() == 5.86 );
  CHECK( pluslr->postfix() == "3.140 2.720 +" );
  CHECK( plusrl->postfix() == "2.720 3.140 +" );
}

// If catch report 0.42 != 0.42 you are likely to have a small
// rounding error in some invisible decimal place. In such case you
// can compare if the difference is small enough to consider two
// doubles equal anyway.
bool compare_equal(double a, double b)
{
    return abs(a - b) <= std::numeric_limits<double>::epsilon();
}

TEST_CASE("test case ignoring rounding errors")
{
  Node* a = new Real{0.01};
  Node* b = new Real{0.09};
  Node* plus = new Addition{a, b};

  // CHECK( plus->evaluate() == 0.1 ); // Rounding error!!
  CHECK( compare_equal(plus->evaluate(), 0.1) );
}


TEST_CASE("operand integer")
{
  Operand* i = new Integer{7};

  CHECK( i->evaluate() == 7 );
  CHECK( i->postfix() == "7" );
}

TEST_CASE("conversion to string")
{
    Node* a = new Subtraction{    new Addition{       new Subtraction{ new Real{1.0},
                                                                      new Integer{1} },
                                                      new Multiplication{ new Integer{2},
                                                                          new Integer{5} }},
                                  new Addition{       new Exponentiation{ new Integer{7},
                                                                          new Integer{3} },
                                                      new Division{       new Integer{7},
                                                                          new Integer{3} } 

                                                                    }
                                              

                              };
    SECTION("prefix")
    {
        CHECK( a->prefix() == "- + - 1.000 1 * 2 5 + ^ 7 3 / 7 3" );
    }
    SECTION("infix")
    {
        CHECK( a->infix() == "( ( ( 1.000 - 1 ) + ( 2 * 5 ) ) - ( ( 7 ^ 3 ) + ( 7 / 3 ) ) )" );
    }

    SECTION("postfix")
    {
        CHECK( a->postfix() == "1.000 1 - 2 5 * + 7 3 ^ 7 3 / + -" );
    }
}


TEST_CASE("not allowed divison/exponentiation")
{
  Node* a = new Division{new Integer{1}, 
                         new Subtraction{new Real{5}, 
                                         new Integer{5}}};
                                         
  Node* b = new Exponentiation{new Integer{0},
                               new Subtraction{new Integer{5}, 
                                               new Integer{7}}};
  
  Node* c = new Exponentiation{new Integer{-5},
                               new Subtraction{new Integer{5}, 
                                               new Real{7.5}}};                                           

  SECTION("division")
  {
    CHECK_THROWS(a->evaluate());
  }
  SECTION("exponentiation")
  {
    CHECK_THROWS(b->evaluate());
    CHECK_THROWS(c->evaluate());
  }
}
#if 0 // Flytta ned denna rad för att aktivera nästa TEST_CASE

#endif
