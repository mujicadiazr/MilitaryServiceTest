#ifndef CPATTERNRECONGNITION_H
#define CPATTERNRECONGNITION_H

#include "common/enums.h"
#include "cknowledgedb.h"

/**
 * Clase controladora
 * Su responsabilidad es clasificar a los nuevos objetos llamando a su metodo "recognize",
 * la implementamos con un patron singlenton pues necesitaremos una unica instancia de la misma
 */

class CPatternRecongnition
{
    static CPatternRecongnition* m_instance;
    CKnowledgeDB *               m_db;


    CPatternRecongnition();
public:

    static CPatternRecongnition* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new CPatternRecongnition();
        }
        return m_instance;
    }

    CKnowledgeDB * getDB();

    EClass recognize(CObject * obj); //Metodo para reconocer un nuevo objeto

};

#endif // CPATTERNRECONGNITION_H
