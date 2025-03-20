#include "L16PageBase.h"
#include <QIntValidator>
#include <QRegularExpressionValidator>

L16PageBase::L16PageBase(Ui_NeoDP *Ui, QHash<QString, QString> *m_L16_Values, QWidget *parent) :
QWidget(parent),
Ui(Ui),
m_L16_Values(m_L16_Values)
{
    // Constructor implementation
}

void L16PageBase::initUi()
{
    initDynamicVariables();
    setupWidget();
    init_lineEdit_of_STNs();
    init_lineEdit_of_Channels();
    init_Misc_Widgets();
}

void L16PageBase::initDynamicVariables()
{
    if (!m_L16_Values)
    {
        qWarning() << "Internal Error: Link-16 QHash Values not found";
        return;
    }

    for (auto itor = m_L16_Values->begin(); itor != m_L16_Values->end(); itor++)
    {
        define_Page();
        QString key = itor.key();
        if (key.startsWith(QString("FILE_%1_").arg(Page)))
        {
            QString dynamicKey = key.mid(7);
            L16_Dynamic_Values[dynamicKey] = key;
        }
    }
}

void L16PageBase::setupWidget()
{
    comboBox_TACAN_BAND->addItems({"X", "Y"});

    auto regExp_CS = new QRegularExpressionValidator(QRegularExpression("^[A-Z]{2}$"), this);
    auto regExp_CSNumber = new QRegularExpressionValidator(QRegularExpression("^([0-9][1-9])$"), this);
    auto regExp_STN = new QRegularExpressionValidator(QRegularExpression("^(?!07777|00177|00176|00077)[0-7]{,5}$"), this);
    auto regExp_MissionChannel = new QIntValidator(0, 127, this);
    QIntValidator *regExp_VoiceChannel = regExp_MissionChannel; // 0-127
    auto regExp_FlightChannel = new QIntValidator(0, 126, this);
    QIntValidator *regExp_SpecialChannel = regExp_FlightChannel; // 0-126
    QIntValidator *regExp_TACAN_CHANNEL = regExp_FlightChannel;  // 0-126

    lineEdit_Flight1->setValidator(regExp_STN);
    lineEdit_Flight2->setValidator(regExp_STN);
    lineEdit_Flight3->setValidator(regExp_STN);
    lineEdit_Flight4->setValidator(regExp_STN);
    lineEdit_Team1->setValidator(regExp_STN);
    lineEdit_Team2->setValidator(regExp_STN);
    lineEdit_Team3->setValidator(regExp_STN);
    lineEdit_Team4->setValidator(regExp_STN);
    lineEdit_Donor1->setValidator(regExp_STN);
    lineEdit_Donor2->setValidator(regExp_STN);
    lineEdit_Donor3->setValidator(regExp_STN);
    lineEdit_Donor4->setValidator(regExp_STN);
    lineEdit_Donor5->setValidator(regExp_STN);
    lineEdit_Donor6->setValidator(regExp_STN);
    lineEdit_Donor7->setValidator(regExp_STN);
    lineEdit_Donor8->setValidator(regExp_STN);

    lineEdit_TACAN_CHANNEL->setValidator(regExp_TACAN_CHANNEL);
    lineEdit_CS->setValidator(regExp_CS);
    lineEdit_CSNumber->setValidator(regExp_CSNumber);
    lineEdit_MissionChannel->setValidator(regExp_MissionChannel);
    lineEdit_FighterChannel->setValidator(regExp_FlightChannel);
    lineEdit_SpecialChannel->setValidator(regExp_SpecialChannel);
    lineEdit_VoiceAChannel->setValidator(regExp_VoiceChannel);
    lineEdit_VoiceBChannel->setValidator(regExp_VoiceChannel);
}

void L16PageBase::init_lineEdit_of_STNs()
{
    QHash<QLineEdit *, QString> bindings = {
        {lineEdit_FighterChannel, L16_Dynamic_Values["FIGHTER_CHANNEL"]},
        {lineEdit_MissionChannel, L16_Dynamic_Values["MISSION_CHANNEL"]},
        {lineEdit_SpecialChannel, L16_Dynamic_Values["SPECIAL_CHANNEL"]},
        {lineEdit_VoiceAChannel, L16_Dynamic_Values["VOICE_GROUP_A_CHANNEL"]},
        {lineEdit_VoiceBChannel, L16_Dynamic_Values["VOICE_GROUP_B_CHANNEL"]},
        {lineEdit_Flight1, L16_Dynamic_Values["FLIGHT_1_STN"]},
        {lineEdit_Flight2, L16_Dynamic_Values["FLIGHT_2_STN"]},
        {lineEdit_Flight3, L16_Dynamic_Values["FLIGHT_3_STN"]},
        {lineEdit_Flight4, L16_Dynamic_Values["FLIGHT_4_STN"]},
        {lineEdit_Team1, L16_Dynamic_Values["TEAM_1_STN"]},
        {lineEdit_Team2, L16_Dynamic_Values["TEAM_2_STN"]},
        {lineEdit_Team3, L16_Dynamic_Values["TEAM_3_STN"]},
        {lineEdit_Team4, L16_Dynamic_Values["TEAM_4_STN"]},
        {lineEdit_Donor1, L16_Dynamic_Values["DONOR_1_STN"]},
        {lineEdit_Donor2, L16_Dynamic_Values["DONOR_2_STN"]},
        {lineEdit_Donor3, L16_Dynamic_Values["DONOR_3_STN"]},
        {lineEdit_Donor4, L16_Dynamic_Values["DONOR_4_STN"]},
        {lineEdit_Donor5, L16_Dynamic_Values["DONOR_5_STN"]},
        {lineEdit_Donor6, L16_Dynamic_Values["DONOR_6_STN"]},
        {lineEdit_Donor7, L16_Dynamic_Values["DONOR_7_STN"]},
        {lineEdit_Donor8, L16_Dynamic_Values["DONOR_8_STN"]}};

    for (auto itor = bindings.begin(); itor != bindings.end(); ++itor)
    {
        QLineEdit *lineEdit_X = itor.key();
        const QString &key = itor.value();
        // init Widget
        if (m_L16_Values->contains(key))
        {
            lineEdit_X->setText(m_L16_Values->value(key));
        }
        connect(lineEdit_X, &QLineEdit::editingFinished, this, [this, key, lineEdit_X]()
                { 
                    QString text = lineEdit_X->text();
                    if (text.length() < 5) {
                        text = text.rightJustified(5, '0');
                        lineEdit_X->setText(text);
                    }
                    (*m_L16_Values)[key] = text; 
                    qDebug() << "Value:" << (*m_L16_Values)[key]; });
    }
}

