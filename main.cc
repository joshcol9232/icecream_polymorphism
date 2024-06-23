// Things you may or may not need
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <ostream>
#include <string>

/*
 * == Task description ==
 *
 *  A contractor was hired to implement an ice cream dispenser reciept maker.
 *  They left after a disagreement with the managers - you are left to pick up the work.
 *  They managed to implement the user input, but it is lacking the infrastructure to build the ice cream!
 *  See // TODO: Implement. (and YOUR CODE HERE).
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
 *  The program accepts user text input, to build an ice cream.
 *
 *  Finally, when the user inputs "done", output a reciept for the ice cream based on the user's choice.
 *  This can be in whatever format you would like.
 *
 *  TIPS:
 *  - I recommend using a builder approach, with object oriented principles.
 *    Remember, std::unique_ptr<const T> can be used to hold polymorphic types.
 *  - There are many ways to do this; there is no correct way. Have fun!
*/ 


class IceCreamDispenser {
 public:
  IceCreamDispenser() {}

  /// Print the final reciept. Accepts an output stream to print to.
  // TODO: Incomplete.
  std::ostream& printReciept(std::ostream& os) const {
    float totalPrice = basePrice_;

    // Set number of significant figures.
    os << std::fixed << std::setprecision(2);

    os << "=== Ice cream summary :) ===" << std::endl
       << "==  Cone : £" << basePrice_ << std::endl;

    /// === YOUR CODE HERE ===
    /// ======================

    os << "=== Total price: £" << totalPrice << std::endl;
    os << "============================" << std::endl;

    return os;
  }

  // === USER INPUT ===
  void userInput() {
    std::cout << "Build your ice cream (finish with 'done'): " << std::endl;
    std::string input;

    // Get input whilst the user doesn't put "done".
    do {
      std::cin >> input;
      processLine(input);
    } while (input != "Done" && input != "done");
  }

 private:
  // === USER INPUT ===
  /// Asks the user how many scoops to add once a flavour is chosen.
  size_t askNumScoops() {
    std::cout << "How many scoops? : " << std::endl;
    std::string input;
    std::cin >> input;

    if (input == "") { return 1; }
    return std::stoi(input);
  }

  /// Process a line of user input.
  // TODO: Incomplete.
  void processLine(const std::string& input) {
    if (input == "vanilla") {
      /// YOUR CODE HERE
    } else if (input == "chocolate") {
      /// YOUR CODE HERE
    } else if (input == "strawberry") {
      /// YOUR CODE HERE
    } else if (input == "pistachio") {
      /// YOUR CODE HERE
    } else if (input == "flake") {
      /// YOUR CODE HERE
    } else if (input == "sprinkles") {
      std::cout << "What type of sprinkles? (multicolour, chocolate) : " << std::endl;
      std::string input;
      std::cin >> input;

      if (input == "multicolour") {
        /// YOUR CODE HERE
      } else if (input == "chocolate") {
        /// YOUR CODE HERE
      } else {
        std::cout << "Unrecognised sprinkle type: " << input << ", moving on..." << std::endl;
      }
    } else if (input == "done" || input == "Done") {
    } else {
      std::cout << "Unrecognised input... Moving on." << std::endl;
    }
    std::cout << "------------" << std::endl;
  }

  // Base price - cost of the cone.
  static constexpr float basePrice_ = 0.30f;
};


int main(int argc, char * argv[]) {
  IceCreamDispenser dispenser;
  dispenser.userInput();
  dispenser.printReciept(std::cout);

  return 0;
}
