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

=========================
 To build:

1) `module load bb-env`
2) `g++ main.cc -o icecream -std=c++17`
3) To run: `./icecream`
