//
// Created by alisher on 7/24/21.
//

#include "item.hpp"

Item::Item(Item::Type type, QString image_path) : type_{type}, image_path_{std::move(image_path)} {}

const QString &Item::impath() const noexcept {
  return image_path_;
}

Item::Type Item::type() const noexcept {
  return type_;
}

QString to_string(Item::Type type) {
  switch (type) {
    case Item::Type::APPLE: return "apple";
    case Item::Type::BANANA: return "banana";
  }
  return "unknown";
}

Item::Type to_type(const QString &type) {
  if (type == "apple") return Item::Type::APPLE;
  if (type == "banana") return Item::Type::BANANA;
  return Item::Type::APPLE;
}