void L16PageBase::init_lineEdit_of_Channels()
{
    QHash<QLineEdit *, QString> qHashChannels = {
        {lineEdit_VoiceAChannel, L16_Dynamic_Values["VOICE_GROUP_A_CHANNEL"]},
        {lineEdit_VoiceBChannel, L16_Dynamic_Values["VOICE_GROUP_A_CHANNEL"]},
        {lineEdit_MissionChannel, L16_Dynamic_Values["MISSION_CHANNEL"]},
        {lineEdit_FighterChannel, L16_Dynamic_Values["FIGHTER_CHANNEL"]},
        {lineEdit_SpecialChannel, L16_Dynamic_Values["SPECIAL_CHANNEL"]},
        {lineEdit_TACAN_CHANNEL, L16_Dynamic_Values["TACAN_CHANNEL"]}};

    for (auto itor = qHashChannels.begin(); itor != qHashChannels.end(); itor++)
    {
        QString dtcKey = qHashChannels.value(itor.key());
        QLineEdit *itorKey = itor.key();
        if (m_L16_Values->contains(dtcKey))
        {
            itorKey->setText((*m_L16_Values)[dtcKey]);
        }
        connect(itorKey, &QLineEdit::editingFinished, this, [this, itorKey, dtcKey]()
                {
            QString editedText=itorKey->text();
            if(editedText.length()<3)
            {
                editedText=editedText.rightJustified(3,'0');
            }
            (*m_L16_Values)[dtcKey]=editedText; });
    }
}

void L16PageBase::init_Misc_Widgets()
{
    QString &CALLSIGN = L16_Dynamic_Values["CALLSIGN"];
    if (m_L16_Values->contains(CALLSIGN))
    {
        lineEdit_CS->setText(m_L16_Values->value(CALLSIGN));
    }
    connect(lineEdit_CS, &QLineEdit::editingFinished, this, [this, CALLSIGN]()
            { (*m_L16_Values)[CALLSIGN] = lineEdit_CS->text(); });

    QString &CALLSIGN_NUMBER = L16_Dynamic_Values["CALLSIGN_NUMBER"];
    if (m_L16_Values->contains(CALLSIGN_NUMBER))
    {
        lineEdit_CSNumber->setText(m_L16_Values->value(CALLSIGN_NUMBER));
    }
    connect(lineEdit_CSNumber, &QLineEdit::editingFinished, this, [this, CALLSIGN_NUMBER]()
            { (*m_L16_Values)[CALLSIGN_NUMBER] = lineEdit_CSNumber->text(); });

    QString &TACAN_CHANNEL = L16_Dynamic_Values["TACAN_CHANNEL"];
    if (m_L16_Values->contains(TACAN_CHANNEL))
    {
        lineEdit_TACAN_CHANNEL->setText(m_L16_Values->value(TACAN_CHANNEL));
    }
    connect(lineEdit_TACAN_CHANNEL, &QLineEdit::editingFinished, this, [this, TACAN_CHANNEL]()
            {
        QString text = lineEdit_TACAN_CHANNEL->text();
        if (text.length() < 2) {
            text = text.rightJustified(2, '0');
            lineEdit_TACAN_CHANNEL->setText(text);
        }
        (*m_L16_Values)[TACAN_CHANNEL]= lineEdit_TACAN_CHANNEL->text(); });

    QString &FLIGHT_LEADER = L16_Dynamic_Values["FLIGHT_LEAD"];
    connect(checkBox_Flight_Leader, &QCheckBox::clicked, this, [this, FLIGHT_LEADER](bool TF)
            { (*m_L16_Values)[FLIGHT_LEADER] = QString::number(TF); });

    QString &TACAN_BAND = L16_Dynamic_Values["TACAN_BAND"];
    connect(comboBox_TACAN_BAND, &QComboBox::currentTextChanged, this, [this, TACAN_BAND](QString text)
            { (*m_L16_Values)[TACAN_BAND] = text; });
}
