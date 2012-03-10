#include <QtSql>
#include "database.h"
#include "patient.h"
#include "Preferences/preferences.h"

Database::Database()
{
    preferences = Preferences::getInstance();
    type = preferences->getDatabaseType();
}

int Database::createDatabase()
{
    QSqlDatabase db;

    if( type == Preferences::MYSQL)
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName( preferences->getHostname() );
        db.setDatabaseName( preferences->getDatabaseName() );
        db.setUserName( preferences->getUserName() );
        db.setPassword( preferences->getPassword() );

        if( ! db.open() )
        {
                return -1;
        }

        QSqlQuery query;
        query.exec("ALTER DATABASE `dentx` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci");
    }

    if( type == Preferences::SQLITE )
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName( "patients.db" );
        if( ! db.open() )
            return -1;
    }

    qDebug() << db.lastError();

    return 0;
}


int Database::createTableNote()
{
    QSqlQuery query;
    bool value;

    if( type == Preferences::SQLITE )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS note ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "dateAdded TEXT NOT NULL,"
                            "topic VARCHAR(200) NOT NULL,"
                            "text TEXT,"
                            "textHtml TEXT,"
                            "dateSQL TEXT NOT NULL);"
                                );
    }

    if( type == Preferences::MYSQL )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS note ("
                            "id INTEGER PRIMARY KEY AUTO_INCREMENT,"
                            "dateAdded TEXT NOT NULL,"
                            "topic VARCHAR(200) NOT NULL,"
                            "text TEXT,"
                            "textHtml TEXT,"
                            "dateSQL TEXT NOT NULL);"
                           );
    }

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    return 0;
}

int Database::createTableReminder()
{
    QSqlQuery query;
    bool value;

    if( type == Preferences::SQLITE )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS reminder ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "dateAdded TEXT NOT NULL,"
                            "dateReminder TEXT NOT NULL,"
                            "priority VARCHAR(40),"
                            "dateAddedSQL TEXT,"
                            "dateReminderSQL TEXT,"
                            "topic VARCHAR(200) NOT NULL,"
                            "text TEXT,"
                            "textHtml TEXT);"
                            );
    }

    if( type == Preferences::MYSQL )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS reminder ("
                            "id INTEGER PRIMARY KEY AUTO_INCREMENT,"
                            "dateAdded TEXT NOT NULL,"
                            "dateReminder TEXT NOT NULL,"
                            "priority VARCHAR(40),"
                            "dateAddedSQL TEXT,"
                            "dateReminderSQL TEXT,"
                            "topic VARCHAR(200) NOT NULL,"
                            "text TEXT,"
                            "textHtml TEXT);"
                            );
    }

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    return 0;
}

int Database::createTableHistory()
{
    QSqlQuery query;

    bool value;
    if( type == Preferences::SQLITE )
    {
         value =  query.exec("CREATE TABLE IF NOT EXISTS history( "
                             "id VARCHAR(50) NOT NULL,"
                             "date TEXT NOT NULL,"
                             "milkteeth TEXT,"
                             "secondteeth TEXT, "
                             "diagnosis TEXT, "
                             "plan TEXT, "
                             "auto_id INTEGER PRIMARY KEY AUTOINCREMENT);"
                             );
    }

    if( type == Preferences::MYSQL )
    {
         value =  query.exec("CREATE TABLE IF NOT EXISTS history( "
                             "id VARCHAR(50) NOT NULL,"
                             "date TEXT NOT NULL,"
                             "milkteeth TEXT,"
                             "secondteeth TEXT, "
                             "diagnosis TEXT, "
                             "plan TEXT, "
                             "auto_id INTEGER PRIMARY KEY AUTOINCREMENT);"
                             );
    }



    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    return 0;
}

int Database::createTableTeethDescription()
{
    QSqlQuery query;

    bool value;
    if( type == Preferences::SQLITE )
    {
         value =  query.exec("CREATE TABLE IF NOT EXISTS teeth_description( "
                             "auto_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "id_patient VARCHAR(50), "
                             "id_visit VARCHAR(50), "
                             "type VARCHAR(50), "
                             "number VARCHAR(3), "
                             "description TEXT);"
                             );
    }

    if( type == Preferences::MYSQL )
    {
        value =  query.exec("CREATE TABLE IF NOT EXISTS teeth_description( "
                            "auto_id INTEGER PRIMARY KEY AUTO_INCREMENT, "
                            "id_patient VARCHAR(50), "
                            "id_visit VARCHAR(50), "
                            "type VARCHAR(50), "
                            "number VARCHAR(3), "
                            "description TEXT);"
                            );
    }

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }
    return 0;
}


int Database::createTableTimesheet()
{
    QSqlQuery query;

    bool value =  query.exec("CREATE TABLE IF NOT EXISTS timesheet("
                             "id VARCHAR(50) NOT NULL,"
                             "date TEXT NOT NULL"
                             "dateAdded TEXT NOT NULL,"
                             "type VARCHAR(2),"
                             "visit TEXT);"
                             );    

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }
    return 0;
}


