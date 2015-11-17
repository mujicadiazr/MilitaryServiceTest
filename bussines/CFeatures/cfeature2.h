#ifndef CFEATURE2_H
#define CFEATURE2_H

#include "../cfeature.h"

class CFeature2 : public CFeature
{
public:
    CFeature2();

    double getMedidaVista();

    int compare(IComparable *obj);
};

#endif // CFEATURE2_H
