//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_ITEM_ITEM_HPP_
#define INVENTORY_TEST_ITEM_ITEM_HPP_
#include<QString>

class Item {
 public:

  enum class Type {
    APPLE, BANANA
  };

  Item(Type type, QString image_path);

  ~Item() = default;
  Item(const Item &) = default;
  Item(Item &&) noexcept = default;
  Item &operator=(const Item &) = default;
  Item &operator=(Item &&) noexcept = default;
  Type type() const noexcept;
  const QString& impath() const noexcept;
 private:
  Type type_;
  QString image_path_;
};

QString to_string(Item::Type type);
Item::Type to_type(const QString &type);

#endif //INVENTORY_TEST_ITEM_ITEM_HPP_
