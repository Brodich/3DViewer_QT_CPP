#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model business_logic;
  s21::Controller control(&business_logic);
  s21::View w;
  w.SetController(&control);
  w.show();
  // Need for double number dot instead of comma
  setlocale(LC_NUMERIC, "C");

  return a.exec();
}
