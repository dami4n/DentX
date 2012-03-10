#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QSettings>

#include <QMutex>

class Preferences : public QObject
{
    Q_OBJECT
public:
    static Preferences *getInstance();
    void load();

    void writeSettings();
    void saveGeometry(QByteArray geometry);
    void setDefault();

    enum { SQLITE, MYSQL, POLISH, ENGLISH };

    bool getDynamicSearch() const { return dynamicSearch; }
    bool getMonday() const { return monday; }
    bool getTuesday() const { return tuesday; }
    bool getWednesday() const { return wednesday; }
    bool getThursday() const { return thursday; }
    bool getFriday() const { return friday; }
    bool getSaturday() const { return saturday; }
    bool getSunday() const { return sunday; }
    QTime getStartTime() const { return startTime; }
    QTime getEndTime() const { return endTime; }
    int getDatabaseType() const { return databaseType; }
    QString getDatabaseName() const { return databaseName; }
    QString getHostname() const { return hostname; }
    QString getUserName() const { return userName; }
    QString getPassword() const { return password; }
    int getLanguage() const { return language; }
    bool getSavePosition() const { return savePosition; }
    bool getAlwaysMax() const { return alwaysMax; }
    bool getCloseQuestion() const { return closeQuestion; }
    bool getMovableToolBar() const { return movableToolBar; }
    QString getPositionToolBar() const { return positionToolBar; }
    QByteArray getGeometry() const { return geometry; }

    void setDynamicSearch(bool value);
    void setMonday(bool value);
    void setTuesday(bool value);
    void setWednesday(bool value);
    void setThursday(bool value);
    void setFriday(bool value);
    void setSaturday(bool value);
    void setSunday(bool value) ;
    void setStartTime(QTime value);
    void setEndTime(QTime value);
    void setDatabaseName(QString value);
    void setDatabaseType(int value);
    void setHostname(QString value);
    void setUserName(QString value);
    void setPassword(QString value);
    void setLanguage(int value);
    void setSavePosition(bool value);
    void setAlwaysMax(bool value);
    void setCloseQuestion(bool value);
    void setMovableToolBar(bool value);
    void setPositionToolBar(QString value);

private:
    Preferences();
    Preferences(const Preferences &);
    Preferences& operator = (const Preferences &);
    static Preferences *preferences;

    QSettings settings;

    bool dynamicSearch;
    bool monday;
    bool tuesday;
    bool wednesday;
    bool thursday;
    bool friday;
    bool saturday;
    bool sunday;
    QTime startTime;
    QTime endTime;
    int databaseType;
    QString hostname;
    QString databaseName;
    QString userName;
    QString password;
    int language;
    bool savePosition;
    bool alwaysMax;
    bool closeQuestion;
    bool movableToolBar;
    QString positionToolBar;
    QByteArray geometry;

signals:
    void dynamicSearchChanged();
    void mondayChanged();
    void tuesdayChanged();
    void wednesdayChanged();
    void thursdayChanged();
    void fridayChanged();
    void saturdayChanged();
    void sundayChanged();
    void startTimeChanged();
    void endTimeChanged();
    void databaseTypeChanged();
    void databaseNameChanged();
    void hostnameChanged();
    void userNameChanged();
    void passwordChanged();
    void languageChanged();
    void savePositionChanged();
    void alwaysMaxChanged();
    void closeQuestionChanged();
    void movableToolBarChanged();
    void positionToolBarChanged();

};

#endif // PREFERENCES_H
