#pragma once
#include <stack>
#include <utility>
#include <memory>

#include "IExpressionParser.h"

class MathExpressionInterpreter
{
public:
    MathExpressionInterpreter() = default;
    ~MathExpressionInterpreter() = default;

    void runInterpreter();

    void setParser(IExpressionParser *parser);

    std::deque<int> getResults();
    
    void printHistory();
    std::stack<std::pair<int, std::string>> getHistory() const;

private:
    // Trying to implement Strategy design pattern
    std::unique_ptr<IExpressionParser> m_parser{nullptr};
    std::stack<std::pair<int, std::string>> m_history;

    void pushToHistory(const std::pair<int, std::string>& resultExpr);
};

