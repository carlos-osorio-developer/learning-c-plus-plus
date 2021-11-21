// Crea una clase padre llamada Transporte, con atributos llamados capacidad y velocidad máxima.
// Crea una clase hija llamada Aereo, con atributos llamados pasajeros y combustible.
// Crea una clase hija llamada Terrestre, con atributos llamados pasajeros y combustible.
// Crea una clase hija llamada Maritimo, con atributos llamados pasajeros y combustible.

#include <iostream>
using namespace std;

//Clase padre
class Transporte{
  private:
    int capacidad;
    int vel_maxima;
  public:
    //Constructor
    Transporte(int capacidad, int vel_maxima){
      this->capacidad = capacidad;
      this->vel_maxima = vel_maxima;
    }
    //Setters
    void setCapacidad(int capacidad){
      this->capacidad = capacidad;
    }
    void setVel_maxima(int vel_maxima){
      this->vel_maxima = vel_maxima;
    }
    //Getters
    int getCapacidad(){
      return capacidad;
    }
    int getVel_maxima(){
      return vel_maxima;
    }
};

//Clase hija Aereo (herencia de Transporte)
class Aereo: public Transporte{
  private:
    int pasajeros;
    int combustible;
  public:
    //Constructor (se llama al constructor de la clase padre -Transporte-)
    Aereo(int capacidad, int vel_maxima, int pasajeros, int combustible):Transporte(capacidad, vel_maxima){
      this->pasajeros = pasajeros;
      this->combustible = combustible;
    }
    //Setters
    void setPasajeros(int pasajeros){
      this->pasajeros = pasajeros;
    }
    void setCombustible(int combustible){
      this->combustible = combustible;
    }
    //Getters
    int getPasajeros(){
      return pasajeros;
    }
    int getCombustible(){
      return combustible;
    }
};

//Clase hija Terrestre (herencia de Transporte)
class Terrestre: public Transporte{
  private:
    int pasajeros;
    int combustible;
  public:
    //Constructor (se llama al constructor de la clase padre -Transporte-)
    Terrestre(int capacidad, int vel_maxima, int pasajeros, int combustible):Transporte(capacidad, vel_maxima){
      this->pasajeros = pasajeros;
      this->combustible = combustible;
    }
    //Setters
    void setPasajeros(int pasajeros){
      this->pasajeros = pasajeros;
    }
    void setCombustible(int combustible){
      this->combustible = combustible;
    }
    //Getters
    int getPasajeros(){
      return pasajeros;
    }
    int getCombustible(){
      return combustible;
    }
};

//Clase hija Maritimo (herencia de Transporte)
class Maritimo: public Transporte{
  private:
    int pasajeros;
    int combustible;
  public:
    //Constructor (se llama al constructor de la clase padre -Transporte-)
    Maritimo(int capacidad, int vel_maxima, int pasajeros, int combustible):Transporte(capacidad, vel_maxima){
      this->pasajeros = pasajeros;
      this->combustible = combustible;
    }
    //Setters
    void setPasajeros(int pasajeros){
      this->pasajeros = pasajeros;
    }
    void setCombustible(int combustible){
      this->combustible = combustible;
    }
    //Getters
    int getPasajeros(){
      return pasajeros;
    }
    int getCombustible(){
      return combustible;
    }
};

int main(){
  //Creacion de transporte aereo con capacidad=50 personas, velocidad máxima=500 km/h, 
  //pasajeros=48 personas, combustible=10000 litros
  Aereo jet(50, 500, 48, 10000);
  //Creacion de transporte terrestre con capacidad=30 personas, velocidad máxima=80 km/h, 
  //pasajeros=20 personas, combustible=100 galones
  Terrestre copetran(30, 80, 20, 100);
  //Creacion de transporte maritimo con capacidad=200 personas, velocidad máxima=150 nudos,
  //pasajeros=169 personas, combustible=20000 litros
  Maritimo barco(200, 150, 169, 20000);
  
  //Mostrar datos de los transportes
  cout << "Datos del transporte aereo: jet" << endl;
  cout << "Capacidad: " << jet.getCapacidad() << " personas" << endl;
  cout << "Velocidad máxima: " << jet.getVel_maxima() << " km/h" << endl;
  cout << "Pasajeros: " << jet.getPasajeros() << " personas" << endl;
  cout << "Combustible: " << jet.getCombustible() << " litros" << endl;  
  cout << endl;

  cout << "Datos del transporte terrestre: copetran" << endl;
  cout << "Capacidad: " << copetran.getCapacidad() << " personas" << endl;
  cout << "Velocidad máxima: " << copetran.getVel_maxima() << " km/h" << endl;
  cout << "Pasajeros: " << copetran.getPasajeros() << " personas" << endl;
  cout << "Combustible: " << copetran.getCombustible() << " galones" << endl;
  cout << endl;

  cout << "Datos del transporte maritimo: barco" << endl;
  cout << "Capacidad: " << barco.getCapacidad() << " personas" << endl;
  cout << "Velocidad máxima: " << barco.getVel_maxima() << " nudos" << endl;
  cout << "Pasajeros: " << barco.getPasajeros() << " personas" << endl;
  cout << "Combustible: " << barco.getCombustible() << " litros" << endl;
  return 0;
};