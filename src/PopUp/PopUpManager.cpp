#include <QDebug>
#include "PopUpManager.h"
// #include "utils/utils.h"

PopUpManager::PopUpManager(Ui_NeoDP *ui, QObject *parent)
    : QObject{parent}, ui(ui)
{
    HSlider_Action_Range = ui->horizontalSlider_Action_Range;
    HSlider_Attack_Heading = ui->horizontalSlider_Attack_Heading;
    HSlider_Dive_Angle = ui->horizontalSlider_Dive_Angle;
    HSlider_Pulling_G = ui->horizontalSlider_Pulling_G;
    HSlider_Speed = ui->horizontalSlider_Speed;
    HSlider_Tracking_Time = ui->horizontalSlider_Tracking_Time;
    HSlider_Release_Alt = ui->horizontalSlider_Release_Alt;

    spinBox_Action_Range = ui->spinBox_Action_Range;
    spinBox_Attack_Heading = ui->spinBox_Attack_Heading;
    spinBox_Dive_Angle = ui->spinBox_Dive_Angle;
    doubleSpinBox_Pulling_G = ui->doubleSpinBox_Pulling_G;
    spinBox_Release_Alt = ui->spinBox_Release_Alt;
    spinBox_Speed = ui->spinBox_Speed;
    spinBox_Tracking_Time = ui->spinBox_Tracking_Time;

    spinBox_PopUp_STPT = ui->spinBox_PopUp_STPT;

    m_scene_VIPtoTGT = new QGraphicsScene(this);

    QGraphicsView *graphicsView = ui->graphicsView;
    graphicsView->setScene(m_scene_VIPtoTGT);
    graphicsView->setRenderHint(QPainter::Antialiasing, true);
    graphicsView->setBackgroundBrush(QBrush(Qt::black));

    setupWidgetsLogic();
}

void PopUpManager::setupWidgetsLogic()
{
    setupGraphicsScene();
    connectSlidersAndSpinBoxes();
    setupProfilePropertyLogic();
    setupProfileWidgetsLogic();
    setupInputWidgets();

    connect(spinBox_PopUp_STPT, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]()
            { setSTPT(spinBox_PopUp_STPT->value()); });
}

void PopUpManager::setupGraphicsScene()
{
    m_TextItem_ViPtoTGT = m_scene_VIPtoTGT->addText("VIP to TGT", QFont("Courier", 14));
    m_TextItem_ViPtoTGT->setDefaultTextColor(Qt::green);
    m_TextItem_ViPtoTGT->setPos(0, -80);

    m_TextItem_VIPtoTGT_STPT = m_scene_VIPtoTGT->addText("STPT 1", QFont("Courier", 14));
    m_TextItem_VIPtoTGT_STPT->setDefaultTextColor(Qt::green);
    m_TextItem_VIPtoTGT_STPT->setPos(0, -60);

    m_TextItem_VIPtoTGT_BRG = m_scene_VIPtoTGT->addText("Bearing 180", QFont("Courier", 14));
    m_TextItem_VIPtoTGT_BRG->setDefaultTextColor(Qt::green);
    m_TextItem_VIPtoTGT_BRG->setPos(0, -40);

    m_TextItem_VIPtoTGT_Range = m_scene_VIPtoTGT->addText("Range 1000", QFont("Courier", 14));
    m_TextItem_VIPtoTGT_Range->setDefaultTextColor(Qt::green);
    m_TextItem_VIPtoTGT_Range->setPos(0, -20);
}



void PopUpManager::setupProfileWidgetsLogic()
{
    connect(this, &PopUpManager::gsChanged, this, [this]()
            { ui->label_GS->setText(QString::number(m_GS)); });
    connect(this, &PopUpManager::SpeedChanged, this, [this]()
            { ui->label_Speed->setText(QString::number(m_Speed)); });
    connect(this, &PopUpManager::HorizontalTrackingDistanceChanged, this, [this]()
            { ui->label_HorizontalTrackingDistance->setText(QString::number(m_HorizontalTrackingDistance)); });
    connect(this, &PopUpManager::VerticalTrackingDistanceChanged, this, [this]()
            { ui->label_VerticalTrackingDistance->setText(QString::number(m_VerticalTrackingDistance)); });
    connect(this, &PopUpManager::ClimbAngleChanged, this, [this]()
            { ui->label_ClimbAngle->setText(QString::number(m_ClimbAngle)); });
    connect(this, &PopUpManager::VIPtoTGTBrgChanged, this, [this]()
            { ui->label_VIPtoTGT_BRG->setText(QString::number(m_VIPtoTGT_Brg)); });
}

