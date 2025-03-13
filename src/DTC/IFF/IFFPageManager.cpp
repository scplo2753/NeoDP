#include "IFFPageManager.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

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
    lineEdit_PosEvent_WayPoint = ui->lineEdit_PosEvent_WayPoint;
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
    lineEdit_TIMEvent_Mode1 = ui->lineEdit_TIMEvent_Mode1;
    lineEdit_TIMEvent_Mode3 = ui->lineEdit_TIMEvent_Mode3;

    connectionManager();

    init_Widgets();
    init_Status_Group_Value();
    comboBox_PosEvent->setCurrentIndex(0);
    init_TimeEvent_Group_Value(0);
    comboBox_Time_Event->setCurrentIndex(0);
    init_PosEvent_Group_Value(0);
}

IFFPageManager::~IFFPageManager()
{
}

void IFFPageManager::connectionManager()
{
    /*Pos Event Group*/
    connect(lineEdit_PosEvent_WayPoint, &QLineEdit::editingFinished, [this]()
            { IFF_Values[QString("POS %1 WayPoint").arg(comboBox_PosEvent->currentText())] = lineEdit_PosEvent_WayPoint->text(); });
    connect(checkBox_PosEvent_Mode1, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 Mode1").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_Mode1->isChecked()); });
    connect(checkBox_PosEvent_Mode2, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 Mode2").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_Mode2->isChecked()); });
    connect(checkBox_PosEvent_Mode3, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 Mode3A").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_Mode3->isChecked()); });
    connect(checkBox_PosEvent_Mode4, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 Mode4").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_Mode4->isChecked()); });
    connect(checkBox_PosEvent_ModeS, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 ModeS").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_ModeS->isChecked()); });
    connect(checkBox_PosEvent_ModeC, &QCheckBox::stateChanged, [this]()
            { IFF_Values[QString("POS %1 ModeC").arg(comboBox_PosEvent->currentText())] = QString::number(checkBox_PosEvent_ModeC->isChecked()); });

    /*Time Event Group*/
    connect(comboBox_Time_Event, &QComboBox::currentIndexChanged, this, &IFFPageManager::init_TimeEvent_Group_Value);
    connect(comboBox_PosEvent, &QComboBox::currentIndexChanged, this, &IFFPageManager::init_PosEvent_Group_Value);
    connect(comboBox_PosEvent_Direction, &QComboBox::currentIndexChanged, this, &IFFPageManager::slot_PosEvent_Direction_Changed);
    connect(comboBox_TIMEvent_Hour, &QComboBox::currentIndexChanged, [this]()
            { IFF_Values[QString("TIME %1 Criteria").arg(comboBox_Time_Event->currentText())] = QString("%1%2").arg(comboBox_TIMEvent_Hour->currentText(),comboBox_TIMEvent_Minute->currentText()); });
    connect(comboBox_TIMEvent_Minute, &QComboBox::currentIndexChanged, [this]()
            { IFF_Values[QString("TIME %1 Criteria").arg(comboBox_Time_Event->currentText())] = QString("%1%2").arg(comboBox_TIMEvent_Hour->currentText(),comboBox_TIMEvent_Minute->currentText()); });
}

void IFFPageManager::init_Widgets()
{
    /*Status Group*/
    comboBox_IFF_STATUS->addItems({"POS", "TIM", "P/T"});
    comboBox_Stat_Mode_4->addItems({"A", "B"});

    /*Pos Event Group*/
    auto RegExp_WayPoint = new QIntValidator(1, 99);
    lineEdit_PosEvent_WayPoint->setValidator(RegExp_WayPoint);
    comboBox_PosEvent->addItems({"1", "2"});
    comboBox_PosEvent_Direction->addItems({"--", "North", "South", "East", "West"});

    /*Time Event Group*/
    comboBox_Time_Event->addItems({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"});
    comboBox_TIMEvent_Hour->addItems({"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "---"});
    comboBox_TIMEvent_Minute->addItems({"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "---"});
    comboBox_TIMEvent_Mode4->addItems({"A", "B"});
}

void IFFPageManager::init_Status_Group_Value()
{
    comboBox_IFF_STATUS->setCurrentIndex(IFF_Values["AutoChange"].toInt());
    checkBox_Stat_Mode1->setChecked(IFF_Values["Mode1 On"].toInt());
    checkBox_Stat_Mode2->setChecked(IFF_Values["Mode2 On"].toInt());
    checkBox_Stat_Mode3->setChecked(IFF_Values["Mode3A On"].toInt());
    checkBox_Stat_Mode4->setChecked(IFF_Values["Mode4 On"].toInt());
    checkBox_Stat_ModeS->setChecked(IFF_Values["ModeS On"].toInt());
    checkBox_Stat_ModeC->setChecked(IFF_Values["ModeC On"].toInt());
    lineEdit_Stat_Mode_1->setText(IFF_Values["Mode1 Code"]);
    lineEdit_Stat_Mode_2->setText(IFF_Values["Mode2 Code"]);
    lineEdit_Stat_Mode_3->setText(IFF_Values["Mode3A Code"]);
    comboBox_Stat_Mode_4->setCurrentIndex(IFF_Values["Mode4 Key"].toInt());
}

void IFFPageManager::init_PosEvent_Group_Value(int number)
{
    comboBox_PosEvent->setCurrentIndex(number);
    comboBox_PosEvent_Direction->setCurrentIndex(IFF_Values[QString("POS %1 Direction").arg(number)].toInt());
    int WayPoint = IFF_Values[QString("POS %1 WayPoint").arg(number)].toInt();
    if (WayPoint == 0)
    {
        lineEdit_PosEvent_WayPoint->setEnabled(false);
        lineEdit_PosEvent_WayPoint->setText("---");
    }
    else
    {
        lineEdit_PosEvent_WayPoint->setEnabled(true);
        lineEdit_PosEvent_WayPoint->setText(QString::number(WayPoint));
    }
    checkBox_PosEvent_Mode1->setChecked(IFF_Values[QString("POS %1 Mode1").arg(number)].toInt());
    checkBox_PosEvent_Mode2->setChecked(IFF_Values[QString("POS %1 Mode2").arg(number)].toInt());
    checkBox_PosEvent_Mode3->setChecked(IFF_Values[QString("POS %1 Mode3A").arg(number)].toInt());
    checkBox_PosEvent_Mode4->setChecked(IFF_Values[QString("POS %1 Mode4").arg(number)].toInt());
    checkBox_PosEvent_ModeS->setChecked(IFF_Values[QString("POS %1 ModeS").arg(number)].toInt());
    checkBox_PosEvent_ModeC->setChecked(IFF_Values[QString("POS %1 ModeC").arg(number)].toInt());
}

void IFFPageManager::init_TimeEvent_Group_Value(int number)
{
    int Hour = IFF_Values[QString("TIME %1 Criteria").arg(number)].sliced(0, 2).toInt();
    int Minute = IFF_Values[QString("TIME %1 Criteria").arg(number)].sliced(2, 2).toInt();
    comboBox_TIMEvent_Hour->setCurrentIndex(Hour);
    comboBox_TIMEvent_Minute->setCurrentIndex(Minute);
    lineEdit_TIMEvent_Mode1->setText(IFF_Values[QString("TIME %1 Mode1 Code").arg(number)]);
    lineEdit_TIMEvent_Mode3->setText(IFF_Values[QString("TIME %1 Mode3A Code").arg(number)]);
    comboBox_TIMEvent_Mode4->setCurrentIndex(IFF_Values[QString("TIME %1 Mode4 Key").arg(number)].toInt());
}

void IFFPageManager::slot_PosEvent_Direction_Changed(int index)
{
    if (index == 0)
    {
        lineEdit_PosEvent_WayPoint->setEnabled(false);
        lineEdit_PosEvent_WayPoint->setText("---");
    }
    else if (lineEdit_PosEvent_WayPoint->isEnabled() == false)
    {
        lineEdit_PosEvent_WayPoint->setEnabled(true);
        lineEdit_PosEvent_WayPoint->setText("1");
    }
}