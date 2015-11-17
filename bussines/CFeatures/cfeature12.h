#ifndef CFEATURE12_H
#define CFEATURE12_H

#include "../cfeature.h"

class CFeature12 : public CFeature
{
public:
    CFeature12();

    int getProblemasDigestivos();

    int compare(IComparable *obj);
};

#endif // CFEATURE12_H
