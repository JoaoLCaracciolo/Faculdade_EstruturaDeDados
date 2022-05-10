#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{

  TIPOCHAVE chave;

}REGISTRO;

typedef struct{

  REGISTRO A[MAX];
  int nroElem;

}LISTA;

void inicializarLista(LISTA* l){

  l->nroElem = 0;
  
}

int tamanho(LISTA* l){

  return l->nroElem;
  
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i){

  int j;
  if((l->nroElem == MAX) || (i< 0) || (i> l->nroElem))

  return false;

  for (j = l->nroElem; j > i; j--){
    
    l->A[j] = l->A[j-1];
    
  }
  
    l->A[i] = reg;
    l->nroElem++;
  
  return true;
    
}

void exibirLista(LISTA* l){

  int i;

  printf("LISTA:\n");
//trocamos o i=0 por i=1
  for(i=1;i<l->nroElem;i++){

    printf("%i\n",l->A[i].chave);
    
  }
  printf("\n");
  
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  
  int i = 0;
  
  while (i < l->nroElem){
  if(ch == l->A[i].chave)
      
    return i;
    
  else i++;
    
}
return -1;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA* l) {
  int pos, j;
  pos = buscaSequencial(l,ch);
  
  if(pos == -1) 
  
    return false;
  
  for(j = pos; j < l->nroElem-1; j++)
    l->A[j] = l->A[j+1];
    l->nroElem--;
  
  return true;
  
}

void reinicializarLista(LISTA* l) {
l->nroElem = 0;
}
int main(void) {

  LISTA lista;
  
  inicializarLista(&lista);

  REGISTRO reg;

  // reg.chave = 9;
  // inserirElemLista(&lista,reg,0);
  
  // reg.chave = 98;
  // inserirElemLista(&lista,reg,1);
  
  // reg.chave = 6;
  // inserirElemLista(&lista,reg,2);
  
  // reg.chave = 45;
  // inserirElemLista(&lista,reg,3);
  
  // reg.chave = 3;
  // inserirElemLista(&lista,reg,4);
  
  // reg.chave = 2;
  // inserirElemLista(&lista,reg,5);
  
  // reg.chave = 01;
  // inserirElemLista(&lista,reg,6);
  int teste1[20] = {4,9,7,2,1,5,4,6,8,2,1,4,9,1,5,6,4,1,2,7};
  
  printf("\n");
  for(int i=0; i<20;i++){
  inserirElemLista(&lista,reg,i);
  // scanf("%d",&reg.chave);
    reg.chave= teste1[i];
    }
  
  printf("Tamanho da lista:%d\n", tamanho(&lista));
  
  exibirLista(&lista);
  
  return 0;
}