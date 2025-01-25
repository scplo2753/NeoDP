#ifndef STPTITEMMODEL_H
#define STPTITEMMODEL_H

#include "qstandarditemmodel.h"
#include <QAbstractTableModel>

struct STPTStruct{
    QString Name;
    qreal Latitude;
    qreal Longitude;
    qreal Altitude;
    QString Action;
    QString Target;

    void clear()
    {
        Name=QString();
        Latitude=qreal();
        Longitude=qreal();
        Altitude-=qreal();
        Action=QString();
        Target=QString();
    }
};

class STPTItemModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit STPTItemModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const override;
    QVariant headerData(int section,Qt::Orientation orientation,int role=Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent=QModelIndex()) const override;
    int columnCount(const QModelIndex &parent=QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void appendRow(const STPTStruct rowContent);
    const STPTItemModel* getPtr()const;
private:
    QVector<STPTStruct> STPTData;
};

#endif // STPTITEMMODEL_H
