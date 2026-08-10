# Práctica: Mini sistema de combate RPG

Desarrolle un pequeño programa en C++ que simule un combate entre personajes de un videojuego RPG utilizando **Programación Orientada a Objetos**.

El objetivo principal es utilizar **encapsulación, herencia y polimorfismo**.

## Clases requeridas

### 1. Clase abstracta `Personaje`

Debe contener los siguientes atributos:

* `nombre`
* `vida`

Debe implementar:

* Un constructor.
* Un método `recibirDanio(int cantidad)` que reduzca la vida.
* Un método `mostrarEstado()` que muestre el nombre y la vida actual.
* Un método virtual puro:

```cpp
virtual int atacar() const = 0;
```

La vida nunca debe quedar por debajo de `0`.

---

### 2. Clase `Guerrero`

Debe heredar de `Personaje`.

Debe tener adicionalmente:

* `fuerza`

Debe sobrescribir `atacar()` utilizando `override`.

El daño del guerrero será:

```text
fuerza * 2
```

---

### 3. Clase `Mago`

Debe heredar de `Personaje`.

Debe tener adicionalmente:

* `poderMagico`

Debe sobrescribir `atacar()` utilizando `override`.

El daño del mago será:

```text
poderMagico + 10
```

---

## Programa principal

En `main()`:

1. Crear un objeto `Guerrero`.
2. Crear un objeto `Mago`.
3. Mostrar el estado inicial de ambos personajes.
4. Hacer que el guerrero ataque al mago.
5. Hacer que el mago ataque al guerrero.
6. Mostrar nuevamente el estado de ambos personajes.

Las llamadas a `atacar()` deben realizarse mediante referencias o punteros de tipo `Personaje` para demostrar el uso de **polimorfismo**.

## Requisitos

* `Personaje` debe ser una clase abstracta y no puede instanciarse directamente.
* `Guerrero` y `Mago` deben heredar de `Personaje`.
* Los atributos deben ser privados.
* Debe utilizarse `override`.
* No se permite `using namespace std`.
* Todo el ejercicio puede realizarse en un único archivo `main.cpp`.
* El programa debe compilar correctamente con C++20.

