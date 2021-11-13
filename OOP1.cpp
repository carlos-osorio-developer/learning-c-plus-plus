// Utilizando los conceptos de Programación Orientada a Objetos (Constructores-Métodos) 
// realizar un programa en C++ que permita ingresar por teclado el nombre de la película, 
// tipo de actor (reconocido – no reconocido), 
// la duración de la película (2 – 3 Horas) y el valor de la película.
// Para el desarrollo tenga en cuenta lo siguiente:
// Si el tipo de actor es no reconocido y la duración de la película es de 2 horas, 
// el valor a pagar por la compra se aumenta en un 10% del valor de la película.
// Si el tipo de actor es reconocido y la duración de la película es de 3 horas, 
// el valor a pagar por la compra se aumenta en un 20% del valor de la película.
// Nota: Cualquier otra combinación no es válida (mostrar mensaje)
// 1. Se debe mostrar por pantalla un informe con: Los datos de la película:
// nombre, tipo de actor, duración, valor de la película, valor a pagar por el recargo, 
// porcentaje y el valor total a pagar por la película.

#include<iostream>
using namespace std;

class Pelicula{
  private:
    string nombre;
    string tipoActor;
    int duracion;
    int valor;
    int valorRecargo;
    int porcentaje;
    int valorTotal;

  public:
  //Constructor
    Pelicula(string nombre, string tipoActor, int duracion, int valor){ 
      this->nombre = nombre;
      this->tipoActor = tipoActor;
      this->duracion = duracion;
      this->valor = valor;
      this->valorRecargo = 0;
      this->porcentaje = 0;
      this->valorTotal = 0;
    }

  //Metodos
    void setNombre(string nombre){
      this->nombre = nombre;
    }

    void setTipoActor(string tipoActor){
      this->tipoActor = tipoActor;
    }

    void setDuracion(int duracion){
      this->duracion = duracion;
    }

    void setValor(int valor){
      this->valor = valor;
    }

    void setValorRecargo(int valorRecargo){
      this->valorRecargo = valorRecargo;
    }

    void setPorcentaje(int porcentaje){
      this->porcentaje = porcentaje;
    }

    void setValorTotal(int valorTotal){
      this->valorTotal = valorTotal;
    }

    string getNombre(){
      return this->nombre;
    }

    string getTipoActor(){
      return this->tipoActor;
    }

    int getDuracion(){
      return this->duracion;
    }

    int getValor(){
      return this->valor;
    }

    int getValorRecargo(){
      return this->valorRecargo;
    }

    int getPorcentaje(){
      return this->porcentaje;
    }

    int getValorTotal(){
      return this->valorTotal;
    }

    void calcValorRecargo(); //Calcula el valor del recargo
};

//Calcula el valor del recargo
void Pelicula::calcValorRecargo(){
  if((this->getTipoActor() == "NR" || this->getTipoActor()== "nr") && this->getDuracion() == 2){    
    this->valorRecargo = this->getValor() * 0.1;
    this->porcentaje = 10;
    this->valorTotal = this->getValor() + this->valorRecargo;
  }else if((this->getTipoActor() == "R" || this->getTipoActor()== "r") && this->getDuracion() == 3){
    this->valorRecargo = this->getValor() * 0.2;
    this->porcentaje = 20;
    this->valorTotal = this->getValor() + this->valorRecargo;
  }else{
    this->valorRecargo = 0;
    this->porcentaje = 0;
    this->valorTotal = this->getValor();
  }
};

int main(){  
  string nombre;
  string tipoActor;
  int duracion;
  int valor;
  int valorRecargo;
  int porcentaje;

  cout << "Ingrese el nombre de la pelicula: ";
  std::getline(cin, nombre); 
  
  cout << "Ingrese el tipo de actor (R para reconocido, NR para no-reconocido): ";  
  //Validacion de tipo de actor
  while (cin.fail() || (tipoActor != "NR" && tipoActor != "R" && tipoActor != "nr" && tipoActor != "r")){ 
    cin >> tipoActor;
    cin.clear();
    cin.ignore(256, '\n');
    if(tipoActor != "NR" && tipoActor != "R" && tipoActor != "nr" && tipoActor != "r"){
      cout << "No se admiten otras combinaciones además de R o NR: ";
    }
  }  

  //Validacion de duracion
  cout << "Ingrese la duracion de la pelicula: ";
  while (cin.fail() || (duracion != 2 && duracion != 3)){
    cin >> duracion;
    cin.clear();
    cin.ignore(256, '\n');
    if (duracion != 2 && duracion != 3){
      cout << "No se admiten otras combinaciones además de 2 o 3: ";
    }    
  }  

  cout << "Ingrese el valor de la pelicula: ";
  cin >> valor;  
  
  Pelicula pelicula(nombre, tipoActor, duracion, valor);
  pelicula.calcValorRecargo(); //Calcula el valor del recargo

  cout << "Nombre: " << pelicula.getNombre() << endl;
  cout << "Tipo de actor: " << pelicula.getTipoActor() << endl;
  cout << "Duracion: " << pelicula.getDuracion() << endl;
  cout << "Valor: " << pelicula.getValor() << endl;
  cout << "Valor del recargo: " << pelicula.getValorRecargo() << endl;
  cout << "Porcentaje: " << pelicula.getPorcentaje() << endl;
  cout << "Valor total: " << pelicula.getValorTotal() << endl;

  return 0;
}
