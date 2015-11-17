#ifndef MILITARYSERVICETESTVIEW_H
#define MILITARYSERVICETESTVIEW_H

#include <QMainWindow>
#include "fknowledgebase.h"
#include "../bussines/cknowledgedb.h"

namespace Ui {
class MilitaryServiceTestView;
}

class MilitaryServiceTestView : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MilitaryServiceTestView(QWidget *parent = 0);
    ~MilitaryServiceTestView();
    
private:
    Ui::MilitaryServiceTestView *ui;
    FKnowledgeBase *ui_Fknowlede;

public slots:
    void showKnowledgeBase();
private slots:
    void on_pushButton_clicked();
    void on_actionAdd_Objects_triggered();
    void on_comboBox_14_editTextChanged(const QString &arg1);
    void on_comboBox_13_editTextChanged(const QString &arg1);
    void on_comboBox_12_editTextChanged(const QString &arg1);
    void on_comboBox_11_editTextChanged(const QString &arg1);
    void on_comboBox_10_editTextChanged(const QString &arg1);
    void on_comboBox_9_editTextChanged(const QString &arg1);
    void on_comboBox_8_editTextChanged(const QString &arg1);
    void on_comboBox_7_editTextChanged(const QString &arg1);
    void on_comboBox_6_editTextChanged(const QString &arg1);
    void on_comboBox_5_editTextChanged(const QString &arg1);
    void on_comboBox_4_editTextChanged(const QString &arg1);
    void on_comboBox_3_editTextChanged(const QString &arg1);
    void on_comboBox_2_editTextChanged(const QString &arg1);
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_comboBox_editTextChanged(const QString &arg1);
    void on_actionShow_Knowledge_Base_triggered();
};

#endif // MILITARYSERVICETESTVIEW_H
