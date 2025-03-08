#ifndef JSONREADER_H
#define JSONREADER_H
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

struct ALIC_Struct
{
    QString Name;
    QString ALIC_Code;
    QString Code;
    QSharedPointer<QHash<QString, ALIC_Struct>> Child = nullptr;
};

class JsonReader
{
public:
    JsonReader();

    const QSharedPointer<QHash<QString, ALIC_Struct>> getAlicHash() const;

    const QHash<QString, QString> &getMap_ALIC_Name() const;

    const QHash<QString, QString> &getMap_Name_ALIC() const;

    QVector<QString> getKeys();

    QVector<QString> getChild(QString key);

private:
    QByteArray loadFile(const QString &file_path);
    void parseJson(const QString &file_path);
    void initAtoN(QString ALIC, QString Name);
    void toAlicHash(const QSharedPointer<QHash<QString, ALIC_Struct>> &root, const QJsonObject &samObject);

    QString file_path;
    QVariantMap JsonMap;
    QHash<QString, QString> map_ALIC_Name;
    QHash<QString, QString> map_Name_ALIC;
    QSharedPointer<QHash<QString, ALIC_Struct>> AlicHash = QSharedPointer<QHash<QString, ALIC_Struct>>(new QHash<QString, ALIC_Struct>);
};

#endif // JSONREADER_H
