#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1

//--------------------TAD.H---------------------

typedef struct Celula* ApontadorCelula;

typedef struct Celula {
   ApontadorCelula ant;
   char dado;
   ApontadorCelula prox;
} Celula;

//Cria uma lista vazia e retorna SUCESSO se a operação der certo e FA   LHA se der errado
int criarListaVazia(ApontadorCelula* p);

//Insere o dado no inicio da lista e retorna SUCESSO se tudo ocorrer como o esperado
int insInicio(ApontadorCelula* p, char dado);

//Insere o dado no final da celula e rotorna SUCESSO se tudo ocorrer como o esperado
int insFinal(ApontadorCelula* p, char dado);

//Mostra a lista e rotorna SUCESSO se tudo ocorrer como o esperado
int mostraComplementar(ApontadorCelula* primeiro);

//--------------------TAD.C---------------------

int criarListaVazia(ApontadorCelula* p) {
   (*p) = (ApontadorCelula)NULL;
   return SUCESSO;
}

int insInicio(ApontadorCelula* p, char dado) {
   ApontadorCelula q;

   if(dado != 'A' && dado != 'C' && dado != 'T' && dado != 'G'){
      return FALHA;
   }

   q = (ApontadorCelula)malloc(sizeof(Celula));
   if (q == NULL) {
      return (FALHA);
   }
   else {
      q->ant = (ApontadorCelula)NULL;
      q->dado = dado;
      q->prox = (ApontadorCelula)(*p);
      (*p) = q;
      return (SUCESSO);
   }
}

int insFinal(ApontadorCelula* p, char dado) {
   ApontadorCelula q, r;

   if(dado != 'A' && dado != 'C' && dado != 'T' && dado != 'G'){
      return FALHA;
   }

   if ((*p) == NULL)
      return (insInicio(p, dado));
   else {
      q = (ApontadorCelula)malloc(sizeof(Celula));
      if (q == NULL) {
         return (FALHA);
      }
      else {
         q->dado = dado;
         q->prox = (ApontadorCelula)NULL;
         r = (*p);
         while (r->prox != NULL) {
            r = r->prox;
         }
         q->ant = r;
         r->prox = q;
         return (SUCESSO);
      }
   }
}

int mostraComplementar(ApontadorCelula* primeiro) {
   ApontadorCelula* aux = primeiro;
   int cont = 0;

   if (primeiro == NULL) {
      return FALHA;
   }

   while ((*aux) != NULL) {
      // printf("%c", (*aux)->dado);

      if(((*aux)->dado) == 'A'){
         printf("T");
      }
      if(((*aux)->dado) == 'C'){
         printf("G");
      }
      if(((*aux)->dado) == 'G'){
         printf("C");
      }
      if(((*aux)->dado) == 'T'){
         printf("A");
      }

      (*aux) = (*aux)->prox;
      cont++;
   }
   printf(" %d\n", cont);

   return SUCESSO;
}

//--------------------MAIN.C--------------------

int main() {
   char insersao;
   ApontadorCelula* lista;

   criarListaVazia(lista);

   while (1) {
      scanf(" %c", &insersao);
      fflush(stdin);

      if (insersao == '$') {
         break;
      }
      
      insFinal(lista, insersao);
   }

   mostraComplementar(lista);

   return 0;
}