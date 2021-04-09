#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------------lista.h----------------------
typedef struct no No;
typedef No* ApontaNo;

//retorna um ponteiro para o primeiro No da lista
bool criaListaVazia(ApontaNo* q);

//se o elemento nao estiver na lista, insere este no inicio e retorna true, se nao, retorna false
bool insereInicioSemRepeticao(ApontaNo* q, int dado);

//remove no inicio da lista (MAIOR dado da lista)
int removeInicio(ApontaNo* noInicial);

//remove no final da lista (MENOR dado da lista)
int removeFinal(ApontaNo* noInicial);

//mostra a lista
void mostraLista(ApontaNo* noInicial);

//libera a lista da memoria
bool destroiLista(ApontaNo* noInicial);

//--------------------lista.c----------------------
struct no {
   int dado;
   ApontaNo proximo;
};

bool criaListaVazia(ApontaNo* q) {
   *q = (ApontaNo)NULL;

   return true;
}

bool insereInicioSemRepeticao(ApontaNo* noInicial, int dado) {
   ApontaNo q = (ApontaNo)malloc(sizeof(No));
   ApontaNo verificacao;

   verificacao = (*noInicial);

   // printf("entrou na função\n");

   while (verificacao != NULL) {
      if (dado == verificacao->dado) {
         // printf("repetido\n");
         return false;
      }
      verificacao = verificacao->proximo;
   }

   if (q == NULL) {
      return false;
   }

   q->dado = dado;
   q->proximo = (ApontaNo)(*noInicial);
   (*noInicial) = q;
}

int removeInicio(ApontaNo* noInicial) {
   ApontaNo removido;
   int dadoRetorno = (*noInicial)->dado;

   if ((*noInicial) == NULL) {
      return false;
   }

   removido = (*noInicial);
   (*noInicial) = (*noInicial)->proximo;
   free(removido);

   return dadoRetorno;
}

int removeFinal(ApontaNo* noInicial) {
   ApontaNo removido, anterior;
   int dadoRetorno;

   if ((*noInicial) == NULL) {
      return false;
   }

   anterior = (*noInicial);
   removido = (*noInicial);
   if ((*noInicial)->proximo == NULL) {
      return(removeInicio(noInicial));
   }
   else {
      while ((removido->proximo) != NULL) {
         anterior = removido;
         removido = removido->proximo;
      }
      anterior->proximo = (ApontaNo)NULL;
      dadoRetorno = removido->dado;
      free(removido);
   }

   return dadoRetorno;
}

void mostraLista(ApontaNo* noInicial) {

   // printf("entrou na mostraLista\n");

   while ((*noInicial) != NULL) {
      printf("%d ", (*noInicial)->dado);
      (*noInicial) = (*noInicial)->proximo;
   }
}

bool destroiLista(ApontaNo* noInicial) {
   ApontaNo removido, anterior;

   if ((*noInicial) == NULL) {
      return false;
   }
   if ((*noInicial)->proximo == NULL) {
      removido = (*noInicial);
      free(removido);
   }
   else {
      removido = (*noInicial);
      anterior = (*noInicial);
      while ((removido->proximo) != NULL) {
         anterior = removido;
         removido = removido->proximo;
         free(anterior);
      }
   }
}


//-----------------CORPO PRINCIPAL----------------

int main() {
   int i, j, n, dadoInsersao = 0;
   ApontaNo lista;


   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      criaListaVazia(&lista);

      while (true) {
         scanf("%d", &dadoInsersao);

         if (dadoInsersao == (-1)) {
            break;
         }

         insereInicioSemRepeticao(&lista, dadoInsersao);
      }

      mostraLista(&lista);
      printf("\n");

      destroiLista(&lista);
      lista = NULL;
   }

   return 0;
}