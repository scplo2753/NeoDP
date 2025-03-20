#include "L16pageB.h"

L16PageB::L16PageB(Ui_NeoDP *Ui,QHash<QString,QString> *m_L16_Values, QWidget *parent) : L16PageBase(Ui,m_L16_Values,parent)
{
    lineEdit_CS = Ui->lineEdit_L16_PageB_CS;
    lineEdit_CSNumber = Ui->lineEdit_L16_PageB_CSNumber;
    checkBox_Flight_Leader = Ui->checkBox_L16_PageB_Flight_Leader;

    lineEdit_FighterChannel = Ui->lineEdit_L16_PageB_FighterChannel;
    lineEdit_MissionChannel = Ui->lineEdit_L16_PageB_MissionChannel;
    lineEdit_SpecialChannel = Ui->lineEdit_L16_PageB_SpecialChannel;

    lineEdit_TACAN_CHANNEL = Ui->lineEdit_L16_PageB_TACAN_Channel;
    comboBox_TACAN_BAND = Ui->comboBox_L16_PageB_TACAN_BAND;

    lineEdit_VoiceAChannel = Ui->lineEdit_L16_PageB_VoiceAChannel;
    lineEdit_VoiceBChannel = Ui->lineEdit_L16_PageB_VoiceBChannel;

    lineEdit_Flight1 = Ui->lineEdit_L16_PageB_Flight1;
    lineEdit_Flight2 = Ui->lineEdit_L16_PageB_Flight2;
    lineEdit_Flight3 = Ui->lineEdit_L16_PageB_Flight3;
    lineEdit_Flight4 = Ui->lineEdit_L16_PageB_Flight4;

    lineEdit_Team1 = Ui->lineEdit_L16_PageB_Team1;
    lineEdit_Team2 = Ui->lineEdit_L16_PageB_Team2;
    lineEdit_Team3 = Ui->lineEdit_L16_PageB_Team3;
    lineEdit_Team4 = Ui->lineEdit_L16_PageB_Team4;

    lineEdit_Donor1 = Ui->lineEdit_L16_PageB_Donor1;
    lineEdit_Donor2 = Ui->lineEdit_L16_PageB_Donor2;
    lineEdit_Donor3 = Ui->lineEdit_L16_PageB_Donor3;
    lineEdit_Donor4 = Ui->lineEdit_L16_PageB_Donor4;
    lineEdit_Donor5 = Ui->lineEdit_L16_PageB_Donor5;
    lineEdit_Donor6 = Ui->lineEdit_L16_PageB_Donor6;
    lineEdit_Donor7 = Ui->lineEdit_L16_PageB_Donor7;
    lineEdit_Donor8 = Ui->lineEdit_L16_PageB_Donor8;

    initUi();
}

void L16PageB::define_Page()
{
    Page = 'B';
}
