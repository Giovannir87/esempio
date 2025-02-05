#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

// CIAO000000

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_ValueSpinBox_valueChanged(double arg1);

    void on_DegreesSpinBox_valueChanged(int arg1);

    void on_FirstSpinBox_valueChanged(int arg1);

    void on_SecondSpinBox_valueChanged(double arg1);

    void updateValueSpinBox();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;

    double savedDegrees;
    double savedFirst;
    double savedSecond;
};
#endif // DIALOG_H
