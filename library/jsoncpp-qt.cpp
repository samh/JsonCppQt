/**
 * @file jsoncpp-qt.cpp
 * @date Created on: May 5, 2011
 * @author: samh
 */

#include "json/jsoncpp-qt.h"

#include <QtCore/QVariant>

#include "json/json.h"

namespace Json {

void JsonValue_to_QVariant(const Json::Value& jv, QVariant& qv) {
    switch(jv.type()) {
    case nullValue:
        qv = QVariant();
        break;
    case intValue:
    case uintValue:
        qv = QVariant(jv.asLargestInt());
        break;
    case realValue:
        qv = QVariant(jv.asDouble());
        break;
    case stringValue:
        qv = QVariant(jv.asCString());
        break;
    case booleanValue:
        qv = QVariant(jv.asBool());
        break;
    case arrayValue:
    {
        QVariantList l;
        foreach(Value jvitem, jv) {
            QVariant qvitem;
            JsonValue_to_QVariant(jvitem, qvitem);
            l << qvitem;
        }
        qv = l;
        break;
    }
    case objectValue:
    {
        QVariantMap m;
        foreach(std::string key, jv.getMemberNames()) {
            QVariant qvitem;
            JsonValue_to_QVariant(jv[key], qvitem);
            m.insert(QString::fromStdString(key), qvitem);
        }
        qv = m;
        break;
    }
    }
}

void QVariant_to_JsonValue(const QVariant& qv, Json::Value& jv) {
    switch(qv.type()) {
    case QVariant::Invalid:
        jv = Value::null;
        break;
    case QVariant::Int:
    case QVariant::LongLong:
    case QVariant::UInt:
    case QVariant::ULongLong:
        jv = qv.toLongLong();
        break;
    case QVariant::Double:
        jv = qv.toDouble();
        break;
    case QVariant::Bool:
        jv = qv.toBool();
        break;
    case QVariant::List:
    case QVariant::StringList:
    {
        QVariantList qvlist = qv.toList();
        foreach(QVariant qvitem, qvlist) {
            Value jvitem;
            QVariant_to_JsonValue(qvitem, jvitem);
            jv.append(jvitem);
        }
        break;
    }
    case QVariant::Map:
    {
        QVariantMap qvmap = qv.toMap();
        QMapIterator<QString, QVariant> it(qvmap);
        while (it.hasNext()) {
            it.next();
            Value jvitem;
            QVariant_to_JsonValue(it.value(), jvitem);
            jv[it.key().toStdString()] = jvitem;
        }
        break;
    }
    default:
        jv = qv.toString().toStdString();
    }
}

QtReader::QtReader() {
    m_reader.reset(new Json::Reader());
}

QtReader::~QtReader() {
}

// How should this return errors?
//bool QtReader::parse(QIODevice& iodevice, QVariant& root) {
//
//}

bool QtReader::parse(const QString& document, QVariant& root) {
    Json::Value jsonRoot;
    bool parsingSuccessful = m_reader->parse(document.toStdString(), jsonRoot);
    if (parsingSuccessful) {
        JsonValue_to_QVariant(jsonRoot, root);
    }
    return parsingSuccessful;
}

QString QtReader::getFormattedErrorMessages() {
    return QString::fromStdString(m_reader->getFormattedErrorMessages());
}


QString QtWriter::write(const QVariant& root) {
    Json::Value value;
    QVariant_to_JsonValue(root, value);
    return QString::fromStdString(value.toStyledString());
}
}
