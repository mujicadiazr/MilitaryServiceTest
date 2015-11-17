#include "cfeature8.h"

CFeature8::CFeature8()
{
    m_description = "Problema del habla";
}

int CFeature8::getProblemaDelHabla()
{
    return this->m_value.toInt();
}

int CFeature8::compare(IComparable *obj)
{
    if (CFeature8 *temp = dynamic_cast<CFeature8*>(obj)) {  //Si obj es un CFeature8 lo meto en temp
        if (temp->getProblemaDelHabla() == this->getProblemaDelHabla())      //y si su valor de la problema del habla es igual al mio
            return 1;
    }
    return 0;
}
