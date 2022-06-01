// Desarrollar una aplicación software que contemple dos clases de la siguiente forma:

// La clase Base contiene los enteros X, Y y Z, y las funciones F1(), F2(), F3() y int F4().
// La clase derivada, hereda de la clase Base, y contiene el entero w, y las funciones F3() y int F5().

// Se deben implementar todos los constructores posibles, destructores y funciones miembro de cada una de las clases.

// Para el caso de las funciones se debe tener en cuenta lo siguiente:
// F1() muestra el valor de x, F2() llama a F1() y muestra el valor de y, F3() llama a F2() y muestra a z, la función F4() retorna x. En la clase derivada F3() se anula mostrando la suma de y, z y w. F5() retorna el número más pequeño de los cuatro (x, y, z, w).

// Desde la función principal se deben crear objetos de tipo Derivada que muestren todas las funcionalidades.

#include <iostream>
#include <string>
using namespace std;

class Base {  
  public:
    int x, y, z;
    Base() {
      x = 0;
      y = 0;
      z = 0;
      cout << "Constructor de la clase Base sin argumentos" << endl;
    }

    Base(int x) {
      this->x = x;
      y = 0;
      z = 0;
      cout << "Constructor de la clase Base con un argumento" << endl;
    }

    Base(int x, int y) {
      this->x = x;
      this->y = y;
      z = 0;
      cout << "Constructor de la clase Base con dos argumentos" << endl;
    }

    Base(int x, int y, int z) {
      this->x = x;
      this->y = y;
      this->z = z;
      cout << "Constructor de la clase Base con tres argumentos" << endl;
    }

    ~Base() {
      cout << "Destructor de la clase Base" << endl;
    }

    void F1() {
      cout << "x = " << x << ", ";
    }

    void F2() {
      F1();
      cout << "y = " << y << ", ";
    }

    void F3() {
      F2();
      cout << "z = " << z << ", ";
    }

    int F4() {
      return x;
    }
};

class Derivada : public Base {  
  public:
    int w;
    Derivada() : Base() {
      w = 0;
      cout << "Constructor de la clase Derivada sin argumentos" << endl;
    }

    Derivada(int x) : Base(x) {
      w = 0;
      cout << "Constructor de la clase Derivada con un argumento" << endl;
    }

    Derivada(int x, int y) : Base(x, y) {
      w = 0;
      cout << "Constructor de la clase Derivada con dos argumentos" << endl;
    }

    Derivada(int x, int y, int z) : Base(x, y, z) {
      w = 0;
      cout << "Constructor de la clase Derivada con tres argumentos" << endl;
    }

    Derivada(int x, int y, int z, int w) : Base(x, y, z) {
      this->w = w;
      cout << "Constructor de la clase Derivada con cuatro argumentos" << endl;
    }

    ~Derivada() {
      cout << "Destructor de la clase Derivada" << endl;
    }

    void F3() { // Se anula la función F3() de la clase Base, y muestra la suma de y, z y w.
      int suma = y + z + w;
      cout << "y + z + w = " << suma;
    }

    int F5() {
      int min = x;
      if (y < min) min = y;
      if (z < min) min = z;
      if (w < min) min = w;
      return min;
    }
};

int main() {
  cout << "--------------------------------" << endl;
  cout << "Constructores de la clase Derivada" << endl;
  cout << "--------------------------------" << endl;
  cout << "Constructor de la clase Derivada sin argumentos" << endl;
  Derivada d1;
  cout << "Constructor de la clase Derivada con un argumento" << endl;
  Derivada d2(1);
  cout << "Constructor de la clase Derivada con dos argumentos" << endl;  
  Derivada d3(1, 2);
  cout << "Constructor de la clase Derivada con tres argumentos" << endl;
  Derivada d4(1, 2, 3);
  cout << "Constructor de la clase Derivada con cuatro argumentos" << endl;
  Derivada d5(3, 2, 5, 8);
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto sin argumentos (X, Y, Z y W son 0 por defecto)" << endl;
  cout << "Llamada a la función F1()" << endl;
  d1.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  d1.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Derivado, muestra la suma de y, z y w:" << endl;
  d1.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << d1.F4() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto con un argumento: X=1 (Y, Z y W son 0 por defecto)" << endl;
  cout << "Llamada a la función F1()" << endl;
  d2.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  d2.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Derivado, muestra la suma de y, z y w:" << endl;
  d2.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << d2.F4() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto con dos argumentos: X=1, Y=2 (Z y W son 0 por defecto)" << endl;
  cout << "Llamada a la función F1()" << endl;
  d3.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  d3.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Derivado, muestra la suma de y, z y w:" << endl;
  d3.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << d3.F4() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto con tres argumentos: X=1, Y=2, Z=3 (W es 0 por defecto)" << endl;
  cout << "Llamada a la función F1()" << endl;
  d4.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  d4.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Derivado, muestra la suma de y, z y w:" << endl;
  d4.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << d4.F4() << endl;
  cout << "El menor de los valores es: " << d4.F5() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto con cuatro argumentos: X=3, Y=2, Z=5, W=8" << endl;
  cout << "Llamada a la función F1()" << endl;
  d5.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  d5.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Derivado, muestra la suma de y, z y w:" << endl;
  d5.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << d5.F4() << endl;
  cout << "El menor de los valores es: " << d5.F5() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Constructor de la clase Base:" << endl;
  cout << "--------------------------------" << endl;
  Base b1(1, 2, 3);  
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Funciones del objeto con tres argumentos: X=1, Y=2, Z=3" << endl;
  cout << "Llamada a la función F1()" << endl;
  b1.F1();
  cout << endl;
  cout << "Llamada a la función F2()" << endl;
  b1.F2();
  cout << endl;
  cout << "La función F3, llamada en un objeto Base, muestra los valores de X, Y y Z, en vez de la suma Y+Z+W: " << endl;
  b1.F3();
  cout << endl;
  cout << "La función f4 retorna el valor de x = " << b1.F4() << endl;
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << "Se ejecutan los destructores:" << endl;
  return 0;
}    