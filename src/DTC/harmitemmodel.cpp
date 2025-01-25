#include "HarmItemModel.h"

HarmItemModel::HarmItemModel(QObject *parent)
    : QAbstractListModel{parent}
{
    initHARMData();
}

HarmItemModel::~HarmItemModel()
{

}

QVariant HarmItemModel::data(const QModelIndex &index,int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role==Qt::DisplayRole)
    {
        int row=index.row();
        if(index.column()==0)
            return HARMKeys.at(row);
        if(index.column()==1)
            return HARMData.value(HARMKeys.at(row));
    }
    return QVariant();
}

int HarmItemModel::rowCount(const QModelIndex &parent) const
{
    return HARMData.size();
}

int HarmItemModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

Qt::ItemFlags HarmItemModel::flags(const QModelIndex &index) const
{
    int column=index.column();
    if(column==1)
        return QAbstractItemModel::flags(index)|Qt::ItemIsEditable;
    return QAbstractItemModel::flags(index)|Qt::ItemIsEnabled;
}

const HarmItemModel* HarmItemModel::getHarmItemModelptr() const
{
    return this;
}
