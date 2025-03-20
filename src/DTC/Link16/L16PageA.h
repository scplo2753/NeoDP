#pragma once
#include "L16PageBase.h"
#include "ui_NeoDP.h"

class L16PageA : public L16PageBase
{
    Q_OBJECT
public:
    explicit L16PageA(Ui_NeoDP *Ui,QHash<QString,QString> *m_L16_Values, QWidget *parent = nullptr);
    ~L16PageA() override = default;

protected: //Functions
    void setupUi();
    void define_Page() override;
};
