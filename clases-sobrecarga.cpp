// Desarrollar una aplicación software original (no se admiten copias entre compañeros) que
// contemple lo siguiente:

// Una clase Prueba como se aprecia en la figura, donde se evidencie por medio de la creación de
// objetos todas las sobrecargas posibles de las funciones constructoras de la clase, las variables i, j y
// k son de tipo entero. La Función miembro Mostrar(), muestra el valor de i, la Función miembro
// Mostrar2() llama a la Función Mostrar() y muestra j, finalmente la Función miembro Mostrar3()
// llama a la Función Mostrar2() y muestra k. Se deben tener mensajes en cada uno de los
// constructores donde se evidencie cual de los mismos es el que está inicializando los objetos
// respectivos.

#include <iostream>
#include <stdlib.h>
using namespace std;

class Prueba {
  int i, j, k;
  public:
    Prueba() {
      i = 0;
      j = 0;
      k = 0;
      cout << "Constructor 1" << endl;
    }

    Prueba(int i) {
      this->i = i;
      j = 0;
      k = 0;
      cout << "Constructor 2" << endl;
    }

    Prueba(int i, int j) {
      this->i = i;
      this->j = j;
      k = 0;
      cout << "Constructor 3" << endl;
    }

    Prueba(int i, int j, int k) {
      this->i = i;
      this->j = j;
      this->k = k;
      cout << "Constructor 4" << endl;
    }

    ~Prueba() {
      cout << "Destructor" << endl;
    }

    void Mostrar() {
      cout << "i = " << i << ", ";
    }

    void Mostrar2() {
      Mostrar();
      cout << "j = " << j << ", ";
    }

    void Mostrar3() {
      Mostrar2();
      cout << "k = " << k << ". " << endl;
    }        
};

int main() {
  // Primero se crean los objetos
  cout << "Creando objeto sin argumentos: " << endl;
  Prueba p1;
  cout << endl;
  cout << "Creando objeto con 1 argumento: " << endl;
  Prueba p2(1);
  cout << endl;
  cout << "Creando objeto con 2 argumentos: " << endl;
  Prueba p3(1, 2);
  cout << endl;
  cout << "Creando objeto con 3 argumentos: " << endl;
  Prueba p4(1, 2, 3);
  cout << endl;
  // Se muestran los valores de los objetos
  cout << "Mostrando valores del objeto sin argumentos: " << endl;
  p1.Mostrar3();
  cout << endl;
  cout << "Mostrando valores del objeto con 1 argumento: " << endl;
  p2.Mostrar3();
  cout << endl;
  cout << "Mostrando valores del objeto con 2 argumentos: " << endl;  
  p3.Mostrar3();
  cout << endl;
  cout << "Mostrando valores del objeto con 3 argumentos: " << endl;
  p4.Mostrar3();
  cout << endl;
  // Se destruyen los objetos
  cout << "Los 4 objetos se destruyen al finalizar el programa:" << endl;
  return 0;
}