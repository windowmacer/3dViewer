#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>

//#ifdef __cplusplus
//extern "C" {
//    #endif
//    #include ""
//    #ifdef __cplusplus
//}
//#endif

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

private:
    Ui::viewer *ui;

};
#endif // VIEWER_H
