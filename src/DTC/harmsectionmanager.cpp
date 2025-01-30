#include "harmsectionmanager.h"
#include "ui_NeoDP.h"

HARMSectionManager::HARMSectionManager(Ui_NeoDP *ui, QObject *parent)
    : QObject{parent},
      ui(ui),
      Mode_ComBox(nullptr),
      SubMode_ComBox(nullptr),
      TerTable_ComBox(nullptr),
      HARMTer1_View(nullptr),
      HARMTer1_ProxyModel(new QSortFilterProxyModel()),
      HARMTer2_View(nullptr),
      HARMTer2_ProxyModel(new QSortFilterProxyModel()),
      HARMTer3_View(nullptr),
      HARMTer3_ProxyModel(new QSortFilterProxyModel()),
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

    HARMTer1_View = ui->HARMTer1_View;
    HARMTer2_View = ui->HARMTer2_View;
    HARMTer3_View = ui->HARMTer3_View;

    HARMTer1_ProxyModel.setSourceModel(HarmModel);
    HARMTer1_ProxyModel.setFilterRegularExpression("^THREAT 0");
    HARMTer1_View->setModel(&HARMTer1_ProxyModel);
    HARMTer1_View->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    HARMTer1_View->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    HARMTer2_ProxyModel.setSourceModel(HarmModel);
    HARMTer2_ProxyModel.setFilterRegularExpression("^THREAT 1");
    HARMTer2_View->setModel(&HARMTer2_ProxyModel);
    HARMTer2_View->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    HARMTer2_View->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    HARMTer3_ProxyModel.setSourceModel(HarmModel);
    HARMTer3_ProxyModel.setFilterRegularExpression("^THREAT 2");
    HARMTer3_View->setModel(&HARMTer3_ProxyModel);
    //HARMTer3_View->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //HARMTer3_View->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}
