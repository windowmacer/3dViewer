#ifndef VIEWER_H
#define VIEWER_H

// #include <QMainWindow>

#include <QWidget>          // library for using widgets
#include <QOpenGLWidget>    // library for using widgets
#include <QColor>           // library for using colors
#include <QFileDialog>      // library for dialog windows
#include <QColorDialog>     // library for dialog windows
#include <QSettings>        // library for saving and restoring settings
#include <QTimer>           // library for time counting

#include "QtGifImage/gifimage/qgifimage.h"

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

// public QMainWindow
class viewer : public QOpenGLWidget {
    Q_OBJECT

public:
    viewer(QWidget *parent = nullptr);
    ~viewer();

private slots:
    void on_pushButton_selectFile_clicked();
    void moving();
    void rotation();
    void scaling();
    void setColor();
    void saveImage();

    void on_actionSave_as_GIF_triggered();
    void on_actionSave_as_bmp_triggered();
    void on_actionSave_as_jpeg_triggered();

private:
    Ui::viewer *ui;     // ui object of the viewer class
    structRoot model;   // model
	
    // model rendering methods
	void 	initializeGL() override;
	void 	resizeGL(int w, int h) override;
    void 	paintGL() override;

    //
	void 	pointSettings();
	void	applyNewSettings();

    // methods for saving images
    void    saveAsJPEG();
    void    saveAsBMP();
    void    saveAsGIF();

    // methods for saving and restoring settings
    QSettings *lastSettings;
    void    saveSettings();
    void    restoreSettings();

    // colors
    QColor backgroundColor;
    QColor edgeColor;
    QColor vertexColor;

    // GIF
    QGifImage *gif;
    QTimer *timer;
    int frames;

    float	x_angle, y_angle, z_angle;
    int		paint_mode;

	float	edge_width;
	float	point_size;
	int		edge_type, point_type, point_visibility;
};

#endif // VIEWER_H
