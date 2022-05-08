#include <iostream>
#include <stdlib.h>
using namespace std;

// Realizar por medio de switch – case un menú que contemple lo siguiente: 1. Números, 2. Vectores,
// 3. Matrices y 4. Salir. Utilizando ciclos infinitos se debe mantener la presentación del menú hasta
// que se digite la opción de salir. En los casos del switch solo debe haber llamados a funciones.

// Para el caso 1 se debe llamar a una función que genere dos números aleatorios entre 1 y 50
// ([1,50])y le solicite al usuario un número adicional, con ellos se debe mostrar la tabla de
// multiplicar del número que digitó el usuario comenzando en el número más pequeño generado
// aleatoriamente y finalizando en el mayor (Uso de condicionales). Ej números generados
// aleatoriamente 40 y 31, número digitado por el usuario 10, salida:

// Con respecto al caso 2 se debe llamar a una función que cree un vector de 5 posiciones, lo debe
// llenar con valores aleatorios menores a 100, mostrarlo en pantalla, luego pasarlo por parámetro
// a otra función que retorne el valor de la suma del primer y el último número del arreglo,
// finalmente mostrar el resultado recibido como respuesta.

// Finalmente, con respecto al caso 3 se debe llamar a una Función que cree una matriz de 4 filas
// por 5 columnas, se debe llenar automáticamente con valores aleatorios entre 20 y 80; con los
// datos de la matrizse debe evidenciar cuantos datos de ellos son menores a 50, cuantos mayores
// y cuantos iguales. Se debe mostrar la matriz y los datos obtenidos.

int numeros() 
{ 
  int num1, num2, num3;
  num1 = rand() % 50 + 1;
  num2 = rand() % 50 + 1;

  cout << "Digite el valor para la tabla de multiplicar: " << endl;
  cin >> num3;

  cout << "Primer valor: " << num1 << ", Segundo valor: " << num2 << endl;
  cout << endl;
  cout << "Tabla del " << num3 << ": " << endl;
  cout << endl;

  if (num1 < num2)
  {
    for (int i = num1; i <= num2; i++)
    {
      cout << num3 << " x " << i << " = " << num3 * i << endl;
    }
  }
  else
  {
    for (int i = num2; i <= num1; i++)
    {
      cout << num3 << " x " << i << " = " << num3 * i << endl;
    }
  }
}

int sumador(int num1, int num2)
{  
  int suma;
  suma = num1 + num2;
  return suma;
}

int vectores()
{
  int vector[5];
  int suma = 0;

  for (int i = 0; i < 5; i++)
  {
    vector[i] = rand() % 100 + 1;
  }

  cout << "Vector: " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << vector[i] << " ";
  }
  cout << endl;

  suma = sumador(vector[0], vector[4]);

  cout << "La suma de " << vector[0] << " y " << vector[4] << " es: " << suma << endl;
}

int matrices()
{
  int matriz[4][5];
  int menores = 0;
  int mayores = 0;
  int iguales = 0;
  
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      matriz[i][j] = rand() % 60 + 20;
    }
  }

  cout << "Matriz: " << endl;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (matriz[i][j] < 50)
      {
        menores++;
      }
      else if (matriz[i][j] > 50)
      {
        mayores++;
      }
      else
      {
        iguales++;
      }
    }
  }

  cout << "Cantidad de datos menores a 50: " << menores << endl;
  cout << "Cantidad de datos mayores a 50: " << mayores << endl;
  cout << "Cantidad de datos iguales a 50: " << iguales << endl;
}

int main()
{
  cout << "MENU" << endl;
  cout << endl;
  cout << "1. Numeros" << endl;
  cout << "2. Vectores" << endl;
  cout << "3. Matrices" << endl;
  cout << "4. Salir" << endl;
  cout << endl;
  cout << "Ingrese una opcion: ";

  int opcion;
  cin >> opcion;
  cout << endl;

  switch (opcion)
  {
  case 1:
    numeros();
    break;
  case 2:
    vectores();
    break;
  case 3:
    matrices();
    break;
  case 4:
    cout << "Saliendo..." << endl;
    break;
  default:
    cout << "Opcion no valida" << endl;
    break;
  }
}