#include "harmlistdialog.h"

HarmListDialog::HarmListDialog(const QString &title, JsonReader *JsonReader_ptr, QWidget *parent) : 
QDialog(parent), JsonReaderObj(JsonReader_ptr)
{
    setWindowTitle(title);

    JsonKeys = JsonReaderObj->getKeys();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    SAM_System_Tree = new QTreeWidget();

    mainLayout = new QGridLayout();
    mainLayout->addWidget(buttonBox, 3, 0, 1, 3);
    mainLayout->addWidget(SAM_System_Tree, 0, 0, 3, 3);
    setupDialog();
    setLayout(mainLayout);
}

void HarmListDialog::setupDialog()
{
    setupTree();
    setupButtonBox();
}

void HarmListDialog::setupTree()
{
    SAM_System_Tree->setColumnCount(1);
    SAM_System_Tree->setHeaderHidden(true); 
    for (auto key : JsonKeys)
    {
        SAM_System_Tree->addTopLevelItem(importItem(key));
    }
}

QTreeWidgetItem *HarmListDialog::importItem(QString key)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(SAM_System_Tree);
    item->setText(0, key);
    QVector<QString> child = JsonReaderObj->getChild(key);
    if (!child.empty())
    {
        for (auto temp : child)
        {
            QTreeWidgetItem *childItem = new QTreeWidgetItem(item);
            childItem->setText(0, temp);
            item->addChild(childItem);
        }
    }
    return item;
}

void HarmListDialog::setupButtonBox()
{
}