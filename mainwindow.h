#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numPressed();
    void mathButton();
    void equalButton();
    void on_ButtonAC_clicked();

    void on_Button10_clicked();

    void on_ButtonPR_clicked();

    void on_ButtonPM_clicked();

private:
    Ui::MainWindow *ui;

private:


};
#endif // MAINWINDOW_H
