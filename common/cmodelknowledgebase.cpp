#include "cmodelknowledgebase.h"
#include <QDebug>


CModelKnowledgeBase::CModelKnowledgeBase(CKnowledgeDB *p_db, QObject *parent) :
    QAbstractTableModel(parent)
{
    this->m_db = p_db;
    for (int i=0; i<this->m_db->getAllObject().size(); i++){
        this->m_objects.append(this->m_db->getAllObject().at(i));
    }
    this->temp = new CObject();
    this->maxRow = this->m_objects.size() + 1;
    this->maxColumn = 16;
}
int CModelKnowledgeBase::rowCount(const QModelIndex &parent) const{
    return this->maxRow;
}
int CModelKnowledgeBase::columnCount(const QModelIndex &parent) const{
    return this->maxColumn;
}
QVariant CModelKnowledgeBase::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int column = index.column();
    bool canRow = true;
    int len = this->maxRow - 1;
    if (len == row) canRow = false;

    if (Qt::DisplayRole == role && column < this->maxColumn - 1 && canRow)
        return this->m_objects.at(row)->getFeature(column)->getValue();
    else if (Qt::DisplayRole == role && column == this->maxColumn - 1 && canRow) {
        if (m_objects.at(row)->getClass() == 1)
            return QString("Apto");
        else if(m_objects.at(row)->getClass() == -1)
            return QString("No Apto");
        else
            return QString("No clasificado");
    }
    return QVariant();
}
QVariant CModelKnowledgeBase::headerData(int section, Qt::Orientation orientation, int role) const{
    if (Qt::DisplayRole == role){
        if (Qt::Horizontal == orientation){
            if (section == this->maxColumn - 1)
                return QString("Clasificacion");
            if (section >= 0 && section < this->maxColumn - 1 )
                return this->m_objects.at(0)->getFeature(section)->getDescription();
        }
    }
    return QVariant();
}
Qt::ItemFlags CModelKnowledgeBase::flags(const QModelIndex &index) const{
     return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
int CModelKnowledgeBase::getMaxColumn(){
    return this->maxColumn;
}
int CModelKnowledgeBase::getMaxRow(){
    return this->maxRow;
}
