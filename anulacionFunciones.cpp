// Herencia, Sobrecarga y Anulación de Funciones

// Clase Estudiante y clase Docente heredadas públicamente de la clase Persona 
// como se aprecia en la Figura 1. 
// Se deben generar las funciones constructoras suficientes y las funciones miembro 
// para que se pueda visualizar la salida de la Figura 2, tenga presente que la 
// función Mostrar() se debe anular en las Subclases y utilizar las funciones 
// Mostrar() de la Superclase por medio del Operador de Ámbito de Resolución cuando 
// sea necesario, adicionalmente la función NotaFinal() retorna un valor flotante 
// y los constructores de Estudiante inicializan las notas en 0 (cero).

// Clase Persona: 
// 1) ID
// 2) Nombre
// 3) Persona()
// 4) Persona(int, string)
// 5) Actualizar()
// 6) Mostrar()
// 7) ~Persona()

// Clase Docente:
// 1) Profesión
// 2) Docente()
// 3) Docente(int, string, string)
// 4) Mostrar()
// 5) ~Docente()

// Clase Estudiante
// 1) Programa
// 2) Notas[3]
// 3) Estudiante()
// 4) Estudiante(int, string)
// 5) Estudiante(int, string, string)
// 6) Mostrar()
// 7) IngresarNotas()
// 8) NotaFinal()
// 9) ~Estudiante()

#include <iostream>
#include <string>
using namespace std;

// Clase Padre Persona
class Persona{    
  public:
    int id;
    string nombre;    
    //Constructor sin parametros
    Persona(){
      cout << "Constructor por defecto de la clase Persona" << endl;
      id = 0;
      nombre = "Por identificar";
      cout << "Nombre: " << nombre << ", Identificación: " << id << endl;
    }
    //Constructor con parametros
    Persona(int id, string nombre){
      cout << "Constructor con parametros de la clase Persona" << endl;
      this->id = id;
      this->nombre = nombre;
      cout << "Nombre: " << nombre << ", Identificación: " << id << endl;
    }
    //Funcion para actualizar los datos de la clase    
    void Actualizar(int id, string nombre){
      this->id = id;
      this->nombre = nombre;
    }
    //Funcion para mostrar los datos de la clase
    void Mostrar(){
      cout << "--- Mostrar() de la clase Persona: ---" << endl;
      cout << "Identificación: " << id << ", Nombre: " << nombre << endl;      
    }
    //Funcion para destruir la clase
    ~Persona(){
      cout << "Se ha destruido objeto de la clase Persona" << endl;
    }
};

// Clase Hija Docente
class Docente: public Persona{
  private:
    string profesion;
  public:
    //Constructor sin parametros
    Docente(){
      cout << "Constructor por defecto de la clase Docente" << endl;
      profesion = "Por definir";
      cout << "Profesión: " << profesion << endl;
    }
    //Constructor con parametros
    Docente(int id, string nombre, string profesion): Persona(id, nombre){
      cout << "Constructor con parametros de la clase Docente" << endl;          
      this->profesion = profesion;
      cout << "Profesión: " << profesion << endl;
    }
    //Funcion para mostrar los datos de la clase
    void Mostrar(){           
      Persona::Mostrar(); // operador de ambito de resolución
      cout << "--- Mostrar() de la clase Docente: ---" << endl; 
      cout << "Profesion: " << profesion << endl;
    }
    //Funcion para destruir la clase
    ~Docente(){
      cout << "Se ha destruido objeto de la clase Docente" << endl;
    }
};

// Clase Hija Estudiante
class Estudiante: public Persona{
  private:
    string programa;
    float notas[3];
  public:
    //Constructor sin parametros
    Estudiante(){
      cout << "Constructor por defecto de la clase Estudiante" << endl;
      programa = "Por definir";
      for(int i = 0; i < 3; i++){
        notas[i] = 0;
      }
      cout << "Programa: " << programa << endl;
    }
    //Constructor con dos parametros
    Estudiante(int id, string nombre): Persona(id, nombre){
      cout << "Constructor con dos parametros de la clase Estudiante" << endl;
      programa = "Por definir";
      for(int i = 0; i < 3; i++){
        notas[i] = 0;
      }
      cout << "Programa: " << programa << endl;
    }
    //Constructor con tres parametros
    Estudiante(int id, string nombre, string programa): Persona(id, nombre){
      cout << "Constructor con 3 parametros de la clase Estudiante" << endl;
      this->programa = programa;
      for(int i = 0; i < 3; i++){
        notas[i] = 0;
      }
      cout << "Programa: " << programa << endl;
    }
    //Funcion para mostrar los datos de la clase
    void Mostrar(){       
      Persona::Mostrar(); // operador de ámbito de resolución
      cout << "--- Mostrar() de la clase Estudiante: ---" << endl;
      cout << "Programa: " << programa << endl;
      cout << "Notas: ";
      for(int i = 0; i < 3; i++){
        cout << notas[i] << ", ";
      }
      cout << endl;
    }
    //Funcion para ingresar las notas
    void IngresarNotas(){
      cout << "Ingrese las notas del estudiante: " << endl;
      for(int i = 0; i < 3; i++){
        cout << "Nota " << i+1 << " de 3: ";
        cin >> notas[i];
      }
    }
    //Funcion para calcular la nota final
    float NotaFinal(){
      float suma = 0;
      for(int i = 0; i < 3; i++){
        suma += notas[i];
      }
      return suma/3;
    }
    //Funcion para destruir la clase
    ~Estudiante(){
      cout << "Se ha destruido objeto de la clase Estudiante" << endl;
    }
};

int main(){
  cout << "----------------------------------------------------" << endl;
  cout << "Ejercicio de POO con Persona, Docente y Estudiante" << endl;
  cout << "----------------------------------------------------" << endl;
  cout << endl;

  cout << "--- Crea estudiante por defecto ---" << endl;
  Estudiante estudiante;  
  cout << endl;

  cout << "--- Crea estudiante con dos parametros ---" << endl;
  Estudiante estudiante2(123123123, "Juan Perez");
  cout << endl;

  cout << "--- Funcionalidades de la clase Estudiante con dos parametros ---" << endl;
  estudiante2.Mostrar();
  cout << endl;

  cout << "--- Crea estudiante con dos parametros ---" << endl;
  Estudiante estudiante3(321321321, "Javier Penagos", "Ingenieria de Software");
  cout << endl;

  cout << "--- Funcionalidades de la clase Estudiante con tres parametros ---" << endl;
  estudiante3.IngresarNotas();
  estudiante3.Mostrar();
  cout << "Nota final: " << estudiante3.NotaFinal() << endl;
  cout << endl;

  cout << "--- Crea docente con tres parametros ---" << endl;
  Docente docente(616616616, "Jaime Perea", "MSc de Ingeniería de datos");
  cout << endl;

  cout << "--- Funcionalidades de la clase Docente con tres parametros ---" << endl;
  docente.Mostrar();  
  cout << endl;      
  return 0;
}