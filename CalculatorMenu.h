#pragma once
#include <memory>

#include "MathExpressionInterpreter.h"

class CalculatorMenu
{
    enum class Option {
        runNothing = -1,
        runInterpreter = 0,
        runHistory = 1,
        runHelp = 2
    } m_currentOption;
public:
    void runMenu();
    Option chooseOption();
    bool checkOption(int option);
    void runOption(Option option);

    CalculatorMenu();
    ~CalculatorMenu() {}
    CalculatorMenu(const CalculatorMenu&) = delete;
    CalculatorMenu& operator=(const CalculatorMenu&) = delete;
    
private:
    MathExpressionInterpreter m_interpreter;


    void printWelcome(const std::string& version) const;
    void printOptionsMenu() const;

    Option getOptionNameByValue(int option) const;

    void runInterpreter();
    void runHistory();
    void runHelp();
    void runNothing();
};

