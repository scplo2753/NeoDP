#include "harmlistdialog.h"

HarmListDialog::HarmListDialog(const QString &title, JsonReader *JsonReader_ptr, QWidget *parent) : QDialog(parent), JsonReaderObj(JsonReader_ptr)
{
    setWindowTitle(title);

    JsonKeys = JsonReaderObj->getKeys();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
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
}

void HarmListDialog::setupTree()
{
    SAM_System_Tree->setColumnCount(1);
    SAM_System_Tree->setHeaderHidden(true);
    for (auto key : JsonKeys)
    {
        SAM_System_Tree->addTopLevelItem(importItem(key));
    }

    /*inital slots*/
    connect(SAM_System_Tree, &QTreeWidget::itemSelectionChanged, this, &HarmListDialog::onSelectionChanged);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &HarmListDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &HarmListDialog::reject);
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

void HarmListDialog::onSelectionChanged()
{
    QTreeWidgetItem *item = SAM_System_Tree->currentItem();
    if (item)
    {
        selectedKey=item->text(0);
        QHash<QString,QString> map_ALIC_Name=JsonReaderObj->getMap_ALIC_Name();
        selectedALIC=map_ALIC_Name[selectedKey];
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else
    {
        selectedKey.clear();
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void HarmListDialog::accept()
{
    QDialog::accept();
}

void HarmListDialog::reject()
{
    selectedKey.clear();
    QDialog::reject();
}