#ifndef CFEATURE8_H
#define CFEATURE8_H

#include "../cfeature.h"

class CFeature8 : public CFeature
{
    int m_problemasDelHabla;

public:
    CFeature8();

    int getProblemaDelHabla();

    int compare(IComparable *obj);
};

#endif // CFEATURE8_H
