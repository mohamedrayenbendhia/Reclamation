#ifndef GRECLAMATION_H
#define GRECLAMATION_H

#include <QWidget>
#include "reclamation.h"
namespace Ui {
class greclamation;
}

class greclamation : public QWidget
{
    Q_OBJECT

public:
    explicit greclamation(QWidget *parent = nullptr);
    ~greclamation();

private slots:
    void on_pushButton_12_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::greclamation *ui;
     reclamation tmprec;
};

#endif // GRECLAMATION_H
