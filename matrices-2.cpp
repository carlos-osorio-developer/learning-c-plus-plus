#include <iostream>
using namespace std;

int* crea_arreglo(int items)  
{
  int* arreglo = new int[items];

  for (int i = 0; i < items; i++)                 
  {
      arreglo[i] = (rand()%500)+100;
  } 

  return arreglo;
}

int muestra_arreglo(int * val, int items)
{    
  cout << "\n" << '[';
  for (int i = 0; i < items; ++i)
  {      
    if(i == items-1){
        cout << val[i] << ']' << "\n";
    }
    else {
        cout << val[i] << ", ";
    }      
  }
  return 0;
}

int* suma_digitos(int * val, int items, int sum_ult_dig)
{
  int* arr_sum = new int[items];
  int count = 0;
  for (int i = 0; i < items; ++i)
  {    
    int num1 = val[i]%100/10;
    int num2 = val[i]%10;    
    if (num1 + num2 == sum_ult_dig)
    {
      arr_sum[count]=val[i];      
      count=count+1;
    }    
  }

  return arr_sum;
}


int main()
{

  cout << "\n" <<"Ingresa la cantidad de datos que deseas (un número entero): " << "\n";
  int usr_items;
  cin >> usr_items;

  int * arreglo_usuario = crea_arreglo(usr_items);

  cout << "\n" <<"Este es el arreglo de números aleatorios (del 100 al 600): " << "\n";
  muestra_arreglo(arreglo_usuario, usr_items);

  cout << "\n" <<"Ingrese el número al que se debe igualar la suma de los 2 últimos dígitos: " << "\n";
  int sum_usr_dig;
  cin >> sum_usr_dig;

  if(sum_usr_dig>18 || sum_usr_dig<0)
  {
    cout << "\n" << "ERROR: No es posible que 2 dígitos sumen el valor " << sum_usr_dig << "\n";
  }
  else
  {
    int * arreglo_usr_sum = suma_digitos(arreglo_usuario, usr_items, sum_usr_dig);

    cout << "\n" <<"Estos son los números cuyos últimos 2 dígitos suman " << sum_usr_dig << ". \n";
    muestra_arreglo(arreglo_usr_sum, usr_items);
  }  
  return 0;
}
