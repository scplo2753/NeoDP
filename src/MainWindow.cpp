#include "MainWindow.h"
#include "ui_NeoDP.h"
#include "DTC/dtc.h"
#include <QMessageBox>
#include <QToolBar>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QRegularExpression>
#include <QPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_NeoDP),STPTSortFilterProxyModel(new QSortFilterProxyModel()),pDTC(new DTC())
{
    setWindowTitle(tr("NeoDP"));
    ui->setupUi(this);
    ui->DockSTPTWidget->hide();
    ui->SteerPointView->setModel(STPTSortFilterProxyModel);
    STPTSortFilterProxyModel->setSourceModel(pDTC->getSTPTTabModel());
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
    STPTSortFilterProxyModel->setFilterRegularExpression("");
    STPTSortFilterProxyModel->invalidate();
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
    STPTSortFilterProxyModel->setFilterRegularExpression("^target");
}

void MainWindow::on_STPT_sub_Lines_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTSortFilterProxyModel->setFilterRegularExpression("^lineSTPT");
}


void MainWindow::on_STPT_sub_PPTs_pBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTSortFilterProxyModel->setFilterRegularExpression("^ppt");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTSortFilterProxyModel->setFilterRegularExpression("^wpntarget");
}

