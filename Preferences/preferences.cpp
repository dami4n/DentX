#include <QObject>
#include <QSettings>
#include <QStringList>
#include <QDebug>
#include "preferences.h"

Preferences *Preferences::preferences = 0;

Preferences::Preferences():
    settings("DentX", "DentX")
{
    load();
}


Preferences *Preferences::getInstance()
{
    static QMutex mutex;
    if(!preferences)
    {
        mutex.lock();
        if(!preferences)
            preferences = new Preferences;
        mutex.unlock();
    }
    return preferences;
}

void Preferences::load()
{
    if( settings.allKeys().size() )
    {
        settings.beginGroup("database");
        databaseType = settings.value("DatabaseType").toInt();
        databaseName = settings.value("DatabaseName").toString();
        hostname = settings.value("Hostname").toString();
        userName = settings.value("UserName").toString();
        password = settings.value("Password").toString();
        settings.endGroup();

        settings.beginGroup("general");
        language = settings.value("Language").toInt();
        savePosition = settings.value("SavePosition").toBool();
        alwaysMax = settings.value("AlwaysMax").toBool();
        closeQuestion = settings.value("CloseQuestion").toBool();
        settings.endGroup();

        settings.beginGroup("look");
        movableToolBar = settings.value("MovableToolBar").toBool();
        positionToolBar = settings.value("PositionToolBar").toString();
        settings.endGroup();

        settings.beginGroup("clinic");
        monday = settings.value("Monday").toBool();
        tuesday = settings.value("Tuesday").toBool();
        wednesday = settings.value("Wednesday").toBool();
        thursday = settings.value("Thursday").toBool();
        friday = settings.value("Friday").toBool();
        saturday = settings.value("Saturday").toBool();
        sunday = settings.value("Sunday").toBool();
        startTime = settings.value("StartTime").toTime();
        endTime = settings.value("EndTime").toTime();
        settings.endGroup();

        settings.beginGroup("advanced");
        dynamicSearch = settings.value("DynamicSearch").toBool();
        settings.endGroup();

        settings.beginGroup("geometry");
        geometry = settings.value("ProgGeometry").toByteArray();
        settings.endGroup();
    }
}

void Preferences::setDefault()
{
    setDynamicSearch(true);
    setMonday(true);
    setTuesday(true);
    setWednesday(true);
    setThursday(true);
    setFriday(true);
    setSaturday(true);
    setSunday(true);
    //setStartTime(true);
    //setEndTime(true);
    setDatabaseName("");
    setDatabaseType(SQLITE);
    setHostname("");
    setUserName("");
    setPassword("");
    setLanguage(POLISH);
    setSavePosition(false);
    setAlwaysMax(true);
    setCloseQuestion(false);
    setMovableToolBar(false);
    setPositionToolBar("");
}

void Preferences::setDynamicSearch(bool value)
{
    if( value != dynamicSearch )
    {
        dynamicSearch = value;
        settings.beginGroup("advanced");
        settings.setValue("DynamicSearch", dynamicSearch);
        settings.endGroup();
        emit dynamicSearchChanged();
    }
}

void Preferences::setMonday(bool value)
{
    if( value != monday  )
    {
        monday = value;
        settings.beginGroup("clinic");
        settings.setValue("Monday", monday );
        settings.endGroup();
        emit mondayChanged();
    }
}

void Preferences::setTuesday(bool value)
{
    if( value != tuesday )
    {
        tuesday = value;
        settings.beginGroup("clinic");
        settings.setValue("Tuesday", tuesday );
        settings.endGroup();
        emit tuesdayChanged();
    }
}

void Preferences::setWednesday(bool value)
{
    qDebug() << "zmiana " << value;
    if( value != wednesday  )
    {
        wednesday = value;
        settings.beginGroup("clinic");
        settings.setValue("Wednesday", wednesday);
        settings.endGroup();
        emit wednesdayChanged();
    }
}

void Preferences::setThursday(bool value)
{
    if( value != thursday )
    {
        thursday = value;
        settings.beginGroup("clinic");
        settings.setValue("Thursday", thursday);
        settings.endGroup();
        emit thursdayChanged();
    }
}

void Preferences::setFriday(bool value)
{
    if( value != friday )
    {
        friday = value;
        settings.beginGroup("clinic");
        settings.setValue("Friday", friday);
        settings.endGroup();
        emit fridayChanged();
    }
}

