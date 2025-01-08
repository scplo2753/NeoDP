#ifndef STPTITEMMODEL_H
#define STPTITEMMODEL_H

#include <QStandardItemModel>

class STPTItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit STPTItemModel(QObject *parent = nullptr);
    ~STPTItemModel();
public slots:
    void InsFliter();
    void BullseyeFilter();
    void LinesFilter();
    void PrePlannedFilter();
};

#endif // STPTITEMMODEL_H
