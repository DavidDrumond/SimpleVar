#-------------------------------------------------
#
# Project created by QtCreator 2017-06-16T13:32:08
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = App_Variograma
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

INCLUDEPATH += $$PWD

CONFIG += static

SOURCES += main.cpp\
        mainwindow.cpp \
    abrir_arquivo.cpp \
    dados.cpp \
    variaveis.cpp \
    outliers.cpp \
    qcustomplot.cpp \
    variogram_map.cpp \
    parametros_variograma_experimental.cpp \
    modelagem_variograma.cpp \
    delegate.cpp \
    scatterplot.cpp \
    statistics.cpp \
    sugerir_lag.cpp \
    vizualizacao.cpp \
    ../SIMPLE VAR/SimpleVAr/abrir_arquivo.cpp \
    ../SIMPLE VAR/SimpleVAr/dados.cpp \
    ../SIMPLE VAR/SimpleVAr/delegate.cpp \
    ../SIMPLE VAR/SimpleVAr/distancia.cpp \
    ../SIMPLE VAR/SimpleVAr/main.cpp \
    ../SIMPLE VAR/SimpleVAr/mainwindow.cpp \
    ../SIMPLE VAR/SimpleVAr/meuitem.cpp \
    ../SIMPLE VAR/SimpleVAr/modelagem_variograma.cpp \
    ../SIMPLE VAR/SimpleVAr/outliers.cpp \
    ../SIMPLE VAR/SimpleVAr/parametros_variograma_experimental.cpp \
    ../SIMPLE VAR/SimpleVAr/qcustomplot.cpp \
    ../SIMPLE VAR/SimpleVAr/scatterplot.cpp \
    ../SIMPLE VAR/SimpleVAr/statistics.cpp \
    ../SIMPLE VAR/SimpleVAr/sugerir_lag.cpp \
    ../SIMPLE VAR/SimpleVAr/variaveis.cpp \
    ../SIMPLE VAR/SimpleVAr/variogram_map.cpp \
    ../SIMPLE VAR/SimpleVAr/vizualizacao.cpp

HEADERS  += mainwindow.h \
    abrir_arquivo.h \
    dados.h \
    variaveis.h \
    outliers.h \
    qcustomplot.h \
    variogram_map.h \
    parametros_variograma_experimental.h \
    modelagem_variograma.h \
    delegate.h \
    FFT/fftw3.h \
    fourier_transform.h \
    scatterplot.h \
    statistics.h \
    sugerir_lag.h \
    vizualizacao.h \
    ../SIMPLE VAR/SimpleVAr/abrir_arquivo.h \
    ../SIMPLE VAR/SimpleVAr/copy_array.h \
    ../SIMPLE VAR/SimpleVAr/dados.h \
    ../SIMPLE VAR/SimpleVAr/delegate.h \
    ../SIMPLE VAR/SimpleVAr/distancia.h \
    ../SIMPLE VAR/SimpleVAr/error_handling.h \
    ../SIMPLE VAR/SimpleVAr/mainwindow.h \
    ../SIMPLE VAR/SimpleVAr/meuitem.h \
    ../SIMPLE VAR/SimpleVAr/modelagem_variograma.h \
    ../SIMPLE VAR/SimpleVAr/outliers.h \
    ../SIMPLE VAR/SimpleVAr/parametros_variograma_experimental.h \
    ../SIMPLE VAR/SimpleVAr/qcustomplot.h \
    ../SIMPLE VAR/SimpleVAr/scatterplot.h \
    ../SIMPLE VAR/SimpleVAr/statistics.h \
    ../SIMPLE VAR/SimpleVAr/sugerir_lag.h \
    ../SIMPLE VAR/SimpleVAr/ui_abrir_arquivo.h \
    ../SIMPLE VAR/SimpleVAr/ui_mainwindow.h \
    ../SIMPLE VAR/SimpleVAr/ui_modelagem_variograma.h \
    ../SIMPLE VAR/SimpleVAr/ui_outliers.h \
    ../SIMPLE VAR/SimpleVAr/ui_parametros_variograma_experimental.h \
    ../SIMPLE VAR/SimpleVAr/ui_scatterplot.h \
    ../SIMPLE VAR/SimpleVAr/ui_statistics.h \
    ../SIMPLE VAR/SimpleVAr/ui_sugerir_lag.h \
    ../SIMPLE VAR/SimpleVAr/ui_variogram_map.h \
    ../SIMPLE VAR/SimpleVAr/ui_vizualizacao.h \
    ../SIMPLE VAR/SimpleVAr/variaveis.h \
    ../SIMPLE VAR/SimpleVAr/variogram_map.h \
    ../SIMPLE VAR/SimpleVAr/vizualizacao.h

FORMS    += mainwindow.ui \
    abrir_arquivo.ui \
    outliers.ui \
    variogram_map.ui \
    parametros_variograma_experimental.ui \
    modelagem_variograma.ui \
    scatterplot.ui \
    statistics.ui \
    sugerir_lag.ui \
    vizualizacao.ui \
    ../SIMPLE VAR/SimpleVAr/abrir_arquivo.ui \
    ../SIMPLE VAR/SimpleVAr/dialog.ui.autosave \
    ../SIMPLE VAR/SimpleVAr/distancia.ui \
    ../SIMPLE VAR/SimpleVAr/mainwindow.ui \
    ../SIMPLE VAR/SimpleVAr/modelagem_variograma.ui \
    ../SIMPLE VAR/SimpleVAr/outliers.ui \
    ../SIMPLE VAR/SimpleVAr/parametros_variograma_experimental.ui \
    ../SIMPLE VAR/SimpleVAr/scatterplot.ui \
    ../SIMPLE VAR/SimpleVAr/statistics.ui \
    ../SIMPLE VAR/SimpleVAr/sugerir_lag.ui \
    ../SIMPLE VAR/SimpleVAr/variogram_map.ui \
    ../SIMPLE VAR/SimpleVAr/vizualizacao.ui

RESOURCES += \
    imagens.qrc \
    ../SIMPLE VAR/SimpleVAr/imagens.qrc

SUBDIRS += \
    ../SIMPLE VAR/SimpleVAr/SimpleVAr.pro

DISTFILES += \
    ../SIMPLE VAR/SimpleVAr/App_Variograma.pro.user.18 \
    ../SIMPLE VAR/SimpleVAr/SimpleVAr.pro.user \
    ../SIMPLE VAR/SimpleVAr/SimpleVar.png \
    ../SIMPLE VAR/SimpleVAr/SimpleVar2.png \
    ../SIMPLE VAR/SimpleVAr/Vizualization.qml


