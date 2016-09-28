#include "util.h"

Util::Util()
{

}

void Util::setBit(unsigned char *ch, unsigned char mask)
{
    *ch = mask | *ch;
}

bool Util::getBit(unsigned char *ch, unsigned char mask)
{
    return (*ch & mask);
}

