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

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui_NeoDP *ui;
    bool isSTPTWidgetExpanded = false;
    DTC *pDTC;

private slots:
    void on_Exit_pBut_clicked();

    void on_Dock_STPT_pBut_clicked(bool checked);
};
