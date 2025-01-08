#include "dtc.h"
#include <QSettings>
#include <QTextStream>
#include <QVector>
#include <QFile>
#include <QStringList>

DTC::DTC()
{
    LoadSTPTActions();
    LoadSTPTSet();
}

DTC::~DTC()
{

}

void DTC::LoadSTPTActions()
{
    QString FilePath=":/COMMON/Resource/Actions"; //Write to Settings.ini for the Future
    QFile ActionsFile(FilePath);
    if(ActionsFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&ActionsFile);
            int &&LineCount=in.readLine().toInt();
            STPTActions=new QVector<QString>();
            STPTActions->reserve(LineCount);
            while (!in.atEnd()) {
            STPTActions->push_back(in.readLine());
            }
    }
}

void DTC::LoadSTPTSet()
{
    QString FilePath=":/4_37_6_DTC/Resource/4.37.6/STPTs.ini";
    STPTset=new QSettings(FilePath,QSettings::IniFormat) ;
    STPTset->beginGroup("STPT");
    STPTkeys=new QStringList(STPTset->allKeys());
}
