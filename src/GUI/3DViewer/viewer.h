#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>          // library for using widgets
#include <QOpenGLWidget>    // library for using widgets
#include <QColor>           // library for using colors
#include <QFileDialog>      // library for dialog windows
#include <QColorDialog>     // library for dialog windows
#include <QSettings>        // library for saving and restoring settings
#include <QTimer>           // library for time counting
#include <QScrollArea>      //
#include <QMouseEvent>      // library for receiving mouse signals
#include <QWheelEvent>      // library for receiving mouse wheel signals
#include <QKeyEvent>        // library for receiving keyboard signals

#include "QtGifImage/gifimage/qgifimage.h" // library for creating GIF-images

#ifdef __cplusplus
extern "C" {
   #endif
   #include "../../Backend/logic/headerCAD.h"
   #ifdef __cplusplus
}
#endif

// coordinates
#define X 1
#define Y 2
#define Z 3

// projection type
#define PARALLEL 1
#define CENTRAL 2

// edge type
#define SOLID 1
#define DASHED 2

// vertex type
#define CIRCLE 1
#define SQUARE 2
#define NOVERTEX 3
#define AVERTEX 4

// lines to save the definition
#define PROJECTION_TYPE "projectionType"
#define EDGE_TYPE "edgeType"
#define VERTEX_TYPE "vertexType"
#define EDGE_THICKNESS "edgeThickness"
#define VERTEX_SIZE "vertexSize"
#define BACKGROUND_COLOR "backgroundColor"
#define EDGE_COLOR "edgeColor"
#define VERTEX_COLOR "vertexColor"
#define STEP "step"
#define ANGLE "angle"
#define SCALE "scale"

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

    // methods for saving images
    void on_actionSave_as_GIF_triggered();
    void on_actionSave_as_bmp_triggered();
    void on_actionSave_as_jpeg_triggered();
    void saveImage();

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

    // mouse events
    QPoint clickPosition;
    bool leftButton;
    bool rightButton;
    void mouseMoveEvent(QMouseEvent *cursorPosition) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *cursorPosition) override;
    void wheelEvent(QWheelEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override; // keys for calling saving gif, jpeg and bmp

    // удалить, если не будет использоваться
    QScrollArea *scrollArea;

    void    initDefaultValues(); // initialization of the initial values of the program

    int     projectionType; // замена paint_mode
    int     edgeType; // замена edge_type
    int     edgeWidth; // замена edge_width
    int     pointType; // замена point_type
    int     pointSize; // замена point_size
    int     pointVisibility; // замена point_visibility
    void    updateValues();


    float	x_angle, y_angle, z_angle;
    int		paint_mode;
	float	edge_width;
	float	point_size;
	int		edge_type, point_type, point_visibility;
};

#endif // VIEWER_H
