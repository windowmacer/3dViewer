#!/bin/bash

if [rm -rf $VIEWER_INSTALLATION_FOLDER/build]
then
	unset VIEWER_INSTALLATION_FOLDER
	echo "Директория установки 3DViewer успешно удалена"
fi