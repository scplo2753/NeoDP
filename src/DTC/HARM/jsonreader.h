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

class JsonReader: public QObject
{
public:
    JsonReader(QObject *parent = nullptr);

    const QHash<QString, ALIC_Struct> getAlicStructureHash() const;

    const QHash<QString, QString> &getAlicToNameMap() const;

    const QHash<QString, QString> &getNameToAlicMap() const;

    QVector<QString> getKeys();

    QVector<QString> getChild(QString parentKey);

private:
    QByteArray loadFile(const QString &file_path);
    void parseJson(const QString &file_path);
    void initAtoN(QString ALIC, QString Name);
    void toAlicHash(QHash<QString, ALIC_Struct> &root, const QJsonObject &samObject);

    QString file_path;
    QVariantMap JsonMap;
    QHash<QString, QString> map_ALIC_Name;
    QHash<QString, QString> map_Name_ALIC;
    QHash<QString, ALIC_Struct> AlicHash;
};

#endif // JSONREADER_H
