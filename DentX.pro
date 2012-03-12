QT  += core gui xml sql svg

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    PatientDialog/personaldetailwidget.cpp \
    PatientDialog/examinationwidget.cpp \
    PatientDialog/additionalinformationwidget.cpp \
    Database/database.cpp \
    patient.cpp \
    Database/databasedebugdialog.cpp \
    Cardfile/cardfiletable.cpp \
    demo.cpp \
    Cardfile/cardfile.cpp \
    Preferences/preferencesdialog.cpp \
    Preferences/preferences.cpp \
    PatientDialog/addpatientdialog.cpp \
    PatientDialog/showpatientdialog.cpp \
    Pdf/pdfcreator.cpp \
    Teeth/teeth.cpp \
    Teeth/molar.cpp \
    Teeth/incisor.cpp \
    Teeth/history.cpp \
    Teeth/diagrammilkteeth.cpp \
    Teeth/diagramdialog.cpp \
    Teeth/diagram.cpp \
    Teeth/colorbuttons.cpp \
    Xml/xmlwriter.cpp \
    Xml/xmlreader.cpp \
    SpeedDial/stat.cpp \
    SpeedDial/speeddial.cpp \
    Timesheet/timesheet.cpp \
    Note/shownotedialog.cpp \
    Note/notewidget.cpp \
    Note/noteviewer.cpp \
    Note/notefunction.cpp \
    Note/note.cpp \
    Note/editor.cpp \
    Note/addnotedialog.cpp \
    Teeth/actiontabs.cpp \
    Teeth/descriptionwidget.cpp \
    Teeth/adddescriptiondialog.cpp \
    Reminder/reminderwidget.cpp \
    Reminder/reminder.cpp \
    Reminder/addreminderdialog.cpp \
    Preferences/lookpagewidget.cpp \
    Preferences/advancedpagewidget.cpp \
    Preferences/generalpagewidget.cpp \
    Preferences/databasepagewidget.cpp \
    Reminder/showreminderdialog.cpp \
    Reminder/reminderviewer.cpp \
    Reminder/reminderfunction.cpp \
    Wizard/wizard.cpp \
    Wizard/intropage.cpp \
    Wizard/languagepage.cpp \
    Wizard/databasepage.cpp \
    Preferences/clinicpagewidget.cpp \
    Wizard/clinicpage.cpp \
    Wizard/finishpage.cpp \
    Timesheet/addappointmentdialog.cpp \
    Database/databasepatient.cpp \
    testclass.cpp \
    Patients/patients.cpp \
    Image/imageviewer.cpp \
    Image/cropimagewidget.cpp \
    Image/croplabel.cpp

HEADERS += \
    mainwindow.h \
    PatientDialog/personaldetailwidget.h \
    PatientDialog/additionalinformationwidget.h \
    PatientDialog/examinationwidget.h \
    Database/database.h \
    patient.h \
    Database/databasedebugdialog.h \
    Cardfile/cardfiletable.h \
    demo.h \
    Cardfile/cardfile.h \
    Preferences/preferencesdialog.h \
    Preferences/preferences.h \
    PatientDialog/addpatientdialog.h \
    PatientDialog/showpatientdialog.h \
    Pdf/pdfcreator.h \
    Teeth/teeth.h \
    Teeth/molar.h \
    Teeth/incisor.h \
    Teeth/history.h \
    Teeth/diagrammilkteeth.h \
    Teeth/diagramdialog.h \
    Teeth/diagram.h \
    Teeth/colorbuttons.h \
    Xml/xmlwriter.h \
    Xml/xmlreader.h \
    SpeedDial/stat.h \
    SpeedDial/speeddial.h \
    Timesheet/timesheet.h \
    Note/shownotedialog.h \
    Note/notewidget.h \
    Note/noteviewer.h \
    Note/notefunction.h \
    Note/note.h \
    Note/editor.h \
    Note/addnotedialog.h \
    Teeth/actiontabs.h \
    Teeth/descriptionwidget.h \
    Teeth/adddescriptiondialog.h \
    Reminder/reminderwidget.h \
    Reminder/reminder.h \
    Reminder/addreminderdialog.h \
    Preferences/lookpagewidget.h \
    Preferences/advancedpagewidget.h \
    Preferences/generalpagewidget.h \
    Preferences/databasepagewidget.h \
    Reminder/showreminderdialog.h \
    Reminder/reminderviewer.h \
    Reminder/reminderfunction.h \
    Wizard/wizard.h \
    Wizard/intropage.h \
    Wizard/languagepage.h \
    Wizard/databasepage.h \
    Preferences/clinicpagewidget.h \
    Wizard/clinicpage.h \
    Wizard/finishpage.h \
    Timesheet/addappointmentdialog.h \
    Database/databasepatient.h \
    testclass.h \
    Patients/patients.h \
    Image/imageviewer.h \
    Image/cropimagewidget.h \
    Image/croplabel.h

OTHER_FILES +=

RESOURCES += \
    dentX.qrc

TRANSLATIONS    += superapp_en.ts

CODECFORTR = UTF-8
CODECFORSRC = UTF-8
