#pragma once
#include "harmitemmodel.h"
#include "ui_NeoDP.h"
#include "jsonreader.h"

#include <QObject>
#include <QComboBox>
#include <QSortFilterProxyModel>

class HARMSectionManager : public QObject
{
    Q_OBJECT
public:
    explicit HARMSectionManager(Ui_NeoDP *ui,QObject *parent = nullptr);

private:
    Ui_NeoDP *ui;

    QComboBox *Mode_ComBox;
    QComboBox *SubMode_ComBox;
    QComboBox *TerTable_ComBox;

    HarmItemModel *HarmModel;
    JsonReader *JsonReaderObj;
signals:
};
