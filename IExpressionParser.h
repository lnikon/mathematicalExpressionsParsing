#pragma once
#include <string>
class IExpressionParser
{
public:
    virtual int parse(const std::string& expression) = 0;
};