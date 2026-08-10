#include <iostream>
#include <memory>

class Persona {
  std::string nombre;
  int *edad;

public:
  Persona() {
    this->nombre = "Faceless";
    this->edad = new int(0);
  }
  Persona(std::string _nombre, int _edad)
      : nombre(_nombre), edad(new int(_edad)) {}
  Persona(const Persona &other)
      : nombre(other.nombre), edad(new int(*other.edad)) {}

  void Saludar() const {
    std::cout << "Hola soy " << this->nombre << " el cobrador"
              << "mi edad es:" << *this->edad << std::endl;
  }
  ~Persona() {
    delete this->edad;
    this->edad = nullptr;
    std::cout << "Muerto " << this->nombre << std::endl;
  }
};

int main() {
  Persona p{};
  auto p2 = p;
  std::cout << "p1: " << &p << "p2: " << &p2 << std::endl;
  return 0;
}
