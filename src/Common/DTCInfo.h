#ifndef DTCINFO_H
#define DTCINFO_H

#include <QStringList>
namespace STPTInfo
{
    const int STPT_TargetCount = 42;
    const int STPT_TargetColumnCount = 5;
    const QStringList STPTActions = {
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
    const QStringList STPTHeader={"Steering Point","Latitude","Longtitude","Altitude","Action","Target"};
}
#endif // DTCINFO_H
