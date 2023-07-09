#include "../../utils.h"
#include <algorithm>
#include <map>
#include <math.h>

int getUserConversionFromChoice() {
  print();
  print("Please select what you want to convert from:");
  print(PrintOptions().separator("\n"), "1. Decimal", "2. Binary", "3. Octal",
        "4. Hexadecimal");
  int choice = input<int>("Please enter your choice: ");
  print();
  return choice;
}

int getUserConversionToChoice() {
  print();
  print("Please select what you want to convert to:");
  print(PrintOptions().separator("\n"), "1. Decimal", "2. Binary", "3. Octal",
        "4. Hexadecimal");
  int choice = input<int>("Please enter your choice: ");
  print();
  return choice;
}

std::string convertNumber(int convertFromChoice, int convertToChoice,
                          std::string number) {
  std::string convertedNumber = "";

  if (convertFromChoice == convertToChoice)
    return number;

  if (convertFromChoice == 1) {
    long long numberToConvert = stringToInt(number);
    // Decimal to Binary
    if (convertToChoice == 2) {
      while (numberToConvert != 0) {
        convertedNumber += intToString(numberToConvert % 2);
        numberToConvert /= 2;
      }
      reverse(convertedNumber.begin(), convertedNumber.end());
    }
    // Decimal to Octal
    if (convertToChoice == 3) {
      while (numberToConvert != 0) {
        convertedNumber += intToString(numberToConvert % 8);
        numberToConvert /= 8;
      }
      reverse(convertedNumber.begin(), convertedNumber.end());
    }
    // Decimal to Hexadecimal
    if (convertToChoice == 4) {
      while (numberToConvert != 0) {
        std::string digits = "0123456789ABCDEF";
        convertedNumber += digits[numberToConvert % 16];
        numberToConvert /= 16;
      }
      reverse(convertedNumber.begin(), convertedNumber.end());
    }
  } else if (convertFromChoice == 2) {
    long long numberToConvert = stringToInt(number), convertedNumberInt = 0;
    int i = 0;

    while (numberToConvert != 0) {
      convertedNumberInt += ((numberToConvert % 10) * pow(2, i));
      numberToConvert /= 10;
      i++;
    }
    convertedNumber =
        convertNumber(1, convertToChoice, intToString(convertedNumberInt));
  } else if (convertFromChoice == 3) {
    long long numberToConvert = stringToInt(number), convertedNumberInt = 0;
    int i = 0;

    while (numberToConvert != 0) {
      convertedNumberInt += ((numberToConvert % 10) * pow(8, i));
      numberToConvert /= 10;
      i++;
    }
    convertedNumber =
        convertNumber(1, convertToChoice, intToString(convertedNumberInt));
  } else if (convertFromChoice == 4) {
    // int i = 0, convertedNumberInt = 0;
    std::map<char, std::string> hexMap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"},
        {'a', "1010"}, {'b', "1011"}, {'c', "1100"}, {'d', "1101"},
        {'e', "1110"}, {'f', "1111"}};

    while (number != "") {
      convertedNumber = hexMap[number[number.length() - 1]] + convertedNumber;
      number = number.substr(0, number.length() - 1);
    }
    convertedNumber = convertNumber(2, convertToChoice, convertedNumber);
  }

  return convertedNumber;
}

int main() {

  print("Welcome to Number Converter!");
  int convertFromChoice = getUserConversionFromChoice();
  std::string numberToConvert =
      input("Enter the number in the chosen format: ");
  int convertToChoice = getUserConversionToChoice();
  std::string convertedNumber =
      convertNumber(convertFromChoice, convertToChoice, numberToConvert);
  print("The converted number is:", convertedNumber);
}