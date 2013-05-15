/****************************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: Andrew den Exter <andrew.den.exter@jollamobile.com>
** All rights reserved.
**
** You may use this file under the terms of the GNU Lesser General
** Public License version 2.1 as published by the Free Software Foundation
** and appearing in the file license.lgpl included in the packaging
** of this file.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file license.lgpl included in the packaging
** of this file.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
** 
****************************************************************************************/

#ifndef DECLARATIVEDBUSADAPTOR_H
#define DECLARATIVEDBUSADAPTOR_H

#include <QObject>
#include <QDeclarativeParserStatus>
#include <QDBusVirtualObject>

QT_BEGIN_NAMESPACE
class QScriptValue;
class QUrl;
QT_END_NAMESPACE

class DeclarativeDBusAdaptor : public QDBusVirtualObject, public QDeclarativeParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QString service READ service WRITE setService NOTIFY serviceChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString iface READ interface WRITE setInterface NOTIFY interfaceChanged)
    Q_PROPERTY(QString xml READ xml WRITE setXml NOTIFY xmlChanged)
    Q_INTERFACES(QDeclarativeParserStatus)
public:
    DeclarativeDBusAdaptor(QObject *parent = 0);
    ~DeclarativeDBusAdaptor();

    QString service() const;
    void setService(const QString &service);

    QString path() const;
    void setPath(const QString &path);

    QString interface() const;
    void setInterface(const QString &interface);

    QString xml() const;
    void setXml(const QString &xml);

    void classBegin();
    void componentComplete();

    QString introspect(const QString &path) const;
    bool handleMessage(const QDBusMessage &message, const QDBusConnection &connection);

signals:
    void serviceChanged();
    void pathChanged();
    void interfaceChanged();
    void xmlChanged();

private:
    QString m_service;
    QString m_path;
    QString m_interface;
    QString m_xml;
};

#endif