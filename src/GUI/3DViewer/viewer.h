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

class viewer : public QOpenGLWidget
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
	structRoot model; // model
	
	void 	initializeGL() override;
	void 	resizeGL(int w, int h) override;
	void 	paintGL() override;

	void 	pointSettings();
	void	applyNewSettings();
	void	setBackgroundColor();
	void	setEdgesColor();

	void	point
	float	x_angle, y_angle, z_angle;
	int		paint_mode;

	float	r_color_background, g_color_background, b_color_background; // background colors in rgb format
	float	r_color_point, g_color_point, b_color_point; // color of the points
	float	r_color_edge, g_color_edge, b_color_edge; // color of the edges of a model
	float	edge_width; 
	int		edge_type, point_type, point_visibility;
};
#endif // VIEWER_H
