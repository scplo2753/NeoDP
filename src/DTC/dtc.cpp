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
      HarmManager(new HARMSectionManager(ui)),
      IFFManagerObj(new IFFPageManager(ui)),
      L16PageManagerObj(new L16PageManager(ui))
{
    InitSTPTSection();
    STPTProxyModel->setSourceModel(STPTTabModel);
    ui->SteerPointView->setModel(STPTProxyModel);
    ui->SteerPointView->setSortingEnabled(true);
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

void DTC::setSTPTFilter(const QString &filter)
{
    if(STPTProxyModel)
    {
        STPTProxyModel->setFilterRegularExpression(filter);
        STPTProxyModel->invalidate();
    }
}