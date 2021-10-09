#include <stdlib.h>
#include <iostream>

using namespace std;

int vet_calc(string raza, string tamanio, int valor_base)
{
    int valor_total;
    if (raza=="labrador" && tamanio=="pequeño")
    {
      valor_total=valor_base*1.1;
    }
    else if (raza=="labrador" && tamanio=="grande")
    {
      valor_total=valor_base*1.2;
    }
    else if (raza=="bulldog" && tamanio=="pequeño")
    {
      valor_total=valor_base*1.15;
    }
    else if (raza=="bulldog" && tamanio=="grande")
    {
      valor_total=valor_base*1.25;
    }
    else {
      return -404;
    }
    return valor_total;
}

string mensaje(string nombre, int valor)
{
  if(valor==-404)
    {
      cout << "Error: No conocemos esa raza ni ese tamaño de perro"<< "\n" << "Tampoco conocemos Google" << "\n";
    }
    else
    {
      cout << "El costo de la consulta para " << nombre << " es de: " << valor << "\n" << "Gracias por preferirnos" << "\n";
    }
    return "";
}

int main()
{
    cout << "Hola! Bienvenido a Labradores&Bulldogs veterinaria" << "\n" << "Por favor, ingrese el nombre de su perro:" << "\n";
    string nombre;
    getline(cin, nombre);
    cout << "Ahora ingrese la raza de su perro (labrador o bulldog)" << "\n";
    string raza;
    getline(cin, raza);
    cout << "Ahora ingrese el tamaño del perro (grande o pequeño)" << "\n";
    string tamanio;
    getline(cin, tamanio);
    cout << "Finalmente, ingrese el valor base de la consulta" << "\n";
    int valor_base;
    cin >> valor_base;

    int valor_final;
    valor_final=vet_calc(raza,tamanio,valor_base);

    mensaje(nombre, valor_final);
    
    return 0;
}