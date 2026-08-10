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

  int get_edad() const { return *this->edad; }
  std::string get_nombre() const { return this->nombre; }

  friend std::ostream &operator<<(std::ostream &os, const Persona &p);

  virtual void Saludar() const {
    std::cout << "Hola soy " << this->nombre << " mi edad es: " << *this->edad
              << std::endl;
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

class Empleado : public Persona {
private:
  int sueldo;
  std::string seguro;

public:
  Empleado(std::string _nombre, int _edad, std::string _seguro, int _sueldo)
      : seguro(_seguro), sueldo(_sueldo), Persona(_nombre, _edad) {}

  void Saludar() const override {

    std::cout << "Hola soy " << this->get_nombre()
              << " y soy empleado, mi sueldo es " << this->sueldo << std::endl;
  }
};

class Estudiante : public Persona {
private:
  std::string matricula;

public:
  Estudiante(std::string _nombre, int _edad, std::string _matricula)
      : matricula(_matricula), Persona(_nombre, _edad) {}

  void Saludar() const override {

    std::cout << "Hola soy " << this->get_nombre() << " tengo "
              << this->get_edad()
              << " , soy estudiante y no he dormido este ano, mi matricula es "
              << this->matricula << std::endl;
  }
};

int main() {
  Empleado p{"Juan Perez", 43, "023402r", 400000};
  Estudiante e1("Jhon smith", 34, "00-00-00");
  // std::cout << e1;
  p.Saludar();
  e1.Saludar();
  return 0;
}
