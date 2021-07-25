//
// Created by alisher on 7/24/21.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <database/sqlitedb.hpp>
#include <iostream>
#include <QDebug>
constexpr unsigned int count = 3;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui_{std::make_unique<Ui::Widget>()}, controller_{std::make_unique<Controller>()} {}

bool MainWindow::initialize(int argc, char **argv) noexcept {
  database_ =
      std::make_shared<SqliteDb>(Param{"127.0.0.1", "/home/alisher/CLionProjects/inventory_test/resources/inventory.db",
                                       "root", ""});
  if (not database_->isOpen()) {
    message_ = database_->message();
    return false;
  }

  if (not controller_->initialize(database_)) {
    return false;
  }

  ui_->setupUi(this);

  ui_->gameWidget->hide();

  ui_->inventoryTableWidget->setColumnCount(count);
  ui_->inventoryTableWidget->verticalHeader()->hide();
  ui_->inventoryTableWidget->horizontalHeader()->hide();
  ui_->inventoryTableWidget->setRowCount(controller_->inventory().size() / count);

  auto cellsize = ui_->inventoryTableWidget->width() / count - 1;
  for (std::size_t i = 0; i < count; ++i) {
    ui_->inventoryTableWidget->setColumnWidth(i, cellsize);
    ui_->inventoryTableWidget->setRowHeight(i, cellsize);
  }

  ui_->itemTableWidget->verticalHeader()->hide();
  ui_->itemTableWidget->setColumnCount(1);
  ui_->itemTableWidget->horizontalHeader()->hide();
  ui_->itemTableWidget->setColumnWidth(0, cellsize);
  ui_->itemTableWidget->setRowCount(controller_->items().size());

  for (std::size_t i = 0; i < controller_->items().size(); ++i) {
    ui_->itemTableWidget->setRowHeight(i, cellsize);
  }

  for (size_t i = 0; i < controller_->items().size(); ++i) {
    auto image = new QImage();
    if (not image->load("/home/alisher/CLionProjects/inventory_test/resources/" + controller_->items()[i].impath())) {
      qDebug() << "image " << controller_->items()[i].impath() << " was not loaded";
      return false;
    }

    auto *item = new QTableWidgetItem{};
    item->setData(Qt::DecorationRole, QPixmap::fromImage(*image).scaled(cellsize, cellsize));
    ui_->itemTableWidget->setItem(i, 0, item);
  }

  return true;
}

const QString &MainWindow::message() noexcept {
  return message_;
}

MainWindow::~MainWindow() = default;
