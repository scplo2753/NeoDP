#pragma once
#include "STPT/stptitemmodel.h"
#include "STPT/stptsortfilterproxymodel.h"
#include "HARM/harmsectionmanager.h"
#include "IFF/iffpagemanager.h"
#include "ui_NeoDP.h"
#include <QSettings>
#include <QVector>
#include <QMultiMap>
#include <QStringList>
#include <QStandardItemModel>

class DTC : public QObject
{
    Q_OBJECT
public:
    explicit DTC(Ui_NeoDP *ui, QObject *parent = nullptr);
    ~DTC();

private:
    Ui_NeoDP *ui;
    QSettings *DTCSettings;

    //[STPT]
    STPTItemModel *STPTTabModel;
    STPTSortFilterProxyModel *STPTProxyModel;
    QStringList STPTKeys;

    //[HARM]
    HARMSectionManager *HarmManager;

    //[IFF]
    IFFPageManager *IFFManagerObj;

    void InitSTPTSection();

private slots:
    void STPTPuButtonClicked(bool checked = false);
    void STPTsubInsPuButtonClicked(bool checked = false);
    void STPTsubLinesPuButtonClicked(bool checked = false);
    void STPTsubPPTsPuButtonClicked();
    void STPTsubWPNTPuButtonClicked();

    void Dock_Harm_pButClicked();
    void Dock_IFF_pButCilcked();
};