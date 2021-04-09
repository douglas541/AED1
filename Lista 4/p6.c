#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 1000

//-----------------Lista.h----------------
typedef struct lista Lista;
Lista* criaListaVazia();
bool inserirFinal(Lista*, char);
bool destruirLista(Lista*);
int obtemTamanhoLista(Lista*);

//-----------------Lista.c----------------
struct lista {
   int tamanho;
   char* dados;
};

Lista* criaListaVazia() {
   Lista* lista = (Lista*)malloc(sizeof(Lista));

   if (lista != NULL) {
      lista->tamanho = 0;
      lista->dados = (char*)malloc(sizeof(char) * 1000);
   }

   return lista;
}

bool inserirFinal(Lista* lista, char dado) {
   if (lista != NULL) {
      lista->dados[lista->tamanho] = dado;
      lista->tamanho++;
      return true;
   }

   return false;
}

bool destruirLista(Lista* lista) {
   if (lista != NULL) {
      free(lista->dados);
      free(lista);
   }
}

int obtemTamanhoLista(Lista* lista) {
   if (lista != NULL) {
      return lista->tamanho;
   }
}

//-----------------Main.c-----------------
int main() {
   Lista* lista1, * lista2;
   char aux, * teste;
   int n, i, j, k, l;

   teste = (char*)malloc(sizeof(char) * 1000);

   lista1 = criaListaVazia();
   lista2 = criaListaVazia();

   gets(teste);

   // for (i = 0; i < strlen(teste); i++) {
   //    if (teste[i] == '(') {
   //       parenteses[j] = '(';
   //       j++;
   //    }
   // }

   i = 0;
   j = 0;
   while (teste[i] != ')') {
      if (teste[i] == '(') {
         // printf("debug\n");
         inserirFinal(lista1, '(');
         j++;
      }
      i++;
   }
   k = i;
   l = 0;
   while (teste[k] != '\0') {
      if (teste[k] == ')') {
         // printf("debug\n");
         inserirFinal(lista2, ')');
         l++;
      }
      k++;
   }

   // printf("tamanho lista1: %d\ntamanho lista2: %d\n", obtemTamanhoLista(lista1), obtemTamanhoLista(lista2));

   if (obtemTamanhoLista(lista1) == obtemTamanhoLista(lista2) && obtemTamanhoLista(lista1) != 0) {
      printf("correta\n");
   }
   else {
      printf("incorreta\n");
   }

   // if (teste[i] == '\n') {
   //    break;
   // }

   // printf("%s\n%ld\n", teste, strlen(teste));

   free(teste);

   destruirLista(lista1);
   destruirLista(lista2);

   return 0;
}