#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
  reset();
}

void ShuntingYard::reset()
{
  lastSymbol = '\0';
  numberStr = "";
  errorCode = 0;

  // Empty stacks
  while(operatorStack.size() > 0)
      operatorStack.pop();
  while(outputQueue.size() > 0)
      outputQueue.pop();
}

void ShuntingYard::parseInfix(std::string infixStr)
{
  char c;
  // Read symbols
  for(unsigned i=0; i<infixStr.length(); i++)
  {
    c = infixStr[i];
    if (c != ' ')
      parseSymbol(infixStr[i]);
  }

  // Finish parsing last number if applicable
  finalizeNumber();

  // Pop remaining operators
  while(operatorStack.size() > 0)
  {
    if(frontOperatorIsNotParenthesis())
        popOperator();
    else
    {
        handleSyntaxError();
        return;
    }
  }
}

void ShuntingYard::printRPN()
{
  std::queue<std::string> copyQueue(outputQueue);
  while(copyQueue.size() > 0) {
    copyQueue.pop();
  }
}

double ShuntingYard::evaluateRPN()
{
  double result = 0;
  double operand1 = 0;
  double operand2 = 0;
  std::stack<double> operandStack;
  std::string oper;
  while(outputQueue.size() > 0)
  {

    // Handle operand
    if(isNumberQueue.front())
    {
      operandStack.push(getNumberFromOutputQueue());
      outputQueue.pop();
      isNumberQueue.pop();
    }

    // Handle operator
    else
    {
        // Get operator
        oper = outputQueue.front();
        outputQueue.pop();
        isNumberQueue.pop();

        if(operandStack.size() > 1)
        {
            operand2 = operandStack.top();
            operandStack.pop();
            operand1 = operandStack.top();
            operandStack.pop();
            result = applyOperator(oper, operand1, operand2);
            operandStack.push(result);
        }
        else
        {
            handleSyntaxError();
        }
    }
  }
  if(operandStack.size() > 0)
  {
      result = operandStack.top();
      operandStack.pop();
  }
  else
  {
      handleSyntaxError();
  }

  return result;
}

void ShuntingYard::parseSymbol(char c)
{
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
    case '^':
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
  finalizeNumber();

  while(
        (frontOperatorHasHigherPrecedence(c)
        || (frontOperatorHasEqualPrecedence(c) && frontOperatorIsLeftAssociative())
        ) && frontOperatorIsNotLeftParenthesis()
    )
    popOperator();

  operatorStack.push(c);
}

int ShuntingYard::getOperatorPrecedence(char c)
{
  // Higher precedence operators are evaluated first
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

int ShuntingYard::getOperatorAssociativity(char c)
{
  // 0 = left-associative
  // 1 = right-associative
  switch(c)
  {
    case '^':
      return 1;

    case '*':
    case '/':
    case '+':
    case '-':
      return 0;

    default:
      return 0;
  }
}

bool ShuntingYard::frontOperatorHasEqualPrecedence(char c)
{
  if(operatorStack.size() > 0)
    return getOperatorPrecedence(operatorStack.top()) == getOperatorPrecedence(c);

  else
    return false;
}

bool ShuntingYard::frontOperatorHasLowerPrecedence(char c)
{
  if(operatorStack.size() > 0)
    return getOperatorPrecedence(operatorStack.top()) < getOperatorPrecedence(c);

  else
    return false;
}

bool ShuntingYard::frontOperatorHasHigherPrecedence(char c)
{
  if(operatorStack.size() > 0)
    return getOperatorPrecedence(operatorStack.top()) > getOperatorPrecedence(c);

  else
    return false;
}

bool ShuntingYard::frontOperatorIsLeftAssociative()
{
  std::cout << "frontOperatorIsLeftAssociative" << std::endl;
  if(operatorStack.size() > 0)
    return getOperatorAssociativity(operatorStack.top()) == 0;
  else
    return false;
}


bool ShuntingYard::frontOperatorIsLeftParenthesis()
{
  std::cout << "frontOperatorIsLeftParenthesis" << std::endl;
  if(operatorStack.size() > 0)
    return operatorStack.top() == '(';
  else
    return false;
}

bool ShuntingYard::frontOperatorIsNotLeftParenthesis()
{
  if(operatorStack.size() > 0)
    return operatorStack.top() != '(';
  else
    return false;
}

bool ShuntingYard::frontOperatorIsNotRightParenthesis()
{
  if(operatorStack.size() > 0)
    return operatorStack.top() != ')';
  else
    return false;
}

bool ShuntingYard::frontOperatorIsNotParenthesis()
{
    return frontOperatorIsNotLeftParenthesis()
            && frontOperatorIsNotRightParenthesis();
}

void ShuntingYard::popOperator()
{
  std::stringstream ss;
  std::string s(1, operatorStack.top());
  outputQueue.push(s);
  // This is not a numbe
  isNumberQueue.push(false);
  operatorStack.pop();
}

double ShuntingYard::applyOperator(std::string oper, double operand1, double operand2)
{
    if(oper == "+")
        return operand1 + operand2;
    if(oper == "-")
        return operand1 - operand2;
    if(oper == "*")
        return operand1 * operand2;
    if(oper == "/")
    {
        // Avoid division by zero
        if (std::abs(operand2) > 1e-10)
            return operand1 / operand2;
        else
        {
            fail(1);
            return 0;
        }
    }
    if(oper == "^")
    {
        // Avoid raising 0 to non-positive power
        if((std::abs(operand1)<1e-10)&&operand2<1e-10)
        {
            fail(1);
            return 0;
        }
        else
        {
            return pow(operand1, operand2);
        }
    }
    else
        return 0;

}

void ShuntingYard::handleParenthesis(char c)
{
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
      if(frontOperatorIsLeftParenthesis())
        operatorStack.pop();
      else
      {
        handleSyntaxError();
        return;
      }
  }
}

double ShuntingYard::getNumberFromOutputQueue()
{
    std::string s = outputQueue.front();

    // Make sure we don't try to convert a single minus sign
    if(s.data()[0] == '-' && s.length() == 1)
    {
        handleSyntaxError();
        return 0;
    }
    else
        return std::stod(s);
}

void ShuntingYard::finalizeNumber()
{
  // Finish handling number if we were previously doing so
  if(numberStr.length() > 0) {
    outputQueue.push(numberStr);
    // This is a number
    isNumberQueue.push(true);
    numberStr = "";
  }
}

void ShuntingYard::handleSyntaxError()
{
  fail(2);
}

void ShuntingYard::handleDivideByZero()
{
  fail(1);
}

void ShuntingYard::fail(int err)
{
    std::cout << "FAIL " << err << std::endl;
    errorCode = err;
}

bool ShuntingYard::checkError()
{
    if(errorCode != 0)
        return true;
    else
        return false;
}

std::string ShuntingYard::getErrorString()
{
    switch(errorCode)
    {
        case(1): return "Divide by zero";
        case(2): return "Syntax Error";
        default: return "";
    }
}
