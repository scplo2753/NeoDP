#ifndef DTC_H
#define DTC_H

#include <QSettings>
#include <QVector>
#include <QMultiMap>
#include <QStringList>

namespace ResourcesPath
{
    const QString Actions = "://Resources/Actions";
    const QString BMS437U6DefaultDTC = "://Resources/4.37.6/4_37_6DefaultDTC.ini";
}

class DTC
{
public:
    DTC();
    ~DTC();

private:
    QSettings *DTCSettings;

    //[STPT]
    QStringList *STPTkeys;

    //[Radio]
    QStringList *UHFkeys;
    QStringList *VHFkeys;
    QStringList *ILSkeys;

    void LoadSTPTKeys();
    void LoadRadioSection();
};

#endif // DTC_H
