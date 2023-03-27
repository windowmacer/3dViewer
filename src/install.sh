#!/bin/bash

DIR=""
echo "Введите директорию для установки приложения"
read DIR

export VIEWER_INSTALLATION_FOLDER=$DIR
if [ "$DIR" == "" ]; then
    cmake -S GUI/3DViewer -B build
    make -C build
    cp build/3DViewer 3DViewer
else
    cmake -S GUI/3DViewer -B $DIR/build
    make -C $DIR/build
fi
