#include "IFFPageManager.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

IFFPageManager::IFFPageManager(Ui_NeoDP *ui, QObject *parent) : QObject(parent),
                                                                ui(ui)
{
    /*IFF Stat Group*/
    comboBox_IFF_STATUS = ui->comboBox_IFF_STATUS;
    spinBox_Stat_Mode1_Tens = ui->spinBox_Stat_Mode1_Tens;
    spinBox_Stat_Mode1_Units = ui->spinBox_Stat_Mode1_Units;
    spinBox_Stat_Mode2_Thousands = ui->spinBox_Stat_Mode2_Thousands;
    spinBox_Stat_Mode2_Hundreds = ui->spinBox_Stat_Mode2_Hundreds;
    spinBox_Stat_Mode2_Tens = ui->spinBox_Stat_Mode2_Tens;
    spinBox_Stat_Mode2_Units = ui->spinBox_Stat_Mode2_Units;
    spinBox_Stat_Mode3A_Thousands = ui->spinBox_Stat_Mode3A_Thousands;
    spinBox_Stat_Mode3A_Hundreds = ui->spinBox_Stat_Mode3A_Hundreds;
    spinBox_Stat_Mode3A_Tens = ui->spinBox_Stat_Mode3A_Tens;
    spinBox_Stat_Mode3A_Units = ui->spinBox_Stat_Mode3A_Units;
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
    spinBox_TIMEvent_Mode1_Tens = ui->spinBox_TIMEvent_Mode1_Tens;
    spinBox_TIMEvent_Mode1_Units = ui->spinBox_TIMEvent_Mode1_Units;
    spinBox_TIMEvent_Mode3A_Thousands = ui->spinBox_TIMEvent_Mode3A_Thousands;
    spinBox_TIMEvent_Mode3A_Hundreds = ui->spinBox_TIMEvent_Mode3A_Hundreds;
    spinBox_TIMEvent_Mode3A_Tens = ui->spinBox_TIMEvent_Mode3A_Tens;
    spinBox_TIMEvent_Mode3A_Units = ui->spinBox_TIMEvent_Mode3A_Units;

    setup_filter();
    connectionManager();

    init_Widgets();
    init_Status_Group_Value();
    comboBox_PosEvent->setCurrentIndex(0);
    init_TimeEvent_Group_Value(0);
    comboBox_Time_Event->setCurrentIndex(0);
    init_PosEvent_Group_Value(0);
}

void IFFPageManager::setup_filter()
{
    QVector<QCheckBox *> checkBoxes_Stat = {checkBox_Stat_Mode1, checkBox_Stat_Mode2, checkBox_Stat_Mode3, checkBox_Stat_Mode4, checkBox_Stat_ModeS, checkBox_Stat_ModeC};
    QVector<QCheckBox *> checkBoxes_PosEvent = {checkBox_PosEvent_Mode1, checkBox_PosEvent_Mode2, checkBox_PosEvent_Mode3, checkBox_PosEvent_Mode4, checkBox_PosEvent_ModeS, checkBox_PosEvent_ModeC};
    for (auto checkBox : checkBoxes_Stat)
    {
        checkBox->installEventFilter(this);
    }
    for (auto checkBox : checkBoxes_PosEvent)
    {
        checkBox->installEventFilter(this);
    }
}