void PopUpManager::setupProfilePropertyLogic()
{
    for (auto signal : {&PopUpManager::SpeedChanged, &PopUpManager::DiveAngleChanged})
    {
        connect(this, signal, this, [this]()
                { setGS(m_Speed * std::cos(m_DiveAngle * M_PI / 180)); });
    }

    for (auto signal : {&PopUpManager::TrackingTimeChanged, &PopUpManager::SpeedChanged, &PopUpManager::DiveAngleChanged})
    {
        connect(this, signal, this, [this]()
                { setHorizontalTrackingDistance(1.69 * m_GS * m_TrackingTime); 
            setVerticalTrackingDistance((1.69*m_Speed*m_TrackingTime)*std::sin(m_DiveAngle * M_PI / 180)); });
    }

    connect(this, &PopUpManager::DiveAngleChanged, this, [this]()
            { setClimbAngle(m_DiveAngle > 15 ? m_DiveAngle + 10 : m_DiveAngle + 5); });

    //--------------DTC DATA Part----------------
    //@brief save the data to backend values, and emit the signal to update the UI
    connect(this, &PopUpManager::AtkHeadChanged, this, [this]()
            { setVIPtoTGT_Brg((m_AttackHeading + 180) >= 360 ? (m_AttackHeading + 180) - 360 : (m_AttackHeading + 180)); });

    connect(this, &PopUpManager::ApTgtDistanceChanged, this, [this]()
            { setVIPtoTGT_Distance(6089*m_APtoTGTDistance); });
}

void PopUpManager::connectSlidersAndSpinBoxes()
{
    // Attack Heading
    connect(HSlider_Attack_Heading, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Attack_Heading, spinBox_Attack_Heading); 
            setAttackHeading(HSlider_Attack_Heading->value()); });
    connect(spinBox_Attack_Heading, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]()
            { syncSpinBoxWithSlider(spinBox_Attack_Heading, HSlider_Attack_Heading); 
            setAttackHeading(spinBox_Attack_Heading->value()); });

    // Action Range
    connect(HSlider_Action_Range, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Action_Range, spinBox_Action_Range); 
            setAPtoTGTDistance(HSlider_Action_Range->value()); });
    connect(spinBox_Action_Range, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]()
            { syncSpinBoxWithSlider(spinBox_Action_Range, HSlider_Action_Range); 
            setAPtoTGTDistance(spinBox_Action_Range->value()); });

    // Dive Angle
    connect(HSlider_Dive_Angle, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Dive_Angle, spinBox_Dive_Angle); 
            setDiveAngle(HSlider_Dive_Angle->value()); });
    connect(spinBox_Dive_Angle, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]()
            {syncSpinBoxWithSlider(spinBox_Dive_Angle, HSlider_Dive_Angle);
            setDiveAngle(spinBox_Dive_Angle->value()); });

    // Pulling G
    int scaleFactor = 100;
    connect(HSlider_Pulling_G, &QSlider::valueChanged, this, [this, scaleFactor]()
            {
                double value = HSlider_Pulling_G->value() / static_cast<double>(scaleFactor);
                doubleSpinBox_Pulling_G->setValue(value);
                m_PullingG = value; });
    connect(doubleSpinBox_Pulling_G, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [this, scaleFactor]()
            {
                int intValue = static_cast<int>(doubleSpinBox_Pulling_G->value() *
                                                scaleFactor);
                HSlider_Pulling_G->setValue(intValue);
                m_PullingG = doubleSpinBox_Pulling_G->value(); });

    // Speed Input Widget
    connect(HSlider_Speed, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Speed, spinBox_Speed); 
            setSpeed(HSlider_Speed->value()); });
    connect(spinBox_Speed, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]()
            { syncSpinBoxWithSlider(spinBox_Speed, HSlider_Speed); 
            setSpeed(spinBox_Speed->value()); });

    // Tracking Time Input Widget
    connect(HSlider_Tracking_Time, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Tracking_Time, spinBox_Tracking_Time); 
            setTrackingTime(HSlider_Tracking_Time->value()); });
    connect(spinBox_Tracking_Time, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this]()
            { syncSpinBoxWithSlider(spinBox_Tracking_Time, HSlider_Tracking_Time); 
            setTrackingTime(spinBox_Tracking_Time->value()); });

    // Release Alt. Input Widget
    connect(HSlider_Release_Alt, &QSlider::valueChanged, this, [this]()
            { syncSliderWithSpinBox(HSlider_Release_Alt, spinBox_Release_Alt); });

    connect(spinBox_Release_Alt, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this]()
            { syncSpinBoxWithSlider(spinBox_Release_Alt, HSlider_Release_Alt); });
}

