#include <iostream>
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectButtons()
{
    connect(ui->button0, &QPushButton::clicked, [=] (void) -> void {appendDisplay('0');});
    connect(ui->button1, &QPushButton::clicked, [=] (void) -> void {appendDisplay('1');});
    connect(ui->button2, &QPushButton::clicked, [=] (void) -> void {appendDisplay('2');});
    connect(ui->button3, &QPushButton::clicked, [=] (void) -> void {appendDisplay('3');});
    connect(ui->button4, &QPushButton::clicked, [=] (void) -> void {appendDisplay('4');});
    connect(ui->button5, &QPushButton::clicked, [=] (void) -> void {appendDisplay('5');});
    connect(ui->button6, &QPushButton::clicked, [=] (void) -> void {appendDisplay('6');});
    connect(ui->button7, &QPushButton::clicked, [=] (void) -> void {appendDisplay('7');});
    connect(ui->button8, &QPushButton::clicked, [=] (void) -> void {appendDisplay('8');});
    connect(ui->button9, &QPushButton::clicked, [=] (void) -> void {appendDisplay('9');});

    connect(ui->buttonAdd, &QPushButton::clicked, [=] (void) -> void {appendDisplay('+');});
    connect(ui->buttonSubtract, &QPushButton::clicked, [=] (void) -> void {appendDisplay('-');});
    connect(ui->buttonMultiply, &QPushButton::clicked, [=] (void) -> void {appendDisplay('*');});
    connect(ui->buttonDivide, &QPushButton::clicked, [=] (void) -> void {appendDisplay('/');});

    connect(ui->buttonParenL, &QPushButton::clicked, [=] (void) -> void {appendDisplay('(');});
    connect(ui->buttonParenR, &QPushButton::clicked, [=] (void) -> void {appendDisplay(')');});
    connect(ui->buttonDot, &QPushButton::clicked, [=] (void) -> void {appendDisplay('.');});

    connect(ui->buttonClear, &QPushButton::clicked, [=] (void) -> void {clear();});
    connect(ui->buttonClearAll, &QPushButton::clicked, [=] (void) -> void {clearAll();});
    connect(ui->buttonEqual, &QPushButton::clicked, [=] (void) -> void {compute();});
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_0: appendDisplay('0');
             break;
        case Qt::Key_1: appendDisplay('1');
             break;
        case Qt::Key_2: appendDisplay('2');
             break;
        case Qt::Key_3: appendDisplay('3');
             break;
        case Qt::Key_4: appendDisplay('4');
             break;
        case Qt::Key_5: appendDisplay('5');
             break;
        case Qt::Key_6: appendDisplay('6');
             break;
        case Qt::Key_7: appendDisplay('7');
             break;
        case Qt::Key_8: appendDisplay('8');
             break;
        case Qt::Key_9: appendDisplay('9');
             break;

        case Qt::Key_Plus: appendDisplay('+');
             break;
        case Qt::Key_Minus: appendDisplay('-');
             break;
        case Qt::Key_Asterisk: appendDisplay('*');
             break;
        case Qt::Key_Slash: appendDisplay('/');
             break;

        case Qt::Key_Period: appendDisplay('.');
             break;
        case Qt::Key_ParenLeft: appendDisplay('(');
             break;
        case Qt::Key_ParenRight: appendDisplay(')');
             break;

        case Qt::Key_Backspace: clear();
             break;
        case Qt::Key_Return: compute();
             break;
        }
}

void MainWindow::appendDisplay(char c)
{
    ui->numberDisplay->setText(ui->numberDisplay->text().append(c));
    std::cout << "Appending " << c << ": '" << ui->numberDisplay->text().toUtf8().constData() << "'" << std::endl;
}

void MainWindow::clear()
{
    ui->numberDisplay->setText(ui->numberDisplay->text().chopped(1));
    std::cout << "Clear: '" << ui->numberDisplay->text().toUtf8().constData() << "'" << std::endl;

}

void MainWindow::clearAll()
{
    ui->numberDisplay->setText("");
    std::cout << "Clear all: '" << ui->numberDisplay->text().toUtf8().constData() << "'" << std::endl;
}

void MainWindow::compute()
{
    std::cout << "Compute!" << std::endl;
    clearAll();
}