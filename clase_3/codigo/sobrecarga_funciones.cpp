#include <iostream>

int suma(const int &a, const int &b) { return a + b; }

float suma(const float &a, const float &b) { return a + b; }

int main() {
  int a = 3;
  int b = 34;
  float c = 3.4f;
  float d = 1.3f;
  std::cout << suma(a, b) << std::endl;

  std::cout << suma(c, d) << std::endl;

  return 0;
}
