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
    Pelicula(string nombre="", string tipoActor="", int duracion=0, int valor=0){ 
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
  Pelicula pelicula;
  string nombre;
  string tipoActor;
  int duracion;
  int valor;
  int valorRecargo;
  int porcentaje;

  cout << "Ingrese el nombre de la pelicula: ";
  cin >> nombre;
  pelicula.setNombre(nombre);
  
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
  pelicula.setTipoActor(tipoActor);

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
  pelicula.setDuracion(duracion);

  cout << "Ingrese el valor de la pelicula: ";
  cin >> valor;
  pelicula.setValor(valor);
  
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
