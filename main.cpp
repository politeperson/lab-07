#include <iostream>
#include <stdlib.h>//para rand()
#include <time.h>//para srand()
using namespace std;
void sleep(int n){//a quii creo mi funcion sleep con un for que aceptara un int, lo que una maquina puede hacer en un 1 seg aprox es 10^8 operaciones
    for(int i = 0; i < 1000000 * n; i++){}
}
void asig_mat(char mat[30][30], bool coords[30][30]){
  for(int i = 0; i < 30; i++){//inicializo m,i matriz con espacios
        for(int j = 0; j < 30; j++){
            mat[i][j] = ' ';
        }
    }
  for(int i = 0; i < 30; i++){//iniciaizo mi matriz de booles en true
      for(int j = 0; j < 30; j++){
	coords[i][j] = true;
      }
    }
  /*aqui creo la letra c*/
  /*#############################*/
    for(int i = 5; i < 25; i++){
      for(int j = 5; j < 7; j++){
	coords[i][j] = false;
      }
    }
    for(int i = 5; i < 15; i++){
      coords[5][i] = false;
      coords[25][i] = false;
      coords[6][i] = false;
      coords[24][i] = false;
    }
    /*###########################*/
    /*aqui creo la primera +*/
    for(int i = 11; i < 19; i++){
	coords[i][14] = false;
	coords[i][15] = false;
    }
    for(int i = 11; i < 19; i++){
	coords[14][i] = false;
	coords[15][i] = false;
    }
    /*######################*/
    /*aqui la segunda +*/
    for(int i = 11; i < 19; i++){
	coords[i][24] = false;
	coords[i][25] = false;
    }
    for(int i = 21; i < 29; i++){
	coords[14][i] = false;
	coords[15][i] = false;
    }
    /*#######################*/
}

void print_mat(char mat[30][30]){//funcion para imprimir mi matriz
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}
void animacion(char mat[30][30], bool coords[30][30]){
  srand (time(NULL));//es como la semilla para el random
  while(true){
    int star[10][2];//creo una matriz de coordenadas "random"
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 2; j++){
	star[i][j] = rand() % 30;//el numero semi random va de 0 a 30 que es el tamaño de mis dos matrices
      }
    }
    
    for(int i = 0; i < 5; i++){
      if(coords[star[i][0]][star[i][1]] == true){//verifico en mi matriz de booles que es del mismo tamaño que la de chars si el espacio esta libre, el espacio libre tiene el valor de true
	mat[star[i][0]][star[i][1]] = '@';
	}
    }
    print_mat(mat);
    sleep(10);/*con esto modero por asi decirlo la velocidad del programa*/
    system("clear");//para GNU-Linux
    //system("cls");para windows
  }
}
int main()
{
    int n=30;
    char mat[30][30];//creo dos matrices una de char la que imprimire y otra de booles para verificar si puedo imprimir ahi o no
    bool coords[30][30];
    asig_mat(mat,coords);
    animacion(mat,coords);

    return 0;
}
