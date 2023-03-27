#!/bin/bash

LIBRARY="3dviewer.a"
NAME=""
echo "Введите директорию для установки приложения"
read NAME

export VIEWER_INSTALLATION_FOLDER=$NAME
mv $LIBRARY GUI/3DViewer/lib$LIBRARY
cmake -S GUI/3DViewer -B $NAME/build
make -C $NAME/build