void Preferences::setSaturday(bool value)
{
    if( value != saturday  )
    {
        saturday = value;
        settings.beginGroup("clinic");
        settings.setValue("Saturday", saturday );
        settings.endGroup();
        emit ;
    }
}

void Preferences::setSunday(bool value)
{
    if( value != sunday )
    {
        sunday = value;
        settings.beginGroup("clinic");
        settings.setValue("Sunday", sunday );
        settings.endGroup();
        emit sundayChanged(); ;
    }
}

void Preferences::setStartTime(QTime value)
{
    if( value != startTime  )
    {
        startTime = value;
        settings.beginGroup("clinic");
        settings.setValue("StartTime", startTime);
        settings.endGroup();
        emit startTimeChanged(); ;
    }
}

void Preferences::setEndTime(QTime value)
{
    if( value != endTime  )
    {
        endTime = value;
        settings.beginGroup("clinic");
        settings.setValue("EndTime", endTime );
        settings.endGroup();
        emit endTimeChanged();
    }
}


void Preferences::setDatabaseName(QString value)
{
    if( value != databaseName  )
    {
        databaseName = value;
        settings.beginGroup("database");
        settings.setValue("DatabaseName", databaseName);
        settings.endGroup();
        emit databaseNameChanged(); ;
    }
}

void Preferences::setDatabaseType(int value)
{
    if( value != databaseType )
    {
        databaseType = value;
        settings.beginGroup("database");
        settings.setValue("DatabaseType", databaseType );
        settings.endGroup();
        emit databaseTypeChanged();
    }
}

void Preferences::setHostname(QString value)
{
    if( value != hostname )
    {
        hostname = value;
        settings.beginGroup("database");
        settings.setValue("Hostname", hostname );
        settings.endGroup();
        emit hostnameChanged();
    }
}

void Preferences::setUserName(QString value)
{
    if( value != userName  )
    {
        userName = value;
        settings.beginGroup("database");
        settings.setValue("UserName", userName);
        settings.endGroup();
        emit userNameChanged();
    }
}

void Preferences::setPassword(QString value)
{
    if( value != password  )
    {
        password = value;
        settings.beginGroup("database");
        settings.setValue("Password", password );
        settings.endGroup();
        emit passwordChanged();
    }
}

void Preferences::setLanguage(int value)
{
    if( value != language )
    {
        language = value;
        settings.beginGroup("general");
        settings.setValue("Language", language );
        settings.endGroup();
        emit languageChanged();
    }
}

void Preferences::setAlwaysMax(bool value)
{
    if( value != alwaysMax  )
    {
        alwaysMax = value;
        settings.beginGroup("general");
        settings.setValue("AlwaysMax", alwaysMax);
        settings.endGroup();
        emit alwaysMaxChanged();
    }
}

void Preferences::setSavePosition(bool value)
{
    if( value != savePosition  )
    {
        savePosition = value;
        settings.beginGroup("general");
        settings.setValue("SavePosition", savePosition );
        settings.endGroup();
        emit savePositionChanged(); ;
    }
}

void Preferences::setCloseQuestion(bool value)
{
    if( value != closeQuestion )
    {
        closeQuestion = value;
        settings.beginGroup("general");
        settings.setValue("CloseQuestion", closeQuestion );
        settings.endGroup();
        emit closeQuestionChanged();
    }
}

void Preferences::setMovableToolBar(bool value)
{
    if( value != movableToolBar  )
    {
        movableToolBar = value;
        settings.beginGroup("look");
        settings.setValue("MovableToolBar", movableToolBar );
        settings.endGroup();
        emit movableToolBarChanged();
    }
}

void Preferences::setPositionToolBar(QString value)
{
    if( value != positionToolBar )
    {
        positionToolBar = value;
        settings.beginGroup("look");
        settings.setValue("PositionToolBar", positionToolBar );
        settings.endGroup();
        emit positionToolBarChanged();
    }
}

void Preferences::writeSettings()
{
    settings.sync();
}

void Preferences::saveGeometry(QByteArray _geometry)
{
    settings.beginGroup("geometry");
    settings.setValue("ProgGeometry", _geometry );
    settings.endGroup();

    geometry = _geometry;
}






























