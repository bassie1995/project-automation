TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    aapje.cpp \
    arduPi.cpp \
    arduPi_template.cpp \
    blink_test.cpp \
    buzzer.cpp \
    CurtainControl.cpp \
    ipcamera.cpp \
    led.cpp \
    light.cpp \
    LightSensor.cpp \
    motionsensor.cpp \
    ProgrammeerBewegingsAapje.cpp \
    RaspPi.cpp \
    rgblight.cpp \
    sensor.cpp \
    SensorAapje.cpp \
    switch.cpp \
    temperaturesensor.cpp \
    test.cpp \
    thermometer.cpp \
    thermostat.cpp \
    windowdecoration.cpp

include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    buzzer.h.gch \
    motionsensor.h.gch \
    Domotica.pro.user \
    README.md \
    Makefile

HEADERS += \
    arduPi.h \
    buzzer.h \
    ipcamera.h \
    led.h \
    light.h \
    LightSensor.h \
    motionsensor.h \
    RaspPi.h \
    rgblight.h \
    sensor.h \
    switch.h \
    temperaturesensor.h \
    windowdecoration.h \
    main.h

