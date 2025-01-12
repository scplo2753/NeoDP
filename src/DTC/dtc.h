#ifndef DTC_H
#define DTC_H

#include "stptitemmodel.h"
#include <QSettings>
#include <QVector>
#include <QMultiMap>
#include <QStringList>
#include <QStandardItemModel>

class DTC
{
public:
    DTC();
    ~DTC();
    STPTItemModel* getSTPTTabModel() const;

private:
    QSettings *DTCSettings;

    //[STPT]
    QStringList STPTKeys;
    QStringList TGTKeys;
    QStringList LinesKeys;
    STPTItemModel *STPTTabModel;

    //[Radio]
    QStringList UHFkeys;
    QStringList VHFkeys;
    QStringList ILSkeys;
    QStandardItemModel *RadioItemModel;

    void LoadSTPTSection();
    void LoadRadioSection();
};

#endif // DTC_H
