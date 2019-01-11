#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
  reset();
}

ShuntingYard::reset()
{
  lastSymbol = '\0';
  numberStr = "";
}

ShuntingYard::parseInfix(std::str infixStr)
{
  // Read symbols
  for(int i=0; i<infixStr.length(); i++)
  {
    parseSymbol(infixStr[i]);
  }

  // Pop remaining operators
  while(operatorQueue.size() > 0)
  {
    // TODO: Handle mismatched parens
    popOperator();
  }
}

ShuntingYard::parseSymbol(char c)
{
  switch c
  {
    // Numbers
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      numberStr.append(c);
      break;

    // Infix operators
    case '+':
    case '*':
    case '/':
      handleInfixOperator(c)
      break;

    // Parentheses
    case '(':
    case ')':
      handleParenthesis(c)
      break;

    // Infix OR unary minus
    case '-':
      if(isUnaryMinus(c))
        handleUnaryMinus();
      else:
        numberStr.append(c)
      break;
  }

  lastSymbol = c;
}

ShuntingYard::isUnaryMinus()
{
  // Only consider a minus sign to be a unary minus
  // if it is the first symbol or is preceeded by a left parenthesis.
  switch lastSymbol
  {
    case '\0':
    case '(':
      return true;
      break;
  }

  return false;
}

ShuntingYard::handleInfixOperator(char c)
{
  finalizeNumber();

  while(
        !frontOperatorHasLowerPrecedence(c)
        && frontOperatorIsNotLeftParenthesis()
    )
    popOperator();

  operatorQueue.push(c);
}

ShuntingYard::getOperatorPrecedence(char c)
{
  // Higher precedence operators are evaluated first
  switch c
  {
    case '*':
    case '/':
      return 1;
      break;

    case '+':
    case '-':
      return 0;
      break;
  }
}

ShuntingYard::frontOperatorHasLowerPrecedence(char c)
{
  return getOperatorPrecedence(operatorQueue.front()) < getOperatorPrecedence(c);
}

ShuntingYard::frontOperatorIsNotLeftParenthesis()
{
  return operatorQueue.front() != '(';
}

ShuntingYard::popOperator()
{
  outputQueue.push(operatorQueue.pop())
}

ShuntingYard::handleParenthesis(char c)
{
  finalizeNumber();

  switch c
  {
    case '(':
      operatorQueue.push(c);
      break;
    case ')':
      // TODO: Handle mismsatched parens
      while(frontOperatorIsNotLeftParenthesis())
        popOperator();
      // Pop the left parenthesis
      popOperator();

  }
}

ShungingYard::finalizeNumber()
{
  // Finish handling number if we were previously doing so
  if(numberStr.length > 0) {
    outputQueue.push();
    numberStr = "";
  }
}

ShuntingYard::handleMismatchedParentheses()
{
  fail();
}
