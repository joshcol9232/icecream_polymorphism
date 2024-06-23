#include <iostream>
#include <memory>
#include <vector>
#include <ostream>

/*
 * == Task description ==
 *
 *  Create a program for an ice cream dispenser. The ice cream dispenser can
 *  make ice creams with:
 *  - A cone.   £0.50
 *  - A number of scoops of ice cream of flavours:
 *    = Vanilla            £0.50
 *    = Chocolate          £0.60
 *    = Strawberry         £0.60
 *    = Pistachio          £0.70
 *  - A chocolate flake.   £1.00
 *  - Sprinkles: {Chocolate, multicolour} £0.30
 *
 *  All of these are optional additions apart from the cone.
 *  Additionally, there are a few set options from the buttons on the machine.
 *  - Base vanilla. (1 cone, 1 scoop vanilla)
 *  - Vanilla with flake. (1 cone, 1 scoop vanilla, chocolate flake)
 *
 *  Finally, output a reciept for the ice cream based on the user's choice.
*/ 

#include "Component.h"
#include "Scoop.h"

class IceCreamFactory {
 public:
  IceCreamFactory() {}

  template<typename ScoopType>
  IceCreamFactory& withScoop(const size_t num = 1) {
    order_.push_back(std::make_unique<ScoopType>(num));
    return *this;
  }

  IceCreamFactory& withSprinkles(const SprinkleType type) {
    order_.push_back(std::make_unique<Sprinkles>(type));
    return *this;
  }

  IceCreamFactory& withFlake() {
    order_.push_back(std::make_unique<Flake>());
    return *this;
  }

  std::ostream& reciept(std::ostream& os) const {
    os << "=== Ice cream summary :) ===" << std::endl
       << "==  Cone : £" << basePrice_ << std::endl;

    float totalPrice = basePrice_;

    for (const auto& comp : order_) {
      os << "==  " << comp->name() << " : £" << comp->price() << std::endl;
      totalPrice += comp->price();
    }

    os << "=== Total price: £" << totalPrice << std::endl;
    os << "============================" << std::endl;

    return os;
  }

  // === USER INPUT ===
  void userInput() {
    std::cout << "Build your ice cream (finish with 'done'): " << std::endl;
    std::string input;

    do {
      std::cin >> input;
      processLine(input);
    } while (input != "Done" && input != "done");
  }

 private:
  std::vector<std::unique_ptr<const Component>> order_;

  size_t askNumScoops() {
    std::cout << "How many scoops? : " << std::endl;
    std::string input;
    std::cin >> input;

    if (input == "") { return 1; }
    return std::stoi(input);
  }

  template<typename ScoopType>
  void processScoop() {
    size_t numScoops = askNumScoops();
    withScoop<ScoopType>(numScoops);
  }

  void processLine(const std::string_view input) {
    if (input == "vanilla") {
      processScoop<Vanilla>();
    } else if (input == "chocolate") {
      processScoop<Chocolate>();
    } else if (input == "strawberry") {
      processScoop<Strawberry>();
    } else if (input == "pistachio") {
      processScoop<Pistachio>();
    } else if (input == "flake") {
      withFlake();
    } else if (input == "sprinkles") {
      std::cout << "What type of sprinkles? (multicolour, chocolate) : " << std::endl;
      std::string input;
      std::cin >> input;

      if (input == "multicolour") {
        withSprinkles(SprinkleType::Multicolour);
      } else if (input == "chocolate") {
        withSprinkles(SprinkleType::Chocolate);
      } else {
        std::cout << "Unrecognised sprinkle type: " << input << ", moving on..." << std::endl;
      }
    }
    std::cout << "------------" << std::endl;
  }

  // Base price - cost of cone.
  static constexpr float basePrice_ = 0.30;
};

int main(int argc, char * argv[]) {
  IceCreamFactory factory;
  factory.withScoop<Vanilla>();
  factory.withScoop<Chocolate>();
  factory.withSprinkles(SprinkleType::Chocolate);
  factory.withFlake();

  factory.reciept(std::cout) << std::endl;

  IceCreamFactory inputFactory;
  inputFactory.userInput();
  inputFactory.reciept(std::cout) << std::endl;

  return 0;
}
