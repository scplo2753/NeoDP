#ifndef DTCINFO_H
#define DTCINFO_H

#include <QStringList>
namespace DTCInfo
{
    const QStringList Sections = {"Bullseye", "COMMS","EWS","HARM","IFF","LINK16","MAP_POP","MFD","Radio", "STPT"};
    const QString BMS437U6DefaultDTC = "://Resources/4.37.6/4_37_6DefaultDTC.ini";
    const QString STPTSectionPath="://Resources/4.37.6/STPTs.ini";
}
#endif // DTCINFO_H
