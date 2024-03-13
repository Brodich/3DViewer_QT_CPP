#define GL_SILENCE_DEPRECATION

#include "glwidget.h"

void glwidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
}

void glwidget::resizeGL(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, w, h);
}

void glwidget::paintGL() {
  initializeGL();
  glClearColor(back_r, back_g, back_b, 1);
//  glClearColor(color_back.redF(), color_back.greenF(), color_back.blueF(),
//               color_back.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    qDebug() << "paintGL\n";
//  glClearColor(255,255,255,1);
  int flag = 0;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (central_type == true) {
    glFrustum(-size, size, -size, size, size, -size);
  } else {
    glOrtho(-size, size, -size, size, -size, size);
  }
  glMatrixMode(GL_MODELVIEW);

  glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);
//  glColor3d(color_line.redF(), color_line.greenF(), color_line.blueF());
  glColor3d(line_r, line_g, line_b);

  if (solid_line == true) {
    glLineWidth(line_width);
  } else {
    flag |= GL_LINE_STIPPLE;
    glLineStipple(1, line_width);
  }

  glPointSize(size_vertex);

  if (vertex_style == 2) {
    flag |= GL_POINT_SMOOTH;

  } else if (vertex_style == 3) {
    glDisable(GL_POINT_SMOOTH);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnable(flag);

  if (vertex_style == 1) {
    glDrawElements(GL_LINES, polygons.number_of_vertices, GL_UNSIGNED_INT,
                   polygons.vertices);
  }
  if (vertex_style > 1) {
    glDrawElements(GL_LINES, polygons.number_of_vertices, GL_UNSIGNED_INT,
                   polygons.vertices);
//    glColor3d(color_vertex.redF(), color_vertex.greenF(), color_vertex.blueF());
    glColor3d(vertex_r, vertex_g, vertex_b);
    glDrawElements(GL_POINTS, polygons.number_of_vertices, GL_UNSIGNED_INT,
                   polygons.vertices);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_LINE_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
//  update();
}

//void glwidget::ChangeBackColor(QColor color) {
//  color_back = color;
//  update();
//}

//void glwidget::ChangeLineColor(QColor color) {
//  color_line = color;
//  update();
//}

//void glwidget::ChangeVertexColor(QColor color) {
//  color_vertex = color;
//  update();
//}


void glwidget::paint() { paintGL(); }
