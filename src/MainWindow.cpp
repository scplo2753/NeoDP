#include "MainWindow.h"
#include "ui_NeoDP.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui_NeoDP()),
      pDTC(nullptr)
{
    setWindowTitle(tr("NeoDP"));
    ui->setupUi(this);
    pDTC = new DTC(ui, this);
    ui->DockSTPTWidget->hide();

    connect(ui->Dock_STPT_pBut, &QPushButton::clicked, this, &MainWindow::STPTPuButtonClicked);
    connect(ui->STPT_sub_INS_pBut, &QPushButton::clicked, this, &MainWindow::STPTsubInsPuButtonClicked);
    connect(ui->STPT_sub_Lines_pBut, &QPushButton::clicked, this, &MainWindow::STPTsubLinesPuButtonClicked);
    connect(ui->STPT_sub_PPTs_pBut, &QPushButton::clicked, this, &MainWindow::STPTsubPPTsPuButtonClicked);
    connect(ui->STPT_sub_WPNT_pBut, &QPushButton::clicked, this, &MainWindow::STPTsubWPNTPuButtonClicked);

    connect(ui->Dock_HARM_pBut, &QPushButton::clicked, this, &MainWindow::Dock_Harm_pButClicked);
    connect(ui->Dock_IFF_pBut, &QPushButton::clicked, this, &MainWindow::Dock_IFF_pButCilcked);
    connect(ui->Dock_L16_pBut,&QPushButton::clicked,this,&MainWindow::Dock_L16_pButClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_pBut_clicked()
{
    this->close();
}

void MainWindow::STPTPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    pDTC->setSTPTFilter("");
    ui->DockSTPTWidget->show();
}

void MainWindow::STPTsubInsPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    pDTC->setSTPTFilter("^target");
}

void MainWindow::STPTsubLinesPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    pDTC->setSTPTFilter("^lineSTPT");
}

void MainWindow::STPTsubPPTsPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    pDTC->setSTPTFilter("^ppt");
}

void MainWindow::STPTsubWPNTPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    pDTC->setSTPTFilter("^wpntarget");
}

void MainWindow::Dock_Harm_pButClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HARMWidget);
    ui->DockSTPTWidget->hide();
}

void MainWindow::Dock_IFF_pButCilcked()
{
    ui->stackedWidget->setCurrentWidget(ui->IFFWidget);
    ui->DockSTPTWidget->hide();
}

void MainWindow::Dock_L16_pButClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Link16PageWidget);
    ui->DockSTPTWidget->hide();
}