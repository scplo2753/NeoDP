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
    : QMainWindow(parent), ui(new Ui_NeoDP),STPTProxyModel(new STPTSortFilterProxyModel()),pDTC(new DTC())
{
    setWindowTitle(tr("NeoDP"));
    ui->setupUi(this);
    ui->DockSTPTWidget->hide();
    ui->SteerPointView->setModel(STPTProxyModel);
    STPTProxyModel->setSourceModel(pDTC->getSTPTTabModel());
    ui->SteerPointView->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete pDTC;
    delete ui;
}

void MainWindow::on_Exit_pBut_clicked()
{
    this->close();
}

void MainWindow::on_Dock_STPT_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("");
    STPTProxyModel->invalidate();
    if (isSTPTWidgetExpanded)
    {
        isSTPTWidgetExpanded = false;
        ui->DockSTPTWidget->hide();
    }
    else
    {
        isSTPTWidgetExpanded = true;
        ui->DockSTPTWidget->show();
    }
}

void MainWindow::on_STPT_sub_INS_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^target");
}

void MainWindow::on_STPT_sub_Lines_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^lineSTPT");
}


void MainWindow::on_STPT_sub_PPTs_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^ppt");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^wpntarget");
}

