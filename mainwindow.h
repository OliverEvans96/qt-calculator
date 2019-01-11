#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <iostream>

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
    void appendDisplay(char c);
    void clear();
    void clearAll();
    void compute();
};

#endif // MAINWINDOW_H
