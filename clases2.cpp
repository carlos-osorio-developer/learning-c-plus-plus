#include<iostream>
using namespace std;

class Cuenta{
  private:
    int numero;
    string titular;
    int saldo;    
  public:
    Cuenta(int numero, string titular, long saldo = 0){
      this->numero = numero;
      this->titular = titular;
      this->saldo = saldo;
    }
    void deposito(long valor){
      if(valor > 0){
        saldo += valor;
      }      
    }
    void retiro(long valor){
      if(valor > 0 && valor <= saldo){
        saldo -= valor;
      }
      else{
        cout << "No se puede retirar esa cantidad" << endl;
      }      
    }
    int getSaldo(){
      return saldo;
    }
};

int main(){
  Cuenta c1(1, "Juan", 1000); // Cuenta 1, Juan
  Cuenta c2(2, "Pedro", 2000); // Cuenta 2, Pedro
  cout << "Saldo de Juan: " << c1.getSaldo() << endl; // 1000
  c1.deposito(500); // ingreso de 500 en la cuenta 1
  cout << "Saldo de Juan: " << c1.getSaldo() << endl; // 1500
  c1.retiro(1000); // retiro de 1000 en la cuenta 1
  cout << "Saldo de Juan: " << c1.getSaldo() << endl; // 500
  c1.retiro(1000); // mensaje de error porque no hay 1000 en la cuenta 1
  cout << "Saldo de Pedro: " << c2.getSaldo() << endl; // 2000
  c2.deposito(-500); // no hace nada no se puede depositar un valor negativo
  cout << "Saldo de Pedro: " << c2.getSaldo() << endl; // 2000
  return 0;
}
