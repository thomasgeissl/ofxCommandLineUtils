#pragma once
#include "./rang/include/rang.hpp"
#include "./cxxopts.hpp"
#include "./spdlog/include/spdlong/spdlong.h"

bool getBoolAnswer(std::string question, bool defaultAnswer = true)
{
    std::cin.clear();
    std::string defaultAnswerAsString = defaultAnswer ? "y" : "n";
    std::cout << rang::style::bold << question<< rang::style::reset;
    std::cout << " [y|n] ("<< rang::style::bold << rang::fg::green << defaultAnswerAsString << rang::style::reset << rang::fg::reset << ") ";
    std::string answer;
    getline(cin, answer);
    if(answer == "y")
    {
        return true;
    }
    else if(answer == "n")
    {
        return false;
    }
    else if(answer.empty())
    {
        return defaultAnswer;
    }
    else
    {
        ofLogError("")<<"invalid answer!";
        return getBoolAnswer(question);
    }
}

std::string getStringAnswer(std::string question, std::string defaultAnswer = "")
{
    std::cin.clear();
    std::string answer;
    std::cout << rang::style::bold << question<< rang::style::reset;
    std::cout << " ("<< rang::style::bold << rang::fg::green << defaultAnswer << rang::style::reset << rang::fg::reset << ") ";
    getline(cin, answer);
    if(answer.empty())
    {
        return defaultAnswer;
    }
    return answer;
}

std::string getOptionAnswer(std::string question, std::vector<std::string> options)
{
    std::cin.clear();
    std::string answer;
    std::cout << rang::style::bold << question<< rang::style::reset << endl;
    for(int i = 0; i < options.size(); i++)
    {
        std::cout<<"("<<i<<") "<<options[i]<<std::endl;
    }
    std::cout<<std::endl;
    getline(cin, answer);
    int optionIndex = ofToInt(answer);
    if(optionIndex < options.size())
    {
        return options[optionIndex];
    }
    else
    {
        ofLogError("")<<"invalid index";
        return getOptionAnswer(question, options);
    }
}

int getIntAnswer(std::string question, int defaultAnswer = 0){
    std::cin.clear();
    std::string answer;

    std::cout << rang::style::bold << question<< rang::style::reset;
    std::cout << " ("<< rang::style::bold << rang::fg::green << defaultAnswer << rang::style::reset << rang::fg::reset << ") ";

    getline(cin, answer);
    if(answer.empty())
    {
        return defaultAnswer;
    }
    return ofToInt(answer);
}
