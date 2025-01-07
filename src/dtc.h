#ifndef DTC_H
#define DTC_H

#include <QSettings>
#include <QVector>
#include <QMultiMap>
class DTC
{
public:
    DTC();
    ~DTC();
private:
    QSettings *STPTset;
    QVector<QString> *STPTActions; //Are SteerPoint's Action, not Qt's Action Func

    void LoadSTPTActions();
    void LoadSTPTSet();
};

#endif // DTC_H
