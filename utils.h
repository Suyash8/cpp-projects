#include <iostream>
#include <limits>
#include <sstream>
#include <string>

template <typename T> T abs(T n) { return (n < 0) ? -n : n; }

std::string ascii(const std::string &input) {
  std::string result;

  for (char c : input) {
    if (static_cast<unsigned char>(c) > 127) {
      // Replace non-ASCII character with escape sequence
      result += "\\x" + std::to_string(static_cast<unsigned char>(c));
    } else {
      result += c;
    }
  }

  return result;
}

template <typename T>
T input(const std::string &inputString, bool safe = false) {
  T input;
  if (safe) {
    bool isValidInput = false;

    while (!isValidInput) {
      std::cout << inputString;
      std::cin >> input;

      if (std::cin.fail()) {
        std::cout << "Invalid input. Please try again."
                  << "\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else {
        isValidInput = true;
      }
    }
  } else {
    std::cout << inputString;
    std::cin >> input;
  }

  return input;
}

std::string input(const std::string &inputString, bool safe = false) {
  std::string input;
  if (safe) {
    bool isValidInput = false;

    while (!isValidInput) {
      std::cout << inputString;
      std::getline(std::cin >> std::ws, input);

      if (std::cin.fail()) {
        std::cout << "Invalid input. Please try again."
                  << "\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else {
        isValidInput = true;
      }
    }
  } else {
    std::cout << inputString;
    std::cin >> input;
  }

  return input;
}

template <typename T> std::string to_string(const T &obj) {
  std::ostringstream oss;
  oss << obj;
  return oss.str();
}

class PrintOptions {
public:
  PrintOptions &separator(const std::string &sep) {
    separator_ = sep;
    return *this;
  }

  PrintOptions &end(const std::string &e) {
    end_ = e;
    return *this;
  }

  PrintOptions &flush(const bool &f = true) {
    flush_ = f;
    return *this;
  }

  std::string separator() const { return separator_; }
  std::string end() const { return end_; }

private:
  std::string separator_ = " ";
  std::string end_ = "\n";
  bool flush_ = false;
};

template <typename... Args> void print(const Args &...args) {
  std::ostringstream oss;
  ((oss << to_string(args) << PrintOptions().separator()), ...);
  // Add the end string to the output
  oss << PrintOptions().end();
  std::cout << oss.str();
}

template <typename... Args>
void print(const PrintOptions &options, const Args &...args) {
  std::ostringstream oss;
  ((oss << to_string(args) << options.separator()), ...);
  // Add the end string to the output
  oss << options.end();
  std::cout << oss.str();
}

long long stringToInt(const std::string &str) {
  long long result = 0;
  bool isNegative = false;
  size_t startIndex = 0;

  // Check if the string is empty
  if (str.empty()) {
    // Handle the error case appropriately
    throw std::invalid_argument(
        "Empty string cannot be converted to an integer.");
  }

  // Check if the string represents a negative number
  if (str[0] == '-') {
    isNegative = true;
    startIndex = 1;
  }

  // Convert each digit character to its corresponding integer value
  for (size_t i = startIndex; i < str.length(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      long long digitValue = str[i] - '0'; // Convert character to integer value

      // Multiply the result by 10 and add the digit value
      result = result * 10 + digitValue;
    } else {
      // Handle the error case for invalid characters in the string
      throw std::invalid_argument("Invalid character found in the string.");
    }
  }

  // Apply the negative sign if necessary
  if (isNegative) {
    result = -result;
  }

  return result;
}

std::string intToString(long long number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

long long floatToInt(long double number) {
    return static_cast<long long>(number);
}

std::string floatToString(long double number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

long double intToFloat(long long number) {
    return static_cast<long double>(number);
}

long double stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    long double number;
    iss >> number;
    return number;
}