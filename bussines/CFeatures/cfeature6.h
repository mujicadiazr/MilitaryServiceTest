#ifndef CFEATURE6_H
#define CFEATURE6_H

#include "../cfeature.h"

class CFeature6 : public CFeature
{
    int m_pruebaDental;

public:
    CFeature6();

    int getPruebaDental();

    int compare(IComparable *obj);
};

#endif // CFEATURE6_H
