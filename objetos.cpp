// Desarrolle la clase PrismaHex (Prisma Hexagonal) con los atributos adecuados, todos los
// constructores posibles acorde con los atributos, destructor y los métodos Area (área de la base),
// AreaSup (área de superficie) y Volumen. En la función principal se deben crear los objetos suficientes
// para que se pueda evidenciar el uso de todos constructores. A partir de cada objeto creado hacer el
// llamado a cada una de las funciones miembros de la clase a fin de visualizar su funcionamiento.

#include <iostream>
#include <stdlib.h>
using namespace std;

class PrismaHex {
  private:
    float base, altura, apotema;
  public:
    PrismaHex() {
      base = 1;
      altura = 1;
      apotema = 1;
      cout << "Constructor 1 sin argumentos, base=1, altura=1 y apotema=1 (valor por defecto)" << endl;
    }

    PrismaHex(int base) {
      this->base = base;
      altura = 1;
      apotema = 1;
      cout << "Constructor 2 con un argumento, base=" << base << ", altura=1 y apotema=1 (valores por defecto)" << endl;
    }

    PrismaHex(int base, int altura) {
      this->base = base;
      this->altura = altura;      
      apotema = 1;
      cout << "Constructor 3 con dos argumentos, base=" << base << ", altura=" << altura << " y apotema= 1 (valor por defecto)." << endl;
    }

    PrismaHex(int base, int altura, int apotema) {
      this->base = base;
      this->altura = altura;
      this->apotema = apotema;
      cout << "Constructor 4 con tres argumentos, base=" << base << ", altura=" << altura << " y apotema=" << apotema << "." << endl;
    }

    ~PrismaHex() {
      cout << "Destructor" << endl;
    }

    void Area() {
      cout << "Area de la base: " << (base * altura) / 2 << endl;
    }

    void AreaSup() {
      cout << "Area de la superficie: " << (base * altura * apotema) / 2 << endl;
    }

    void Volumen() {
      cout << "Volumen: " << (base * altura * apotema) / 3 << endl;
    }
};

int main() {
  cout << "Prueba de constructores y objetos de la clase PrismaHex" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << endl;
  cout << "Objeto PrismaHex sin argumentos" << endl;
  PrismaHex p1;
  p1.Area();
  p1.AreaSup();
  p1.Volumen();
  cout << endl;

  cout << "Objeto PrismaHex con un argumento" << endl;
  PrismaHex p2(2);
  p2.Area();
  p2.AreaSup();
  p2.Volumen();
  cout << endl;
  
  cout << "Objeto PrismaHex con dos argumentos" << endl;
  PrismaHex p3(2, 3);
  p3.Area();
  p3.AreaSup();
  p3.Volumen();
  cout << endl;

  cout << "Objeto PrismaHex con tres argumentos" << endl;
  PrismaHex p4(2, 3, 4);
  p4.Area();
  p4.AreaSup();
  p4.Volumen();
  cout << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "A continuación, se invocará automáticamente un destructor para cada objeto creado:" << endl;
  return 0;
}