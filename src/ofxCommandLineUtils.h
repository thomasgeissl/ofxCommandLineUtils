#pragma once

bool getBoolAnswer(string question, bool defaultAnswer = true)
{
    string defaultAnswerAsString = defaultAnswer ? "y" : "n";
    std::cout<<question<<" [y|n] ("<<defaultAnswerAsString<<") ";
    string answer;
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
string getStringAnswer(string question, string defaultAnswer = "")
{
    string answer;
    std::cout<<question<<" ("<<defaultAnswer<<") ";
    getline(cin, answer);
    if(answer.empty())
    {
        return defaultAnswer;
    }
    return answer;
}
string getOptionAnswer(string question, std::vector<string> options)
{
    string answer;
    std::cout<<question<<std::endl;
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
