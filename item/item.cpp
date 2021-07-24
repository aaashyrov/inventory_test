//
// Created by alisher on 7/24/21.
//

#include "item.hpp"

Item::Item(Item::Type type, std::string image_path) : type_{type}, image_path_{std::move(image_path)} {}
