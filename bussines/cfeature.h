#ifndef CFEATURE_H
#define CFEATURE_H
#include <QVariant>
#include <QString>

#include "icomparable.h"
#include <QJsonArray>
#include <QDebug>

/**
 * Clase rasgo
 * Su responsabilidad es representar a un rasgo abstracto porque no implementa el metodo compare que hereda de IComparable
 * y lo deja para que los rasgos especificos o sea sus hijas lo implementen.
 */
class CFeature : public IComparable
{
protected:

    QString m_description;
    QVariant m_value;
    int m_testor;

public:
    CFeature();

    void setDescription(QString);
    void setValue(QVariant);
    void setTestor(int);
    void setDefault(QVariant, int);

    QVariant getValue();
    QString  getDescription();
    int      getTestor();

};

#endif // CFEATURE_H
