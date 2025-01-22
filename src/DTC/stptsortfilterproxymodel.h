#ifndef STPTSORTFILTERPROXYMODEL_H
#define STPTSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class STPTSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    explicit STPTSortFilterProxyModel(QObject *parent = nullptr);
protected:
    bool lessThan(const QModelIndex &source_left,const QModelIndex &source_right)const override;
};

#endif // STPTSORTFILTERPROXYMODEL_H
