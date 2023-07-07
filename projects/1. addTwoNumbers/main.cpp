#include "../../utils.h"
#include <iostream>
#include <string>

template <class T> T addNumbers(T firstNumber, T secondNumber) {
  T sum = firstNumber + secondNumber;
  return sum;
}

int main() {
  int a, b, sum;
  a = input<int>("Enter the first number: ");
  b = input<int>("Enter the second number: ");
  sum = addNumbers<int>(a, b);
	print("The sum of", a, "and", b, "is", sum);
  return 0;
}
