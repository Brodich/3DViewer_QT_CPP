#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("3DViewer");
  w.show();
  // Need for double number dot instead of comma
  setlocale(LC_NUMERIC, "C");

  return a.exec();
}
