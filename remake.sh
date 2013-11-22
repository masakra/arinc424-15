#!/bin/sh

TARGET="arinc424-15"
GMAKE="/usr/local/bin/gmake"
QMAKE="/usr/local/bin/qmake-qt4"

${GMAKE} distclean

${QMAKE} -project

if [ -e ${TARGET}.pro ]
then
	sed -i -e 's/TEMPLATE = app/TEMPLATE = lib/g' ${TARGET}.pro;

	${QMAKE}
else
	echo "ERROR: file ${TARGET}.pro not found."
fi
