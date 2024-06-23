#pragma once

#include <string>
#include <string_view>

class Component {
 public:
  Component(const float price) : price_(price) {}
  float price() const { return price_; }

  virtual std::string_view name() const = 0;

 private:
  float price_;
};

class Flake : public Component {
 public:
  Flake() : Component(1.00) {}
  std::string_view name() const override { return "Flake"; }
};

// == Sprinkles...

enum class SprinkleType {
  Multicolour,
  Chocolate,
};

class Sprinkles : public Component {
 public:
  Sprinkles(const SprinkleType type) :
    Component(0.30)
  {
    switch (type) {
      case SprinkleType::Multicolour:
        name_ = "Sprinkles (Multicolour)";
        break;
      case SprinkleType::Chocolate:
        name_ = "Sprinkles (Chocolate)";
        break;
    }
  }

  std::string_view name() const override { return name_; }

 private:
  std::string name_;
};

