#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QKeySequence>
#include <QString>
#include <iostream>

#include "ShuntingYard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    using QWidget::keyPressEvent;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void connectButtons();
    void keyPressEvent(QKeyEvent *event);
    void appendDisplay(std::string s);
    void clear();
    void clearResult();
    void clearInput();
    void clearAll();
    void compute();
    void handleErrors();

    ShuntingYard shuntingYard;
};

#endif // MAINWINDOW_H
