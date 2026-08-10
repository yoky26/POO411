#include <iostream>

void Imprimir(const int &num) {
  // num = 34;
  std::cout << num << std::endl;
}

void Sumar1(int num) {
  num = num + 1;
  std::cout << "Valor: " << num << " dentro " << &(num) << std::endl;
}

void Sumar_ref(int &num) {
  num = num + 1;
  std::cout << "Valor: " << num << " dentro " << &(num) << std::endl;
}

int main() {
  int num = 0;

  // Sumar1(num); // parametro por valor

  Sumar_ref(num); // parametro por referencia

  std::cout << "valor: " << num << " fuera:" << &(num) << std::endl;

  Imprimir(num);
  return 0;
}
