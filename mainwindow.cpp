//
// Created by alisher on 7/24/21.
//

#include "mainwindow.h"
#include "./ui_mainwindow.h"

constexpr unsigned int count = 3;

Widget::Widget(QWidget *parent) : QWidget(parent), ui_{std::make_unique<Ui::Widget>()} {
  ui_->setupUi(this);
  ui_->gameWidget->hide();
  ui_->tableWidget->setRowCount(count);
  ui_->tableWidget->setColumnCount(count);

  ui_->tableWidget->verticalHeader()->hide();
  ui_->tableWidget->horizontalHeader()->hide();
  auto cellWidth = ui_->tableWidget->width() / count - 1;
  auto cellHeight = ui_->tableWidget->height() / count - 1;
  for (std::size_t i = 0; i < count; ++i) {
    ui_->tableWidget->setColumnWidth(i, cellWidth);
    ui_->tableWidget->setRowHeight(i, cellHeight);
  }
}

Widget::~Widget() = default;

