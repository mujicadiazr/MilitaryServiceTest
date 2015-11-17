#include "cfeature7.h"

CFeature7::CFeature7()
{
}

int CFeature7::getProblemaOido()
{
    return this->m_value.toInt();
}

int CFeature7::compare(IComparable *obj)
{
    if (CFeature7 *temp = dynamic_cast<CFeature7*>(obj)) {  //Si obj es un CFeature7 lo meto en temp
        if (temp->getProblemaOido() == this->getProblemaOido() )      //y si su valor de la problema del oido es igual al mio
            return 1;
    }
    return 0;
}
