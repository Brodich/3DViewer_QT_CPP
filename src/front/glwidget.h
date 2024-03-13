#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtWidgets>

#define GL_SILENCE_DEPRECATION

#include "../back/parser.h"
#include "mainwindow.h"

class glwidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  glwidget(QWidget* parent = NULL) : QOpenGLWidget(parent) {}

//  void  ChangeBackColor(QColor color);
//  void  ChangeLineColor(QColor color);
//  void  ChangeVertexColor(QColor color);

  using QOpenGLWidget::QOpenGLWidget;
  void paint();

  data_t parse_data = {0};
  polygon_t polygons = {0};
  double* vertices = NULL;
  double size = 1;

  int xTrans = 0, yTrans = 0, zTrans = 0;
  int xRot = 0, yRot = 0, zRot = 0;
  int scale = 1;
  bool solid_line = true;
  int line_width = 1;

  double size_vertex = 1;
  int vertex_style = 1;  // 1 - none; 2 - circle; 3 - square.

  bool central_type = false;

  QSettings setting;

//  QColor color_back;
//  QColor color_line;
//  QColor color_vertex;

//  float back_r = 0.9f, back_g = 0.7f, back_b = 0.941f;
  float back_r = 0.0f, back_g = 0.0f, back_b = 0.0f;
  float line_r = 1.0f, line_g = 1.0f, line_b = 1.0f;
  float vertex_r = 1.0f, vertex_g = 1.0f, vertex_b = 1.0f;

 protected:
  void initializeGL() override;
  void resizeGL(int weight, int height) override;
  void paintGL() override;
};

#endif  // GLWIDGET_H
