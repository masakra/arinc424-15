#!/bin/sh

TARGET="arinc424-15"
MODULES_DEL="core gui"
GMAKE="/usr/local/bin/gmake"
QMAKE="/usr/local/bin/qmake-qt4"
COMPILER=clang
CXX_FLAGS="-m64 -mmmx -msse -msse2 -msse3"
INCLUDEPATH="../geo"
LIBS="-L../geo -lgeo"

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
	echo "INCLUDEPATH += ${INCLUDEPATH}" >> ${TARGET}.pro;
	echo "include += ${INCLUDEPATH}";

	# libraries
	echo "LIBS += ${LIBS}" >> ${TARGET}.pro;
	echo "libraries += ${LIBS}";

	${QMAKE} -spec freebsd-${COMPILER}
else
	echo "ERROR: file ${TARGET}.pro not found."
fi
