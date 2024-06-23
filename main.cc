// Things you may or may not need
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
 * == Task description ==
 *
 *  A contractor was hired to implement an ice cream dispenser receipt maker.
 *  They left after a disagreement with the managers - you are told to pick up the work.
 *  They managed to implement the user input, but it is lacking the infrastructure to build the ice cream!
 *  See TODO markers throughout the code.
 *
 *  Create a program for an ice cream dispenser. The ice cream dispenser can
 *  make ice creams with:
 *  - A cone.                                         £0.30
 *  - Multiple scoops:
 *    = Vanilla                                       £0.50 per scoop
 *    = Chocolate                                     £0.60 per scoop
 *    = Strawberry                                    £0.60 per scoop
 *    = Pistachio                                     £0.70 per scoop
 *  - A chocolate flake.                              £1.00
 *  - Sprinkles: {Chocolate, Hundreds-and-thousands}  £0.30
 *
 *  All of these are optional additions apart from the cone, which is implicitly added to the order.
 *
 *  The program accepts user text input, to build an ice cream.
 *
 *  Finally, when the user inputs "done", output a receipt for the ice cream based on the user's choice.
 *  This can be in whatever format you would like, but some base code is provided by the previous contractor.
 *
 *  TIPS:
 *  - I recommend using object oriented principles wherever possible.
 *    Remember, std::unique_ptr<const BaseClass> can be used to hold polymorphic types.
 *  - There are many ways to do this; there is no correct way. Have fun!
*/ 


class IceCreamDispenser {
 public:
  IceCreamDispenser() {}

  /// Print the final receipt. Accepts an output stream to print to.
  // TODO: Incomplete.
  void printReceipt() const {
    // Set number of significant figures.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Ice cream receipt ===" << std::endl
              << "==  Cone : £" << basePrice_ << std::endl;

    /// === TODO: Build a receipt ===
    /// =============================

    std::cout << "=== Total price: £" << basePrice_ << std::endl
              << "=========================" << std::endl;
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
  // TODO: Not used yet?
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
      // TODO
    } else if (input == "chocolate") {
      // TODO
    } else if (input == "strawberry") {
      // TODO
    } else if (input == "pistachio") {
      // TODO
    } else if (input == "flake") {
      // TODO
    } else if (input == "sprinkles") {
      std::cout << "What type of sprinkles? (multicolour, chocolate) : " << std::endl;
      std::string input;
      std::cin >> input;

      if (input == "multicolour") {
        // TODO
      } else if (input == "chocolate") {
        // TODO
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

  // First, build the ice cream from user input.
  dispenser.userInput();

  // Finally, produce a receipt for the built ice cream.
  dispenser.printReceipt();

  return 0;
}
