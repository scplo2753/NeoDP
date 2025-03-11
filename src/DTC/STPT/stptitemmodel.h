#ifndef STPTITEMMODEL_H
#define STPTITEMMODEL_H

#include <QAbstractTableModel>

struct STPTStruct
{
    QString Name;
    qreal Latitude;
    qreal Longitude;
    qreal Altitude;
    QString Action;
    QString Target;

    void clear()
    {
        Name = QString();
        Latitude = qreal();
        Longitude = qreal();
        Altitude -= qreal();
        Action = QString();
        Target = QString();
    }
};

namespace STPTInfo
{
    const int STPTRowCount = 42;
    const int STPTColumnCount = 6;
    const QVector<QString> STPTActions = {
        "Nav",
        "TakeOff",
        "Push",
        "Split",
        "Refuel",
        "Rearm",
        "PickUp",
        "Land",
        "Holding",
        "CASCAP",
        "Escort",
        "Sweep",
        "CAP",
        "Intrcpt",
        "GNDStrk",
        "NAVStrk",
        "SD",
        "Strike",
        "Bomb",
        "SEAD",
        "ELINT",
        "RECON",
        "Rescue",
        "ASW",
        "Tanker",
        "Airdrop",
        "JAM",
        "Land 2",
        "B5",
    };
    const QVector<QString> STPTHeader = {"Steering Point", "Latitude", "Longtitude", "Altitude", "Action/Range", "Target"};
}

class STPTItemModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit STPTItemModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void appendRow(const STPTStruct rowContent);
    const STPTItemModel *getPtr() const;

private:
    QVector<STPTStruct> STPTData;
};

#endif // STPTITEMMODEL_H
