// Desarrollar una aplicación software original (no se admiten copias entre compañeros) que
// contemple lo siguiente:

// • Una función F1() que sea llamada desde la función principal -main()- que no reciba parámetros
// y que no tenga retorno.

// • Una función F2() que sea llamada desde la función uno -F1()- que reciba un parámetro entero y
// que no tenga retorno.

// • Una función F3() que sea llamada desde la función uno -F1()- que reciba un parámetro entero y
// que no tenga retorno.

// • Una función F4() que sea llamada desde la función dos-F2()- que reciba dos parámetros enteros
// y que tenga un retorno entero.

// • La aplicación debe trabajar con variables locales y paso de parámetros por valor.

// Con respecto a la función uno -F1()-:
// • Debe crear un arreglo de cinco posiciones, inicializar el mismo con valores aleatorios entre 5 y
// 15 [5,15], diferentes entre sí.
// • Mostrar por pantalla el vector inicializado.
// • Se deben identificar los valores mayores y menores en el arreglo, mostrarlos y llamar a la función
// dos pasándole por valor la suma de estos dos valores.
// • Apoyándose en una variable acumuladora, se debe llamar a la función tres pasándole por valor
// la suma de los otros tres números diferentes al menor y al mayor. Previamente se debe mostrar
// por pantalla la suma calculada.

// Con respecto a la función dos -F2()-:
// • Debe crear un arreglo de cinco posiciones, se debe inicializar el mismo por medio de un ciclo for
// teniendo en cuenta el valor recibido por parámetro desde F1() mas 10 en la primera posición,
// mas 20 en la segunda, mas 30 en la tercera, más 40 para la cuarta y mas 50 para la quinta Ej: v1
// = 11 el vector sería: [21,31,41,51,61].
// • Se debe mostrar el vector para la función dos.
// • Se hace el llamado a la función cuatro pasándole por valor el primer número y el último. Se
// muestran los valores a pasar.
// • Se muestra el resultado de la operación que realiza F4() claramente. Ej (21 + 61)* 20 = 1640

// Con respecto a la función tres -F3()-:
// • Con el valor que recibe por parámetro debe mostrar el cuadrado del número si es un número
// par, sino debe mostrar el cubo. Ej: el cuadrado de 28 es 784.

// Con respecto a la función cuatro -F4()-:
// • Retorna la suma de los dos valores recibidos multiplicados por veinte.

#include <iostream>
using namespace std;


//Funciones


int F4(int v1, int v5){
  int suma = 0;
  suma = (v1 + v5) * 20;

  cout << "(" << v1 << " + " << v5 << ") * 20 = " << suma << endl;

  return suma;
}


int F3(int resto){
  
  int numero = resto;
  int cubo = 0;
  int cuadrado = 0;

  cout << "El valor para F3() es: " << numero << ", resultado: " << endl;
  if (numero % 2 == 0){
    cuadrado = numero * numero;
    cout << "El cuadrado de " << numero << " es: " << cuadrado << endl;
  }
  else{
    cubo = numero * numero * numero;
    cout << "El cubo de " << numero << " es: " << cubo << endl;
  }
  
  return 0;  
}


int F2(int acumulador){
  int v2[5];
  int i;

  for(i = 0; i < 5; i++){
    if(i == 0){
      v2[i] = acumulador + 10;
    }else if(i == 1){
      v2[i] = acumulador + 20;
    }else if(i == 2){
      v2[i] = acumulador + 30;
    }else if(i == 3){
      v2[i] = acumulador + 40;
    }else if(i == 4){
      v2[i] = acumulador + 50;
    }
  }

  cout << "Vector de F2: " << endl;
  for(i = 0; i < 5; i++){
    cout << v2[i] << " ";
  }
  cout << endl;

  // muestra el primer y último valor del vector
  cout << "Los valores para F4() son " << v2[0] << " y  " << v2[4] << endl;

  return F4(v2[0], v2[4]);
}


int F1(){
  int v1[5];
  int i;
  int mayor = 0;
  int menor = 20;
  int acumulador = 0;
  int suma = 0;
  int resto = 0;

  srand((unsigned int)time(NULL));
  for(i = 0; i < 5; i++){
    v1[i] = rand() % 16;
  }

  cout << "Vector inicial: " << endl;
  for(i = 0; i < 5; i++){
    cout << v1[i] << " ";
    suma = suma + v1[i];
  }
  cout << endl;

  for(i = 0; i < 5; i++){
    if(v1[i] > mayor){
      mayor = v1[i];
    }
  }

  for(i = 0; i < 5; i++){
    if(v1[i] < menor){
      menor = v1[i];
    }
  }

  acumulador = mayor + menor;
  resto = suma-acumulador;
  
  cout << "El mayor es: " << mayor << ", el menor es: " << menor << ", y la suma de ambos es: " << acumulador << endl;

  cout << "La suma del resto es: " << resto  << endl;
  cout << endl;
  F2(acumulador);
  cout << endl;
  return F3(resto);

}


int main(){
  F1();
  return 0;
}