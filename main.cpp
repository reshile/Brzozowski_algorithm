#include "regex.h"

int main() {
  std::string regex;
  std::string word;
  std::cin >> regex >> word;
  int result = Evaluate(regex, word);
  std::cout << result << '\n';
}
