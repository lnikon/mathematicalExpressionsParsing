#pragma once
#include <stack>
#include <string>

#include "IExpressionParser.h"

class MathExpressionParser final : public IExpressionParser
{
public:
    MathExpressionParser() = default;
    ~MathExpressionParser() = default;

    int parse(const std::string& expression = std::string("")) override;
    
    void setExpression(const std::string& exp);
    std::string getExpression() const;

private:
    std::stack<int> m_values;
    std::stack<char> m_ops;
    std::string m_expression;

    bool isDigit(const std::string& string);
    std::size_t extractNumberFromExpr(const std::string& expr, std::size_t index);
};

