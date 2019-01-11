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
    connect(ui->button0, &QPushButton::clicked, [=] (void) -> void {appendDisplay("0");});
    connect(ui->button1, &QPushButton::clicked, [=] (void) -> void {appendDisplay("1");});
    connect(ui->button2, &QPushButton::clicked, [=] (void) -> void {appendDisplay("2");});
    connect(ui->button3, &QPushButton::clicked, [=] (void) -> void {appendDisplay("3");});
    connect(ui->button4, &QPushButton::clicked, [=] (void) -> void {appendDisplay("4");});
    connect(ui->button5, &QPushButton::clicked, [=] (void) -> void {appendDisplay("5");});
    connect(ui->button6, &QPushButton::clicked, [=] (void) -> void {appendDisplay("6");});
    connect(ui->button7, &QPushButton::clicked, [=] (void) -> void {appendDisplay("7");});
    connect(ui->button8, &QPushButton::clicked, [=] (void) -> void {appendDisplay("8");});
    connect(ui->button9, &QPushButton::clicked, [=] (void) -> void {appendDisplay("9");});

    connect(ui->buttonAdd, &QPushButton::clicked, [=] (void) -> void {appendDisplay(" + ");});
    connect(ui->buttonSubtract, &QPushButton::clicked, [=] (void) -> void {appendDisplay(" - ");});
    connect(ui->buttonMultiply, &QPushButton::clicked, [=] (void) -> void {appendDisplay(" × ");});
    connect(ui->buttonDivide, &QPushButton::clicked, [=] (void) -> void {appendDisplay(" ÷ ");});

    connect(ui->buttonParenL, &QPushButton::clicked, [=] (void) -> void {appendDisplay("(");});
    connect(ui->buttonParenR, &QPushButton::clicked, [=] (void) -> void {appendDisplay(")");});
    connect(ui->buttonDot, &QPushButton::clicked, [=] (void) -> void {appendDisplay(".");});

    connect(ui->buttonClear, &QPushButton::clicked, [=] (void) -> void {clear();});
    connect(ui->buttonClearAll, &QPushButton::clicked, [=] (void) -> void {clearAll();});
    connect(ui->buttonEqual, &QPushButton::clicked, [=] (void) -> void {compute();});
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_0: appendDisplay("0");
             break;
        case Qt::Key_1: appendDisplay("1");
             break;
        case Qt::Key_2: appendDisplay("2");
             break;
        case Qt::Key_3: appendDisplay("3");
             break;
        case Qt::Key_4: appendDisplay("4");
             break;
        case Qt::Key_5: appendDisplay("5");
             break;
        case Qt::Key_6: appendDisplay("6");
             break;
        case Qt::Key_7: appendDisplay("7");
             break;
        case Qt::Key_8: appendDisplay("8");
             break;
        case Qt::Key_9: appendDisplay("9");
             break;

        case Qt::Key_Plus: appendDisplay(" + ");
             break;
        case Qt::Key_Minus: appendDisplay(" - ");
             break;
        case Qt::Key_Asterisk: appendDisplay(" × ");
             break;
        case Qt::Key_Slash: appendDisplay(" ÷ ");
             break;

        case Qt::Key_Period: appendDisplay(".");
             break;
        case Qt::Key_ParenLeft: appendDisplay("(");
             break;
        case Qt::Key_ParenRight: appendDisplay(")");
             break;

        case Qt::Key_Backspace:
            if(event->modifiers().testFlag(Qt::ControlModifier))
                clearAll();
            else
                clear();
             break;
        case Qt::Key_Equal:
        case Qt::Key_Return: compute();
             break;
        }
}

void MainWindow::appendDisplay(std::string s)
{
    ui->inputDisplay->setText(ui->inputDisplay->text().append(QString::fromStdString(s)));
}

void MainWindow::clear()
{
    if(ui->inputDisplay->text().size() > 0)
    {
        ui->inputDisplay->setText(ui->inputDisplay->text().chopped(1));
    }

}

void MainWindow::clearInput()
{
    ui->inputDisplay->setText("");
}

void MainWindow::clearResult()
{
    ui->oldInputDisplay->setText("");
    ui->resultDisplay->display(0);
}

void MainWindow::clearAll()
{
    clearInput();
    clearResult();
}

void MainWindow::compute()
{
    std::string inputStr(ui->inputDisplay->text().toUtf8().data());
    shuntingYard.reset();
    shuntingYard.parseInfix(inputStr);
    shuntingYard.printRPN();
    double result = shuntingYard.evaluateRPN();
    ui->resultDisplay->display(result);
    ui->oldInputDisplay->setText(ui->inputDisplay->text().append(" ="));
    clearInput();
}
