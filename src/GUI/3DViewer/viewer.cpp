#include "viewer.h"
#include "./ui_viewer.h"

#include <QPixmap> // для аниме тянок
#include <QFileDialog>

viewer::viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::viewer)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/anime.jpg");
    ui->picture->setPixmap(pix.scaled(844, 1280, Qt::KeepAspectRatio));
}

viewer::~viewer()
{
    delete ui;
}


void viewer::on_pushButton_selectFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, ("Select Model"), "../models/", "3D Image Files (*.obj)");
    char *path = (filePath.toLocal8Bit()).data();

    ui->fileName->setText((QFileInfo (filePath)).fileName());
}
