#include "dtc.h"
#include "../Common/DTCInfo.h"
#include "stptitemmodel.h"
#include <QSettings>
#include <QTextStream>
#include <QStringView>
#include <QVector>
#include <QFile>
#include <QStringList>
#include <QDebug>

DTC::DTC()
	:DTCSettings(new QSettings(DTCInfo::BMS437U6DefaultDTC, QSettings::IniFormat))
{
	LoadSTPTSection();
}

DTC::~DTC()
{
}

void DTC::LoadSTPTSection()
{
	STPTTabModel = new STPTItemModel();

	DTCSettings->beginReadArray("STPT");
	STPTKeys = QStringList(DTCSettings->allKeys());
	STPTStruct STPTrow;
	QStringList values;
	for (auto& i : STPTKeys)
	{
		STPTrow.clear();
		values.clear();
		STPTrow.Name = i;
		values = DTCSettings->value(i).value<QStringList>();
		STPTrow.Latitude = values[0].toDouble();
		STPTrow.Longtitude = values[1].toDouble();
		STPTrow.Altitude = values[2].toDouble();
		if (values.size() > 3)
		{
			STPTrow.Action = values[3];
			STPTrow.Target = values[4];
		}
		STPTTabModel->appendRow(STPTrow);
	}
	DTCSettings->endArray();
}

STPTItemModel* DTC::getSTPTTabModel() const
{
	return STPTTabModel;
}
