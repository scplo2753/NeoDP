#pragma once
#include "ui_NeoDP.h"
#include "DTC/dtc.h"
#include "DTC/stptsortfilterproxymodel.h"
#include <QSpinBox>
#include <QFontComboBox>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QTableView>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui_NeoDP *ui;
    bool isSTPTWidgetExpanded = false;
    STPTSortFilterProxyModel* STPTProxyModel;
    DTC *pDTC;

private slots:
    void on_Exit_pBut_clicked();

    void on_Dock_STPT_pBut_clicked();
    void on_STPT_sub_INS_pBut_clicked();
    void on_STPT_sub_Lines_pBut_clicked();
    void on_STPT_sub_PPTs_pBut_clicked();
    void on_pushButton_3_clicked();
};
