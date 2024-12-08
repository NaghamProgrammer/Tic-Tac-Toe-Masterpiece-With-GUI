#include "mainwindow.h"
#include "helpwindow.h"
#include "creditswindow.h"
#include "manuwindow.h"
#include "ui_mainwindow.h"
#include "ui_helpwindow.h"
#include "ui_creditswindow.h"
#include "manuwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , helpWindow(nullptr)
    , creditWindow(nullptr)
    , manuWindow(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete helpWindow;
    delete creditWindow;
    delete manuWindow;
}

void MainWindow::showMainWindow()
{
    this->show(); // Show MainWindow again when returning
}

void MainWindow::on_quitBtn_clicked()
{
    this->close();
}

void MainWindow::on_helpBtn_clicked()
{
    if (!helpWindow) {
        helpWindow = new HelpWindow(this);
        connect(helpWindow, &HelpWindow::backToMainWindow, this, &MainWindow::showMainWindow);
    }
    helpWindow->show();
}

void MainWindow::on_creditsBtn_clicked()
{
    if (!creditWindow) {
        creditWindow = new CreditsWindow(this); // Pass MainWindow as parent
        connect(creditWindow, &CreditsWindow::backToMainWindow, this, &MainWindow::showMainWindow);
    }
    creditWindow->show();
}


void MainWindow::on_startBtn_clicked()
{
    this->hide();
    if (!manuWindow) {
        manuWindow = new ManuWindow(this); // Pass MainWindow as parent
        connect(manuWindow, &ManuWindow::backToMainWindow, this, &MainWindow::showMainWindow);
    }
    manuWindow->showFullScreen();
}