void PopUpManager::setupInputWidgets()
{
    spinBox_PopUp_STPT->setRange(1, 99);

    spinBox_Attack_Heading->setRange(0, 360);
    spinBox_Action_Range->setRange(1, 5);
    spinBox_Speed->setRange(300, 500);
    doubleSpinBox_Pulling_G->setRange(2.0f, 6.0f);
    spinBox_Dive_Angle->setRange(10, 45);
    spinBox_Tracking_Time->setRange(1, 10);
    spinBox_Release_Alt->setRange(300, 4000);

    HSlider_Attack_Heading->setRange(0, 360);
    HSlider_Action_Range->setRange(1, 5);
    HSlider_Speed->setRange(300, 500);
    HSlider_Dive_Angle->setRange(10, 45);
    HSlider_Tracking_Time->setRange(1, 10);
    HSlider_Release_Alt->setRange(300, 4000);
    int scaleFactor = 100;
    HSlider_Pulling_G->setRange(2.0 * scaleFactor, 6.0 * scaleFactor);
}

void PopUpManager::updateVipToTgtSTPTText()
{
    if (m_TextItem_VIPtoTGT_STPT)
    {
        m_TextItem_VIPtoTGT_STPT->setPlainText(QString("STPT %1").arg(m_STPT));
    }
}

void PopUpManager::updateVipToTgtBearingText()
{
    if (m_TextItem_VIPtoTGT_BRG)
    {
        m_TextItem_VIPtoTGT_BRG->setPlainText(QString("Bearing %1").arg(m_VIPtoTGT_Brg));
    }
}

void PopUpManager::updateVipToTgtDistanceText()
{
    if (m_TextItem_VIPtoTGT_Range)
    {
        m_TextItem_VIPtoTGT_Range->setPlainText(QString("Range %1").arg(m_VIPtoTGT_Range));
    }
}

void PopUpManager::syncSliderWithSpinBox(QSlider *slider, QSpinBox *spinBox)
{
    spinBox->setValue(slider->value());
}

void PopUpManager::syncSpinBoxWithSlider(QSpinBox *spinBox, QSlider *slider)
{
    slider->setValue(spinBox->value());
}

//------------------- 
void PopUpManager::setSTPT(int value)
{
    if(m_STPT != value)
    {
        m_STPT = value;
        ui->label_PopUp_STPT->setText(QString::number(spinBox_PopUp_STPT->value()));
        emit StptChanged();
        updateVipToTgtSTPTText();
    }
}

void PopUpManager::setSpeed(int value)
{
    if (m_Speed != value)
    {
        m_Speed = value;
        emit SpeedChanged();
    }
}

void PopUpManager::setGS(int value)
{
    if (m_GS != value)
    {
        m_GS = value;
        emit gsChanged();
    }
}

void PopUpManager::setDiveAngle(int value)
{
    if (m_DiveAngle != value)
    {
        m_DiveAngle = value;
        emit DiveAngleChanged();
    }
}

void PopUpManager::setAttackHeading(int value)
{
    if (m_AttackHeading != value)
    {
        m_AttackHeading = value;
        emit AtkHeadChanged();
    }
}

void PopUpManager::setAPtoTGTDistance(int value)
{
    if (m_APtoTGTDistance != value)
    {
        m_APtoTGTDistance = value;
        emit ApTgtDistanceChanged();
    }
}

void PopUpManager::setTrackingTime(int value)
{
    if (m_TrackingTime != value)
    {
        m_TrackingTime = value;
        emit TrackingTimeChanged();
    }
}

void PopUpManager::setHorizontalTrackingDistance(double value)
{
    if (m_HorizontalTrackingDistance != value)
    {
        m_HorizontalTrackingDistance = value;
        emit HorizontalTrackingDistanceChanged();
    }
}

void PopUpManager::setVerticalTrackingDistance(double value)
{
    if (m_VerticalTrackingDistance != value)
    {
        m_VerticalTrackingDistance = value;
        emit VerticalTrackingDistanceChanged();
    }
}

void PopUpManager::setClimbAngle(int value)
{
    if (m_ClimbAngle != value)
    {
        m_ClimbAngle = value;
        emit ClimbAngleChanged();
    }
}

//------------------------------------

void PopUpManager::setVIPtoTGT_Brg(int value)
{
    if (m_VIPtoTGT_Brg != value)
    {
        m_VIPtoTGT_Brg = value;
        emit VIPtoTGTBrgChanged();
        updateVipToTgtBearingText();
    }
}

void PopUpManager::setVIPtoTGT_Distance(int value)
{
    if (m_VIPtoTGT_Range!= value)
    {
        m_VIPtoTGT_Range = value;
        emit VIPtoTGTDistanceChanged();
        updateVipToTgtDistanceText();
    }
}