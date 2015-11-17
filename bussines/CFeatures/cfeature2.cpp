#include "cfeature2.h"

CFeature2::CFeature2()
{
    m_description = "Medida de la vista";
}

double CFeature2::getMedidaVista()
{
    return this->m_value.toDouble();
}

int CFeature2::compare(IComparable *obj)
{
    if (CFeature2 *temp = dynamic_cast<CFeature2*>(obj)) {              //Si obj es un CFeature2 lo meto en temp
        if (abs(temp->getMedidaVista() - this->getMedidaVista()) <= 0.05)        //Si el error es < 0.05 Iguales
            return 1;
        if (abs(temp->getMedidaVista() - this->getMedidaVista()) > 0.05) //Si el error es mayor que 0.05 diferentes
            return 0;
    }
    return 0;
}
