#include "MainWindow.h"
#include "ui_NeoDP.h"
#include "DTC/dtc.h"
#include <QMessageBox>
#include <QToolBar>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_NeoDP),pDTC(new DTC()),STPTSortFilterProxyModel(new QSortFilterProxyModel())
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

void MainWindow::on_Dock_STPT_pBut_clicked(bool checked)
{
    Q_UNUSED(checked)
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
