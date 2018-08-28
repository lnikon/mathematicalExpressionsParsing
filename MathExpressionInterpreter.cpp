#include "stdafx.h"
#include <iostream>
#include <string>

#include "MathExpressionInterpreter.h"

void MathExpressionInterpreter::runInterpreter()
{
    std::string expression;
    std::cout << "> ";
    std::cin >> expression;
    //std::getline(std::cin, expression);

    auto result = m_parser->parse(expression);

    pushToHistory(std::make_pair(result, expression));

    std::cout << expression << " = " << result << "\n\n";
}

void MathExpressionInterpreter::setParser(IExpressionParser * parser)
{
    m_parser.reset(parser);
}

std::deque<int> MathExpressionInterpreter::getResults()
{
    std::deque<int> results;
    auto copyOfHistory = getHistory();

    while (!copyOfHistory.empty())
    {
        auto result = copyOfHistory.top().first;
        copyOfHistory.pop();

        results.push_back(result);
    }

    return results;
}

void MathExpressionInterpreter::printHistory()
{
    auto copyOfHistory = getHistory();

    int numberOfItemInHistory = copyOfHistory.size();
    while (!copyOfHistory.empty())
    {
        std::cout << "[" << numberOfItemInHistory-- << "]" << copyOfHistory.top().first << '\n';
        copyOfHistory.pop();
    }
}

std::stack<std::pair<int, std::string>> MathExpressionInterpreter::getHistory() const
{
    return m_history;
}

void MathExpressionInterpreter::pushToHistory(const std::pair<int, std::string>& resultExpr)
{
    m_history.push(resultExpr);
}

