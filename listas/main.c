#include <stdio.h>
#include <stdlib.h>
//Erik Vargas
typedef struct Nodo{
    int type;
    int start;
    int length;
    struct Nodo *siguiente;
}ListaEnlazadaNodo;
typedef ListaEnlazadaNodo *ListaEnlazada;

void insertar(ListaEnlazada *ptr, int car1,int num1, int num2);
void imprimir(ListaEnlazada ptr);
void borrar(ListaEnlazada *ptr);
void agregar(int list[], ListaEnlazada ptr, int nm);
void imprimirTodo(int list[], int nm);
void crearNuevaLista(int list[], ListaEnlazada ptr, int nm);
void primerAjuste(int list[], ListaEnlazada ptr, int nm);

int main(void) {
  int clave=1,n=96,aux = 0, cantidad = 4,nm=100;
  int n2=cantidad*3;
  FILE * fPointer;
  fPointer = fopen("list.txt","r");
  char texto[n];
  fgets(texto,n,fPointer);
  puts(texto);
  int memoria2[n2];
  for(int i=0;i<n2;i+=3){
    memoria2[i]=texto[aux]-'0';
    memoria2[i+1]=((texto[aux+1]-'0')*10)+(texto[aux+2]-'0');
    memoria2[i+2]=((texto[aux+3]-'0')*10)+(texto[aux+4]-'0');
    aux+=6;
  }

  ListaEnlazada ptr;
  ptr = NULL;
  ListaEnlazada ptr2;
  ptr2 = NULL;
  for(int i=0;i<n2;i++){
    printf("%d",memoria2[i]);
  }
  for(int i=0;i<n2;i+=3){
    insertar(&ptr,memoria2[i],memoria2[i+1],memoria2[i+2]);
  }
  
  printf("\nimprimir: \n");
  imprimir(ptr);  

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
  agregar(memoria,ptr,nm);
  imprimirTodo(memoria,nm);
  while(clave!=0){
    int aux1=0,aux2=0,aux3=0;
    printf("\nIngrese la longitud de la actividad: ");
    scanf("%d",&aux3);
    insertar(&ptr2,aux1,aux2,aux3);
    printf("Ingrese cero para terminar: ");
    scanf("%d",&clave);
  }
  primerAjuste(memoria,ptr2,nm);
  printf("\n");
  imprimirTodo(memoria,nm);
  printf("\n");
  imprimir(ptr2);
}
void primerAjuste(int list[], ListaEnlazada ptr, int nm){
  int contador = 0;
  while(ptr != NULL){
    int aux3 = ptr->length;
    for(int i=0;i<nm;i++){
      if(list[i]==0){
        contador++;
        if(contador==aux3){
          for(int j = 0; j < contador; j++){
            list[i+j-contador+1]=1;
          }contador = 0; break;
        }
      }else if(list[i]==1){
        contador=0;
      }
    }
    ptr = ptr->siguiente;
  }
}
void insertar(ListaEnlazada *ptr, int car1,int num1, int num2){
    ListaEnlazada  lista;
    lista = malloc(sizeof(ListaEnlazadaNodo));
    lista->type = car1;
    lista->start = num1;
    lista->length = num2;
    lista->siguiente = *ptr;
    *ptr = lista;
}

void imprimir(ListaEnlazada ptr){
    while(ptr != NULL){
        printf("%d,",ptr->type);
        printf("%d,",ptr->start);
        printf("%d",ptr->length);
        printf("\n");
        ptr = ptr->siguiente;
    }
}

void borrar(ListaEnlazada *ptr){
    ListaEnlazada aux;
    while(*ptr != NULL){
      //ptr = *ptr;
      *ptr = (*ptr)->siguiente;
      free(aux);
    }
}
void imprimirTodo(int list[], int nm){
    for(int i=0;i<nm;i++){
        if(list[i]==1){
            printf("#");
        }else{
            printf(".");
        }
    }
}
void agregar(int list[], ListaEnlazada ptr, int nm){
  while(ptr != NULL){
    int aux1 = ptr->type;
    int aux2 = ptr->start;
    int aux3 = ptr->length;
    for(int i=aux2;i<aux3+aux2;i++){
      list[i]=aux1;
    }
    ptr = ptr->siguiente;
  }
}
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
    int info;
    struct Nodo *siguiente;
}ListaEnlazadaNodo;
typedef ListaEnlazadaNodo *ListaEnlazada;

void insetar(ListaEnlazada *ptr,int num);
void imprimir(ListaEnlazada ptr);
void borrar(ListaEnlazada *ptr);

int main(void) {
    int num;
    ListaEnlazada ptr;
    ptr = NULL;
    printf("Ingrese elementos: ");
    scanf("%d",&num);
    while(num!=-1){
        insetar(&ptr,num);
        printf("Ingrese elementos: ");
        scanf("%d",&num);

    }
    printf("\nimprimir: \n");
    imprimir(ptr);
    printf("\nborrar: \n");
    borrar(&ptr);
    system("PAUSE");
    return 0;
}

void insetar(ListaEnlazada *ptr,int num){
    ListaEnlazada  lista;
    lista = malloc(sizeof(ListaEnlazadaNodo));
    lista->info = num;
    lista->siguiente = *ptr;
    *ptr = lista;
}

void imprimir(ListaEnlazada ptr){
    while(ptr != NULL){
        printf("%d",ptr->info);
        ptr = ptr->siguiente;
    }
}

void borrar(ListaEnlazada *ptr){
    ListaEnlazada aux;
    while(*ptr != NULL){
        //ptr = *ptr;
        *ptr = (*ptr)->siguiente;
        free(aux);
    }
}*/