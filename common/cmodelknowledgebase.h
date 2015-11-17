#ifndef CMODELKNOWLEDGEBASE_H
#define CMODELKNOWLEDGEBASE_H

#include <QAbstractTableModel>

#include "../bussines/cobject.h"
#include "../bussines/cknowledgedb.h"

class CModelKnowledgeBase : public QAbstractTableModel
{
    Q_OBJECT
private:
     QVector<CObject *> m_objects;
     CKnowledgeDB *m_db;
     int maxRow, maxColumn;
     CObject *temp;
public:
    explicit CModelKnowledgeBase(CKnowledgeDB *p_db, QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    int getMaxRow();
    int getMaxColumn();
signals:
    void updateFeature();
    void updateObject();
public slots:

};

#endif // CMODELKNOWLEDGEBASE_H
