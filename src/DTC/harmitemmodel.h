#pragma once
#include <QAbstractTableModel>
class HarmItemModel : public QAbstractTableModel
{
public:
    explicit HarmItemModel(QObject *parent = nullptr);
    ~HarmItemModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void initHARMData()
    {
        HARMData["THREAT 0 0"] = "0202";
        HARMData["THREAT 0 1"] = "0203";
        HARMData["THREAT 0 2"] = "0204";
        HARMData["THREAT 0 3"] = "0205";
        HARMData["THREAT 0 4"] = "0210";
        HARMData["THREAT 1 0"] = "0402";
        HARMData["THREAT 1 1"] = "0403";
        HARMData["THREAT 1 2"] = "0404";
        HARMData["THREAT 1 3"] = "0405";
        HARMData["THREAT 1 4"] = "0410";
        HARMData["THREAT 2 0"] = "0106";
        HARMData["THREAT 2 1"] = "0608";
        HARMData["THREAT 2 2"] = "0111";
        HARMData["THREAT 2 3"] = "0615";
        HARMData["THREAT 2 4"] = "0117";
        HARMData["MODE"] = "1";
        HARMData["SUBMODE"] = "0";
        HARMData["TER"] = "0";

        HARMKeys = HARMData.keys();
    };
    const HarmItemModel *getHarmItemModelptr() const;

private:
    QHash<QString, QString> HARMData;
    QList<QString> HARMKeys;
};
