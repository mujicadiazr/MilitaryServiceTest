#include "fknowledgebase.h"
#include "ui_fknowledgebase.h"

FKnowledgeBase::FKnowledgeBase(CKnowledgeDB * p_db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FKnowledgeBase)
{
    ui->setupUi(this);
    initTable(p_db);
}

FKnowledgeBase::~FKnowledgeBase()
{
    delete ui;
}

void FKnowledgeBase::initTable(CKnowledgeDB * p_db){
    CModelKnowledgeBase *model = new CModelKnowledgeBase(p_db);
    ui->tableView->setModel(model);
}


void FKnowledgeBase::on_pushButton_2_clicked()
{
    close();
}
