#include <iostream>

int main() {
  int edad = 34;
  std::cout << "edad 1:" << edad << std::endl;

  int *pEdad = &edad;
  *pEdad = 0;
  std::cout << "edad 2:" << edad << std::endl;
  return 0;
}
