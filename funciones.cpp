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
  int operacion = 0; // Variable para almacenar el resultado de la operacion
  operacion = (v1 + v5) * 20; // suma los valores de los parámetros y lo multiplica por 20

  return operacion;
}


int F3(int resto){
  
  int numero = resto; // parámetro para la operación
  int cubo = 0; // resultado del cubo del número
  int cuadrado = 0; // resultado del cuadrado del número

  cout << "El valor para F3() es: " << numero << ", resultado: " << endl;
  if (numero % 2 == 0){ // si el número es par, calcula el cuadrado del número
    cuadrado = numero * numero;
    cout << "El cuadrado de " << numero << " es: " << cuadrado << endl;
  }
  else{ // si el número es impar, calcula el cubo del número
    cubo = numero * numero * numero;
    cout << "El cubo de " << numero << " es: " << cubo << endl;
  }  
}


int F2(int acumulador){
  int v2[5]; // Vector de 5 elementos
  int i; // Indice para recorrer el vector
  int operacion = 0; // Variable para almacenar el resultado de la operacion

  cout << "Vector de F2: " << endl;
  for(i = 0; i < 5; i++){
    if(i == 0){ // Primer elemento, será el valor del parámetro (acumulador) más 10
      v2[i] = acumulador + 10;
    }else if(i == 1){ // Segundo elemento, será el valor del parámetro (acumulador) más 20
      v2[i] = acumulador + 20;
    }else if(i == 2){ // Tercer elemento, será el valor del parámetro (acumulador) más 30
      v2[i] = acumulador + 30;
    }else if(i == 3){ // Cuarto elemento, será el valor del parámetro (acumulador) más 40
      v2[i] = acumulador + 40;
    }else if(i == 4){ // Quinto elemento, será el valor del parámetro (acumulador) más 50
      v2[i] = acumulador + 50;
    }
    cout << v2[i] << " "; // Imprime el valor del elemento
  }
  cout << endl;

  // muestra el primer y último valor del vector
  cout << "Los valores para F4() son " << v2[0] << " y " << v2[4] << endl;

     = F4(v2[0], v2[4]); // llama a la función F4() y le pasa los valores máximo y mínimo del vector v2

  cout << "(" << v2[0] << " + " << v2[4] << ") * 20 = " << operacion << endl;
}


int F1(){
  int v1[5]; // vector de 5 elementos
  int i; // indice para recorrer el vector
  int count; // contador para recorrer el vector
  int mayor = 0; // valor mayor del vector
  int menor = 20; // valor menor del vector
  int acumulador = 0; // acumulador para tener la suma de todo el vector
  int suma = 0; // suma del mayor y menor valor del vector
  int resto = 0; // suma del resto de valores del vector

  cout << "Vector inicial: " << endl;
  srand((unsigned int)time(NULL)); // crea una nueva semilla para que no se repitan los números aleatorios en cada ejecución
  int index = 0; // indice para el vector v1
  int num_temp; // variable temporal para guardar los números aleatorios
  for(count = 0; count < 5; count++){ // ciclo que creará 5 números
    do{ // lineas de ejecución del while
			// crea un número aleatorio entre 5 y 15, usando el residuo de dividir entre 11 (máximo regresa un 10), y al residuo le suma 5
      num_temp = (rand() % 11) + 5;
			for(i = 0; i < 5; i++ ){ // recorre lo que hay en el vector hasta ahora
				if( num_temp == v1[i] ){ // si el número aleatorio ya está en el vector
					num_temp = -1; // lo vuelve cero
					break; // rompe el ciclo
				}
			}
		}while( num_temp == -1 ); // mientras el número aleatorio sea -1, se repite el ciclo
            v1[index] = num_temp; // si deja de repetir el ciclo, guarda el número aleatorio en el vector
            cout << v1[index] << " "; // imprime el número aleatorio
            index++; // incrementa el indice del vector, para guardar el siguiente número
            acumulador += num_temp; // suma el número aleatorio al acumulador
  };
  cout << endl;

  for(i = 0; i < 5; i++){ // recorre el vector
    if(v1[i] > mayor){ 
      mayor = v1[i]; // si el valor analizado es mayor que el máximo hasta el momento, lo reescribe
    }
  }

  for(i = 0; i < 5; i++){
    if(v1[i] < menor){
      menor = v1[i]; // si el valor analizado es menor que el mínimo hasta el momento, lo reescribe
    }
  }

  suma = mayor + menor; // suma el mayor y menor valor del vector
  resto = acumulador-suma; // obtiene la suma de los demás, restando lo anterior a la suma total del vector
  
  cout << "El mayor es: " << mayor << ", el menor es: " << menor << ", y la suma de ambos es: " << suma << endl;

  cout << "La suma del resto es: " << resto  << endl;
  cout << endl;
  F2(suma); // llama a la función F2, pasando como parámetro la suma de los valores máximo y mínimo del vector
  cout << endl;
  F3(resto);  // llama a la función F3, pasando como parámetro la suma de los valores restantes del vector

}


int main(){
  F1();
  return 0;
}