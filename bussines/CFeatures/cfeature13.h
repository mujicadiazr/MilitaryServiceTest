#ifndef CFEATURE13_H
#define CFEATURE13_H

#include "../cfeature.h"

class CFeature13 : public CFeature
{
public:
    CFeature13();

    int getHemorroides();

    int compare(IComparable *obj);
};

#endif // CFEATURE13_H
