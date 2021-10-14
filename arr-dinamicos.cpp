#include <iostream>
using namespace std;

float muestra_arreglo(int * valores)
{  
  if(valores[2]==1)
  {
    if(valores[1]>100)
    {      
      return 0.09;      
    }
    else
    {
      return 0.05;
    }
  }
  else
  {
    if(valores[1]>20000000)
    {      
      return 0.15;
    }
    else
    {      
      return 0.10;
    }
  }
}

int main()
{
  int valorizacion[3]{0, 0, 0}; //{valor comercial, dimension o ingresos, residencial o comercial}

  cout << "\n" << "Bienvenido a su calculador de valorización" << "\n" << "Ingrese la direccion de su predio" << "\n"; 
  string direccion;
  std::getline(cin, direccion);

  while (cin.fail() || (valorizacion[2] != 1 && valorizacion[2] != 2))
  {         
    cout << "\n" << "A continuacion, ingrese 1 si es un predio residencial, 2 si es un predio comercial" << "\n";        
    cin >> valorizacion[2];    
    cin.clear();
    cin.ignore(1, '\n');           
  }  

  cout << "\n" << "Ingrese el valor comercial de su predio: "<< "\n";  
  cin >> valorizacion[0];  

  if (valorizacion[2]==1)
  {
    while (cin.fail() || valorizacion[1]==0) {
      cout << "\n" << "Ingrese la dimension de su predio (en m^2): "<< "\n";
      cin >> valorizacion[1];
      cin.clear();
      cin.ignore(1, '\n');
    }    
    cout << "\n" << "\n" << "El tipo de predio es residencial.";
  }
  else
  {
    while (cin.fail() || valorizacion[1]==0) {
      cout << "\n" << "Ingrese los ingresos reportados de su predio"<< "\n";
      cin >> valorizacion[1];
      cin.clear();
      cin.ignore(1, '\n');
    }
    cout << "\n" << "\n" << "El tipo de predio es comercial.";
  }       

  float porcentaje_valorizacion = muestra_arreglo(valorizacion);

  cout << "\n" << "Su valor comercial es de: " << valorizacion[0];
  cout << "\n" << "Su dirección es: " << direccion;

  if (valorizacion[2]==1)
  {
    cout << "\n" << "La dimension de su predio es: " << valorizacion[1] << " m^2";
  }
  else{
    cout << "\n" << "Los ingresos reportados de su predio son: " << valorizacion[1];
  }  

  

  cout << "\n" << "El porcentaje de su valorizacion es de: " << porcentaje_valorizacion*100 << "%";
  cout << "\n" << "El valor de su valorizacion es de: " << fixed << valorizacion[0]*porcentaje_valorizacion;
  cout << "\n" << "El nuevo valor de su predio es de: " << fixed << valorizacion[0]*(1+porcentaje_valorizacion) << "\n";

}