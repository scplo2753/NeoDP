#ifndef HARMLISTDIALOG_H
#define HARMLISTDIALOG_H

#include "jsonreader.h"
#include <QDialog>
#include <QObject>
#include <QListWidget>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QTreeWidget>

class HarmListDialog : public QDialog
{
    Q_OBJECT
public:
    HarmListDialog(const QString &title,JsonReader *JsonReader_ptr, QWidget *parent);


private:
    QTreeWidget *SAM_System_Tree;
    QGridLayout *mainLayout;
    QDialogButtonBox *buttonBox;

    JsonReader *JsonReaderObj;
    QVector<QString> JsonKeys;

    void setupDialog();
    void setupTree();
    void setupButtonBox();
    QTreeWidgetItem *importItem(QString key);
};

#endif // HARMLISTDIALOG_H
