#ifndef COBJECT_H
#define COBJECT_H
#include <QVector>
#include "cfeature.h"
#include "common/enums.h"


/**
 * Clase Objeto
 * Su responsabilidad es representar a un objeto o sea un recluta, su responsabilidad principal
 * esta dada por la implementacion del metodo "compare" que este representaria la funcion de comparacion
 */

class CObject : public IComparable
{
    QVector<CFeature*> m_features; //Vector con los rasgos
    EClass             m_class;    //Clase del objeto {null, apto o noApto}

public:
    CObject();

    CFeature* getFeature(int index);
    bool addFeature(CFeature * feature);

    void setClass(EClass p_class);

    int compare(IComparable *obj);

    EClass getClass();
};

#endif // COBJECT_H
