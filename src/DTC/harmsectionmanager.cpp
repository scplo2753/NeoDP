#include "harmsectionmanager.h"

HARMSectionManager::HARMSectionManager(Ui_NeoDP *ui, QObject *parent)
    : QObject{parent},
      ui(ui),
      comBox_Mode(nullptr),
      comBox_SubMode(nullptr),
      comBox_TerTable(nullptr),
      JsonReaderObj(new JsonReader),
      HarmListDialogObj(nullptr)
{
  QWidget *parentWidget = qobject_cast<QWidget *>(parent);

  Map_ALIC_Name = JsonReaderObj->getMap_ALIC_Name();
  Map_Name_ALIC = JsonReaderObj->getMap_Name_ALIC();

  HarmListDialogObj = new HarmListDialog(tr("Select an SAM system"), JsonReaderObj, parentWidget);

  comBox_TerTable = ui->comBox_TerTable;
  QStringList TerTableItems = {"1", "2", "3", "0"};
  comBox_TerTable->addItems(TerTableItems);

  comBox_Mode = ui->comBox_Mode;
  QStringList ModeItems = {"HAS", "POS"};
  comBox_Mode->addItems(ModeItems);

  comBox_SubMode = ui->comBox_SubMode;
  QStringList SubModeItems = {"PB", "EOM", "RUK"};
  comBox_SubMode->addItems(SubModeItems);

  Threat00_Label = ui->lbl_TrTab00;
  Threat01_Label = ui->lbl_TrTab01;
  Threat02_Label = ui->lbl_TrTab02;
  Threat03_Label = ui->lbl_TrTab03;
  Threat00_Button = ui->btn_TrTab00;
  Threat01_Button = ui->btn_TrTab01;
  Threat02_Button = ui->btn_TrTab02;
  Threat03_Button = ui->btn_TrTab03;

  Threat10_Label = ui->lbl_TrTab10;
  Threat11_Label = ui->lbl_TrTab11;
  Threat12_Label = ui->lbl_TrTab12;
  Threat13_Label = ui->lbl_TrTab13;
  Threat10_Button = ui->btn_TrTab10;
  Threat11_Button = ui->btn_TrTab11;
  Threat12_Button = ui->btn_TrTab12;
  Threat13_Button = ui->btn_TrTab13;

  Threat20_Label = ui->lbl_TrTab20;
  Threat21_Label = ui->lbl_TrTab21;
  Threat22_Label = ui->lbl_TrTab22;
  Threat23_Label = ui->lbl_TrTab23;
  Threat20_Button = ui->btn_TrTab20;
  Threat21_Button = ui->btn_TrTab21;
  Threat22_Button = ui->btn_TrTab22;
  Threat23_Button = ui->btn_TrTab23;

  ButtonToThreat = {{Threat00_Button, QPair<QLabel *, QString>(Threat00_Label, "THREAT 0 0")},
                    {Threat01_Button, QPair<QLabel *, QString>(Threat01_Label, "THREAT 0 1")},
                    {Threat02_Button, QPair<QLabel *, QString>(Threat02_Label, "THREAT 0 2")},
                    {Threat03_Button, QPair<QLabel *, QString>(Threat03_Label, "THREAT 0 3")},
                    {Threat10_Button, QPair<QLabel *, QString>(Threat10_Label, "THREAT 1 0")},
                    {Threat11_Button, QPair<QLabel *, QString>(Threat11_Label, "THREAT 1 1")},
                    {Threat12_Button, QPair<QLabel *, QString>(Threat12_Label, "THREAT 1 2")},
                    {Threat13_Button, QPair<QLabel *, QString>(Threat13_Label, "THREAT 1 3")},
                    {Threat20_Button, QPair<QLabel *, QString>(Threat20_Label, "THREAT 2 0")},
                    {Threat21_Button, QPair<QLabel *, QString>(Threat21_Label, "THREAT 2 1")},
                    {Threat22_Button, QPair<QLabel *, QString>(Threat22_Label, "THREAT 2 2")},
                    {Threat23_Button, QPair<QLabel *, QString>(Threat23_Label, "THREAT 2 3")}};

  connect(comBox_Mode, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &HARMSectionManager::on_Mode_ComBox_currentIndexChanged);
  connect(comBox_SubMode, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &HARMSectionManager::on_SubMode_ComBox_currentIndexChanged);
  connect(comBox_TerTable, &QComboBox::currentTextChanged, this, &HARMSectionManager::on_TerTable_ComBox_currentTextChanged);

  init_DockWidget();
  setupEventFilters();
}