bool IFFPageManager::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QCheckBox *checkBox = qobject_cast<QCheckBox *>(obj);
        if (checkBox)
        {
            QString key;
            if (checkBox == checkBox_Stat_Mode1)
                key = "Mode1 On";
            else if (checkBox == checkBox_Stat_Mode2)
                key = "Mode2 On";
            else if (checkBox == checkBox_Stat_Mode3)
                key = "Mode3A On";
            else if (checkBox == checkBox_Stat_Mode4)
                key = "Mode4 On";
            else if (checkBox == checkBox_Stat_ModeS)
                key = "ModeS On";
            else if (checkBox == checkBox_Stat_ModeC)
                key = "ModeC On";
            else if (checkBox == checkBox_PosEvent_Mode1)
                key = QString("POS %1 Mode1").arg(comboBox_PosEvent->currentText());
            else if (checkBox == checkBox_PosEvent_Mode2)
                key = QString("POS %1 Mode2").arg(comboBox_PosEvent->currentText());
            else if (checkBox == checkBox_PosEvent_Mode3)
                key = QString("POS %1 Mode3A").arg(comboBox_PosEvent->currentText());
            else if (checkBox == checkBox_PosEvent_Mode4)
                key = QString("POS %1 Mode4").arg(comboBox_PosEvent->currentText());
            else if (checkBox == checkBox_PosEvent_ModeS)
                key = QString("POS %1 ModeS").arg(comboBox_PosEvent->currentText());
            else if (checkBox == checkBox_PosEvent_ModeC)
                key = QString("POS %1 ModeC").arg(comboBox_PosEvent->currentText());

            if (!key.isEmpty())
            {
                IFF_Values[key] = QString::number(!checkBox->isChecked());
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void IFFPageManager::connectionManager()
{
    /*Status Group*/
    connect(comboBox_IFF_STATUS, QOverload<int>::of(&QComboBox::currentIndexChanged), [this]()
            { IFF_Values["IFF Status"] = comboBox_IFF_STATUS->currentText(); });
    connect(spinBox_Stat_Mode1_Tens, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode1Digit_Changed);
    connect(spinBox_Stat_Mode1_Units, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode1Digit_Changed);
    connect(spinBox_Stat_Mode2_Thousands, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode2Digit_Changed);
    connect(spinBox_Stat_Mode2_Hundreds, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode2Digit_Changed);
    connect(spinBox_Stat_Mode2_Tens, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode2Digit_Changed);
    connect(spinBox_Stat_Mode2_Units, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode2Digit_Changed);
    connect(spinBox_Stat_Mode3A_Thousands, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode3ADigit_Changed);
    connect(spinBox_Stat_Mode3A_Hundreds, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode3ADigit_Changed);
    connect(spinBox_Stat_Mode3A_Tens, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode3ADigit_Changed);
    connect(spinBox_Stat_Mode3A_Units, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_Mode3ADigit_Changed);
    connect(comboBox_Stat_Mode_4, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int index)
            { IFF_Values["Mode4 Key"] = QString::number(comboBox_Stat_Mode_4->currentIndex()); });

    /*Pos Event Group*/
    connect(lineEdit_PosEvent_WayPoint, &QLineEdit::editingFinished, [this]()
            { IFF_Values[QString("POS %1 WayPoint").arg(comboBox_PosEvent->currentText())] = lineEdit_PosEvent_WayPoint->text(); });
    connect(comboBox_PosEvent, &QComboBox::currentIndexChanged, this, &IFFPageManager::init_PosEvent_Group_Value);
    connect(comboBox_PosEvent_Direction, &QComboBox::currentIndexChanged, this, &IFFPageManager::slot_PosEvent_Direction_Changed);

    /*Time Event Group*/
    connect(comboBox_Time_Event, &QComboBox::currentIndexChanged, this, &IFFPageManager::init_TimeEvent_Group_Value);
    connect(comboBox_TIMEvent_Hour, &QComboBox::currentIndexChanged, [this]()
            { IFF_Values[QString("TIME %1 Criteria").arg(comboBox_Time_Event->currentText())] = QString("%1%2").arg(comboBox_TIMEvent_Hour->currentText(), comboBox_TIMEvent_Minute->currentText()); });
    connect(comboBox_TIMEvent_Minute, &QComboBox::currentIndexChanged, [this]()
            { IFF_Values[QString("TIME %1 Criteria").arg(comboBox_Time_Event->currentText())] = QString("%1%2").arg(comboBox_TIMEvent_Hour->currentText(), comboBox_TIMEvent_Minute->currentText()); });
    connect(spinBox_TIMEvent_Mode1_Tens, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode1Digit_Changed);
    connect(spinBox_TIMEvent_Mode1_Units, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode1Digit_Changed);
    connect(spinBox_TIMEvent_Mode3A_Thousands, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode3Digit_Changed);
    connect(spinBox_TIMEvent_Mode3A_Hundreds, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode3Digit_Changed);
    connect(spinBox_TIMEvent_Mode3A_Tens, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode3Digit_Changed);
    connect(spinBox_TIMEvent_Mode3A_Units, QOverload<int>::of(&QSpinBox::valueChanged), this, &IFFPageManager::on_TIMEvent_Mode3Digit_Changed);
    connect(comboBox_TIMEvent_Mode4, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int index)
            { IFF_Values[QString("TIME %1 Mode4 Key").arg(comboBox_Time_Event->currentText())] = QString::number(comboBox_TIMEvent_Mode4->currentIndex()); });
}

