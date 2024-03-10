#define GL_SILENCE_DEPRECATION

#include "glwidget.h"

void glwidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void glwidget::resizeGL(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, w, h);
}

void glwidget::paintGL() {
  initializeGL();
  glClearColor(back_r, back_g, back_b, 1);
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
    glColor3d(vertex_r, vertex_g, vertex_b);
    glDrawElements(GL_POINTS, polygons.number_of_vertices, GL_UNSIGNED_INT,
                   polygons.vertices);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_LINE_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
  update();
}

void glwidget::paint() { paintGL(); }
