#pragma once
#include "ui_NeoDP.h"
#include <QObject>
#include <QObject>
#include <QSlider>
#include <QSpinBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>

class PopUpManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int STPT MEMBER m_STPT WRITE setSTPT NOTIFY StptChanged)
    Q_PROPERTY(int Speed MEMBER m_Speed WRITE setSpeed NOTIFY SpeedChanged)
    Q_PROPERTY(int GS MEMBER m_GS WRITE setGS NOTIFY gsChanged)
    Q_PROPERTY(int DiveAngle MEMBER m_DiveAngle WRITE setDiveAngle NOTIFY DiveAngleChanged)
    Q_PROPERTY(int AttackHeading MEMBER m_AttackHeading WRITE setAttackHeading NOTIFY AtkHeadChanged)
    Q_PROPERTY(int ApTgtDistance MEMBER m_APtoTGTDistance WRITE setAPtoTGTDistance NOTIFY ApTgtDistanceChanged)
    Q_PROPERTY(double PullingG MEMBER m_PullingG NOTIFY PullingGChanged)
    Q_PROPERTY(int ReleaseAlt MEMBER m_ReleaseAlt NOTIFY ReleaseAltChanged)
    Q_PROPERTY(int OffsetAngle MEMBER m_OffsetAngle NOTIFY OffsetAngleChanged)
    Q_PROPERTY(int TrackingTime MEMBER m_TrackingTime WRITE setTrackingTime NOTIFY TrackingTimeChanged)

    Q_PROPERTY(double HorizontalTrackingDistance MEMBER m_HorizontalTrackingDistance WRITE setHorizontalTrackingDistance NOTIFY HorizontalTrackingDistanceChanged)
    Q_PROPERTY(double VerticalTrackingDistance MEMBER m_VerticalTrackingDistance WRITE setVerticalTrackingDistance NOTIFY VerticalTrackingDistanceChanged)
    Q_PROPERTY(int ClimbAngle MEMBER m_ClimbAngle WRITE setClimbAngle NOTIFY ClimbAngleChanged)

    Q_PROPERTY(int VIPtoTGT_Brg MEMBER m_VIPtoTGT_Brg WRITE setVIPtoTGT_Brg NOTIFY VIPtoTGTBrgChanged)
    Q_PROPERTY(int VIPtoTGT_Range MEMBER m_VIPtoTGT_Range WRITE setVIPtoTGT_Distance NOTIFY VIPtoTGTDistanceChanged)

public:
    explicit PopUpManager(Ui_NeoDP *ui, QObject *parent = nullptr);

private slots:
    void syncSliderWithSpinBox(QSlider *slider, QSpinBox *spinBox);
    void syncSpinBoxWithSlider(QSpinBox *spinBox, QSlider *slider);
    void setClimbAngle(int value);
    void setVIPtoTGT_Brg(int value);
    void setVIPtoTGT_Distance(int value);

private: // functions
    void setupWidgetsLogic();
    void setupGraphicsScene();
    void setupProfileWidgetsLogic();
    void setupProfilePropertyLogic();
    void connectSlidersAndSpinBoxes();
    void setupInputWidgets();


    //DTC DATA Part
    void updateVipToTgtSTPTText();
    void updateVipToTgtBearingText();
    void updateVipToTgtDistanceText();
    //-----------------

    // Setters for properties
    void setSTPT(int value);
    void setSpeed(int value);
    void setGS(int value);
    void setDiveAngle(int value);
    void setAttackHeading(int value);
    void setAPtoTGTDistance(int value);
    void setTrackingTime(int value);
    void setHorizontalTrackingDistance(double value);
    void setVerticalTrackingDistance(double value);

private: // Values
    Ui_NeoDP *ui;

    int m_STPT = 1;
    int m_Speed = 300; // TAS
    int m_DiveAngle = 10;
    int m_GS = 295;
    int m_AttackHeading = 0;
    int m_APtoTGTDistance = 0;
    double m_PullingG = 0.0f;
    int m_ReleaseAlt = 0;
    int m_OffsetAngle = 0;
    int m_TrackingTime = 0;

    double m_HorizontalTrackingDistance = 0;
    double m_VerticalTrackingDistance = 0;
    int m_ClimbAngle = 15;

    int m_VIPtoTGT_Brg = 0;
    int m_VIPtoTGT_Range = 0;

    QSlider *HSlider_Attack_Heading, *HSlider_Action_Range, *HSlider_Speed, *HSlider_Pulling_G, *HSlider_Tracking_Time, *HSlider_Dive_Angle, *HSlider_Release_Alt;
    QSpinBox *spinBox_Action_Range, *spinBox_Attack_Heading, *spinBox_Dive_Angle, *spinBox_Release_Alt, *spinBox_Speed, *spinBox_Tracking_Time;
    QDoubleSpinBox *doubleSpinBox_Pulling_G;
    QSpinBox *spinBox_PopUp_STPT;

    QGraphicsScene *m_scene_VIPtoTGT;
    QGraphicsTextItem *m_TextItem_ViPtoTGT;
    QGraphicsTextItem *m_TextItem_VIPtoTGT_STPT;
    QGraphicsTextItem *m_TextItem_VIPtoTGT_BRG;
    QGraphicsTextItem *m_TextItem_VIPtoTGT_Range;

    QGraphicsScene *m_scene_VRPtoTGT;
    QGraphicsTextItem *m_TextItem_VRPtoTGT;
    QGraphicsTextItem *m_TextItem_VRPtoTGT_STPT;
    QGraphicsTextItem *m_TextItem_VRPtoTGT_BRG;
    QGraphicsTextItem *m_TextItem_VRPtoTGT_Range;

signals:
    void StptChanged();
    void SpeedChanged();
    void gsChanged();
    void DiveAngleChanged();
    void AtkHeadChanged();
    void ApTgtDistanceChanged();
    void PullingGChanged();
    void ReleaseAltChanged();
    void OffsetAngleChanged();
    void TrackingTimeChanged();
    void HorizontalTrackingDistanceChanged();
    void VerticalTrackingDistanceChanged();
    void ClimbAngleChanged();
    void VIPtoTGTBrgChanged();
    void VIPtoTGTDistanceChanged();
};
