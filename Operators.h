#include <string>

#ifndef HEADERFILE_H
#define HEADERFILE_H

class Node
{
public:

  virtual double evaluate() = 0;
  virtual std::string postfix() = 0;
  virtual std::string infix() = 0;
  virtual std::string prefix() = 0; 

};


class Operator: public Node
{
public:

  Operator(Node* const & lhs, Node* const & rhs); // Adress till operanderna 
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;

  
protected:
  virtual char token() = 0;
  Node* opl{};
  Node* opr{};
};


class Addition: public Operator
{
public:

  Addition(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
protected:
  char token() override;

};


class Subtraction: public Operator
{
public:
  Subtraction(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
protected:
  char token() override;
};

class Multiplication: public Operator
{
public:
  Multiplication(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
protected:
  char token() override;
};

class Division: public Operator
{
public:
  Division(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
protected:
  char token() override;
};

class Exponentiation: public Operator
{
public:
  Exponentiation(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
protected:
  char token() override;
};


class Operand : public Node {

public:
    Operand();

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

};

class Variable : public Operand {
private:
    std::string x;
public:
    Variable(std::string x);
    std::string postfix() override;
    std::string infix() override;
    std::string prefix() override;


    double evaluate() override;

};



#endif
