#include <QApplication>

#include "viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  viewer w;
  w.show();
  return a.exec();
}
