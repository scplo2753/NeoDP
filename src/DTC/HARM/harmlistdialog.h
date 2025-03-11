#ifndef HARMLISTDIALOG_H
#define HARMLISTDIALOG_H

#include "jsonreader.h"
#include <QDialog>
#include <QObject>
#include <QListWidget>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QTreeWidget>
#include <QPushButton>

class HarmListDialog : public QDialog
{
    Q_OBJECT
public:
    HarmListDialog(const QString &title, JsonReader *JsonReader_ptr, QWidget *parent);
    QString getSelectedKey() const { return selectedKey; }
    QString getSelectedALIC() const { return selectedALIC; }

private slots:
    void accept();
    void reject();
    void onSelectionChanged();

private:
    QTreeWidget *SAM_System_Tree;
    QGridLayout *mainLayout;
    QDialogButtonBox *buttonBox;

    JsonReader *JsonReaderObj;
    QVector<QString> JsonKeys;

    QString selectedKey;
    QString selectedALIC;

    void setupDialog();
    void setupTree();
    QTreeWidgetItem *importItem(QString key);
};

#endif // HARMLISTDIALOG_H
