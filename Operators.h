#include <string>
<<<<<<< Updated upstream
#include "Expression2.h"
=======
#include <memory>
//#include "Expression2.h"
>>>>>>> Stashed changes

#ifndef OPERATORS_H
#define OPERATORS_H

double abs(double const a);

class Node
{
public:
<<<<<<< Updated upstream

=======
  Node() {};
  //Node(Node const& rhs); 
  //  ~Node() = default;
>>>>>>> Stashed changes
  virtual double evaluate() = 0;
  virtual std::string postfix() = 0;
  virtual std::string infix() = 0;
  virtual std::string prefix() = 0;
<<<<<<< Updated upstream
=======
  //virtual std::unique_ptr<Node> construct() = 0;

  virtual std::unique_ptr<Node> clone() = 0;
>>>>>>> Stashed changes

};


class Operator: public Node
{
public:

<<<<<<< Updated upstream
  Operator(Node* const & lhs, Node* const & rhs); // Adress till operanderna
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;
=======
  Operator(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs); // Adress till operanderna
  //Operator(Operator const&);
  // ~Operator() ;
  std::string postfix() override;
  std::string infix() override;
  std::string prefix() override;
  virtual std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) = 0;
  std::unique_ptr<Node> clone() override;
>>>>>>> Stashed changes


protected:
  virtual char token() = 0;
  // std::<std::unique_ptr<Node>> opr{};

  std::unique_ptr<Node> opl{};
  std::unique_ptr<Node> opr{};
};


class Addition: public Operator
{
public:

<<<<<<< Updated upstream
  Addition(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
=======
  Addition(std::unique_ptr<Node>const & lhs, std::unique_ptr<Node> const & rhs);
  // ~Addition();

  double evaluate() override;
  std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) override;
>>>>>>> Stashed changes
protected:
  char token() override;

};


class Subtraction: public Operator
{
public:
<<<<<<< Updated upstream
  Subtraction(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
=======
  Subtraction(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs);
  // ~Subtraction();

  double evaluate() override;
  std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) override;
>>>>>>> Stashed changes
protected:
  char token() override;
};

class Multiplication: public Operator
{
public:
<<<<<<< Updated upstream
  Multiplication(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
=======
  Multiplication(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs);
  // ~Multiplication();

  double evaluate() override;
  std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) override;
>>>>>>> Stashed changes
protected:
  char token() override;
};

class Division: public Operator
{
public:
<<<<<<< Updated upstream
  Division(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
=======
  Division(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs);
  // ~Division();
  double evaluate() override;
  std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) override;
>>>>>>> Stashed changes
protected:
  char token() override;
};

class Exponentiation: public Operator
{
public:
<<<<<<< Updated upstream
  Exponentiation(Node* const & lhs, Node* const & rhs);
  double evaluate() override;
=======
  Exponentiation(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs);
  // ~Exponentiation();
  double evaluate() override;
  std::unique_ptr<Node> construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs) override;
>>>>>>> Stashed changes
protected:
  char token() override;
};


class Operand : public Node {

public:
    Operand();
<<<<<<< Updated upstream
=======
    // ~Operand() ;
    //std::unique_ptr<Node> clone()  override;
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
=======
  std::unique_ptr<Node> clone() override;
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
=======
  std::unique_ptr<Node> clone() override;
>>>>>>> Stashed changes

};

class Variable : public Operand {
private:
    std::string x;
public:
    Variable(std::string x);
    std::string postfix() override;
    std::string infix() override;
    std::string prefix() override;
<<<<<<< Updated upstream

=======
    std::unique_ptr<Node> clone() override;
>>>>>>> Stashed changes

    double evaluate() override;

};



#endif
