#ifndef COW_H
#define COW_H

#include "ASCIIPicture.hpp"

class Cow final : public ASCIIPicture {

    string tongue;

public:

    Cow(const string& tongue, const string& fname);
    ~Cow();

    void print(unsigned int left, char fill, unsigned int width) override;

};

#endif