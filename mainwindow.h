//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST__MAINWINDOW_H_
#define INVENTORY_TEST__MAINWINDOW_H_
#include <memory>
#include <QWidget>

#include <controller/controller.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

 private:
  std::unique_ptr<Ui::Widget> ui_;
  std::shared_ptr<Database> database_;
  std::unique_ptr<Controller> controller_;
};

#endif //INVENTORY_TEST__MAINWINDOW_H_
