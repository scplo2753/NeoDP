#include "dtc.h"
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
    DTCSettings->beginGroup("STPT");
    STPTkeys=new QStringList(DTCSettings->allKeys());
    DTCSettings->endGroup();
}

void DTC::LoadRadioSection()
{

}
