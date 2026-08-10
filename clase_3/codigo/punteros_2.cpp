#include <iostream>
class Persona {
  std::string nombre;
  int edad;

public:
  Persona(std::string _nombre, int _edad) {
    (*this).nombre = _nombre;

    this->edad = _edad;
  }
  void Saludar() const {
    std::cout << "Hola soy " << this->nombre << " el cobrador" << std::endl;
  }
};

int main() {
  Persona juan = Persona("pedro", 34);
  Persona *ppersona = &juan;

  ppersona->Saludar();
  return 0;
}
