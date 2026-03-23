#ifndef ASCIIPICTURE_H
#define ASCIIPICTURE_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class ASCIIPicture {

protected:

    vector<string> picture;

public:

    ASCIIPicture(const string& fname);
    int getWidth() const;
    int getHeight() const;
    virtual void print(unsigned int left, char fill, unsigned int width) = 0;
    virtual ~ASCIIPicture() = default;

};

#endif