#include "HarmItemModel.h"

HarmItemModel::HarmItemModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    initHARMData();
}

HarmItemModel::~HarmItemModel()
{
}

QVariant HarmItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        const int column = index.column();
        QString key = HARMKeys.at(row);
        switch (column)
        {
        case 0:
            return key;
        case 1:
            return HARMData.value(key);
        }
    }
    return QVariant();
}

int HarmItemModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return HARMData.size();
}

int HarmItemModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

Qt::ItemFlags HarmItemModel::flags(const QModelIndex &index) const
{
    int column = index.column();
    if (column == 1)
        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled;
}

const HarmItemModel *HarmItemModel::getHarmItemModelptr() const
{
    return this;
}
