#include <iostream>
using namespace std;

struct cliente {
  string nombre;
  int cedula;
  int tipoVivienda;
  int valorVivienda;
};

int main() {

  cliente user;

  cout << "\n" << "Bienvenido a su calculadora inmobiliaria" << "\n" << "Por favor ingrese el nombre del usuario: ";  
  std::getline(cin, user.nombre);

  cout << "\n" << "A continuación, ingrese la cédula del usuario: "; 
  while (!(cin >> user.cedula)){   
    cout << "\n" << "Error => Ingrese unicamente numeros: "; 
    cin.clear();
    cin.ignore(123, '\n');    
  }

  cout << "\n" << "Ingrese el valor de su vivienda: ";  
  while (!(cin >> user.valorVivienda)){   
    cout << "\n" << "Error => Ingrese unicamente numeros: "; 
    cin.clear();
    cin.ignore(123, '\n');    
  }  

  
  while (cin.fail() || (user.tipoVivienda != 1 && user.tipoVivienda != 2))
  {                 
    cout << "\n" << "Finalmente, ingrese 1 si su vivienda se encuentra en obra negra, o ingrese 2 si ya tiene acabados" << "\n";
    cin >> user.tipoVivienda;   
    cin.clear();
    cin.ignore(123, '\n');           
  }  
}