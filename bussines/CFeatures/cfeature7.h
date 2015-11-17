#ifndef CFEATURE7_H
#define CFEATURE7_H

#include "../cfeature.h"

class CFeature7 : public CFeature
{
    int m_problemaOido;

public:
    CFeature7();

    int getProblemaOido();

    int compare(IComparable *obj);
};

#endif // CFEATURE7_H
