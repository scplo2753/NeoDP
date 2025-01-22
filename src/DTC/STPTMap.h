#ifndef STPTMAP_H
#define STPTMAP_H
#include <QHash>
#include <QDebug>

class STPTMap
{
private:
    QHash<QString,int> STPTmaps;

    STPTMap()
    {
        //target_01 ~ target_23
        for(int i=0;i<=23;i++)
            STPTmaps[QString("target_%1").arg(i)]=i+1;

        //lineSTPT_0 ~ lineSTPT_23
        for(int i=0;i<=23;i++)
            STPTmaps[QString("lineSTPT_%1").arg(i)]=i+31;

        //ppt_0 ~ ppt_14
        for(int i=0;i<=14;i++)
            STPTmaps[QString("ppt_%1").arg(i)]=i+56;

        //target_80 ~ target_98
        for(int i=0;i<=18;i++)
            STPTmaps[QString("target_%1").arg(i+80)]=i+81;

        for(int i=0;i<=99;i++)
            STPTmaps[QString("wpntarget_%1").arg(i)]=i+100;
    }
    ~STPTMap()=default;

    STPTMap(const STPTMap&);
    STPTMap& operator=(const STPTMap&);
public:
    static STPTMap &instance()
    {
        static STPTMap instance;
        return instance;
    }

    int getSTPTIndex(QString &key)
    {
        if(STPTmaps.contains(key))
        {
            return STPTmaps.value(key);
        }
        else
        {
            qWarning()<<"Key not found";
            return -1;
        }
    }
};

#endif // STPTMAP_H
