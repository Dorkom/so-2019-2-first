#include <stdio.h>
//Erik Vargas

void imprimir(int list[], int n);
void base(int list[], int n);
void agregar(int list[], int n);

int main(void) {
  int clave=1,n=100;
  int memoria[100] = {0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0};
  imprimir(memoria,n);
  base(memoria,n);
  imprimir(memoria,n);
  agregar(memoria,n);
}
void imprimir(int list[], int n){
    for(int i=0;i<n;i++){
        if(list[i]==1){
            printf("#");
        }else{
            printf(".");
        }
    }
}
void base(int list[], int n){
    int clave = 1, espacios = 0, posicion = 0, i = 0;
    printf("\nIngrese el caso base: ");
    while(clave!=0){
        printf("\nCuantos espacios de moria ocupa el proceso: ");
        scanf("%d",&espacios);
        printf("\nEn que espacio de memoria se ingresara el proceso: ");
        scanf("%d",&posicion);
        if((n-posicion)<espacios){
            printf("\nNo se puede ingresar el proceso en la posicion indicada.");
        }else if((n-posicion)>=espacios){
            for(i=posicion;i<espacios+posicion;i++){
                list[i]=1;
            }
        }
        printf("\nIngrese cero para terminar de ingresar caso base o uno para continuar: ");
        scanf("%d",&clave);
    }
}
void agregar(int list[], int n){
  int espacios,clave=1,contador=0;
  while(clave!=0){
    printf("\nIngrese el espacio de memoria que ocupa el proceso: ");
    scanf("%d",&espacios);
    for(int i=0;i<n;i++){
      if(list[i]==0){
        contador++;
        if(contador==espacios){
          for(int j = 0; j < contador; j++){
            list[i+j-contador+1]=1;
          }contador = 0; break;
        }
      }else if(list[i]==1){
        contador=0;
      }
    }
    imprimir(list,100);
    printf("\nPresione cero para terminar o uno para continuar: ");
    scanf("%d",&clave);
  }
}