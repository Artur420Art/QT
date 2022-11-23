#include "mainwindow.h"
#include "./ui_mainwindow.h"

double m_result = 0.0;
bool addFlag = false;
bool mullFlag = false;
bool divFlag = false;
bool subFlag = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
//   ui->Display->setText(QString::number(m_result));
   QPushButton* numButtons[10];
   for (int i = 0; i < 10; i++) {
       QString butName = "Button" + QString::number(i);
       numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
       connect(numButtons[i], SIGNAL(released()), this, SLOT(numPressed()));
   }
   connect(ui->ADD, SIGNAL(released()), this, SLOT(mathButton()));
   connect(ui->Mull, SIGNAL(released()), this, SLOT(mathButton()));
   connect(ui->DIV, SIGNAL(released()), this, SLOT(mathButton()));
   connect(ui->Min, SIGNAL(released()), this, SLOT(mathButton()));

   connect(ui->EQUAL, SIGNAL(released()), this, SLOT(equalButton()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numPressed() {
    QPushButton* button = (QPushButton * )sender();
    QString ButVal = button->text();
    QString DispVal = ui->Display->text();
    if ((DispVal.toDouble() == 0 ) || (DispVal.toDouble() == 0.0) ) {
        ui->Display->setText( ui->Display->text() + ButVal);
    }else {
        QString newVal = DispVal + ButVal;
        double dblVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblVal, 'g', 16));
    }

}

void MainWindow::mathButton() {
    addFlag = false;
    mullFlag = false;
    divFlag = false;
    subFlag = false;
    QString DispVal = ui->Display->text();
    m_result = DispVal.toDouble();
    QPushButton * button = (QPushButton *) sender();
    QString butVal = button->text();
    if (QString::compare(butVal, "/", Qt::CaseInsensitive) == 0) {
        divFlag = true;
    }else if(QString::compare(butVal, "X", Qt::CaseInsensitive) == 0) {
        mullFlag = true;
    }else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0) {
             subFlag= true;
    }else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0) {
        addFlag = true;
    }
    ui->Display->setText("");
}

void MainWindow::equalButton() {

        double solution = 0.0;
        QString displayVal = ui->Display->text();
        double dblDispVal = displayVal.toDouble();
        if (divFlag || addFlag || mullFlag || subFlag) {
            if (divFlag) {
                solution = m_result / dblDispVal;
            }
            else if (addFlag) {
                solution = m_result + dblDispVal;
            }
            else if (subFlag) {
                solution = m_result - dblDispVal;
            }
            else if (mullFlag) {
                solution = m_result * dblDispVal;
            }
        }
        ui->Display->setText(QString::number(solution));
}

void MainWindow::on_ButtonAC_clicked()
{
    ui->Display->setText("");
    m_result = 0;
    addFlag = false;
    mullFlag = false;
    divFlag = false;
    subFlag = false;
    ui->Display->setText(QString::number(m_result));

}


void MainWindow::on_Button10_clicked()
{
    if (!(ui->Display->text().contains('.'))) {
        ui->Display->setText(ui->Display->text() + ".");
    }
}


void MainWindow::on_ButtonPR_clicked()
{

    double tmp = ui->Display->text().toDouble();
    ui->Display->setText(QString::number(tmp * 0.01));
}


void MainWindow::on_ButtonPM_clicked()
{

    QString DisplVal = ui->Display->text();
    double dispVal = DisplVal.toDouble();
    dispVal *= -1;
    ui->Display->setText(QString::number(dispVal));
}

