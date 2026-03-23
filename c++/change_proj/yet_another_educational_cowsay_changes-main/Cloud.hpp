#ifndef CLOUD_H
#define CLOUD_H

#include "ASCIIPicture.hpp"

class Cloud final : public ASCIIPicture {

    string message;

public:

    Cloud(const string& message, const string& fname);
    ~Cloud();

    void print(unsigned int left, char fill, unsigned int width) override;

};

#endif