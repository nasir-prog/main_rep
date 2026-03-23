#ifndef FIELD_H
#define FIELD_H

#include <string>
using std::string;

#include "Cow.hpp"
#include "Cloud.hpp"
class Parser;

class Field final {

    string message;
    Cow cow;
    Cloud cloud;
    string tongue;
    char fill;
    char sun; 

public:

    explicit Field(const Parser& parser);
    ~Field();

    void print() const;

};

#endif