#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
  reset();
}

void ShuntingYard::reset()
{
  lastSymbol = '\0';
  numberStr = "";

  // Empty stacks
  while(operatorStack.size() > 0)
      operatorStack.pop();
  while(outputQueue.size() > 0)
      outputQueue.pop();
}

void ShuntingYard::parseInfix(std::string infixStr)
{
  // Read symbols
  std::cout << "PI.readSymbols" << std::endl;
  for(unsigned i=0; i<infixStr.length(); i++)
  {
    parseSymbol(infixStr[i]);
  }

  // Finish parsing last number if applicable
  finalizeNumber();

  // Pop remaining operators
  std::cout << "PI.pop" << std::endl;
  while(operatorStack.size() > 0)
  {
    // TODO: Handle mismatched parens
    popOperator();
  }

  std::cout << "PI.done" << std::endl;
}

void ShuntingYard::printRPN()
{
    std::queue<std::string> copyQueue(outputQueue);
    std::cout << "RPN: ";
    while(copyQueue.size() > 0) {
        std::cout << "'" << copyQueue.front() << "' ";
        copyQueue.pop();
    }
    std::cout << std::endl;
}

void ShuntingYard::parseSymbol(char c)
{
  std::cout << "parse '" << c << "'" << std::endl;
  switch(c)
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
      numberStr.append(1, c);
      break;

    // Infix operators
    case '+':
    case '*':
    case '/':
      handleInfixOperator(c);
      break;

    // Parentheses
    case '(':
    case ')':
      handleParenthesis(c);
      break;

    // Infix OR unary minus
    case '-':
      if(isUnaryMinus())
        numberStr.append(1, c);
      else
        handleInfixOperator(c);
      break;
  }

  lastSymbol = c;
}

bool ShuntingYard::isUnaryMinus()
{
  // Only consider a minus sign to be a unary minus
  // if it is the first symbol or is preceeded by a left parenthesis.
  switch(lastSymbol)
  {
    case '\0':
    case '(':
      return true;
  }

  return false;
}

void ShuntingYard::handleInfixOperator(char c)
{
  std::cout << "handleInfix: '" << c << "'" << std::endl;
  finalizeNumber();

  while(
        !frontOperatorHasLowerPrecedence(c)
        && frontOperatorIsNotLeftParenthesis()
    )
    popOperator();

  operatorStack.push(c);
}

int ShuntingYard::getOperatorPrecedence(char c)
{
  // Higher precedence operators are evaluated first
  std::cout << "getOperatorPrecedence '" << c << "'" << std::endl;
  switch(c)
  {
    case '^':
      return 2;

    case '*':
    case '/':
      return 1;

    case '+':
    case '-':
      return 0;

    default:
      return 0;
  }
}

bool ShuntingYard::frontOperatorHasLowerPrecedence(char c)
{
  std::cout << "frontOperatorHasLowerPrecedence '" << c << "'" << std::endl;
  if(operatorStack.size() > 0)
    return getOperatorPrecedence(operatorStack.top()) < getOperatorPrecedence(c);

  else
    return false;

}

bool ShuntingYard::frontOperatorIsNotLeftParenthesis()
{
  std::cout << "frontOperatorIsNotLeftParenthesis" << std::endl;
  if(operatorStack.size() > 0)
    return operatorStack.top() != '(';
  else
    return false;
}

void ShuntingYard::popOperator()
{
  std::cout << "popOperator (" << operatorStack.size() << ")" << std::endl;
  std::cout << "pop '" << operatorStack.top() << "'" << std::endl;
  std::stringstream ss;
  std::string s(1, operatorStack.top());
  outputQueue.push(s);
  operatorStack.pop();
}

void ShuntingYard::handleParenthesis(char c)
{
  std::cout << "handleParenthesis '" << c << "'" << std::endl;
  finalizeNumber();

  switch(c)
  {
    case '(':
      operatorStack.push(c);
      break;
    case ')':
      while(frontOperatorIsNotLeftParenthesis())
        popOperator();
      // Pop (without pushing) the left parenthesis
      if(operatorStack.top() == '(')
        operatorStack.pop();
      else
        handleMismatchedParentheses();
  }
}

void ShuntingYard::finalizeNumber()
{
  std::cout << "finalizeNumber '" << numberStr << "'" << std::endl;
  // Finish handling number if we were previously doing so
  if(numberStr.length() > 0) {
    outputQueue.push(numberStr);
    numberStr = "";
  }
}

void ShuntingYard::handleMismatchedParentheses()
{
  fail();
}

void ShuntingYard::fail()
{
    std::cout << "FAIL" << std::endl;
}
