#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

namespace ShuntingYardNamespace {
  class ShuntingYard;
}

class ShuntingYard
{
public:
  ShuntingYard();
  void reset();
  void parseInfix(std::string infixStr);
  void printRPN();
  void evaluateRPN();

private:

  void parseSymbol(char c);
  bool isUnaryMinus();
  void handleInfixOperator(char c);
  int getOperatorPrecedence(char c);
  void handleParenthesis(char c);
  void finalizeNumber();

  bool frontOperatorHasLowerPrecedence(char c);
  bool frontOperatorIsNotLeftParenthesis();
  void popOperator();

  void handleMismatchedParentheses();
  void fail();

  std::stack<char> operatorStack;
  std::string inputStr;
  std::queue<std::string> outputQueue;
  std::string numberStr;
  char lastSymbol;
};

#endif // SHUNTING_YARD_H
