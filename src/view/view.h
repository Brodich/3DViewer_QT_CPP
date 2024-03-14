#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <locale.h>

#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>

//#include "glwidget.h"
//#include "../model/parser.h"
#include "../controller/controller.h"

//#define DIMENTION_COUNT 3

// extern "C" {
//#include "../back/parser.h"
// }

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget* parent = nullptr);
  ~View();

  void SetController(s21::Controller* controll) { m_controll = controll; }
 private slots:
  void on_open_file_clicked();

  void on_translate_x_valueChanged(int arg1);
  void on_translate_y_valueChanged(int arg1);
  void on_translate_z_valueChanged(int arg1);

  void on_rotate_x_valueChanged(int arg1);
  void on_rotate_y_valueChanged(int arg1);
  void on_rotate_z_valueChanged(int arg1);

  void on_scale_valueChanged(int arg1);

  void on_color_back_clicked();
  void on_color_line_clicked();
  void on_color_vertex_clicked();

  void on_line_width_valueChanged(int arg1);
  void on_line_style_solid_toggled(bool checked);

  void on_vertex_size_valueChanged(int arg1);
  void on_vertex_style_circle_clicked();
  void on_vertex_style_none_clicked();
  void on_vertex_style_square_clicked();

  void on_projection_type_central_toggled(bool checked);
  void on_screenshot_clicked();

  void save_settings(void);
  void restore_settings(void);

  void on_line_width_slider_valueChanged(int value);

 private:
  Ui::View* ui;
  s21::Controller* m_controll;
};
}  // namespace s21
#endif  // MAINWINDOW_H
