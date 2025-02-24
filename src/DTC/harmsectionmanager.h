#pragma once
#include <QObject>
#include <QComboBox>
#include <QSortFilterProxyModel>
#include "ui_NeoDP.h"
#include "harmitemmodel.h"

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
signals:
};
