#pragma once

#include "Component.h"

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



