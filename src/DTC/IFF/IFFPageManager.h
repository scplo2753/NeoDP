#pragma once
#include "ui_NeoDP.h"
#include <QHash>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
class IFFPageManager : public QObject
{
    Q_OBJECT
public:
    IFFPageManager(Ui_NeoDP *ui, QObject *parent = nullptr);
    ~IFFPageManager();

private slots:
    void init_TimeEvent_Group_Value(int number);
    void init_PosEvent_Group_Value(int number);
    void slot_PosEvent_Direction_Changed(int index);

private: // Methods
    void connectionManager();
    void init_Widgets();
    void init_Status_Group_Value();

private: // Members
    Ui_NeoDP *ui;

    /*IFF Stat Group*/
    QComboBox *comboBox_IFF_STATUS;
    QLineEdit *lineEdit_Stat_Mode_1;
    QLineEdit *lineEdit_Stat_Mode_2;
    QLineEdit *lineEdit_Stat_Mode_3;
    QComboBox *comboBox_Stat_Mode_4;
    QCheckBox *checkBox_Stat_Mode1;
    QCheckBox *checkBox_Stat_Mode2;
    QCheckBox *checkBox_Stat_Mode3;
    QCheckBox *checkBox_Stat_Mode4;
    QCheckBox *checkBox_Stat_ModeS;
    QCheckBox *checkBox_Stat_ModeC;

    /*Pos Event Group*/
    QComboBox *comboBox_PosEvent;
    QComboBox *comboBox_PosEvent_Direction;
    QLineEdit *lineEdit_PosEvent_WayPoint;
    QCheckBox *checkBox_PosEvent_Mode1;
    QCheckBox *checkBox_PosEvent_Mode2;
    QCheckBox *checkBox_PosEvent_Mode3;
    QCheckBox *checkBox_PosEvent_Mode4;
    QCheckBox *checkBox_PosEvent_ModeS;
    QCheckBox *checkBox_PosEvent_ModeC;

    /*Time Event Group*/
    QComboBox *comboBox_Time_Event;
    QComboBox *comboBox_TIMEvent_Hour;
    QComboBox *comboBox_TIMEvent_Minute;
    QLineEdit *lineEdit_TIMEvent_Mode1;
    QLineEdit *lineEdit_TIMEvent_Mode3;
    QComboBox *comboBox_TIMEvent_Mode4;

    /*----------------Values-----------------*/
    QHash<QString, QString> IFF_Values = {
        {"Mode1 On", "1"},
        {"Mode2 On", "1"},
        {"Mode3A On", "0"},
        {"Mode4 On", "1"},
        {"ModeC On", "0"},
        {"ModeS On", "0"},
        {"Mode1 Code", "11"},
        {"Mode2 Code", "7004"},
        {"Mode3A Code", "3554"},
        {"Mode4 Key", "1"},
        {"AutoChange", "2"},
        {"TIME 0 Mode1 Code", "02"},
        {"TIME 0 Mode3A Code", "5754"},
        {"TIME 0 Mode4 Key", "1"},
        {"TIME 0 Criteria", "0900"},
        {"TIME 1 Mode1 Code", "52"},
        {"TIME 1 Mode3A Code", "5654"},
        {"TIME 1 Mode4 Key", "1"},
        {"TIME 1 Criteria", "1000"},
        {"TIME 2 Mode1 Code", "11"},
        {"TIME 2 Mode3A Code", "6430"},
        {"TIME 2 Mode4 Key", "1"},
        {"TIME 2 Criteria", "1100"},
        {"TIME 3 Mode1 Code", "10"},
        {"TIME 3 Mode3A Code", "5354"},
        {"TIME 3 Mode4 Key", "1"},
        {"TIME 3 Criteria", "1200"},
        {"TIME 4 Mode1 Code", "12"},
        {"TIME 4 Mode3A Code", "3654"},
        {"TIME 4 Mode4 Key", "1"},
        {"TIME 4 Criteria", "1300"},
        {"TIME 5 Mode1 Code", "12"},
        {"TIME 5 Mode3A Code", "7304"},
        {"TIME 5 Mode4 Key", "1"},
        {"TIME 5 Criteria", "1400"},
        {"TIME 6 Mode1 Code", "50"},
        {"TIME 6 Mode3A Code", "2454"},
        {"TIME 6 Mode4 Key", "1"},
        {"TIME 6 Criteria", "1500"},
        {"TIME 7 Mode1 Code", "10"},
        {"TIME 7 Mode3A Code", "5454"},
        {"TIME 7 Mode4 Key", "1"},
        {"TIME 7 Criteria", "1600"},
        {"TIME 8 Mode1 Code", "13"},
        {"TIME 8 Mode3A Code", "4654"},
        {"TIME 8 Mode4 Key", "1"},
        {"TIME 8 Criteria", "1700"},
        {"TIME 9 Mode1 Code", "73"},
        {"TIME 9 Mode3A Code", "0154"},
        {"TIME 9 Mode4 Key", "1"},
        {"TIME 9 Criteria", "1800"},
        {"TIME 10 Mode1 Code", "33"},
        {"TIME 10 Mode3A Code", "5204"},
        {"TIME 10 Mode4 Key", "1"},
        {"TIME 10 Criteria", "1900"},
        {"TIME 11 Mode1 Code", "30"},
        {"TIME 11 Mode3A Code", "3704"},
        {"TIME 11 Mode4 Key", "1"},
        {"TIME 11 Criteria", "2000"},
        {"POS 0 Mode1", "1"},
        {"POS 0 Mode2", "1"},
        {"POS 0 Mode3A", "0"},
        {"POS 0 Mode4", "1"},
        {"POS 0 ModeC", "0"},
        {"POS 0 ModeS", "0"},
        {"POS 0 WayPoint", " 1"},
        {"POS 0 Direction", "01"},
        {"POS 1 Mode1", "1"},
        {"POS 1 Mode2", "1"},
        {"POS 1 Mode3A", "0"},
        {"POS 1 Mode4", "1"},
        {"POS 1 ModeC", "1"},
        {"POS 1 ModeS", "1"},
        {"POS 1 WayPoint", " 2"},
        {"POS 1 Direction", "02"}};
};