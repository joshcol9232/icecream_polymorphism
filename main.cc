#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <ostream>

/*
 * == Task description ==
 *
 *  Create a program for an ice cream dispenser. The ice cream dispenser can
 *  make ice creams with:
 *  - A cone.              £0.30
 *  - A number of scoops of ice cream of flavours:
 *    = Vanilla            £0.50
 *    = Chocolate          £0.60
 *    = Strawberry         £0.60
 *    = Pistachio          £0.70
 *  - A chocolate flake.   £1.00
 *  - Sprinkles: {Chocolate, multicolour} £0.30
 *
 *  All of these are optional additions apart from the cone, which is implicitly added to the order.
 *
 *  The program should accept user text input, to build an ice cream.
 *
 *  Finally, when the user inputs "done", output a reciept for the ice cream based on the user's choice.
 *  This can be in whatever format you would like.
 *
 *  TIPS:
 *  - Start off without any user input, just building an ice cream in the program.
 *  - I recommend using a builder approach, with object oriented principles.
 *    Remember, std::unique_ptr<const T> can be used to hold polymorphic types.
 *  - There are many ways to do this; there is no correct way. Have fun!
*/ 

#include "Component.h"
#include "Scoop.h"

class IceCreamBuilder {
 public:
  IceCreamBuilder() {}

  template<typename ScoopType>
  IceCreamBuilder& withScoop(const size_t num = 1) {
    order_.push_back(std::make_unique<ScoopType>(num));
    return *this;
  }

  IceCreamBuilder& withSprinkles(const SprinkleType type) {
    order_.push_back(std::make_unique<Sprinkles>(type));
    return *this;
  }

  IceCreamBuilder& withFlake() {
    order_.push_back(std::make_unique<Flake>());
    return *this;
  }

  std::ostream& reciept(std::ostream& os) const {
    // Set number of s.f
    os << std::fixed << std::setprecision(2);

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
    } else if (input == "done" || input == "Done") {
    } else {
      std::cout << "Unrecognised input... Moving on." << std::endl;
    }
    std::cout << "------------" << std::endl;
  }

  // Base price - cost of cone.
  static constexpr float basePrice_ = 0.30;
};

int main(int argc, char * argv[]) {
  IceCreamBuilder inputFactory;
  inputFactory.userInput();
  inputFactory.reciept(std::cout) << std::endl;

  return 0;
}
