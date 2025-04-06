#pragma once
#include "ui_NeoDP.h"
#include "DTC/dtc.h"

#include <QSpinBox>
#include <QFontComboBox>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QTableView>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui_NeoDP *ui;
    DTC *pDTC;
    //

private slots:
    void STPTPuButtonClicked();
    void STPTsubInsPuButtonClicked();
    void STPTsubLinesPuButtonClicked();
    void STPTsubPPTsPuButtonClicked();
    void STPTsubWPNTPuButtonClicked();

    void Dock_Harm_pButClicked();
    void Dock_IFF_pButCilcked();
    void Dock_L16_pButClicked();

    void on_Exit_pBut_clicked();
};
