#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>

#ifdef __cplusplus
extern "C" {
   #endif
   #include "../../Backend/logic/headerCAD.h"
   #ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class viewer; }
QT_END_NAMESPACE

class viewer : public QMainWindow
{
    Q_OBJECT

public:
    viewer(QWidget *parent = nullptr);
    ~viewer();

private slots:
    void on_pushButton_selectFile_clicked();
    void moving();
    void rotation();
    void scaling();

    void on_testButton_clicked();

private:
    Ui::viewer *ui;

    // model
    structRoot model;

    // background colors in rgb format
    float r_color_background;
};
#endif // VIEWER_H
