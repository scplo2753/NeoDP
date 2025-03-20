#include "L16PageManager.h"

L16PageManager::L16PageManager(Ui_NeoDP *Ui, QObject *parent) : QObject(parent),
                                                                Ui(Ui)
{
    pageA = new L16PageA(Ui, &L16_Values, qobject_cast<QWidget *>(this));
    pageB = new L16PageB(Ui, &L16_Values, qobject_cast<QWidget *>(this));
}
