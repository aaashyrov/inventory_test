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

class MainWindow : public QWidget {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;
  bool initialize(int argc, char **argv) noexcept;
  const QString& message() noexcept;

 private:
  QString message_;
  std::unique_ptr<Ui::Widget> ui_;
  std::shared_ptr<Database> database_;
  std::unique_ptr<Controller> controller_;
};

#endif //INVENTORY_TEST__MAINWINDOW_H_
