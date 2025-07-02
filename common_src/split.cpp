#include "split.h"

#include <sstream>
#include <string>
#include <vector>

Splitter::Splitter() {}

std::vector<std::string> Splitter::Split(const std::string& token, char delimiter) const {
    std::vector<std::string> result;
    std::istringstream stream(token);
    std::stringstream ss;
    char c;

    while (stream.get(c)) {
        if (c == delimiter) {
            result.push_back(ss.str());
            ss.str("");
        } else {
            ss << c;
        }
    }

    std::string s = ss.str();
    if (s != "") {
        result.push_back(s);
    }

    return result;
}
