#ifndef CFEATURE1_H
#define CFEATURE1_H

#include <QVariant>

#include "../cfeature.h"

/**
 * CFeature1 hereda de CFeature y es el primer rasgo que corresponde a si tiene pies planos o no,
 * cada uno de los rasgos se definen con un numero sucesivo despues de CFeature
 * y se implementa el metodo "compare", tambien se declaran los miembros que se
 * necesiten.
 */

class CFeature1 : public CFeature
{
public:
    CFeature1() ;

    int isPiesPlanos();

    int compare(IComparable *obj);
};

#endif // CFEATURE1_H
