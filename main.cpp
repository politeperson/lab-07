#include <iostream>
#include <stdlib.h>
using namespace std;
void sleep(int n){
    for(int i = 0; i < 1000000 * n; i++){}
}
void asig_mat(char mat[30][30]){
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            mat[i][j] = ' ';
        }
    }
}
void print_mat(char mat[30][30]){
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}
void animacion(char mat[30][30]){
    asig_mat(mat);
    while(true){
        int v1 = rand() % 30 + 1;
        int v2 = rand() % 30 + 1;
            mat[v1][v2] = '@';
            mat[v1][v2] = '@';
            mat[v1][v2] = '@';
            mat[v1][v2] = '@';
            mat[v1][v2] = '@';

        print_mat(mat);
        sleep(100);
        system("cls");
    }
}
int main()
{
    int n=30;
    char mat[30][30];
    asig_mat(mat);
    print_mat(mat);
    animacion(mat);

    return 0;
}
