#include "dtc.h"
#include "../Common/DTCInfo.h"
#include <QSettings>
#include <QTextStream>
#include <QStringView>
#include <QVector>
#include <QFile>
#include <QStringList>
#include <QDebug>

DTC::DTC()
    :DTCSettings(new QSettings(DTCInfo::BMS437U6DefaultDTC,QSettings::IniFormat))
{
    LoadSTPTSection();
}

DTC::~DTC()
{
}

void DTC::LoadSTPTSection()
{
    STPTItemModel=new QStandardItemModel();

    DTCSettings->beginReadArray("STPT");
    STPTKeys=QStringList(DTCSettings->allKeys());
    QList<QStandardItem *> rowItems;
    QStringList values;
    for(auto i:STPTKeys)
    {
        rowItems.clear();
        values.clear();
        rowItems.append(new QStandardItem(i));
        values=DTCSettings->value(i).value<QStringList>();
        for(auto j:values)
        {
            rowItems.append(new QStandardItem(j));
        }
        while(rowItems.size()<DTCInfo::STPTInfo::STPTColumnCount)
            rowItems.append(new QStandardItem(""));
        STPTItemModel->appendRow(rowItems);
    }
    DTCSettings->endArray();
    STPTItemModel->setHorizontalHeaderLabels(DTCInfo::STPTInfo::STPTHeader);
}

QStandardItemModel * DTC::getSTPTItemModel() const
{
    return STPTItemModel;
}
