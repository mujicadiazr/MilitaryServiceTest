#ifndef CFEATURE14_H
#define CFEATURE14_H

#include "../cfeature.h"

class CFeature14 : public CFeature
{
    int m_migrana;

public:
    CFeature14();

    int getMigrana();

    int compare(IComparable *obj);
};

#endif // CFEATURE14_H
