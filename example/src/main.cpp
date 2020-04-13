#include <chrono>
#include <thread>
#include "ofLog.h"
#include "ofMath.h"
#include "ofxCommandLineUtils.h"

int main(int argc, char *argv[])
{
    ofxCommandLineUtils clu;
    auto name = clu.getStringAnswer("Hello, what's your name?");
    ofLogNotice() << "Nice to meet you " << name << ".";
    if (clu.getBoolAnswer("How are you? Everything okay?"))
    {
        ofLogNotice() << "Glad to hear that.";
    }
    else
    {
        ofLogNotice() << "I am sorry to hear that. Let me know if I can do anything for you.";
    }
    auto noThanks = "no thanks";

    // all member functions are static and can be accessed like this
    auto drink = ofxCommandLineUtils::getOptionAnswer("Can I offer you anything to drink?", {noThanks, "water", "tea", "orange juice"});
    if (drink == noThanks)
    {
        ofLogNotice() << "Okey-dokey";
    }
    else
    {
        ofLogNotice() << "Okey-dokey, I will bring you " << drink << ".";
        auto age = clu.getIntAnswer(name + ", how old are you by the way");
        ofLogNotice() << "perfect, " << age << " is old enough to drink " << drink;
    }

    auto pi = clu.getFloatAnswer("And what is the exact value of pi?");
    ofLogNotice() << "Not too bad, you are only " << std::abs(glm::pi<float>() - pi) << " away.";

    clu.printNewLines(3);
    ofLogNotice() << "Good bye, talk you soon.";
    clu.printNewLines(2);

    // progress bar
    auto size = 0;
    for (auto i = 0; i <= 50; i++)
    {
        std::string text = "[" + ofToString(i * 2, 0, 2, '0') + "]" + std::string(i, '-');
        size = clu.print(text);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        clu.del(size);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    clu.printNewLines();
    return 0;
}