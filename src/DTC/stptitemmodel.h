#ifndef STPTITEMMODEL_H
#define STPTITEMMODEL_H

#include "qstandarditemmodel.h"
#include <QAbstractItemModel>

class STPTItemModel : public QAbstractItemModel
{
    Q_OBJECT
    struct STPTStruct{
        QString Name;
        int Latitude;
        int Longtitude;
        int Altitude;
        QStandardItem Action=QStandardItem("");
        QStandardItem Target=QStandardItem("");
    };
public:
    explicit STPTItemModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent=QModelIndex()) const override;
    int columnCount(const QModelIndex &parent=QModelIndex()) const override;
    QModelIndex index(int row,int column,const QModelIndex &parent=QModelIndex()) const override;
private:
    QVector<STPTStruct> STPTData;
};

#endif // STPTITEMMODEL_H
