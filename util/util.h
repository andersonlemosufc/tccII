#ifndef UTIL_H
#define UTIL_H

#include <math.h>

class Util
{
public:
    Util();
    static void setBit(unsigned char *ch, unsigned char mask);
    static bool getBit(unsigned char *ch, unsigned char mask);
};

#endif // UTIL_H
