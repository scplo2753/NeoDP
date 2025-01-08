#include "dtc.h"
#include "Common/DTCInfo.h"
#include <QSettings>
#include <QTextStream>
#include <QVector>
#include <QFile>
#include <QStringList>

DTC::DTC()
    :DTCSettings(new QSettings(ResourcesPath::BMS437U6DefaultDTC,QSettings::IniFormat))
{
    LoadSTPTSection();
}

DTC::~DTC()
{

}

void DTC::LoadSTPTSection()
{
    STPTItemModel=new QStandardItemModel();
    STPTItemModel->setHorizontalHeaderLabels(STPTInfo::STPTHeader);
    DTCSettings->beginReadArray("STPT");

}

void DTC::LoadRadioSection()
{

}
