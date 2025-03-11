#include "dtc.h"

#include "../Common/DTCInfo.h"
#include "ui_NeoDP.h"
#include <QDebug>

DTC::DTC(Ui_NeoDP *ui, QObject *parent)
    : QObject{parent},
      ui(ui),
      DTCSettings(new QSettings(DTCInfo::STPTSectionPath, QSettings::IniFormat)),
      STPTTabModel(new STPTItemModel()),
      STPTProxyModel(new STPTSortFilterProxyModel()),
      HarmManager(new HARMSectionManager(ui))
{
    InitSTPTSection();
    STPTProxyModel->setSourceModel(STPTTabModel);
    ui->SteerPointView->setModel(STPTProxyModel);
    ui->SteerPointView->setSortingEnabled(true);

    connect(ui->Dock_STPT_pBut, &QPushButton::clicked, this, &DTC::STPTPuButtonClicked);
    connect(ui->STPT_sub_INS_pBut, &QPushButton::clicked, this, &DTC::STPTsubInsPuButtonClicked);
    connect(ui->STPT_sub_Lines_pBut, &QPushButton::clicked, this, &DTC::STPTsubLinesPuButtonClicked);
    connect(ui->STPT_sub_PPTs_pBut, &QPushButton::clicked, this, &DTC::STPTsubPPTsPuButtonClicked);
    connect(ui->STPT_sub_WPNT_pBut, &QPushButton::clicked, this, &DTC::STPTsubWPNTPuButtonClicked);

    connect(ui->Dock_HARM_pBut, &QPushButton::clicked, this, &DTC::Dock_Harm_pButClicked);
    connect(ui->Dock_IFF_pBut, &QPushButton::clicked, this, &DTC::Dock_IFF_pButCilcked);
}

DTC::~DTC()
{
}

void DTC::InitSTPTSection()
{
    DTCSettings->beginReadArray("STPT");
    STPTKeys = QStringList(DTCSettings->allKeys());
    STPTStruct STPTrow;
    QStringList values;
    for (auto &i : STPTKeys)
    {
        STPTrow.clear();
        values.clear();
        STPTrow.Name = i;
        values = DTCSettings->value(i).value<QStringList>();
        STPTrow.Latitude = values[0].toDouble();
        STPTrow.Longitude = values[1].toDouble();
        STPTrow.Altitude = values[2].toDouble();
        if (values.size() > 3)
        {
            STPTrow.Action = values[3];
            STPTrow.Target = values[4];
        }
        STPTTabModel->appendRow(STPTrow);
    }
    DTCSettings->endArray();
}

void DTC::STPTPuButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("");
    STPTProxyModel->invalidate();
    ui->DockSTPTWidget->show();
}

void DTC::STPTsubInsPuButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^target");
}

void DTC::STPTsubLinesPuButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^lineSTPT");
}

void DTC::STPTsubPPTsPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^ppt");
}

void DTC::STPTsubWPNTPuButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->STPTWidget);
    STPTProxyModel->setFilterRegularExpression("^wpntarget");
}

void DTC::Dock_Harm_pButClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HARMWidget);
    ui->DockSTPTWidget->hide();
}

void DTC::Dock_IFF_pButCilcked()
{
    ui->stackedWidget->setCurrentWidget(ui->IFFWidget);
    ui->DockSTPTWidget->hide();
}