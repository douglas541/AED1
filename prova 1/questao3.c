#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------------lista.h----------------------
typedef struct no No;
typedef No *ApontaNo;

//retorna um ponteiro para o primeiro No da lista
bool criaListaVazia(ApontaNo *q);

//insere um dado em ordem decrescente na lista
bool insereCrescente(ApontaNo *noInicial, int dado);

//remove no inicio da lista (MAIOR dado da lista)
int removeInicio(ApontaNo *noInicial);

//remove no final da lista (MENOR dado da lista)
int removeFinal(ApontaNo *noInicial);

//libera a lista da memoria
bool destroiLista(ApontaNo *noInicial);

//--------------------lista.c----------------------
struct no
{
   int dado;
   ApontaNo proximo;
};

bool criaListaVazia(ApontaNo *q)
{
   *q = (ApontaNo)NULL;

   return true;
}

bool insereCrescente(ApontaNo *noInicial, int dado)
{
   ApontaNo anterior, posterior;
   ApontaNo q = (ApontaNo)malloc(sizeof(No));

   if (q == NULL)
   {
      return false;
   }

   if ((*noInicial) == NULL)
   {
      q->dado = dado;
      q->proximo = (ApontaNo)(*noInicial);
      (*noInicial) = q;
   }
   else
   {
      if ((*noInicial)->proximo == NULL)
      {
         if (dado < (*noInicial)->dado)
         {
            q->dado = dado;
            q->proximo = (ApontaNo)(*noInicial);
            (*noInicial) = q;
         }
         else
         {
            q->dado = dado;
            q->proximo = (ApontaNo)NULL;
            (*noInicial)->proximo = q;
         }
      }
      else
      {
         if (dado < (*noInicial)->dado)
         {
            q->dado = dado;
            q->proximo = *noInicial;
            (*noInicial) = q;
         }
         else
         {
            q->dado = dado;
            posterior = (*noInicial);
            while (((posterior->dado) <= dado) && ((posterior->proximo) != NULL))
            {
               anterior = posterior;
               posterior = posterior->proximo;
            }
            if (posterior->dado < dado)
            {
               q->proximo = (ApontaNo)NULL;
               posterior->proximo = q;
            }
            else
            {
               q->proximo = posterior;
               anterior->proximo = q;
            }
         }
      }
   }

   return true;
}

int removeInicio(ApontaNo *noInicial)
{
   ApontaNo removido;
   int dadoRetorno = (*noInicial)->dado;

   if ((*noInicial) == NULL)
   {
      return false;
   }

   removido = (*noInicial);
   (*noInicial) = (*noInicial)->proximo;
   free(removido);

   return dadoRetorno;
}

int removeFinal(ApontaNo *noInicial)
{
   ApontaNo removido, anterior;
   int dadoRetorno;

   if ((*noInicial) == NULL)
   {
      return false;
   }

   anterior = (*noInicial);
   removido = (*noInicial);
   if ((*noInicial)->proximo == NULL)
   {
      return (removeInicio(noInicial));
   }
   else
   {
      while ((removido->proximo) != NULL)
      {
         anterior = removido;
         removido = removido->proximo;
      }
      anterior->proximo = (ApontaNo)NULL;
      dadoRetorno = removido->dado;
      free(removido);
   }

   return dadoRetorno;
}

bool destroiLista(ApontaNo *noInicial)
{
   ApontaNo removido, anterior;

   if ((*noInicial) == NULL)
   {
      return false;
   }
   if ((*noInicial)->proximo == NULL)
   {
      removido = (*noInicial);
      free(removido);
   }
   else
   {
      removido = (*noInicial);
      anterior = (*noInicial);
      while ((removido->proximo) != NULL)
      {
         anterior = removido;
         removido = removido->proximo;
         free(anterior);
      }
   }
}

//-----------------CORPO PRINCIPAL-----------------

int main()
{
   ApontaNo lista1, lista2, lista3;
   int dado1, dado2, dadoInsersao, n, i, j;

   criaListaVazia(&lista1);
   criaListaVazia(&lista2);
   criaListaVazia(&lista3);

   scanf("%d", &n);
   scanf("%d", &dado1);
   scanf("%d", &dado2);

   for (i = 0; i < n; i++)
   {
      scanf("%d", &dadoInsersao);
      insereCrescente(&lista1, dadoInsersao);
   }
   for (i = 0; i < dado1; i++)
   {
      dadoInsersao = removeFinal(&lista1);
      insereCrescente(&lista2, dadoInsersao);

      // printf("inserindo %d na lista2\n", dadoInsersao);
   }
   for (i = 0; i < dado2; i++)
   {
      dadoInsersao = removeInicio(&lista1);
      insereCrescente(&lista2, dadoInsersao);

      // printf("inserindo %d na lista2\n", dadoInsersao);
   }

   for (i = 0; i < (dado1 + dado2); i++)
   {
      printf("%d ", removeFinal(&lista2));
   }
   printf("\n");

   // destroiLista(&lista1);
   // destroiLista(&lista2);
   // destroiLista(&lista3);

   return 0;
}