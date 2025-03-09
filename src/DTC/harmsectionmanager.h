#pragma once
#include "ui_NeoDP.h"
#include "jsonreader.h"
#include "harmlistdialog.h"

#include <QObject>
#include <QComboBox>
#include <QSortFilterProxyModel>

class HARMSectionManager : public QObject
{
    Q_OBJECT
public:
    explicit HARMSectionManager(Ui_NeoDP *ui, QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_Mode_ComBox_currentIndexChanged(int index);
    void on_SubMode_ComBox_currentIndexChanged(int index);
    void on_TerTable_ComBox_currentTextChanged();

private:
    void init_DockWidget();
    void initHarmData();
    void setupEventFilters();

    QHash<QString, QString> HARM_ALIC;
    QHash<QString, QString> Map_ALIC_Name;
    QHash<QString, QString> Map_Name_ALIC;
    JsonReader *JsonReaderObj;
    HarmListDialog *HarmListDialogObj;

    Ui_NeoDP *ui;

    QComboBox *comBox_Mode;
    QComboBox *comBox_SubMode;
    QComboBox *comBox_TerTable;

    /*Tr Tab1*/
    QLabel *Threat00_Label;
    QLabel *Threat01_Label;
    QLabel *Threat02_Label;
    QLabel *Threat03_Label;
    QPushButton *Threat00_Button;
    QPushButton *Threat01_Button;
    QPushButton *Threat02_Button;
    QPushButton *Threat03_Button;

    /*Tr Table2*/
    QLabel *Threat10_Label;
    QLabel *Threat11_Label;
    QLabel *Threat12_Label;
    QLabel *Threat13_Label;
    QPushButton *Threat10_Button;
    QPushButton *Threat11_Button;
    QPushButton *Threat12_Button;
    QPushButton *Threat13_Button;

    /*Tr Table3*/
    QLabel *Threat20_Label;
    QLabel *Threat21_Label;
    QLabel *Threat22_Label;
    QLabel *Threat23_Label;
    QPushButton *Threat20_Button;
    QPushButton *Threat21_Button;
    QPushButton *Threat22_Button;
    QPushButton *Threat23_Button;

    QHash<QPushButton *, QPair<QLabel *, QString>> ButtonToThreat;
};
