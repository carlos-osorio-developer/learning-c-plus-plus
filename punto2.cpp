#include <iostream>
using namespace std;

int main()
{
    int row = 5, col = 5; 

    cout << "Ingresa los valores numericos de la matriz 5x5 (Ingresa texto si deseas terminar prematuramente) " << endl;
    cout << endl;
    // check if row and col > 0
    int val[row][col];
    int comp[row][col];



    for (int i = 0; i < row; i++)                 
    {
        for (int j = 0; j < col; j++)
        {
            comp[i][j]=(i*col)+j+1;
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
    
    cout << endl;
    cout << "Resultado (MatC): ";
    cout << endl;
    cout << endl;
    cout << '[';
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {            
            if(val[i][j] == comp[i][j]){
                if(i == row-1 && j == col-1){
                    cout << comp[i][j]+val[i][j] << ']';
                }
                else {
                    cout << comp[i][j]+val[i][j] << ", ";
                }                
            }
            else{
                if(i == row-1 && j == col-1){
                    cout << ' ' << ']';
                }
                else {
                    cout << ' ' << ", ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}