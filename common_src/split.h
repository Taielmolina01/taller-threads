#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

class Splitter {
public:
    Splitter();
    std::vector<std::string> Split(const std::string& token, char delimiter) const;
};


#endif
