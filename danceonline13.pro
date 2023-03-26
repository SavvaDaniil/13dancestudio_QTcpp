QT -= gui
QT += httpserver sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#lib/crypt_blowfish/crypt_gensalt.c \
#lib/crypt_blowfish/crypt_blowfish.c \
#lib/crypt_blowfish/bcrypt.c \

#lib/crypt_blowfish/crypt_gensalt.h \
#lib/crypt_blowfish/crypt_blowfish.h \
#lib/crypt_blowfish/crypt.h \
#lib/crypt_blowfish/bcrypt.h \
#lib/crypt_blowfish/ow-crypt.h \

#lib/qt-bcrypt/openwall_crypt/ow-crypt.h \

SOURCES += \
        internal/controller/apistylecontroller.cpp \
        internal/controller/apitutorialcontroller.cpp \
        internal/entity/style.cpp \
        internal/entity/teacher.cpp \
        internal/entity/tutorial.cpp \
        internal/facade/tutorialfacade.cpp \
        internal/factory/stylefactory.cpp \
        internal/factory/teacherfactory.cpp \
        internal/factory/tutorialfactory.cpp \
        internal/repository/stylerepository.cpp \
        internal/repository/teacherrepository.cpp \
        internal/repository/tutorialrepository.cpp \
        internal/viewmodel/Style/stylemicroviewmodel.cpp \
        internal/viewmodel/Teacher/teachermicroviewmodel.cpp \
        internal/viewmodel/Tutorial/tutorialpreviewviewmodel.cpp \
        lib/qjsonwebtoken/qjsonwebtoken.cpp \
        internal/middleware/usermiddleware.cpp \
        internal/controller/apiusercontroller.cpp \
        internal/data/applicationdbcontext.cpp \
        internal/dto/User/userlogindto.cpp \
        internal/entity/user.cpp \
        internal/facade/userfacade.cpp \
        internal/factory/userfactory.cpp \
        internal/repository/userrepository.cpp \
        internal/viewmodel/User/userprofileviewmodel.cpp \
        internal/viewmodel/jsonanswerstatus.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    internal/controller/apistylecontroller.h \
    internal/controller/apitutorialcontroller.h \
    internal/entity/style.h \
    internal/entity/teacher.h \
    internal/entity/tutorial.h \
    internal/facade/tutorialfacade.h \
    internal/factory/stylefactory.h \
    internal/factory/teacherfactory.h \
    internal/factory/tutorialfactory.h \
    internal/repository/stylerepository.h \
    internal/repository/teacherrepository.h \
    internal/repository/tutorialrepository.h \
    internal/viewmodel/Style/stylemicroviewmodel.h \
    internal/viewmodel/Teacher/teachermicroviewmodel.h \
    internal/viewmodel/Tutorial/tutorialpreviewviewmodel.h \
    lib/qjsonwebtoken/qjsonwebtoken.h \
    internal/middleware/usermiddleware.h \
    internal/controller/apiusercontroller.h \
    internal/data/applicationdbcontext.h \
    internal/dto/User/userlogindto.h \
    internal/facade/userfacade.h \
    internal/entity/user.h \
    internal/factory/userfactory.h \
    internal/repository/userrepository.h \
    internal/viewmodel/User/userprofileviewmodel.h \
    internal/viewmodel/jsonanswerstatus.h
