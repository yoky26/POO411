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
  // copia
  Persona(const Persona &other)
      : nombre(other.nombre), edad(new int(*other.edad)) {}
  // Movimiento
  Persona(Persona &&otra) noexcept {
    this->nombre = std::move(otra.nombre);
    this->edad = new int(*otra.edad);
  }
  friend std::ostream &operator<<(std::ostream &os, const Persona &p);
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

std::ostream &operator<<(std::ostream &os, const Persona &p) {
  os << p.nombre << " " << *p.edad << std::endl;
  return os;
}

int main() {
  Persona p{};
  Persona p2(std::move(p));
  std::cout << p << p2;
  return 0;
}
