#include "stptitemmodel.h"
#include "../Common/DTCInfo.h"

STPTItemModel::STPTItemModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

QVariant STPTItemModel::data(const QModelIndex &index,int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role==Qt::DisplayRole)
    {
        const int row=index.row();
        switch(index.column())
        {
        case 0:
            return STPTData.at(row).Name;
        case 1:
            return STPTData.at(row).Latitude;
        case 2:
            return STPTData.at(row).Longitude;
        case 3:
            return STPTData.at(row).Altitude;
        case 4:
            if(!STPTData.at(row).Action.isNull())
            {
                QString str=STPTData.at(row).Name.split('_')[0];
                if(str=="target"||str=="wpntarget")
                {
                    if(!STPTData.at(row).Action.isNull() && STPTData.at(row).Action!="-1")
                        return DTCInfo::STPTInfo::STPTActions[STPTData.at(row).Action.toInt()];
                    else
                        return QVariant();
                }
                else
                    return STPTData.at(row).Action;
            }
        case 5:
            if (!STPTData.at(row).Target.isNull())
                return STPTData.at(row).Target;
        }
    }
    return QVariant();
}

int STPTItemModel::rowCount(const QModelIndex &index)const
{
    Q_UNUSED(index)
    return STPTData.count();
}

int STPTItemModel::columnCount(const QModelIndex &index)const
{
    Q_UNUSED(index)
    return DTCInfo::STPTInfo::STPTColumnCount;
}

QVariant STPTItemModel::headerData(int section,Qt::Orientation orientation,int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal)
        {
            if(section<=DTCInfo::STPTInfo::STPTHeader.size()-1)
                return DTCInfo::STPTInfo::STPTHeader.at(section);
            else
                return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags STPTItemModel::flags(const QModelIndex &index) const
{
    int column=index.column();
    int row=index.row();

    QString keyName=STPTData.at(row).Name.split('_').at(0);
    switch (column) {
    case 0:
        return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled;
    case 4:
        if(keyName=="lineSTPT")
            return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled;
    case 5:
        if(keyName=="lineSTPT")
            return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index)|Qt::ItemIsEditable;
}

void STPTItemModel::appendRow(const STPTStruct rowContent)
{
    STPTData.append(rowContent);
}

const STPTItemModel* STPTItemModel::getPtr()const
{
    return this;
}
