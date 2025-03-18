#include "L16PageBase.h"
#include <QIntValidator>
#include <QRegExp>
#include <QRegularExpressionValidator>

L16PageBase::L16PageBase(QWidget *parent) : QWidget(parent)
{
    // Constructor implementation
}

void L16PageBase::setupUi(QWidget *parent)
{
    // setupUi implementation
}

void L16PageBase::setupWidget()
{
    comboBox_TACAN_BAND->addItems({"X", "Y"});
    auto regExp_TACAN_CHANNEL = new QIntValidator(1, 126, this);

    auto regExp_CS = new QRegularExpressionValidator(QRegularExpression("[A-Z]{2}"), this);
    auto regExp_CSNumber = new QRegularExpressionValidator(QRegularExpression("[1-9][1-4]"), this);
    auto regExp_STN= new QRegularExpressionValidator(QRegularExpression("^(?!07777|00177|00176|00077)[0-7]{5}"), this);
    auto regExp_MissionChannel = new QIntValidator(0, 127, this);
    QIntValidator *regExp_FighterChannel=regExp_MissionChannel;
}
