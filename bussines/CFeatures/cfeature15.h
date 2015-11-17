#ifndef CFEATURE15_H
#define CFEATURE15_H

#include "../cfeature.h"

class CFeature15 : public CFeature
{
public:
    CFeature15();

    int getCancer();

    int compare(IComparable *obj);
};

#endif // CFEATURE15_H
