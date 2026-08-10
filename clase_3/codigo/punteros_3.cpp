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
  ~Persona() { std::cout << "Muerto" << std::endl; }
};

void Nacer_y_Morir() {
  Persona *p = new Persona("juan", 4);
  p->Saludar();
  delete p; // destruir objeto
  // delete p; //da error
  p = nullptr;
}

int main() {
  Nacer_y_Morir();
  std::cout << "Final" << std::endl;
  return 0;
}
