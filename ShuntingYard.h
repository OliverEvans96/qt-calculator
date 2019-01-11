#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <iostream>
#include <queue>
#include <string>

namespace ShuntingYard {
  class ShuntingYard;
}

class ShuntingYard
{
public:
  void reset();
  void parseInfix(std::str infixStr);
  void evaluateRPN();

private:

  void parseSymbol();
  void isUnaryMinus();
  void handleInfixOperator(char c);
  void getOperatorPrecedence(char c);
  void handleParenthesis(char c);
  void finalizeNumber();

  void frontOperatorHasLowerPrecedence(char c);
  void frontOperatorIsNotLeftParenthesis();
  void popOperator();

  void handleMismatchedParentheses();
  void fail();

  std::queue operatorQueue;
  std::str inputStr;
  std::queue outputQueue;
  std::str numberStr;
  char lastSymbol;
};

#endif // SHUNTING_YARD_H
