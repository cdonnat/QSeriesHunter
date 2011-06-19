#Includes common configuration for all subdirectory .pro files.
INCLUDEPATH += . ..
QT          += core
DESTDIR     = ../exe

RESOURCES   = ../QSeriesHunter.qrc

# The following keeps the generated files at least somewhat separate
# from the source files.
UI_DIR = uic
MOC_DIR = moc
OBJECTS_DIR = obj

