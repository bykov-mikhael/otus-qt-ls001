#include "wndcalculator.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  wndCalculator w;
  w.show();
  return a.exec();
}
