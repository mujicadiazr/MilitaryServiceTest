#include "militaryservicetestview.h"
#include "ui_militaryservicetestview.h"
#include "../bussines/cpatternrecongnition.h"

MilitaryServiceTestView::MilitaryServiceTestView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MilitaryServiceTestView)
{
    ui->setupUi(this);

    ui_Fknowlede = new FKnowledgeBase(CPatternRecongnition::getInstance()->getDB());
}

MilitaryServiceTestView::~MilitaryServiceTestView()
{
    delete ui;
}

void MilitaryServiceTestView::showKnowledgeBase()
{
    ui_Fknowlede->show();
}

void MilitaryServiceTestView::on_pushButton_clicked()
{
    CObject * objToClas = new CObject();
    QVector<double> values;

    values.append(ui->comboBox->currentText().toDouble());
    values.append(ui->doubleSpinBox->value());
    values.append(ui->comboBox_2->currentText().toDouble());
    values.append(ui->comboBox_3->currentText().toDouble());
    values.append(ui->comboBox_4->currentText().toDouble());
    values.append(ui->comboBox_5->currentText().toDouble());
    values.append(ui->comboBox_6->currentText().toDouble());
    values.append(ui->comboBox_7->currentText().toDouble());
    values.append(ui->comboBox_8->currentText().toDouble());
    values.append(ui->comboBox_9->currentText().toDouble());
    values.append(ui->comboBox_10->currentText().toDouble());
    values.append(ui->comboBox_11->currentText().toDouble());
    values.append(ui->comboBox_12->currentText().toDouble());
    values.append(ui->comboBox_13->currentText().toDouble());
    values.append(ui->comboBox_14->currentText().toDouble());


    for (int i = 0; i < 15; ++i)
        objToClas->addFeature(CFactoryFeature::createFeature(i + 1,values.at(i),0));

    EClass result = CPatternRecongnition::getInstance()->recognize(objToClas);
    if (result == EClass::apto )
        ui->label_16->setText("Apto");
    else if (result == EClass::noApto)
        ui->label_16->setText("No Apto");

}


void MilitaryServiceTestView::on_comboBox_14_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_13_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_12_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_11_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_10_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_9_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_8_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_7_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_6_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_5_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_4_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_3_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_2_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_comboBox_editTextChanged(const QString &arg1)
{
    ui->label_16->setText("No Clasificado");
}

void MilitaryServiceTestView::on_actionShow_Knowledge_Base_triggered()
{
    ui_Fknowlede->show();
}
