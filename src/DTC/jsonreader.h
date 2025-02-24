#ifndef JSONREADER_H
#define JSONREADER_H
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QSharedPointer>
#include <QHash>

struct ALIC_Struct
{
    QString Name;
    int ALIC_Code;
    QString Code;
    QSharedPointer<QHash<QString,ALIC_Struct>> Child = nullptr;
};

class JsonReader
{
public:
    JsonReader();
    void JsonDebugger();
private:
    QByteArray loadFile(const QString &file_path);
    void parseJson(const QString &file_path);
    void toAlicHash(const QSharedPointer<QHash<QString,ALIC_Struct>> &root,const QJsonObject &samObject);

    QString file_path;
    QVariantMap JsonMap;
    QSharedPointer<QHash<QString,ALIC_Struct>> AlicHash=QSharedPointer<QHash<QString,ALIC_Struct>>(new QHash<QString,ALIC_Struct>);
};

#endif // JSONREADER_H
