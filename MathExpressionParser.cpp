#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <exception>

#include "MathExpressionParser.h"

int MathExpressionParser::parse(const std::string& expression)
{
    setExpression(expression);

    if (m_expression.empty()) {
        std::cout << "empty expression to parse is specified\n";
        return 0;
    }

    const auto expSize = m_expression.size();
    int lhs = 0;
    int rhs = 0;
    int result = 0;
    char op;

    // kastil
    std::size_t closeParenCount = 0;
    std::size_t operationCount = 0;
    for (std::string::size_type i = 0; i < expSize; i++)
    {
        switch (m_expression[i])
        {
        case ')':
            ++closeParenCount;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        default:
            ++operationCount;
            break;
        }
    }

    if (closeParenCount != operationCount)
    {
        std::cout << "Invalid brackets\n";
        return 0;
    }
    // kastil


    for (std::string::size_type i = 0; i < expSize; i++)
    {
        switch (m_expression[i])
        {
        case ' ':
        case '(':
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            m_ops.push(m_expression[i]);
            break;
        case ')':
            op = m_ops.top();
            m_ops.pop();

            rhs = m_values.top();
            m_values.pop();

            lhs = m_values.top();
            m_values.pop();

            result = 0;
            switch (op)
            {
            case '+':
                result = lhs + rhs;
                break;
            case '-':
                result = lhs - rhs;
                break;
            case '*':
                result = lhs * rhs;
                break;
            case '/':
                try
                {
                    if (rhs == 0)
                    {
                        throw std::domain_error("division by zero\n");
                    }
                    result = lhs / rhs;
                }
                catch (const std::domain_error& e)
                {
                    std::cout << e.what() << '\n';
                }
                break;
            default:
                break;
            }

            m_values.push(result);
            break;
        default:
            int num = 0;

            std::size_t endIndex = extractNumberFromExpr(m_expression, i);
            std::string number = m_expression.substr(i, endIndex - i + 1);

            std::stringstream strStream(number);

            strStream >> num;
            m_values.push(num);

            /*i += endIndex - i;*/
            break;
        }
    }
    return m_values.top();
}

void MathExpressionParser::setExpression(const std::string & exp)
{
    m_expression = exp;
}

std::string MathExpressionParser::getExpression() const
{
    return m_expression;
}

bool MathExpressionParser::isDigit(const std::string & string)
{
    return false;
}

std::size_t MathExpressionParser::extractNumberFromExpr(const std::string & expr, std::size_t index)
{
    std::size_t endIndex = index;
    while (std::isdigit(expr[++index]))
    {
        endIndex = index;
    }

    return endIndex;
}
