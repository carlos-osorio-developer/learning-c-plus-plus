//Crea una clase llamada persona, y dos clases hijas llamadas alumno y profesor.

#include<iostream>
using namespace std;

//Clase padre
class Persona{
  private:
    int id;
    string nombre;    
  public:
  //Constructor
    Persona(int id=0, string nombre="NN"){
      this->id = id;
      this->nombre = nombre;
    };
    //Setters
    void setId(int id){
      this->id = id;
    };
    void setNombre(string nombre){
      this->nombre = nombre;
    };
    //Getters
    int getId(){
      return this->id;
    };
    string getNombre(){
      return this->nombre;
    };
};

//Clase hija (hereda de Persona)
class Alumno: public Persona{
  private:
    string programa;
  public:
  //Constructor (se llama al constructor de la clase padre -Persona-)
    Alumno(int id=0, string nombre="NN", string programa="NN"):Persona(id, nombre){
      this->programa = programa;
    };
    //setters
    void setPrograma(string programa){
      this->programa = programa;
    };
    //getters
    string getPrograma(){
      return this->programa;
    };
};

//Clase hija (hereda de Persona)
class Docente: public Persona{
  private:
    string profesion;
  public:
  //Constructor (se llama al constructor de la clase padre -Persona-)
    Docente(int id=0, string nombre="NN", string profesion="NN"):Persona(id, nombre){
      this->profesion = profesion;
    };
    //Setters
    void setProfesion(string profesion){
      this->profesion = profesion;
    };
    //Getters
    string getProfesion(){
      return this->profesion;
    };
};

int main(){  
  Docente d(1, "Pedro", "Mecanico"); //Copia 1 de la clase Docente
  Docente d2(2, "Juan", "Electricista"); //Copia 2 de la clase Docente
  Alumno a(3, "Maria", "Programacion"); //Copia 1 de la clase Alumno
  Alumno a2(4, "Jose", "Prototipado"); //Copia 2 de la clase Alumno
  cout << "El Docente 1 se llama: " << d.getNombre() << ", y trabaja como: " << d.getProfesion() << endl;
  cout << "El Docente 2 se llama: " << d2.getNombre() << ", y trabaja como: " << d2.getProfesion() << endl;
  cout << "El Alumno 1 se llama: " << a.getNombre() << ", y esta cursando: " << a.getPrograma() << endl;
  cout << "El Alumno 2 se llama: " << a2.getNombre() << ", y esta cursando: " << a2.getPrograma() << endl;
  return 0;
};