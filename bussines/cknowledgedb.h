#ifndef CKNOWLEDGEDB_H
#define CKNOWLEDGEDB_H

#include <QtSql/QtSql>
#include <QVector>
#include "cobject.h"
#include "./common/cfactoryfeature.h"

/**
 * Clase manejadora de DB
 * Su responsabilidad es almacenar en una base de datos SQLite los objetos que van siendo clasificados,
 * constituyendo esta nuestra base de conocimiento, de manera que aunque la aplicacion se cierre se
 * mantiene el conocimiento adquirido guardado en disco
 */

class CKnowledgeDB
{
private:
    QSqlDatabase m_dataBase;
    QString      m_dataBaseName;
    bool         m_testorCreated;

    bool         setAsTestor(int featureId, int value);         //Activa a un rasgo como testor en la base de datos
    bool         createTestors();                               //Crea los testores

    //Devuelven los valores de la BD de los rasgos
    QString      getDescription(int featureId);
    int          getTestor(int featureId);

public:
    CKnowledgeDB(QString dataBaseName = "data.db");
    ~CKnowledgeDB();

    bool connect();
    bool disconnect();
    bool isConnected();
    bool isTestorsCreated();


    bool                setNewObject(CObject * obj); //Almacena un nuevo objeto clasificado en la base de conocimiento
    QVector<CObject *>  getAllObject();              //Devuelve un vector con los objetos de la base de conocimiento
    QVector<int>        getTestors();                //Devuelve un vector los numeros de los rasgos que son testores

};

#endif // CKNOWLEDGEDB_H
