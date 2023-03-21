#ifndef VIEWER_H
#define VIEWER_H

// #include <QMainWindow>
#include <QWidget>
#include <QOpenGLWidget>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>

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
	Ui::viewer *ui;
	structRoot model; // model
	
	void 	initializeGL() override;
	void 	resizeGL(int w, int h) override;
	void 	paintGL() override;

	void 	pointSettings();
	void	applyNewSettings();
    void    setColor();

    // void	point;
	float	x_angle, y_angle, z_angle;
	int		paint_mode;

    // colors // нужно будет в конструкторе сразу инициализировать какими-то начальными значениями, для того чтобы и фон, и модель не была белой
    QColor backgroundColor;
    QColor edgeColor;
    QColor vertexColor;

	float	edge_width;
	int		edge_type, point_type, point_visibility;
};

#endif // VIEWER_H
