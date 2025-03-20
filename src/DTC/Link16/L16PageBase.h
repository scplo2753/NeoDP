#pragma once
#include "ui_NeoDP.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QComboBox>
#include <QCheckBox>
#include <QWidget>

// Abstract class for L16 pages
class L16PageBase : public QWidget
{
    Q_OBJECT
public:
    explicit L16PageBase(Ui_NeoDP *Ui, QHash<QString, QString> *m_L16_Values, QWidget *parent = nullptr);
    virtual ~L16PageBase() = default;

protected: // Functions
    virtual void define_Page() = 0;
    void initUi();
    void setupWidget();
    void initDynamicVariables();
    void init_lineEdit_of_STNs();
    void init_lineEdit_of_Channels();
    void init_Misc_Widgets();

protected: // Variables
    char Page;

    Ui_NeoDP *Ui;

    QHash<QString, QString> *m_L16_Values;
    QHash<QString, QString> L16_Dynamic_Values;

    QLineEdit *lineEdit_VoiceAChannel;
    QLineEdit *lineEdit_VoiceBChannel;

    QLineEdit *lineEdit_FighterChannel;
    QLineEdit *lineEdit_MissionChannel;
    QLineEdit *lineEdit_SpecialChannel;

    QLineEdit *lineEdit_CS;
    QLineEdit *lineEdit_CSNumber;
    QCheckBox *checkBox_Flight_Leader;

    QComboBox *comboBox_TACAN_BAND;
    QLineEdit *lineEdit_TACAN_CHANNEL;

    QLineEdit *lineEdit_Flight1;
    QLineEdit *lineEdit_Flight2;
    QLineEdit *lineEdit_Flight3;
    QLineEdit *lineEdit_Flight4;

    QLineEdit *lineEdit_Team1;
    QLineEdit *lineEdit_Team2;
    QLineEdit *lineEdit_Team3;
    QLineEdit *lineEdit_Team4;

    QLineEdit *lineEdit_Donor1;
    QLineEdit *lineEdit_Donor2;
    QLineEdit *lineEdit_Donor3;
    QLineEdit *lineEdit_Donor4;
    QLineEdit *lineEdit_Donor5;
    QLineEdit *lineEdit_Donor6;
    QLineEdit *lineEdit_Donor7;
    QLineEdit *lineEdit_Donor8;
};
