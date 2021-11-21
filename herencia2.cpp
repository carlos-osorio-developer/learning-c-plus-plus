//Crea una clase padre llamada texto, con código, título y año de publicacion.
//Crea una clase hija llamada libro, con estado de prestamo.
//Crea una clase hija llamada revista, con número de páginas.

#include<iostream>
using namespace std;

//Clase padre
class Texto{
  private:
    int codigo;
    string titulo;
    int anio;
  public:
  //Constructor
    Texto(int codigo, string titulo, int anio){
      this->codigo = codigo;
      this->titulo = titulo;
      this->anio = anio;
    }

    //Setters
    void setCodigo(int codigo){
      this->codigo = codigo;
    };
    void setTitulo(string titulo){
      this->titulo = titulo;
    };
    void setAnio(int anio){
      this->anio = anio;
    };

    //Getters
    int getCodigo(){
      return codigo;
    };
    string getTitulo(){
      return titulo;
    };
    int getAnio(){
      return anio;
    };
};

//Clase hija libro (herencia de texto)
class Libro: public Texto{
  private:
    bool prestado;
  public:
  //Constructor (se llama al constructor de la clase padre -Texto-)
    Libro(int codigo, string titulo, int anio, bool prestado=false): Texto(codigo, titulo, anio){
      this->prestado = prestado;
    };
    //Getters
    bool getPrestado(){
      return prestado;
    };
    //Setters
    void setPrestado(bool prestado){
      this->prestado = prestado;
    };
};

//Clase hija revista (herencia de texto)
class Revista: public Texto{
  private:
    int numeroPaginas;
  public:
  //Constructor (se llama al constructor de la clase padre -Texto-)
    Revista(int codigo, string titulo, int anio, int numeroPaginas): Texto(codigo, titulo, anio){
      this->numeroPaginas = numeroPaginas;
    };
    //Getters
    int getNumeroPaginas(){
      return numeroPaginas;
    };
    //Setters
    void setNumeroPaginas(int numeroPaginas){
      this->numeroPaginas = numeroPaginas;
    };
};

int main(){
  //Creación de objetos de tipo libro
  Libro libro1(1, "El señor de los anillos", 1954, false);
  cout << "Libro 1, con codigo: " << libro1.getCodigo() << ", llamado: " << libro1.getTitulo() << ", del anio: " << libro1.getAnio() << ", y estado de prestamo: " << libro1.getPrestado() << endl;
  //Un usuario presta el libro
  libro1.setPrestado(true);
  cout << "Un usuario ha prestado el libro..." << endl;
  cout << "Libro 1, con codigo: " << libro1.getCodigo() << ", llamado: " << libro1.getTitulo() << ", del anio: " << libro1.getAnio() << ", y estado de prestamo: " << libro1.getPrestado() << endl;
  //Creación de objetos de tipo revista
  Revista revista1(2, "Times magazine", 1999, 100);
  cout << "Revista 1, con codigo: " << revista1.getCodigo() << ", llamada: " << revista1.getTitulo() << ", del anio: " << revista1.getAnio() << ", y numero de paginas: " << revista1.getNumeroPaginas() << endl;
  //Un usuario le arranca páginas a la revista
  revista1.setNumeroPaginas(90);
  cout << "Un usuario ha arrancado páginas a la revista..." << endl;
  cout << "Revista 1, con codigo: " << revista1.getCodigo() << ", llamada: " << revista1.getTitulo() << ", del anio: " << revista1.getAnio() << ", y numero de paginas: " << revista1.getNumeroPaginas() << endl;
  return 0;
};