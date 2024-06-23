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

// == Scoops...

class Scoop : public Component {
 public:
  Scoop(const size_t numScoops,
        const float pricePerScoop,
        const std::string baseName) :
    Component(pricePerScoop * numScoops)
  {
    if (numScoops > 1) {
      name_ = baseName + " x" + std::to_string(numScoops);
    } else {
      name_ = baseName;
    }
  }

  std::string_view name() const override { return name_; }

 protected:
  std::string name_;
};

// ========= Ice cream flavours ========

class Vanilla : public Scoop {
 public:
  Vanilla(const size_t numScoops) :
    Scoop(numScoops, 0.50, "Vanilla") {}
};

class Chocolate : public Scoop {
 public:
  Chocolate(const size_t numScoops) :
    Scoop(numScoops, 0.60, "Chocolate") {}
};

class Strawberry : public Scoop {
 public:
  Strawberry(const size_t numScoops) :
    Scoop(numScoops, 0.60, "Strawberry") {}
};

class Pistachio : public Scoop {
 public:
  Pistachio(const size_t numScoops) :
    Scoop(numScoops, 0.70, "Pistachio") {}
};

// ====================================


