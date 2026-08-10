#include <iostream>
#include <memory>

class Persona {
  std::string nombre;
  int *edad;

public:
  Persona(std::string _nombre, int _edad) {
    (*this).nombre = _nombre;

    this->edad = new int(_edad);
  }
  void Saludar() const {
    std::cout << "Hola soy " << this->nombre << " el cobrador"
              << "mi edad es:" << *this->edad << std::endl;
  }
  ~Persona() {
    delete this->edad;
    this->edad = nullptr;
    std::cout << "Muerto" << std::endl;
  }
};

void Nacer_y_Morir() {
  std::unique_ptr<Persona> p = std::make_unique<Persona>("juan", 4);
  p->Saludar();
  std::cout << p.get() << std::endl;
}

int main() {
  Nacer_y_Morir();
  std::cout << "Final" << std::endl;
  return 0;
}
