#-------------------------------------------------
#
# Project created by QtCreator 2017-07-14T02:45:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SimpleVAr
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    abrir_arquivo.cpp \
    dados.cpp \
    delegate.cpp \
    meuitem.cpp \
    modelagem_variograma.cpp \
    outliers.cpp \
    parametros_variograma_experimental.cpp \
    qcustomplot.cpp \
    scatterplot.cpp \
    statistics.cpp \
    sugerir_lag.cpp \
    variaveis.cpp \
    variogram_map.cpp \
    vizualizacao.cpp

HEADERS  += mainwindow.h \
    abrir_arquivo.h \
    copy_array.h \
    dados.h \
    delegate.h \
    error_handling.h \
    meuitem.h \
    modelagem_variograma.h \
    outliers.h \
    parametros_variograma_experimental.h \
    qcustomplot.h \
    scatterplot.h \
    statistics.h \
    sugerir_lag.h \
    ui_abrir_arquivo.h \
    ui_mainwindow.h \
    ui_modelagem_variograma.h \
    ui_outliers.h \
    ui_parametros_variograma_experimental.h \
    ui_scatterplot.h \
    ui_statistics.h \
    ui_sugerir_lag.h \
    ui_variogram_map.h \
    ui_vizualizacao.h \
    variaveis.h \
    variogram_map.h \
    vizualizacao.h

FORMS    += mainwindow.ui \
    abrir_arquivo.ui \
    dialog.ui.autosave \
    modelagem_variograma.ui \
    outliers.ui \
    parametros_variograma_experimental.ui \
    scatterplot.ui \
    statistics.ui \
    sugerir_lag.ui \
    variogram_map.ui \
    vizualizacao.ui

RESOURCES += \
    imagens.qrc

DISTFILES += \
    App_Variograma.pro.user.18 \
    SimpleVAr.pro.user \
    SimpleVar.png \
    SimpleVar2.png
