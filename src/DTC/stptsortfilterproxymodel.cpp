#include "stptsortfilterproxymodel.h"
#include "STPTMap.h"

STPTSortFilterProxyModel::STPTSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

bool STPTSortFilterProxyModel::lessThan(const QModelIndex &source_left,const QModelIndex &source_right) const
{
    if(source_left.column()==0 && source_right.column()==0)
    {
    QString leftKey=sourceModel()->data(source_left).toString();
    QString rightKey=sourceModel()->data(source_right).toString();

    int leftIndex=STPTMap::instance().getSTPTIndex(leftKey);
    int rightIndex=STPTMap::instance().getSTPTIndex(rightKey);

    return leftIndex>rightIndex;
    }
    return true;
}

const STPTSortFilterProxyModel* STPTSortFilterProxyModel::getPtr() const
{
    return this;
}
