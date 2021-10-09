#include <iostream>
using namespace std;

int main()
{
    int row = 6, col = 6; 

    cout << "Ingresa los valores numericos de la matriz 6x6 (Ingresa texto si deseas terminar prematuramente) " << endl;
    cout << endl;

    int val[row][col];

    for (int i = 0; i < row; i++)                 
    {
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
    
    cout << "Matriz ingresada (valor por defecto=0): ";
    cout << endl;
    cout << endl;
    cout << '[';
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if(i == row-1 && j == col-1){
                cout << val[i][j] << ']';
            }
            else {
                cout << val[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << endl;
}