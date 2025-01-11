#include "stptitemmodel.h"
#include "../Common/DTCInfo.h"

STPTItemModel::STPTItemModel(QObject *parent)
    : QAbstractItemModel{parent}
{}

QVariant STPTItemModel::data(const QModelIndex &index,int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role==Qt::DisplayRole || role==Qt::EditRole)
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
            if(!STPTData.at(row).Action.data().isNull()&&STPTData.at(row).Action.data().toString()!="-1")
                return DTCInfo::STPTInfo::STPTActions.at(STPTData.at(row).Action.data().toInt());
            else
                return QVariant("");
        case 5:
            return STPTData.at(row).Target.data();
        }
    }
    return QVariant();
}

int STPTItemModel::rowCount(const QModelIndex &index)const
{
    return STPTData.count();
}

int STPTItemModel::columnCount(const QModelIndex &index)const
{
    return DTCInfo::STPTInfo::STPTColumnCount;
}

QModelIndex STPTItemModel::index(int row,int column,const QModelIndex &parent) const
{

}
