#ifndef VIEWER_H
#define VIEWER_H

// #include <QMainWindow>

#include <QWidget>          // library for using widgets
#include <QOpenGLWidget>    // library for using widgets
#include <QColor>           // library for using colors
#include <QFileDialog>      // library for dialog windows
#include <QColorDialog>     // library for dialog windows
#include <QSettings>

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
    void    setColor();

    // methods for saving images
    void    saveAsJPEG();
    void    saveAsBMP();
    void    saveAsGIF();

    //
    QSettings *lastSettings;
    void    saveSettings();
    void    restoreSettings();

    // void	point; // Вань, разберись что это и для чего
	float	x_angle, y_angle, z_angle;
	int		paint_mode;

    // colors
    QColor backgroundColor;
    QColor edgeColor;
    QColor vertexColor;

	float	edge_width;
	float	point_size;
	int		edge_type, point_type, point_visibility;
};

#endif // VIEWER_H
