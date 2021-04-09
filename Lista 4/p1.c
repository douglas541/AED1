#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 50

//--------------lista.h---------------

typedef struct lista Lista;
typedef struct no No;
Lista* criaListaVazia();
bool insereFinal(int, int, int, Lista*);
No* removeInicio(Lista*);
int critico(Lista*);
bool liberaLista(Lista*);

//--------------lista.c---------------
struct lista {
   No* primeiro;
   No* ultimo;
   int tamanho;
};

struct no {
   int hora;
   int minuto;
   int critico;
   No* proximo;
};

//cria uma lista vazia
Lista* criaListaVazia() {
   Lista* p = (Lista*)malloc(sizeof(Lista));
   if (p != NULL) {
      p->primeiro = NULL;
      p->ultimo = NULL;
      p->tamanho = 0;
   }
   return p;
}

//insere um No no fim da fila P com as horas, minutos e critico informados por parametro
bool insereFinal(int hora, int minuto, int critico, Lista* lista) {
   No* q = (No*)malloc(sizeof(No));

   if (q == NULL) {
      return false;
   }

   q->hora = hora;
   q->minuto = minuto;
   q->critico = critico;
   q->proximo = NULL;

   if (lista->tamanho == 0) {
      lista->primeiro = q;
      lista->ultimo = q;
   }
   else {
      lista->ultimo->proximo = q;
      lista->ultimo = q;
   }
   lista->tamanho++;
   return true;
}


//retrona um vetor inteiro de 3 posicoes, 0 = hora, 1 = minuto, 2 = critico
No* removeInicio(Lista* lista) {
   No* q = (No*)malloc(sizeof(No));
   No* aux;

   if (lista->tamanho == 0) {
      EXIT_FAILURE;
   }
   else {
      q->hora = lista->primeiro->hora;
      q->minuto = lista->primeiro->minuto;
      q->critico = lista->primeiro->critico;
      q->proximo = NULL;

      aux = lista->primeiro;
      lista->primeiro = lista->primeiro->proximo;
      free(aux);
   }

   lista->tamanho--;
   // printf("hora: %d\nminuto: %d\ncritico: %d\n", q->hora, q->minuto, q->critico);
   return q;
}

//retorna a quantidade em inteiro de pacientes em estado critico na lista
int critico(Lista* lista) {
   int casosCriticos = 0, horarioAtendimento[2], horarioEntrada[2], tempoEspera = 0;
   No* aux;

   //trecho de codigo define o primeiro horario de atendimento
   horarioEntrada[0] = lista->primeiro->hora;
   horarioEntrada[1] = lista->primeiro->minuto;

   if (horarioEntrada[1] == 0 || horarioEntrada[1] == 30) {
      horarioAtendimento[0] = horarioEntrada[0];
      horarioAtendimento[1] = horarioEntrada[1];
   }
   else {
      if (horarioEntrada[0] < 30) {
         horarioAtendimento[0] = horarioEntrada[0];
         horarioAtendimento[1] = 30;
      }
      else {
         horarioAtendimento[0] = horarioEntrada[0] + 1;
         horarioEntrada[1] = 0;
      }
   }
   //-------------------------------------------------------

   while (lista->tamanho > 0) {
      aux = removeInicio(lista);
      horarioEntrada[0] = aux->hora;
      horarioEntrada[1] = aux->minuto;
      tempoEspera = ((horarioAtendimento[0] - horarioEntrada[0]) * 60) + (horarioAtendimento[1] - horarioEntrada[1]);

      if (tempoEspera > aux->critico) {
         casosCriticos++;
      }

      if (horarioAtendimento[1] == 30) {
         horarioAtendimento[0]++;
         horarioAtendimento[1] = 0;
      }
      else {
         horarioAtendimento[1] = 30;
      }
   }

   free(aux);
   aux = NULL;

   return casosCriticos;
}

//libera a lista na memoria
bool liberaLista(Lista* lista) {
   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == 0) {
      free(lista);
   }
   else {
      if (lista->tamanho == 1) {
         free(lista->primeiro);
         free(lista);
      }
      else {
         No* q = lista->primeiro;
         No* aux;
         while (q != NULL) {
            aux = q;
            q = q->proximo;
            free(aux);
         }
      }
   }
   return true;
}

//------------------MAIN.C---------------------
int main() {
   int hora, minuto, tempoCritico, i, n;
   Lista* listaSus;

   listaSus = criaListaVazia();

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &hora);
      scanf("%d", &minuto);
      scanf("%d", &tempoCritico);

      insereFinal(hora, minuto, tempoCritico, listaSus);
   }
   
   printf("%d\n", critico(listaSus));

   liberaLista(listaSus);

   return 0;
}