int Database::createTablePatinets()
{
    QSqlQuery query;

    bool value;

    if( type == Preferences::SQLITE )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS patient ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "name VARCHAR(40) NOT NULL,"
             "lastname VARCHAR(50) NOT NULL,"
             "pesel VARCHAR(40) NOT NULL,"
             "city VARCHAR(100),"
             "street VARCHAR(100),"
             "house VARCHAR(20),"
             "zipcode VARCHAR(20),"
             "apartment VARCHAR(20),"
             "address VARCHAR(100),"
             "phone VARCHAR(20),"
             "pharmaceuticals TEXT,"
             "allergy TEXT,"
             "disorders TEXT,"
             "note TEXT,"
             "registrationdate VARCHAR(40),"
             "dentalArticulation VARCHAR(40),"
             "joint VARCHAR(40),"
             "exposure VARCHAR(40),"
             "color VARCHAR(40),"
             "efflorescencePre VARCHAR(40),"
             "efflorescenceSec VARCHAR(40),"
             "morfologicalChanges VARCHAR(40),"
             "tongue VARCHAR(40),"
             "morfologicalDisorder VARCHAR(40),"
             "ohi VARCHAR(40),"
             "pli VARCHAR(40),"
             "api VARCHAR(40),"
             "salivaS VARCHAR(40),"
             "salivaNS VARCHAR(40));"
          );
    }

    if( type == Preferences::MYSQL )
    {
        value = query.exec("CREATE TABLE IF NOT EXISTS patient ("
             "id INTEGER PRIMARY KEY AUTO_INCREMENT,"
             "name VARCHAR(40) NOT NULL,"
             "lastname VARCHAR(50) NOT NULL,"
             "pesel VARCHAR(40) NOT NULL,"
             "city VARCHAR(100),"
             "street VARCHAR(100),"
             "house VARCHAR(20),"
             "zipcode VARCHAR(20),"
             "apartment VARCHAR(20),"
             "address VARCHAR(100),"
             "phone VARCHAR(20),"
             "pharmaceuticals TEXT,"
             "allergy TEXT,"
             "disorders TEXT,"
             "note TEXT,"
             "registrationdate VARCHAR(40),"
             "dentalArticulation VARCHAR(40),"
             "joint VARCHAR(40),"
             "exposure VARCHAR(40),"
             "color VARCHAR(40),"
             "efflorescencePre VARCHAR(40),"
             "efflorescenceSec VARCHAR(40),"
             "morfologicalChanges VARCHAR(40),"
             "tongue VARCHAR(40),"
             "morfologicalDisorder VARCHAR(40),"
             "ohi VARCHAR(40),"
             "pli VARCHAR(40),"
             "api VARCHAR(40),"
             "salivaS VARCHAR(40),"
             "salivaNS VARCHAR(40));"
          );
    }




     if( !value )
     {
         qDebug() << query.lastQuery();
         qDebug() << query.lastError();
         return -1;
     }

     return 0;
}

int Database::addPatient(const Patient patient)
{
        qDebug() << "Adding new patient...";

        QSqlQuery query;
        query.prepare("INSERT INTO patient ("
                      "name, lastname, pesel,"
                      "city, street, house,"
                      "zipcode, apartment, address,"
                      "phone, pharmaceuticals, allergy,"
                      "disorders, note, registrationdate,"
                      "dentalArticulation, joint, exposure,"
                      "color, efflorescencePre, efflorescenceSec,"
                      "morfologicalChanges, tongue, morfologicalDisorder,"
                      "ohi, pli, api, salivaS, salivaNS)"
                      "VALUES ("
                      ":name, :lastname, :pesel,"
                      ":city, :street, :house,"
                      ":zipcode, :apartment, :address,"
                      ":phone, :pharmaceuticals, :allergy,"
                      ":disorders, :note, :registrationdate,"
                      ":dentalArticulation, :joint, :exposure,"
                      ":color, :efflorescencePre, :efflorescenceSec,"
                      ":morfologicalChanges, :tongue, :morfologicalDisorder,"
                      ":ohi, :pli, :api, :salivaS, :salivaNS)");

          query.bindValue(":name", patient.name);
          query.bindValue(":lastname" , patient.lastName);
          query.bindValue(":pesel" , patient.PESEL);
          query.bindValue(":city" , patient.city);
          query.bindValue(":street" , patient.street);
          query.bindValue(":house" , patient.house);
          query.bindValue(":zipcode" , patient.zipCode);
          query.bindValue(":apartment" , patient.apartment);
          query.bindValue(":address" , patient.getAddress());
          query.bindValue(":phone" , patient.phone);
          query.bindValue(":pharmaceuticals" , patient.pharmaceuticals);
          query.bindValue(":allergy" , patient.allergy);
          query.bindValue(":disorders" , patient.disorders);
          query.bindValue(":note" , patient.note);
          query.bindValue(":registrationdate" , QDateTime::currentDateTime().toString());
          query.bindValue(":dentalArticualtion" , patient.dentalArticulation);
          query.bindValue(":joint" , patient.joint);
          query.bindValue(":exposure" , patient.exposure);
          query.bindValue(":color" , patient.color);
          query.bindValue(":efflorescencePre" , patient.efflorescencePre);
          query.bindValue(":efflorescenceSec" , patient.efflorescenceSec);
          query.bindValue(":morfologicalChanges" , patient.morfologicalChanges);
          query.bindValue(":tongue" , patient.tongue);
          query.bindValue(":morfologicalDisorder" , patient.morfologicalDisorder);
          query.bindValue(":ohi" , patient.ohi);
          query.bindValue(":pli" , patient.pli);
          query.bindValue(":api" , patient.api);
          query.bindValue(":salivaS" , patient.salivaS);
          query.bindValue(":salivaNS" , patient.salivaNS);

          bool value = query.exec();          

          if( !value )
          {
              qDebug() << query.lastQuery();
              qDebug() << query.lastError();
              return -1;
          }
          return 0;
}
