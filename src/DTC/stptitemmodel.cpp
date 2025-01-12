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
            return STPTData.at(row).Longtitude;
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
            if(!STPTData.at(row).Target.isNull())
                return STPTData.at(row).Target;
        default:
            return QVariant();
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

Qt::ItemFlags STPTItemModel::flags(const QModelIndex &index) const
{
    int column=index.column();
    int row=index.row();
    switch (column) {
    case 0:
        return QAbstractItemModel::flags(index)|Qt::ItemIsEnabled;
    case 1:
        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    case 2:
        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    case 3:
        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    case 4:
        if(!STPTData.at(row).Action.isNull())
            return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    case 5:
        if(!STPTData.at(row).Target.isNull())
            return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    }
    return QAbstractItemModel::flags(index)|Qt::ItemIsEnabled;
}

void STPTItemModel::appendRow(const STPTStruct rowContent)
{
    STPTData.append(rowContent);
}
