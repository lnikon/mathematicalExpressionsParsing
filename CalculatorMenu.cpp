#include "stdafx.h"
#include <iostream>
#include <string>

#include "CalculatorMenu.h"
#include "MathExpressionParser.h"

void CalculatorMenu::runMenu()
{
    printWelcome("0.1");
    while (true)
    {
        printOptionsMenu();
        auto option = chooseOption();
        runOption(option);
    }
}

typename CalculatorMenu::Option CalculatorMenu::chooseOption()
{
    std::cout << "Enter option: ";
    
    int option = 0;
    std::cin >> option;

    if (checkOption(option))
    {
        return getOptionNameByValue(option);
    }
    else
    {
        std::cout << "unsoported option specified\n";
        return Option::runNothing;
    }
}

bool CalculatorMenu::checkOption(int option)
{
    return ((option >= -1) && (option <= 3));
}

void CalculatorMenu::runOption(Option option)
{
    switch (option)
    {
    case Option::runInterpreter:
        runInterpreter();
        break;
    case Option::runHistory:
        runHistory();
        break;
    case Option::runHelp:
        runHelp();
        break;
    case Option::runNothing:
        runNothing();
        break;
    }
}

CalculatorMenu::CalculatorMenu()
{
    m_interpreter.setParser(new MathExpressionParser);
}

void CalculatorMenu::printWelcome(const std::string & version) const
{
    std::cout << "Wecome to CompilerMompiler version " << version << "\n";
}

void CalculatorMenu::printOptionsMenu() const
{
    std::cout << "0. Run Interpretator\n"
        << "1. Print History\n"
        << "2. See Help\n";
}

typename CalculatorMenu::Option CalculatorMenu::getOptionNameByValue(int option) const
{
    Option optionName;
    switch (option)
    {
    case 0:
        optionName = Option::runInterpreter;
        break;
    case 1:
        optionName = Option::runHistory;
        break;
    case 2:
        optionName = Option::runHelp;
        break;
    default:
        optionName = Option::runNothing;
        break;
    }

    return optionName;
}

void CalculatorMenu::runInterpreter()
{
    m_interpreter.runInterpreter();
}

void CalculatorMenu::runHistory()
{
    m_interpreter.printHistory();
}

void CalculatorMenu::runHelp()
{
    std::cout << "PLLLEEEASEEE HEELPPPPPP!\n";
}

void CalculatorMenu::runNothing()
{
    /**/
}

