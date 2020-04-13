#pragma once
#include "ofUtils.h"
#include "./rang.hpp"
#include "./cxxopts.hpp"

class ofxCommandLineUtils
{
public:
    static bool getBoolAnswer(std::string question, bool defaultAnswer = true)
    {
        std::cin.clear();
        std::string defaultAnswerAsString = defaultAnswer ? "y" : "n";
        std::cout << rang::style::bold << question << rang::style::reset;
        std::cout << " [y|n] (" << rang::style::bold << rang::fg::green << defaultAnswerAsString << rang::style::reset << rang::fg::reset << ") ";
        std::string answer;
        getline(std::cin, answer);
        if (answer == "y")
        {
            return true;
        }
        else if (answer == "n")
        {
            return false;
        }
        else if (answer.empty())
        {
            return defaultAnswer;
        }
        else
        {
            ofLogError("") << "invalid answer!";
            return getBoolAnswer(question);
        }
    }

    static std::string getStringAnswer(std::string question, std::string defaultAnswer = "")
    {
        std::cin.clear();
        std::string answer;
        std::cout << rang::style::bold << question << rang::style::reset;
        std::cout << " (" << rang::style::bold << rang::fg::green << defaultAnswer << rang::style::reset << rang::fg::reset << ") ";
        getline(std::cin, answer);
        if (answer.empty())
        {
            return defaultAnswer;
        }
        return answer;
    }

    static std::string getOptionAnswer(std::string question, std::vector<std::string> options)
    {
        std::cin.clear();
        std::string answer;
        std::cout << rang::style::bold << question << rang::style::reset << std::endl;
        for (int i = 0; i < options.size(); i++)
        {
            std::cout << "(" << i << ") " << options[i] << std::endl;
        }
        std::cout << std::endl;
        getline(std::cin, answer);
        int optionIndex = ofToInt(answer);
        if (optionIndex < options.size())
        {
            return options[optionIndex];
        }
        else
        {
            ofLogError("") << "invalid index";
            return getOptionAnswer(question, options);
        }
    }
    static int getIntAnswer(std::string question, int defaultAnswer = 0)
    {
        std::cin.clear();
        std::string answer;

        std::cout << rang::style::bold << question << rang::style::reset;
        std::cout << " (" << rang::style::bold << rang::fg::green << defaultAnswer << rang::style::reset << rang::fg::reset << ") ";

        getline(std::cin, answer);
        if (answer.empty())
        {
            return defaultAnswer;
        }
        return ofToInt(answer);
    }
    static int getFloatAnswer(std::string question, float defaultAnswer = 0)
    {
        std::cin.clear();
        std::string answer;

        std::cout << rang::style::bold << question << rang::style::reset;
        std::cout << " (" << rang::style::bold << rang::fg::green << defaultAnswer << rang::style::reset << rang::fg::reset << ") ";

        getline(std::cin, answer);
        if (answer.empty())
        {
            return defaultAnswer;
        }
        return ofToFloat(answer);
    }
    static void printNewLines(int count = 1)
    {
        for (auto i = 0; i < count; i++)
        {
            std::cout << std::endl;
        }
    }

    static int print(std::string text)
    {
        std::cout << text << std::flush;
        return text.size();
    }
    static void del(int size)
    {
        std::cout << std::string(size, '\b');
    }
};