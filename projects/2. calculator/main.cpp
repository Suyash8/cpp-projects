#include "../../utils.h"
#include <iostream>
#include <limits>
#include <string>

template <class T> T add(T a, T b) { return a + b; }

template <class T> T subtract(T a, T b) { return a - b; }

template <class T> T multiply(T a, T b) { return a * b; }

template <class T> T divide(T a, T b) { return a / b; }

int getMenuChoice() {
  print(PrintOptions().separator("\n"), "Please enter a choice",
        "1 for addition", "2 for subtraction", "3 for multiplication",
        "4 for division");
  int choice = input<int>(
      "Enter your choice (1-4) for the operation you want to perform: ", true);
  while (choice < 1 || choice > 4) {
    print("Invalid choice. Please enter a valid choice (1-4).");
    choice = input<int>(
        "Enter your choice (1-4) for the operation you want to perform: ",
        true);
  }
  return choice;
}

void performOperation(int choice, float number1, float number2) {
  switch (choice) {
  case 1:
    print(number1, "+", number2, "=", add(number1, number2));
    break;
  case 2:
    print(number1, "-", number2, "=", subtract(number1, number2));
    break;
  case 3:
    print(number1, "*", number2, "=", multiply(number1, number2));
    break;
  case 4:
    try {
      if (number2 == 0) {
        print("Error: Cannot divide by zero!");
      } else {
        print(number1, "/", number2, "=", divide(number1, number2));
      }
    } catch (const std::exception &e) {
      print(e.what());
    }
    break;
  }
}

int main() {
  print("Welcome to the Calculator!");
  while (true) {
    int choice = getMenuChoice();

    float number1 = input<float>("Enter the first number: ", true);
    float number2 = input<float>("Enter the second number: ", true);

    performOperation(choice, number1, number2);

    std::string continueChoice =
        input("Do you want to perform another operation? (yes/no): ", true);
    if (continueChoice != "yes") {
      break;
    }
  }

  return 0;
}