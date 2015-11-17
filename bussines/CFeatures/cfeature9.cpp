#include "cfeature9.h"

CFeature9::CFeature9()
{
    m_description = "Falta de extremidades";
}

int CFeature9::getFaltaDeExtremidades()
{
    return this->m_value.toInt();
}

int CFeature9::compare(IComparable *obj)
{
    if (CFeature9 *temp = dynamic_cast<CFeature9*>(obj)) {                //Si obj es un CFeature9 lo meto en temp
        if (temp->getFaltaDeExtremidades() == this->getFaltaDeExtremidades())      //y si su valor de la problema del habla es igual al mio
            return 1;
    }
    return 0;
}
