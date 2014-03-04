#!/bin/sh

TARGET="arinc424-15"
VERSION="0.1.0"
MODULES_DEL="core gui"

if [ ${OS} ]	# На Win* выдает что-то типа Windows_NT, на других платформах не определена
then
	GMAKE="/c/MinGW/bin/mingw32-make";
	QMAKE="/c/Qt/4.8.4/bin/qmake";
	#LIBS="-L../geo/release -lgeo"
else
	GMAKE="/usr/local/bin/gmake";
	QMAKE="/usr/local/bin/qmake-qt4";
	CXX_FLAGS="-mmmx -msse -msse2 -msse3"
	SPEC="-spec freebsd-clang"
	# COMPILER=g++48
	#LIBS="-L../geo -lgeo"
fi

DEFINES="VERSION=\\\\\\\"${VERSION}\\\\\\\""	# aaaaaaaaaaaaaaaaa fuck !!

${GMAKE} distclean

${QMAKE} -project

if [ -e ${TARGET}.pro ]
then
	sed -i -e 's/TEMPLATE = app/TEMPLATE = lib/g' ${TARGET}.pro;

	echo "QT -= ${MODULES_DEL}" >> ${TARGET}.pro;
	echo "modules \"${MODULES_DEL}\" was removed.";

	echo "QMAKE_CXXFLAGS += ${CXX_FLAGS}" >> ${TARGET}.pro;
	echo "C++ flags \"${CXX_FLAGS}\" was added.";

	# includepath
	#echo "INCLUDEPATH += ${INCLUDEPATH}" >> ${TARGET}.pro;
	#echo "include += ${INCLUDEPATH}";

	# libraries
	#echo "LIBS += ${LIBS}" >> ${TARGET}.pro;
	#echo "libraries += ${LIBS}";

	${QMAKE} ${SPEC}
else
	echo "ERROR: file ${TARGET}.pro not found."
fi
