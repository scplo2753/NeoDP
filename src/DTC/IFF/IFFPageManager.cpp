#include "IFFPageManager.h"

IFFPageManager::IFFPageManager(Ui_NeoDP *ui, QObject *parent) : QObject(parent),
                                                                ui(ui)
{
    /*IFF Stat Group*/
    comboBox_IFF_STATUS = ui->comboBox_IFF_STATUS;
    lineEdit_Stat_Mode_1 = ui->lineEdit_Stat_Mode1;
    lineEdit_Stat_Mode_2 = ui->lineEdit_Stat_Mode2;
    lineEdit_Stat_Mode_3 = ui->lineEdit_Stat_Mode3;
    comboBox_Stat_Mode_4 = ui->comboBox_Stat_Mode4;
    checkBox_Stat_Mode1 = ui->checkBox_Stat_Mode1;
    checkBox_Stat_Mode2 = ui->checkBox_Stat_Mode2;
    checkBox_Stat_Mode3 = ui->checkBox_Stat_Mode3;
    checkBox_Stat_Mode4 = ui->checkBox_Stat_Mode4;
    checkBox_Stat_ModeS = ui->checkBox_Stat_ModeS;
    checkBox_Stat_ModeC = ui->checkBox_Stat_ModeC;

    /*Pos Event Group*/
    comboBox_PosEvent = ui->comboBox_PosEvent;
    comboBox_PosEvent_Direction = ui->comboBox_PosEvent_Direction;
    lineEdit_PosEvent_WayPoint= ui->lineEdit_PosEvent_WayPoint;
    checkBox_PosEvent_Mode1 = ui->checkBox_PosEvent_Mode1;
    checkBox_PosEvent_Mode2 = ui->checkBox_PosEvent_Mode2;
    checkBox_PosEvent_Mode3 = ui->checkBox_PosEvent_Mode3;
    checkBox_PosEvent_Mode4 = ui->checkBox_PosEvent_Mode4;
    checkBox_PosEvent_ModeS = ui->checkBox_PosEvent_ModeS;
    checkBox_PosEvent_ModeC = ui->checkBox_PosEvent_ModeC;

    /*Time Event Group*/
    comboBox_Time_Event = ui->comboBox_TIMEvent;
    comboBox_TIMEvent_Mode4 = ui->comboBox_TIMEvent_Mode4;
    comboBox_TIMEvent_Hour = ui->comboBox_TIMEvent_Hour;
    comboBox_TIMEvent_Minute = ui->comboBox_TIMEvent_Minute;
    lineEdit_TimEvent_Mode1 = ui->lineEdit_TIMEvent_Mode1;
    lineEdit_TimEvent_Mode3 = ui->lineEdit_TIMEvent_Mode3;

    init_Status_Group();
    init_PosEvent_Group();
    init_TimeEvent_Group();
}

IFFPageManager::~IFFPageManager()
{
}

inline void IFFPageManager::init_Status_Group()
{
    comboBox_IFF_STATUS->addItems({"POS", "TIM", "P/T"});
    comboBox_Stat_Mode_4->addItems({"A", "B"});
}

inline void IFFPageManager::init_PosEvent_Group()
{
    comboBox_PosEvent->addItems({"1", "2"});
    comboBox_PosEvent_Direction->addItems({"North", "South", "East", "West"});
}

inline void IFFPageManager::init_TimeEvent_Group()
{
    comboBox_Time_Event->addItems({"1", "2", "3", "4","5","6","7","8","9","10","11","12"});
    comboBox_TIMEvent_Hour->addItems({"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23","---"});
    comboBox_TIMEvent_Minute->addItems({"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59","---"});
    comboBox_TIMEvent_Mode4->addItems({"A", "B"});
}