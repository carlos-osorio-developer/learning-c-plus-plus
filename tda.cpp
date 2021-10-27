#include <iostream>
using namespace std;

struct cliente {
  string nombre;
  int cedula;
  int tipoVivienda;
  int valorVivienda;
};

int calculadora(int valorPredio, int tipoVivienda) {

  int criterio;
  int valorNuevo;

  if(tipoVivienda==1) {
    cout << "\n" << "Ya que su predio se encuentra en obra negra, ingrese su dimension en metros cuadrados: "; 
    while (!(cin >> criterio)){   
      cout << "\n" << "Error => Ingrese unicamente numeros: "; 
      cin.clear();
      cin.ignore(123, '\n');    
    }
    
    if(criterio<60) {
      valorNuevo = valorPredio*0.9;
    }
    else {
      valorNuevo = valorPredio*0.85;
    }
  }
  else {
    cout << "\n" << "Ya que su predio tiene acabados, ingrese el nivel de estrato: "; 
    while (!(cin >> criterio)){   
      cout << "\n" << "Error => Ingrese unicamente numeros: "; 
      cin.clear();
      cin.ignore(123, '\n');    
    }

    if(criterio>4) {
      valorNuevo = valorPredio*1.2;
    }
    else {
      valorNuevo = valorPredio*1.1;
    }
  }  
  return valorNuevo;
}

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

  int valorizacion;
  valorizacion = calculadora(user.valorVivienda, user.tipoVivienda);
}