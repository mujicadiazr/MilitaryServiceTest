#include "cfeature3.h"
#include "cmath"

CFeature3::CFeature3()
{
    m_description = "Analisis Psicologico";
}

int CFeature3::getAnalisisPsicologico()
{
    return this->m_value.toInt();
}

int CFeature3::compare(IComparable *obj)
{
    if (CFeature3 *temp = dynamic_cast<CFeature3*>(obj)) {                  //Si obj es un CFeature3 lo meto en temp
        if (temp->getAnalisisPsicologico() == this->getAnalisisPsicologico())          //Si son iguales retorno 1
            return 1;
        if (temp->getAnalisisPsicologico() != this->getAnalisisPsicologico()) //Si son diferentes retorno 0
            return 0;        
    }
}
