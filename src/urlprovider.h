#ifndef URLPROVIDER_H
#define URLPROVIDER_H

#include <qjson/parser.h>

class urlprovider
{
public:
    urlprovider();

    QJson::Parser parser;
};

#endif // URLPROVIDER_H
