/**
 * This is a wrapper around JsonCpp which reads and stores QVariants.
 * I wrote this to replace QJson, which didn't give detailed parsing errors,
 * and didn't format the files it wrote very well.
 *
 * @file jsoncpp-qt.h
 * @date Created on: May 5, 2011
 * @author: samh
 */

#ifndef JSONCPP_QT_H_
#define JSONCPP_QT_H_

#include <QtCore/QIODevice>
#include <QtCore/QScopedPointer>

namespace Json {

class Reader;

class QtReader {
public:
    QtReader();
    virtual ~QtReader();

//    bool parse(QIODevice& iodevice, QVariant& root);
    bool parse(const QString& document, QVariant& root);
    QString getFormattedErrorMessages();

private:
    QScopedPointer<Reader> m_reader;
};

class QtWriter {
public:
    QString write(const QVariant& root);
};

}

#endif /* JSONCPP_QT_H_ */