void IFFPageManager::init_Widgets()
{
    /*Status Group*/
    spinBox_Stat_Mode1_Tens->setRange(0, 7);
    spinBox_Stat_Mode1_Units->setRange(0, 3);
    spinBox_Stat_Mode2_Thousands->setRange(0, 7);
    spinBox_Stat_Mode2_Hundreds->setRange(0, 7);
    spinBox_Stat_Mode2_Tens->setRange(0, 7);
    spinBox_Stat_Mode2_Units->setRange(0, 7);
    spinBox_Stat_Mode3A_Thousands->setRange(0, 7);
    spinBox_Stat_Mode3A_Hundreds->setRange(0, 7);
    spinBox_Stat_Mode3A_Tens->setRange(0, 7);
    spinBox_Stat_Mode3A_Units->setRange(0, 7);
    comboBox_IFF_STATUS->addItems({"MAN", "POS", "TIM", "P/T"});
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
    int Mode1 = IFF_Values["Mode1 Code"].toInt();
    spinBox_Stat_Mode1_Tens->setValue(Mode1 / 10);
    spinBox_Stat_Mode1_Units->setValue(Mode1 % 10);
    int Mode2 = IFF_Values["Mode2 Code"].toInt();
    spinBox_Stat_Mode2_Thousands->setValue(Mode2 / 1000);
    spinBox_Stat_Mode2_Hundreds->setValue((Mode2 % 1000) / 100);
    spinBox_Stat_Mode2_Tens->setValue((Mode2 % 100) / 10);
    spinBox_Stat_Mode2_Units->setValue(Mode2 % 10);
    int Mode3A = IFF_Values["Mode3A Code"].toInt();
    spinBox_Stat_Mode3A_Thousands->setValue(Mode3A / 1000);
    spinBox_Stat_Mode3A_Hundreds->setValue((Mode3A % 1000) / 100);
    spinBox_Stat_Mode3A_Tens->setValue((Mode3A % 100) / 10);
    spinBox_Stat_Mode3A_Units->setValue(Mode3A % 10);
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
    int Hour = IFF_Values[QString("TIME %1 Criteria").arg(number)].mid(0, 2).toInt();
    int Minute = IFF_Values[QString("TIME %1 Criteria").arg(number)].mid(2, 2).toInt();
    comboBox_TIMEvent_Hour->setCurrentIndex(Hour);
    comboBox_TIMEvent_Minute->setCurrentIndex(Minute);
    spinBox_TIMEvent_Mode1_Tens->setValue(IFF_Values[QString("TIME %1 Mode1 Code").arg(number)].mid(0, 1).toInt());
    spinBox_TIMEvent_Mode1_Units->setValue(IFF_Values[QString("TIME %1 Mode1 Code").arg(number)].mid(1, 1).toInt());
    spinBox_TIMEvent_Mode3A_Thousands->setValue(IFF_Values[QString("TIME %1 Mode3A Code").arg(number)].mid(0, 1).toInt());
    spinBox_TIMEvent_Mode3A_Hundreds->setValue(IFF_Values[QString("TIME %1 Mode3A Code").arg(number)].mid(1, 1).toInt());
    spinBox_TIMEvent_Mode3A_Tens->setValue(IFF_Values[QString("TIME %1 Mode3A Code").arg(number)].mid(2, 1).toInt());
    spinBox_TIMEvent_Mode3A_Units->setValue(IFF_Values[QString("TIME %1 Mode3A Code").arg(number)].mid(3, 1).toInt());
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
    IFF_Values[QString("POS %1 WayPoint").arg(comboBox_PosEvent->currentText())] = QString::number(index);
    }
}

void IFFPageManager::on_Mode1Digit_Changed()
{
    QString Mode1_Code = QString("%1%2")
                             .arg(spinBox_Stat_Mode1_Tens->value())
                             .arg(spinBox_Stat_Mode1_Units->value());

    IFF_Values["Mode1 Code"] = Mode1_Code;
}

void IFFPageManager::on_Mode2Digit_Changed()
{
    QString Mode2_Code = QString("%1%2%3%4")
                             .arg(spinBox_Stat_Mode2_Thousands->value())
                             .arg(spinBox_Stat_Mode2_Hundreds->value())
                             .arg(spinBox_Stat_Mode2_Tens->value())
                             .arg(spinBox_Stat_Mode2_Units->value());

    IFF_Values["Mode2 Code"] = Mode2_Code;
}

void IFFPageManager::on_Mode3ADigit_Changed()
{
    QString Mode3A_Code = QString("%1%2%3%4")
                              .arg(spinBox_Stat_Mode3A_Thousands->value())
                              .arg(spinBox_Stat_Mode3A_Hundreds->value())
                              .arg(spinBox_Stat_Mode3A_Tens->value())
                              .arg(spinBox_Stat_Mode3A_Units->value());

    IFF_Values["Mode3A Code"] = Mode3A_Code;
}

void IFFPageManager::on_TIMEvent_Mode1Digit_Changed()
{
    QString Mode1_Code = QString("%1%2")
                             .arg(spinBox_TIMEvent_Mode1_Tens->value())
                             .arg(spinBox_TIMEvent_Mode1_Units->value());

    IFF_Values[QString("TIME %1 Mode1 Code").arg(comboBox_Time_Event->currentText())] = Mode1_Code;
}

void IFFPageManager::on_TIMEvent_Mode3Digit_Changed()
{
    QString Mode3A_Code = QString("%1%2%3%4")
                              .arg(spinBox_TIMEvent_Mode3A_Thousands->value())
                              .arg(spinBox_TIMEvent_Mode3A_Hundreds->value())
                              .arg(spinBox_TIMEvent_Mode3A_Tens->value())
                              .arg(spinBox_TIMEvent_Mode3A_Units->value());

    IFF_Values[QString("TIME %1 Mode3A Code").arg(comboBox_Time_Event->currentText())] = Mode3A_Code;
}