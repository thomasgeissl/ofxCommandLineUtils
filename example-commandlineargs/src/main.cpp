#include "ofLog.h"
#include "ofxCommandLineUtils.h"

int main(int argc, char *argv[])
{
    cxxopts::Options options("example-commandlineargs", "example application to demonstrate how ot use cxxopts");
    options.add_options()("d,debug", "Enable debugging")  // a bool parameter
        ("p,port", "port", cxxopts::value<int>())         // int parameter, no default
        ("h,host", "host", cxxopts::value<std::string>()) // host parameter, no default
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
    auto result = options.parse(argc, argv);

    ofLogNotice("debug") << result["d"].as<bool>();
    ofLogNotice("verbose") << result["v"].as<bool>();
    if (result.count("port"))
    {
        ofLogNotice("port") << result["p"].as<int>();
    }
    if (result.count("host"))
    {
        ofLogNotice("host") << result["h"].as<std::string>();
    }

    return 0;
}