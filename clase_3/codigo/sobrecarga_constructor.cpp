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

void Nacer_y_Morir() {
  std::unique_ptr<Persona> p = std::make_unique<Persona>("juan", 4);
  p->Saludar();
  auto p2 = std::make_unique<Persona>();
  p2->Saludar();
  std::cout << p.get() << std::endl;
}

int main() {
  Nacer_y_Morir();
  std::cout << "Final" << std::endl;
  return 0;
}
