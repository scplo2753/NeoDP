#pragma once
#include "ui_NeoDP.h"
#include "L16PageA.h"
#include "L16PageB.h"
#include <QObject>
class L16PageManager : public QObject
{
    Q_OBJECT
public:
    L16PageManager(Ui_NeoDP *Ui, QObject *parent = nullptr);
    //void set_Values(QHash<QString,QString> L16_Values);
    //QHash<QString,QString> get_Values();

private:
    Ui_NeoDP *Ui;
    L16PageA *pageA;
    L16PageB *pageB;

    QHash<QString, QString> L16_Values = {
        {"FILE_A_VOICE_GROUP_A_CHANNEL", "000"},
        {"FILE_A_VOICE_GROUP_B_CHANNEL", "000"},
        {"FILE_A_MISSION_CHANNEL", "125"},
        {"FILE_A_FIGHTER_CHANNEL", "085"},
        {"FILE_A_SPECIAL_CHANNEL", "-01"},
        {"FILE_A_CALLSIGN", "RT"},
        {"FILE_A_CALLSIGN_NUMBER", "21"},
        {"FILE_A_FLIGHT_LEAD", "1"},
        {"FILE_A_EXT_TIME_REFERENCE", "0"},
        {"FILE_A_TACAN_CHANNEL", "00"},
        {"FILE_A_TACAN_BAND", "X"},
        {"FILE_A_FLIGHT_1_STN", "25531"},
        {"FILE_A_FLIGHT_2_STN", "00000"},
        {"FILE_A_FLIGHT_3_STN", "00000"},
        {"FILE_A_FLIGHT_4_STN", "00000"},
        {"FILE_A_TEAM_1_STN", "00000"},
        {"FILE_A_TEAM_2_STN", "00000"},
        {"FILE_A_TEAM_3_STN", "00000"},
        {"FILE_A_TEAM_4_STN", "00000"},
        {"FILE_A_DONOR_1_STN", "00000"},
        {"FILE_A_DONOR_2_STN", "00000"},
        {"FILE_A_DONOR_3_STN", "00000"},
        {"FILE_A_DONOR_4_STN", "00000"},
        {"FILE_A_DONOR_5_STN", "00000"},
        {"FILE_A_DONOR_6_STN", "00000"},
        {"FILE_A_DONOR_7_STN", "00000"},
        {"FILE_A_DONOR_8_STN", "00000"},
        {"FILE_B_VOICE_GROUP_A_CHANNEL", "000"},
        {"FILE_B_VOICE_GROUP_B_CHANNEL", "000"},
        {"FILE_B_MISSION_CHANNEL", "000"},
        {"FILE_B_FIGHTER_CHANNEL", "000"},
        {"FILE_B_SPECIAL_CHANNEL", "000"},
        {"FILE_B_CALLSIGN", ""},
        {"FILE_B_CALLSIGN_NUMBER", "00"},
        {"FILE_B_FLIGHT_LEAD", "0"},
        {"FILE_B_EXT_TIME_REFERENCE", "0"},
        {"FILE_B_TACAN_CHANNEL", "00"},
        {"FILE_B_TACAN_BAND", "X"},
        {"FILE_B_FLIGHT_1_STN", "00000"},
        {"FILE_B_FLIGHT_2_STN", "00000"},
        {"FILE_B_FLIGHT_3_STN", "00000"},
        {"FILE_B_FLIGHT_4_STN", "00000"},
        {"FILE_B_TEAM_1_STN", "00000"},
        {"FILE_B_TEAM_2_STN", "00000"},
        {"FILE_B_TEAM_3_STN", "00000"},
        {"FILE_B_TEAM_4_STN", "00000"},
        {"FILE_B_DONOR_1_STN", "00000"},
        {"FILE_B_DONOR_2_STN", "00000"},
        {"FILE_B_DONOR_3_STN", "00000"},
        {"FILE_B_DONOR_4_STN", "00000"},
        {"FILE_B_DONOR_5_STN", "00000"},
        {"FILE_B_DONOR_6_STN", "00000"},
        {"FILE_B_DONOR_7_STN", "00000"},
        {"FILE_B_DONOR_8_STN", "00000"}};
};
