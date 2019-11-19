#include <stdio.h>
//Erik Vargas
void imprimir(int list[], int n);
void agregar(int list[], int n);

int main(void) {
  int clave=1,n=100;

  FILE * fPointer;
  fPointer = fopen("list.txt","r");
  char texto[n];
  fgets(texto,n,fPointer);
  puts(texto);
  int memoria2[n];
  for(int i=0;i<n;i++){
    memoria2[i]=texto[i]-'0';
  }

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
  imprimir(memoria2,n);
  agregar(memoria2,n);
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

