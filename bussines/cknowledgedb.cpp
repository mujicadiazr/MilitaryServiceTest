#include "cknowledgedb.h"
#include "../common/cfactoryfeature.h"
#include <QDebug>
#include <QJsonArray>
#include <memory.h>
#define MAX_F 15

CKnowledgeDB::CKnowledgeDB(QString dataBaseName)
{
    m_dataBase = QSqlDatabase::addDatabase(QString("QSQLITE"));
    m_dataBaseName = dataBaseName;
    m_dataBase.setDatabaseName(m_dataBaseName);

    connect();
    createTestors();
}

CKnowledgeDB::~CKnowledgeDB()
{
}

bool CKnowledgeDB::connect()
{
    if (!m_dataBase.open()) {
        qDebug() << QString("Failed to open database : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return false;
    }

    return true;
}

bool CKnowledgeDB::disconnect()
{
    m_dataBase.close();
    return true;
}

bool CKnowledgeDB::isConnected()
{
    return m_dataBase.isOpen();
}

bool CKnowledgeDB::setNewObject(CObject *obj)
{
    QSqlQuery query;

    query.prepare("INSERT INTO object(f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,k) "
                  "VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");

    query.addBindValue(dynamic_cast<CFeature1*>(obj->getFeature(0))->isPiesPlanos());


    query.addBindValue(dynamic_cast<CFeature2*>(obj->getFeature(1))->getMedidaVista());
    query.addBindValue(dynamic_cast<CFeature3*>(obj->getFeature(2))->getAnalisisPsicologico());
    query.addBindValue(dynamic_cast<CFeature4*>(obj->getFeature(3))->getProblemasPiel());
    query.addBindValue(dynamic_cast<CFeature5*>(obj->getFeature(4))->getProblemaTesticulos());
    query.addBindValue(dynamic_cast<CFeature6*>(obj->getFeature(5))->getPruebaDental());
    query.addBindValue(dynamic_cast<CFeature7*>(obj->getFeature(6))->getProblemaOido());
    query.addBindValue(dynamic_cast<CFeature8*>(obj->getFeature(7))->getProblemaDelHabla());
    query.addBindValue(dynamic_cast<CFeature9*>(obj->getFeature(8))->getFaltaDeExtremidades());
    query.addBindValue(dynamic_cast<CFeature10*>(obj->getFeature(9))->getAsmaticoCronico());
    query.addBindValue(dynamic_cast<CFeature11*>(obj->getFeature(10))->getCardiopatia());
    query.addBindValue(dynamic_cast<CFeature12*>(obj->getFeature(11))->getProblemasDigestivos());
    query.addBindValue(dynamic_cast<CFeature13*>(obj->getFeature(12))->getHemorroides());
    query.addBindValue(dynamic_cast<CFeature14*>(obj->getFeature(13))->getMigrana());
    query.addBindValue(dynamic_cast<CFeature15*>(obj->getFeature(14))->getCancer());

    query.addBindValue(obj->getClass());

    if (!query.exec()) {
        qDebug() << QString("Failed to save the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return false;
    }

    return true;
}

void printObject(CObject *obj) {
    for(int i=0;  i<15; ++i)
        qDebug() << QString("f%1 = %2, ").arg(i+1).arg(obj->getFeature(i)->getValue().toDouble());

}

QVector<CObject*> CKnowledgeDB::getAllObject()
{
    QVector<CObject *> objects;
    QSqlQuery query;
    QSqlRecord record;

    query.prepare("SELECT f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,k FROM object");

    if (!query.exec()) {
        qDebug() << QString("Failed to obtain the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return objects;
    }

    record = query.record();

    while (query.next()) {
        CObject *obj = new CObject();

        for (int i=1; i<=15; ++i) {
            QString featureName = QString("f%1").arg(i);

            QVariant value = query.value(record.indexOf(featureName));
            int testor = getTestor(i);

            obj->addFeature(CFactoryFeature::createFeature(i , value, testor));

        }
        obj->setClass((EClass)query.value(record.indexOf("k")).toInt());
        objects.append(obj);
    }

    return objects;
}

QVector<int> CKnowledgeDB::getTestors()
{
    QSqlQuery query;
    QSqlRecord record;
    QVector<int> testors;

    query.prepare("SELECT id FROM feature WHERE isTestor = 1;");

    if (!query.exec()) {
        qDebug() << QString("Failed to obtain the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return testors;
    }

    record = query.record();

    while (query.next()) {
        testors.append(query.value(record.indexOf("id")).toInt());
    }

    return testors;
}


bool CKnowledgeDB::setAsTestor(int featureId, int value)
{
    QSqlQuery query;

    query.prepare("update feature SET isTestor = ?  where id = ?;");
    query.addBindValue(value);
    query.addBindValue(featureId);

    if (!query.exec()) {
        qDebug() << QString("Failed to obtain the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return false;
    }

    return true;

}

bool CKnowledgeDB::createTestors()
{
    QVector <CObject*> objs = getAllObject();
    int cant = objs.size();
    int maxM = 100;
    /* **Md;  //Matriz de diferencia
    Md = new int * [maxM];
    for(int i=0; i<maxM; ++i){
        Md[i] = new int[maxM];
    }*/

    int Md[maxM][maxM];
    memset(Md,0,sizeof(Md));
    int rows = 0;  //Cantidad de filas de la matriz de diferencia
    for(int i=0; i<cant-1; ++i){  //Recorrer todos los objetos
        CObject *A = objs.at(i);
        for(int j=i+1; j<cant; ++j){
            CObject *B = objs.at(j);
            if(A->getClass() && B->getClass() && (A->getClass() != B->getClass())){ //Si son de clases distintas, comparo
                for(int k=0; k<MAX_F; ++k){
                    int comparacion = A->getFeature(k)->compare(B->getFeature(k));
                    Md[rows][k] = 1 - comparacion;  //Rellenando la matriz de diferencia
                }
                 ++rows;
            }
        }
    }
    //Sacar la matriz base
    int w = 99, e = 98;
    for(int i=0; i<rows-1; ++i){
        for(int j=i+1; j<rows; ++j){
            for(int k=0; k<MAX_F; ++k){
                if(Md[i][k] < Md[j][k]){
                    ++Md[i][w];
                }
                else if(Md[i][k] > Md[j][k]){
                    ++Md[j][w];
                }
            }
            if(Md[i][w] || Md[j][w]){   //En caso de que no sean iguales las filas
                if(Md[i][w] == 0) Md[i][e] = -1;   //M[i][j] es subfila si se cumple esta condicion
                if(Md[j][w] == 0) Md[j][e] = -1;
            } //Si no se cumple ninguna de las condiciones, las filas son linealmente independientes
            Md[i][w] = 0;  //Variable auxiliar para saber que fila es subfila de la otra
            Md[j][w] = 0;
        }
    }

    //Sacar los testores
    QVector <QVector <int>> testores;
    int cantTestores = 0;
    for(int i=0; i<rows; ++i){  //Recorro la matriz de diferencia por filas para sacar los testores
        if(Md[i][e] == 0){   //Si esta fila corresponde a un testor
            QVector <int> temp;
            ++cantTestores;
            for(int j=0; j<MAX_F; ++j){  //Recorro cada rasgo
                if(Md[i][j] == 1){  //Si el rasgo está activo
                    temp.append(j);  //Agrego el rasgo al testor
                }
            }
            testores.append(temp);
        }

    }

    //Sacar la importancia de los rasgos
    double H[4][MAX_F+2];

    memset(H,0,sizeof(H));
    //Cantidad de informacione de los rasgos
    for(int i=0; i<MAX_F; ++i){
        for(int j=0; j<cantTestores; ++j){
            if(testores.at(j).indexOf(i) != -1)
                H[0][i] += 1;  //Aumentamos en 1 la cantidad de apariciones del rasgo i
        }
        H[0][i] /= cantTestores;
    }
    //Longitud
    for(int i=0; i<MAX_F; ++i){
        for(int j=0; j<cantTestores; ++j){
            if(testores.at(j).indexOf(i) != -1) //Si está el rasgo i en el testor j
                H[1][i] += 1/testores.at(j).size();
        }
        H[1][i] /= cantTestores;
    }
    //Importancia final de los rasgos
    double alfa = 0.5, beta = 0.5;
    for(int i=0; i<MAX_F; ++i){
        H[2][i] += H[0][i]*alfa + H[1][i]*beta;
    }
    //Mejor testor
    int mejorTestor = 0;
    double maxTestor = 0;
    for(int i=0; i<cantTestores; ++i){  //Recorriendo todos los testores
        double aux = 0;
        for(int j=0; j<testores.at(i).size(); ++j){
            aux += H[2][testores.at(i).at(j)];
        }
        if(aux > maxTestor){
            maxTestor = aux;
            mejorTestor = i;
        }
    }

    //Activar los rasgos del testor
    for(int i=0; i<MAX_F; ++i){
        if(testores.at(mejorTestor).indexOf(i) != -1){
            qDebug() << i;
            setAsTestor(i,1);
        }
        else setAsTestor(i,0);
    }

}


QString CKnowledgeDB::getDescription(int featureId)
{
    QSqlQuery query;
    QString des;
    QSqlRecord record;

    query.prepare("SELECT description FROM feature WHERE id = ?;");
    query.addBindValue(featureId);

    if (!query.exec()) {
        qDebug() << QString("Failed to obtain the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return "";
    }

    record = query.record();

    while (query.next()) {
        des = query.value(record.indexOf("description")).toString();
    }

    return des;
}

int CKnowledgeDB::getTestor(int featureId)
{
    QSqlQuery query;
    int tes;
    QSqlRecord record;

    query.prepare("SELECT isTestor FROM feature WHERE id = ?;");
    query.addBindValue(featureId);

    if (!query.exec()) {
        qDebug() << QString("Failed to obtain the object in DB : ") + m_dataBaseName << "\n"
                 << m_dataBase.lastError().text();
        return -1;
    }

    record = query.record();

    while (query.next()) {

        tes = query.value(record.indexOf("isTestor")).toInt();
    }

    return tes;
}
