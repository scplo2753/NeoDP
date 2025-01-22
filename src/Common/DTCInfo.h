#ifndef DTCINFO_H
#define DTCINFO_H

#include <QStringList>
namespace DTCInfo
{
    const QStringList Sections = {"Bullseye", "COMMS","EWS","HARM","IFF","LINK16","MAP_POP","MFD","Radio", "STPT"};
    const QString BMS437U6DefaultDTC = "://Resources/4.37.6/4_37_6DefaultDTC.ini";
    namespace STPTInfo
    {
        const QString STPTSectionPath="://Resources/4.37.6/STPTs.ini";
        const int STPTRowCount = 42;
        const int STPTColumnCount = 6;
        const QVector<QString> STPTActions = {
            "Nav",
            "TakeOff",
            "Push",
            "Split",
            "Refuel",
            "Rearm",
            "PickUp",
            "Land",
            "Holding",
            "CASCAP",
            "Escort",
            "Sweep",
            "CAP",
            "Intrcpt",
            "GNDStrk",
            "NAVStrk",
            "SD",
            "Strike",
            "Bomb",
            "SEAD",
            "ELINT",
            "RECON",
            "Rescue",
            "ASW",
            "Tanker",
            "Airdrop",
            "JAM",
            "Land 2",
            "B5",
        };
        const QVector<QString> STPTHeader = {"Steering Point", "Latitude", "Longtitude", "Altitude", "Action/Range", "Target"};
    }
}
#endif // DTCINFO_H
