#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;

class Parser final {

    string cowsource, cloudsource, message, tongue;
    struct Flags {
        bool cowsource = false;
        bool cloudsource = false;
        bool eyes = false;
        bool tongue = false;
        bool snow = false;
        bool rain = false;
        bool background = false;
        bool ks = false;
        bool money = false;
    } flags;

public:

    Parser(int argc, char *argv[]);
    ~Parser();

    string getCow() const;
    string getCloud() const;
    char   getFill() const;
    char   getSun() const;
    string getMessage() const;
    string getTongue() const;
};

#endif