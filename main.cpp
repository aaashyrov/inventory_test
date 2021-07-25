#include <QMessageBox>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow mainwindow;

  if (not mainwindow.initialize(argc, argv)) {
    QMessageBox message_box;
    message_box.setText(mainwindow.message());
    return message_box.exec();
  }

  mainwindow.show();

  return app.exec();
}
