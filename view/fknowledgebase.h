#ifndef FKNOWLEDGEBASE_H
#define FKNOWLEDGEBASE_H

#include <QWidget>
#include <QModelIndex>

#include "../bussines/cknowledgedb.h"
#include "../common/cmodelknowledgebase.h"


namespace Ui {
class FKnowledgeBase;
}

class FKnowledgeBase : public QWidget
{
    Q_OBJECT

public:
    explicit FKnowledgeBase(CKnowledgeDB * p_db, QWidget *parent = 0);
    ~FKnowledgeBase();

private:
    Ui::FKnowledgeBase *ui;
    void initTable(CKnowledgeDB * p_db);
    CModelKnowledgeBase *model;
public slots:
private slots:
    void on_pushButton_2_clicked();
};

#endif // FKNOWLEDGEBASE_H


