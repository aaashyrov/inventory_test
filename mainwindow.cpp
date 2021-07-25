//
// Created by alisher on 7/24/21.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <database/sqlitedb.hpp>

constexpr unsigned int count = 3;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui_{std::make_unique<Ui::Widget>()} {}

bool MainWindow::initialize(int argc, char **argv) noexcept {
  database_ = std::make_shared<SqliteDb>(Param{"localhost", "inventory", "user", "pass"});
  if (not database_->isOpen()) {
    message_ = database_->message();
    return false;
  }

  ui_->setupUi(this);
  ui_->gameWidget->hide();
  ui_->inventoryTableWidget->setRowCount(count);
  ui_->inventoryTableWidget->setColumnCount(count);
  ui_->inventoryTableWidget->verticalHeader()->hide();
  ui_->inventoryTableWidget->horizontalHeader()->hide();
  auto cellWidth = ui_->inventoryTableWidget->width() / count - 1;
  auto cellHeight = ui_->inventoryTableWidget->height() / count - 1;
  for (std::size_t i = 0; i < count; ++i) {
    ui_->inventoryTableWidget->setColumnWidth(i, cellWidth);
    ui_->inventoryTableWidget->setRowHeight(i, cellHeight);
  }
  return true;
}

const QString &MainWindow::message() noexcept {
  return message_;
}

MainWindow::~MainWindow() = default;