inline void HARMSectionManager::initHarmData()
{
  HARM_ALIC["THREAT 0 0"] = "0202";
  HARM_ALIC["THREAT 0 1"] = "0203";
  HARM_ALIC["THREAT 0 2"] = "0204";
  HARM_ALIC["THREAT 0 3"] = "0205";
  HARM_ALIC["THREAT 0 4"] = "0210";
  HARM_ALIC["THREAT 1 0"] = "0402";
  HARM_ALIC["THREAT 1 1"] = "0403";
  HARM_ALIC["THREAT 1 2"] = "0404";
  HARM_ALIC["THREAT 1 3"] = "0405";
  HARM_ALIC["THREAT 1 4"] = "0410";
  HARM_ALIC["THREAT 2 0"] = "0106";
  HARM_ALIC["THREAT 2 1"] = "0608";
  HARM_ALIC["THREAT 2 2"] = "0111";
  HARM_ALIC["THREAT 2 3"] = "0615";
  HARM_ALIC["THREAT 2 4"] = "0117";
  HARM_ALIC["MODE"] = "1";
  HARM_ALIC["SUBMODE"] = "0";
  HARM_ALIC["TER"] = "0";
}

inline void HARMSectionManager::init_DockWidget()
{
  initHarmData();

  Threat00_Label->setText(HARM_ALIC["THREAT 0 0"]);
  Threat01_Label->setText(HARM_ALIC["THREAT 0 1"]);
  Threat02_Label->setText(HARM_ALIC["THREAT 0 2"]);
  Threat03_Label->setText(HARM_ALIC["THREAT 0 3"]);
  Threat00_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 0 0"]]);
  Threat01_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 0 1"]]);
  Threat02_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 0 2"]]);
  Threat03_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 0 3"]]);

  Threat10_Label->setText(HARM_ALIC["THREAT 1 0"]);
  Threat11_Label->setText(HARM_ALIC["THREAT 1 1"]);
  Threat12_Label->setText(HARM_ALIC["THREAT 1 2"]);
  Threat13_Label->setText(HARM_ALIC["THREAT 1 3"]);
  Threat10_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 1 0"]]);
  Threat11_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 1 1"]]);
  Threat12_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 1 2"]]);
  Threat13_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 1 3"]]);

  Threat20_Label->setText(HARM_ALIC["THREAT 2 0"]);
  Threat21_Label->setText(HARM_ALIC["THREAT 2 1"]);
  Threat22_Label->setText(HARM_ALIC["THREAT 2 2"]);
  Threat23_Label->setText(HARM_ALIC["THREAT 2 3"]);
  Threat20_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 2 0"]]);
  Threat21_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 2 1"]]);
  Threat22_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 2 2"]]);
  Threat23_Button->setText(Map_ALIC_Name[HARM_ALIC["THREAT 2 3"]]);
}

void HARMSectionManager::setupEventFilters()
{
  QVector<QPushButton *> buttons = {Threat00_Button, Threat01_Button, Threat02_Button, Threat03_Button,
                                    Threat10_Button, Threat11_Button, Threat12_Button, Threat13_Button,
                                    Threat20_Button, Threat21_Button, Threat22_Button, Threat23_Button};
  for (auto button : buttons)
  {
    button->installEventFilter(this);
  }
}

bool HARMSectionManager::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseButtonPress)
  {
    QPushButton *button = qobject_cast<QPushButton *>(obj);
    if (button)
    {
      if (HarmListDialogObj->exec() == QDialog::Accepted)
      {
        button->setText(HarmListDialogObj->getSelectedKey());
        QString &ALIC = Map_Name_ALIC[HarmListDialogObj->getSelectedKey()];
        QPair<QLabel *, QString> &ButtonNum = ButtonToThreat[button];
        HARM_ALIC[ButtonNum.second] = ALIC;
        ButtonNum.first->setText(ALIC);
      }
      return true;
    }
  }
  return QObject::eventFilter(obj, event);
}

/*connect QComBox to slots*/
void HARMSectionManager::on_Mode_ComBox_currentIndexChanged(int index)
{
  HARM_ALIC["MODE"] = QString::number(index);
  qDebug() << "Mode: " << HARM_ALIC["MODE"];
}

void HARMSectionManager::on_SubMode_ComBox_currentIndexChanged(int index)
{
  HARM_ALIC["SUBMODE"] = QString::number(index);
  qDebug() << "SubMode: " << HARM_ALIC["SUBMODE"];
}

void HARMSectionManager::on_TerTable_ComBox_currentTextChanged()
{
  HARM_ALIC["TER"] = comBox_TerTable->currentText();
  qDebug() << "Ter: " << HARM_ALIC["TER"];
}