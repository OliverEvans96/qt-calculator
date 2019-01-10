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
    captureKeys();
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
}

void MainWindow::captureKeys()
{

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
