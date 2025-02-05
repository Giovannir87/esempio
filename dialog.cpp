#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ValueSpinBox_valueChanged(double arg1)
{
    int parte_intera_degrees = static_cast<int>(arg1);
    double arg2 = (arg1 - static_cast<double>(parte_intera_degrees)) * 60;
    int parte_intera_first = static_cast<int>(arg2);
    double arg3 = (arg2 - static_cast<double>(parte_intera_first)) * 60;
    double secondi = static_cast<double>(std::round(arg3*100.0)/100.0);

    //Lo std::round è per arrotondare per eccesso
    //Nella variabile secondi è per arrotondare a due cifre decimali
    //Il Passo 0.000278 --> Corrisponde ad un secondo



    ui->DegreesSpinBox->setValue(parte_intera_degrees);
    ui->FirstSpinBox->setValue(parte_intera_first);
    ui->SecondSpinBox->setValue(secondi);
}

void Dialog::on_DegreesSpinBox_valueChanged(int arg1)
{
    if(arg1 >= 0 && arg1 <= 359)
    {
        savedDegrees = arg1;
        updateValueSpinBox();
    }
}

void Dialog::on_FirstSpinBox_valueChanged(int arg1)
{
    double parte_decimale;
    if(arg1 >= 0 && arg1 <= 59)
    {
        savedFirst = std::round(arg1 / 60.0 * 1000000.0) / 1000000.0;
        updateValueSpinBox();
    }

}


void Dialog::on_SecondSpinBox_valueChanged(double arg1)
{
    if(arg1 >= 0.00 && arg1 <= 59.99)
    {
         savedSecond = std::round(arg1 / 3600.0 * 1000000.0) / 1000000.0;
        updateValueSpinBox();
    }
}

void Dialog::updateValueSpinBox()
{
    double Total = savedDegrees + savedFirst + savedSecond;
    ui -> ValueSpinBox ->setValue(Total);
}



void Dialog::on_buttonBox_accepted()
{
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}



