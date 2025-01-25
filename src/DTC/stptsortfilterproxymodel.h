#pragma once
#include <QSortFilterProxyModel>

class STPTSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    explicit STPTSortFilterProxyModel(QObject *parent = nullptr);

    const STPTSortFilterProxyModel* getPtr()const;
protected:
    bool lessThan(const QModelIndex &source_left,const QModelIndex &source_right)const override;
};
