#include <iostream>
using namespace std;

int** recibe_matriz(int row, int col)  
{
  cout << "\n" <<"Ingresa los valores numericos de la matriz "<< row << "x" << col <<" (Ingresa texto si deseas terminar prematuramente) " << "\n";

  int** val = new int*[row];

  for (int i = 0; i < row; i++)                 
  {
      val[i]= new int[col];
      for (int j = 0; j < col; j++)
      {
          val[i][j] = 0; 
      }   
  } 

  for (int i = 0; i < row; i++)                 
  {
      for (int j = 0; j < col; j++)
      {            
          cin >> val[i][j]; 
      }                 
  }

  return val;
}

int muestra_matriz(int **val, int row, int col)
{    
  cout << "\n" << '[';
  for (int i = 0; i < row; ++i)
  {
      for (int j = 0; j < col; ++j)
      {
          if(i == row-1 && j == col-1){
              cout << val[i][j] << ']' << "\n";
          }
          else {
              cout << val[i][j] << ", ";
          }        
      } 
    cout << "\n";     
  }

  return 0;
}

int** suma_matriz(int **usr_mat, int row, int col) 
{
  cout << "\n" << "Ingresa la primera columna que quieres sumar:" << "\n";
  int colSum1;
  cin >> colSum1;
  cout << "\n" << "Ingresa la segunda columna que quieres sumar:" << "\n";
  int colSum2;
  cin >> colSum2;
  int** sum = new int*[row];
  for (int i = 0; i < row; ++i){
    sum[i]= new int[col];    
    sum[i][0]=usr_mat[i][colSum1-1]+usr_mat[i][colSum2-1];  
  }

  return sum;
}


int main()
{

  cout << "\n" << "¿De cuántas filas debe ser la matriz?" << "\n";
  int row;
  cin >> row;
  cout << "\n" << "¿De cuántas columnas debe ser la matriz?" << "\n";
  int col;
  cin >> col;
  
  int **matriz_usuario;
  matriz_usuario = recibe_matriz(row, col);

  cout << "\n" << "Matriz ingresada (valor por defecto=0): " << "\n";
  muestra_matriz(matriz_usuario, row, col);

  int **suma_usuario;
  suma_usuario = suma_matriz(matriz_usuario, row, col);

  cout << "\n" << "La suma de las columnas seleccionadas es: " << "\n" ;
  muestra_matriz(suma_usuario, row, 1);
}
