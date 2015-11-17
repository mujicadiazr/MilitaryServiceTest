#ifndef CFEATURE9_H
#define CFEATURE9_H

#include "../cfeature.h"

class CFeature9 : public CFeature
{
    int m_faltaDeExtremidades;

public:
    CFeature9();

    int getFaltaDeExtremidades();

    int compare(IComparable *obj);
};

#endif // CFEATURE9_H
