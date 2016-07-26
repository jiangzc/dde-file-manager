/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DCalendarDBus -p dcalendardbus com.deepin.api.LunarCalendar.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DCALENDARDBUS_H_1439794748
#define DCALENDARDBUS_H_1439794748

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

class CaYearInfo
{
public:
    CaYearInfo() {}

    inline static void registerMetaType();

    friend QDebug operator<<(QDebug argument, const CaYearInfo & what);
    friend QDBusArgument &operator<<(QDBusArgument & argument, const CaYearInfo & what);
    friend const QDBusArgument &operator>>(const QDBusArgument & argument, CaYearInfo & what);

public:
    qint32 mYear;
    qint32 mMonth;
    qint32 mDay;
};

class CaLunarDayInfo
{
public:
    CaLunarDayInfo() {}

    inline static void registerMetaType();

    friend QDebug operator<<(QDebug argument, const CaLunarDayInfo & what);
    friend QDBusArgument &operator<<(QDBusArgument & argument, const CaLunarDayInfo & what);
    friend const QDBusArgument &operator>>(const QDBusArgument & argument, CaLunarDayInfo & what);

public:
    QString mGanZhiYear;
    QString mGanZhiMonth;
    QString mGanZhiDay;
    QString mLunarMonthName;
    QString mLunarDayName;
    qint32 mLunarLeapMonth;
    QString mZodiac;
    QString mTerm;
    QString mSolarFestival;
    QString mLunarFestival;
    qint32 mWorktime;
};

class CaLunarMonthInfo
{
public:
    CaLunarMonthInfo() {}

    inline static void registerMetaType();

    friend QDebug operator<<(QDebug argument, const CaLunarMonthInfo & what);
    friend QDBusArgument &operator<<(QDBusArgument & argument, const CaLunarMonthInfo & what);
    friend const QDBusArgument &operator>>(const QDBusArgument & argument, CaLunarMonthInfo & what);

public:
    qint32 mFirstDayWeek;
    qint32 mDays;
    QList<CaLunarDayInfo> mCaLunarDayInfo;
};

class CaSolarMonthInfo
{
public:
    CaSolarMonthInfo() {}

    inline static void registerMetaType();

    friend QDebug operator<<(QDebug argument, const CaSolarMonthInfo & what);
    friend QDBusArgument &operator<<(QDBusArgument & argument, const CaSolarMonthInfo & what);
    friend const QDBusArgument &operator>>(const QDBusArgument & argument, CaSolarMonthInfo & what);


public:
    qint32 mFirstDayWeek;
    qint32 mDays;
    QList<CaYearInfo> mCaYearInfo;
};

/*
 * Proxy class for interface com.deepin.api.LunarCalendar
 */
class DCalendarDBus: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.api.LunarCalendar")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
 	            Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.api.LunarCalendar"; }

public:
    DCalendarDBus(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~DCalendarDBus();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<CaYearInfo, bool, bool> GetLunarDateBySolar(int in0, int in1, int in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("GetLunarDateBySolar"), argumentList);
    }
    inline QDBusReply<CaYearInfo> GetLunarDateBySolar(int in0, int in1, int in2, bool &out1, bool &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("GetLunarDateBySolar"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
            out2 = qdbus_cast<bool>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<CaLunarDayInfo, bool> GetLunarInfoBySolar(int in0, int in1, int in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("GetLunarInfoBySolar"), argumentList);
    }
    inline QDBusReply<CaLunarDayInfo> GetLunarInfoBySolar(qint32 in0, qint32 in1, qint32 in2, bool &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("GetLunarInfoBySolar"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<CaLunarMonthInfo, bool> GetLunarMonthCalendar(int in0, int in1, bool in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("GetLunarMonthCalendar"), argumentList);
    }
    inline QDBusReply<CaLunarMonthInfo> GetLunarMonthCalendar(int in0, int in1, bool in2, bool &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("GetLunarMonthCalendar"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<CaYearInfo, bool> GetSolarDateByLunar(int in0, int in1, int in2, bool in3)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        return asyncCallWithArgumentList(QStringLiteral("GetSolarDateByLunar"), argumentList);
    }
    inline QDBusReply<CaYearInfo> GetSolarDateByLunar(int in0, int in1, int in2, bool in3, bool &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("GetSolarDateByLunar"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<CaSolarMonthInfo, bool> GetSolarMonthCalendar(int in0, int in1, bool in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("GetSolarMonthCalendar"), argumentList);
    }
    inline QDBusReply<CaSolarMonthInfo> GetSolarMonthCalendar(int in0, int in1, bool in2, bool &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("GetSolarMonthCalendar"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
        }
        return reply;
    }

Q_SIGNALS: // SIGNALS
// begin property changed signals
};

namespace com {
  namespace deepin {
    namespace api {
      typedef ::DCalendarDBus LunarCalendar;
    }
  }
}

Q_DECLARE_METATYPE(CaYearInfo)
Q_DECLARE_METATYPE(CaLunarDayInfo)
Q_DECLARE_METATYPE(CaLunarMonthInfo)
Q_DECLARE_METATYPE(CaSolarMonthInfo)
#endif
