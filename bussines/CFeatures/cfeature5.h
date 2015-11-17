#ifndef CFEATURE5_H
#define CFEATURE5_H

#include "../cfeature.h"

class CFeature5 : public CFeature
{
    int m_problemaTesticulos;

public:
    CFeature5();

    int getProblemaTesticulos();

    int compare(IComparable *obj);
};

#endif // CFEATURE5_H
