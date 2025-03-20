#ifndef L16PAGEB_H
#define L16PAGEB_H

#include <QObject>
#include "L16PageBase.h"

class L16PageB : public L16PageBase
{
public:
    explicit L16PageB(Ui_NeoDP *Ui,QHash<QString,QString> *m_L16_Values, QWidget *parent = nullptr);
protected:
    void define_Page() override;
};

#endif // L16PAGEB_H
