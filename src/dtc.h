#ifndef DTC_H
#define DTC_H

#include <QSettings>
class DTC
{
public:
    DTC();
    ~DTC();
private:
    QString strCfg=":/src/4_37_6_Default.ini";
    QSettings *set;
};

#endif // DTC_H
