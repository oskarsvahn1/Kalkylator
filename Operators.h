#include <string>
//#include "Expression2.h"

#ifndef OPERATORS_H
#define OPERATORS_H

double abs(double const a);

class Node
{
public:
   Node() {};
  //  ~Node() = default;
  virtual double evaluate() = 0;
  virtual std::string postfix() = 0;
  virtual std::string infix() = 0;
  virtual std::string prefix() = 0;
  //virtual Node* construct() = 0;

  virtual Node* clone() = 0;

};

class Operator: public Node
{
public:

  Operator(Node* const & lhs, Node* const & rhs); // Adress till operanderna
  ~Operator() ;
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;
  virtual Node* construct(Node* const & lhs, Node* const & rhs) = 0;
  Node* clone() override;


protected:
  virtual char token() = 0;
  Node* opl{};
  Node* opr{};
};


class Addition: public Operator
{
public:

  Addition(Node* const & lhs, Node* const & rhs);
  // ~Addition();

  double evaluate() override;
  Node* construct(Node* const & lhs, Node* const & rhs) override;
protected:
  char token() override;

};

class Subtraction: public Operator
{
public:
  Subtraction(Node* const & lhs, Node* const & rhs);
  // ~Subtraction();

  double evaluate() override;
  Node* construct(Node* const & lhs, Node* const & rhs) override;
protected:
  char token() override;
};

class Multiplication: public Operator
{
public:
  Multiplication(Node* const & lhs, Node* const & rhs);
  // ~Multiplication();

  double evaluate() override;
  Node* construct(Node* const & lhs, Node* const & rhs) override;
protected:
  char token() override;
};

class Division: public Operator
{
public:
  Division(Node* const & lhs, Node* const & rhs);
  // ~Division();
  double evaluate() override;
  Node* construct(Node* const & lhs, Node* const & rhs) override;
protected:
  char token() override;
};

class Exponentiation: public Operator
{
public:
  Exponentiation(Node* const & lhs, Node* const & rhs);
  // ~Exponentiation();
  double evaluate() override;
  Node* construct(Node* const & lhs, Node* const & rhs) override;
protected:
  char token() override;
};


class Operand : public Node {

public:
    Operand();
    ~Operand() ;
    //Node* clone()  override;

};

class Real : public Operand
{
private:
  float x;
public:
  Real(float r);
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;
  double evaluate() override;
  Node* clone() override;

};

class Integer : public Operand
{
private:
  int x;
public:
  Integer(int i);
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;
  double evaluate() override;
  Node* clone() override;

};

class Variable : public Operand {
private:
    std::string x;
public:
    Variable(std::string x);
    std::string postfix() override;
    std::string infix() override;
    std::string prefix() override;
    Node* clone() override;

    double evaluate() override;

};



#endif
