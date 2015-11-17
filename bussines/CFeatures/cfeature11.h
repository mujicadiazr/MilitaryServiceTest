#ifndef CFEATURE11_H
#define CFEATURE11_H

#include "../cfeature.h"

class CFeature11 : public CFeature
{
public:
    CFeature11();

    int getCardiopatia();

    int compare(IComparable *obj);
};

#endif // CFEATURE11_H
