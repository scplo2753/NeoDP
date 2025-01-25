#include "MainWindow.h"
#include "ui_NeoDP.h"
#include "DTC/dtc.h"
#include "DTC/stptsortfilterproxymodel.h"
#include <QMessageBox>
#include <QToolBar>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QRegularExpression>
#include <QPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_NeoDP()),pDTC(nullptr)
{
    setWindowTitle(tr("NeoDP"));
    ui->setupUi(this);
    pDTC = new DTC(ui, this);
    ui->DockSTPTWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_pBut_clicked()
{
    this->close();
}
