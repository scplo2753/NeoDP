#include "jsonreader.h"
#include <QJsonArray>

JsonReader::JsonReader(QObject *parent) : file_path(":/Resources/ALIC.json"), QObject(parent)
{
    parseJson(file_path);
}

QByteArray JsonReader::loadFile(const QString &file_path)
{
    QFile file_obj(file_path);
    if (!file_obj.open(QIODevice::ReadOnly))
    {
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();
    return json_bytes;
}

void JsonReader::parseJson(const QString &file_path)
{
    QByteArray JsonArray = loadFile(file_path);
    QJsonDocument json_doc = QJsonDocument::fromJson(JsonArray);
    auto rootArray = json_doc.array();
    ALIC_Struct samSystem;

    for (const QJsonValue &value : rootArray)
    {
        if (value.isObject())
        {
            auto samObject = value.toObject();

            toAlicHash(AlicHash, samObject);
        }
    }
}

inline void JsonReader::initAtoN(QString ALIC, QString Name)
{
    map_ALIC_Name[ALIC] = Name;
    map_Name_ALIC[Name] = ALIC;
}

void JsonReader::toAlicHash(QHash<QString, ALIC_Struct> &root, const QJsonObject &samObject)
{
    ALIC_Struct temp;
    temp.Name = samObject["Name"].toString();
    temp.Code = samObject["Code"].toString();
    temp.ALIC_Code = samObject["ALIC"].toString();
    initAtoN(temp.ALIC_Code, temp.Name);
    if (!samObject["Child"].isNull())
    {
        temp.Child = QSharedPointer<QHash<QString, ALIC_Struct>>(new QHash<QString, ALIC_Struct>());
        for (const QJsonValue &subValue : samObject["Child"].toArray())
        {
            toAlicHash(*temp.Child, subValue.toObject());
        }
    }
    root.insert(temp.Name, temp);
}

QVector<QString> JsonReader::getKeys()
{
    return AlicHash.keys().toVector();
}

QVector<QString> JsonReader::getChild(QString key)
{
    QVector<QString> childKeys;
    const auto &item = AlicHash.value(key);
    if (item.Child)
    {
        childKeys = item.Child->keys().toVector();
    }
    return childKeys;
}

const QHash<QString, ALIC_Struct> JsonReader::getAlicStructureHash() const
{
    return AlicHash;
}

const QHash<QString, QString> &JsonReader::getAlicToNameMap() const
{
    return map_ALIC_Name;
}

const QHash<QString, QString> &JsonReader::getNameToAlicMap() const
{
    return map_Name_ALIC;
}