#include<iostream>
using namespace std;

class Funcion
  {    
    public:
    string nombre;
    int precio;
    Funcion(string nombre="NN", int precio=0)
    {
      this->nombre=nombre;
      this->precio=precio;
    };
    void setNombre(string nombre){
      this->nombre = nombre;
    };

    void setPrecio(int precio){
      this->precio = precio;
    };
  };

class Teatro 
{
      
  public:  
  int x = 0;
  string nombre, direccion;
  Funcion funciones[4];
  Teatro(string, string);       
  void crearFuncion(string, int);
  void setNombre(string);
};

Teatro::Teatro(string nombre, string direccion)
{
  this->nombre = nombre;
  this->direccion = direccion;
}

void Teatro::crearFuncion(string nombre, int precio)
{  
  if(x>=4)
  {   
    cout<<"No se pueden crear mas funciones"<<endl;
  }
  else{
    funciones[x] = Funcion(nombre, precio);
    x++;
  }  
};

void Teatro::setNombre(string nombre){
  this->nombre = nombre;
};

int main()
{
  Teatro t("Teatro de la Plaza", "Calle de la Plaza");
  t.crearFuncion("El rey leon", 100);
  t.crearFuncion("El rey leon 2", 200);  
  t.crearFuncion("El rey leon 3", 300); 
  t.crearFuncion("El rey leon 4", 400);    
  t.crearFuncion("El rey leon 5", 500);

  cout << "Nombre: " << t.nombre << endl; // Nombre: Teatro de la Plaza
  cout << "Direccion: " << t.direccion << endl; // Direccion: Calle de la Plaza
  cout << "Funciones: " << t.funciones[0].nombre << endl; // Funciones: El rey leon
  cout << "Precio: " << t.funciones[0].precio << endl; // Precio: 100
  t.funciones[0].setNombre("El nuevo rey leon"); // Cambia el nombre de la funcion
  t.funciones[0].setPrecio(500); // Cambia el precio de la funcion
  cout << "Funciones: " << t.funciones[0].nombre << endl; // Funciones: El nuevo rey leon
  cout << "Precio: " << t.funciones[0].precio << endl; // Precio: 500
  t.setNombre("Nuevo Teatro de la plaza"); // Cambia el nombre del teatro
  cout << "Nombre: " << t.nombre << endl; // Nombre: Nuevo Teatro de la plaza
  return 0;
}