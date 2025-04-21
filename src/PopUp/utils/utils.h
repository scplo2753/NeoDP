/*
* @brief This file for Pop-Up VRP calculation, formula reference:Multi-Command Handbook 11-F16 Volume 5
*/

#pragma once
#include <QDebug>
#include <cmath>

double get_Horizontal_tracking_distance(const double TAS, const double dive_angle, const double tracking_Time)
{
    return (TAS * std::cos(dive_angle)) * 1.69 * tracking_Time;
}

double get_Vertical_tracking_distance(const double TAS, const double dive_angle, const double tracking_Time)
{
    return TAS * 1.69 * tracking_Time * std::sin(dive_angle);
}

double get_MAP_Distance(const double bomb_range, const double horizontal_tracking_distance)
{
    return bomb_range + horizontal_tracking_distance;
}

double get_Track_point_altitude(const double release_altitude, const double vertical_tracking_distance)
{
    return release_altitude + vertical_tracking_distance;
}

double get_AOD(const double ALT, const double dive_angle, const double bomb_range)
{
    return ALT / std::tan(dive_angle) - bomb_range;
}

double get_Climb_angle(const double dive_angle)
{
    return dive_angle + ((dive_angle <= 15) ? 5 : 10);
}

double get_Angle_off(const double climb_angle)
{
    return 2 * climb_angle;
}

double get_Apex_altitude(const double track_point_altitude, const double dive_G)
{
    if (dive_G >= 3 && dive_G <= 3.5)
    {
        return track_point_altitude + dive_G * 50;
    }
    else if (dive_G >= 4.5 && dive_G < 5)
    {
        return track_point_altitude + dive_G * 37.5;
    }
    else
    {
        qWarning() << "illegal dive G:" << dive_G;
        return 0;
    }
}

double get_Pulldown_altitude(const double apex_alt, const double climb_angle, const double dive_G)
{
    if (dive_G >= 3 && dive_G <= 3.5)
    {
        return apex_alt - (climb_angle * 50);
    }
    else if (dive_G >= 4.5 && dive_G <= 5)
    {
        return apex_alt - (climb_angle * 37.5);
    }
    else
    {
        qWarning("illegal dive G");
        return 0;
    }
}

double get_PopToPull_dist(const double apex_alt, const double climb_angle)
{
    return apex_alt * 60 / climb_angle;
}
