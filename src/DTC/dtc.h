#ifndef DTC_H
#define DTC_H

#include "stptitemmodel.h"
#include "stptsortfilterproxymodel.h"
#include "harmitemmodel.h"
#include "ui_NeoDP.h"
#include <QSettings>
#include <QVector>
#include <QMultiMap>
#include <QStringList>
#include <QStandardItemModel>

class DTC:public QObject
{
    Q_OBJECT
public:
    explicit DTC(Ui_NeoDP *ui,QObject *parent=nullptr);
    ~DTC();

private:
    Ui_NeoDP *ui;
    QSettings *DTCSettings;

    //[STPT]
    STPTItemModel *STPTTabModel;
    STPTSortFilterProxyModel *STPTProxyModel;
    QStringList STPTKeys;

    void InitSTPTSection();

private slots:
    void STPTPuButtonClicked(bool checked=false);
    void STPTsubInsPuButtonClicked(bool checked=false);
    void STPTsubLinesPuButtonClicked(bool check=false);
    void STPTsubPPTsPuButtonClicked();
    void STPTsubWPNTPuButtonClicked();
};

#endif // DTC_H
