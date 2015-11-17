#include "cpatternrecongnition.h"

CPatternRecongnition* CPatternRecongnition::m_instance = nullptr;

CPatternRecongnition::CPatternRecongnition()
{
    m_db = new CKnowledgeDB();
}

CKnowledgeDB *CPatternRecongnition::getDB()
{
    return m_db;
}

EClass CPatternRecongnition::recognize(CObject *obj)
{
    double promedioApto = 0, promedioNoApto = 0;
    int cantApto = 0, cantNoApto = 0;
    EClass ret;
    QVector<CObject*> objs = m_db->getAllObject();

    foreach (CObject* elem, objs) {
        if (elem->getClass() == EClass::apto) {
            promedioApto += obj->compare(elem);
            ++cantApto;
        } else if(elem->getClass() == EClass::noApto) {
            promedioNoApto += obj->compare(elem);
            ++cantNoApto;
        }
    }

    promedioApto /= cantApto;
    promedioNoApto /= cantNoApto;

    if (promedioApto > promedioNoApto) {  //Compruebo cual promedio de comparaciones es mayor para poder clasificar
        obj->setClass(EClass::apto);
        ret = EClass::apto;
    }
    else {
        obj->setClass(EClass::noApto);
        ret = EClass::noApto;
    }

    m_db->setNewObject(obj);            //Almaceno el objecto ya clasificado en la BD

    return ret;
}
