//
// Created by alisher on 7/24/21.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr unsigned int count = 3;

Widget::Widget(QWidget *parent) : QWidget(parent), ui_{std::make_unique<Ui::Widget>()} {
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
}

Widget::~Widget() = default;
