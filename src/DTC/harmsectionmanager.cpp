#include "harmsectionmanager.h"
#include "ui_NeoDP.h"

HARMSectionManager::HARMSectionManager(Ui_NeoDP *ui, QObject *parent)
    : QObject{parent},
      ui(ui),
      Mode_ComBox(nullptr),
      SubMode_ComBox(nullptr),
      TerTable_ComBox(nullptr),
    HarmModel(new HarmItemModel())
{
    TerTable_ComBox = ui->TerTable_comBox;
    QStringList TerTableItems = {"1", "2", "3", "0"};
    TerTable_ComBox->addItems(TerTableItems);

    Mode_ComBox = ui->Mode_comBox;
    QStringList ModeItems = {"HAS", "POS"};
    Mode_ComBox->addItems(ModeItems);

    SubMode_ComBox = ui->SubMode_comBox;
    QStringList SubModeItems = {"PB", "EOM", "RUK"};
    SubMode_ComBox->addItems(SubModeItems);
}
