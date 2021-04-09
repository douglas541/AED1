#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define CRESCENTE 1
#define DECRESCENTE 0

#define SUCESSO 1
#define FALHA 0

//-----------------conjunto.h-------------------

typedef struct conjunto Conjunto;

//retorna TRUE se o conjunto for vazio, se não retorna FALSE
Conjunto* criaConjunto();

//retorna SUCESSO ou FALHA. A falha ocorre se não for possível, por alguma ocorrência, criar o conjunto C.
int conjuntoVazio(Conjunto*);

//retorna TRUE se a operação foi concluída com sucesso consequetemente o número x foi inserido no conjunto C
int insereElementoConjunto(int, Conjunto*);

//retorna TRUE se a operação foi concluída com sucesso consequetemente o número x foi removido do conjunto C
int excluirElementoConjunto(int, Conjunto*);

//retorna o valor referente ao tamanho do conjunto C
int tamanhoConjunto(Conjunto* C);

//retorna a quantidade de inteiros maiores que x dentro do conjunto C
int maior(int, Conjunto*);

//retorna a quantidade de inteiros menores que x dentro do conjunto C
int menor(int, Conjunto*);

//retorna TRUE se o elemento x pertence ao conjunto C, e FALSE se não pertence
int pertenceConjunto(int, Conjunto*);

//retorna TRUE se os conjuntos C1 e C2 têm os mesmos elementos e cardinalidade (identicos)
int conjuntosIdenticos(Conjunto*, Conjunto*);

//retorna TRUE caso C1 seja subconjunto de C2
int subconjunto(Conjunto*, Conjunto*);

//retorna um Conjunto que é o complemento de C1 em C2
Conjunto* complemento(Conjunto*, Conjunto*);

//retorna um Conjunto que é a uniao dos conjuntos C1 e C2
Conjunto* uniao(Conjunto*, Conjunto*);

//retorna um conjunto que é a intersecção entre C1 e C2
Conjunto* interseccao(Conjunto*, Conjunto*);

//retorna um conjunto com todos elementos de C1 que não pertencem a C2 (diferença)
Conjunto* diferenca(Conjunto*, Conjunto*);

//retorna o conjunto das partes de C
Conjunto** conjuntoPartes(Conjunto*);

//imprime os elemntos de C em ordem CRESCENTE caso ordem = 1 e DECRESCENTE caso ordem = 0
void mostraConjunto(Conjunto*, int);

//retorna TRUE se a copia de C1 em C2 for bem sucedida
int copiarConjunto(Conjunto*, Conjunto*);

//retorna TRUE caso a opreação de destruir o conjuto seja bem sucedida
int destroiConjunto(Conjunto*);

//imprime o menu
void menu();

//-----------------conjunto.c-------------------

struct conjunto {
   int tamanho;
   long int* numeros;
};

int conjuntoVazio(Conjunto* C) {
   if (C->tamanho == 0)
      return true;
   else
      return false;
}

Conjunto* criaConjunto() {
   Conjunto* C = (Conjunto*)malloc(sizeof(Conjunto));
   if (C != NULL) {
      C->tamanho = 0;
      C->numeros = (long int*)malloc(sizeof(long int) * 1000000);
      // return true;
   }
   // else {
   //    return false;
   // }
   return C;
}

int insereElementoConjunto(int x, Conjunto* C) {
   if (C == NULL || pertenceConjunto(x, C) || x < LONG_MIN || x > LONG_MAX)
      return false;

   C->numeros[C->tamanho] = x;
   C->tamanho++;

   return true;
}

int excluirElementoConjunto(int x, Conjunto* C) {
   if (C == NULL || !pertenceConjunto(x, C))
      return false;

   int i;
   bool encontrou = false;
   for (i = 0; i < C->tamanho; i++) {
      if (C->numeros[i] == x) {
         encontrou = true;
         // printf("%ld\n", C->numeros[i]);
      }
      if (encontrou) {
         C->numeros[i] = C->numeros[i + 1];
      }
   }

   C->numeros[C->tamanho] = (long int)NULL;
   C->tamanho--;

   return true;
}

int tamanhoConjunto(Conjunto* C) {
   if (C != NULL)
      return C->tamanho;
}

int maior(int x, Conjunto* C) {
   int i, maiores = 0;

   for (i = 0; i < C->tamanho; i++) {
      if (C->numeros[i] > x)
         maiores++;
   }

   return maiores;
}

int menor(int x, Conjunto* C) {
   int i, menores = 0;

   for (i = 0; i < C->tamanho; i++) {
      if (C->numeros[i] < x)
         menores++;
   }

   return menores;
}

int pertenceConjunto(int x, Conjunto* C) {
   int i;
   bool pertence = false;

   if (C == NULL || C->tamanho == 0)
      return false;

   for (i = 0; i < C->tamanho; i++) {
      if (C->numeros[i] == x) {
         pertence = true;
         break;
      }
   }

   return pertence;
}

int conjuntosIdenticos(Conjunto* C1, Conjunto* C2) {
   bool identico = true;
   int i;

   for (i = 0; i < C1->tamanho; i++) {
      if (C1->numeros[i] != C2->numeros[i]) {
         identico = false;
         break;
      }
   }

   for (i = 0; i < C2->tamanho; i++) {
      if (C1->numeros[i] != C2->numeros[i]) {
         identico = false;
         break;
      }
   }

   return identico;
}

int subconjunto(Conjunto* C1, Conjunto* C2) {
   if (C1 == NULL || C2 == NULL)
      return false;

   int i, j;
   bool estaContidoEmC2, identicos = true;

   for (i = 0; i < C1->tamanho; i++) {
      estaContidoEmC2 = false;
      for (j = 0; j < C2->tamanho; j++) {
         if (C1->numeros[i] == C2->numeros[j])
            estaContidoEmC2 = true;
      }
      if (!estaContidoEmC2) {
         identicos = false;
         break;
      }
   }

   return identicos;
}

Conjunto* complemento(Conjunto* C1, Conjunto* C2) {
   int i;
   long int elemento;
   Conjunto* C_complemento;

   C_complemento = criaConjunto();
   copiarConjunto(C2, C_complemento);

   for (i = 0; i < C2->tamanho; i++) {
      elemento = C1->numeros[i];
      // printf("%ld\n", elemento);
      excluirElementoConjunto(elemento, C_complemento);
   }

   return C_complemento;
}

Conjunto* uniao(Conjunto* C1, Conjunto* C2) {
   int i;
   long int elemento;
   Conjunto* C_uniao;

   C_uniao = criaConjunto();
   copiarConjunto(C1, C_uniao);

   for (i = 0; i < C2->tamanho; i++) {
      elemento = C2->numeros[i];
      insereElementoConjunto(elemento, C_uniao);
   }

   return C_uniao;
}

Conjunto* interseccao(Conjunto* C1, Conjunto* C2) {
   int i;
   long int elemento;
   Conjunto* C_interseccao;

   C_interseccao = criaConjunto();

   for (i = 0; i < C1->tamanho; i++) {
      if (pertenceConjunto(C1->numeros[i], C2)) {
         elemento = C1->numeros[i];
         insereElementoConjunto(elemento, C_interseccao);
      }
   }

   return C_interseccao;
}

Conjunto* diferenca(Conjunto* C1, Conjunto* C2) {
   int i;
   long int elemento;
   Conjunto* C_diferenca;

   C_diferenca = criaConjunto();

   for (i = 0; i < C1->tamanho; i++) {
      if (!pertenceConjunto(C1->numeros[i], C2)) {
         elemento = C1->numeros[i];
         insereElementoConjunto(elemento, C_diferenca);
      }
   }

   return C_diferenca;
}

Conjunto** conjuntoPartes(Conjunto* C) {
   Conjunto** partes = (Conjunto**)malloc(sizeof(Conjunto*));

   copiarConjunto(C, partes[0]);
   copiarConjunto(C, partes[1]);

   return partes;
}

void mostraConjunto(Conjunto* C, int ordem) {
   int i;

   if (C->tamanho != 0)
      printf("( ");

   if (ordem == 1) {
      for (i = 0; i < C->tamanho; i++) {
         printf("%ld ", C->numeros[i]);
         // if ((i % 10 == 0 || i == C->tamanho - 1) && i != 0)
         //    printf("\n");
      }
   }
   else if (ordem == 0) {
      for (i = C->tamanho; i >= 0; i--) {
         printf("%ld ", C->numeros[i]);
         // if ((i % 10 == 0 || i == C->tamanho - 1) && i != 0)
         //    printf("\n");
      }
   }

   if (C->tamanho != 0)
      printf(")\n");

   if (C->tamanho == 1)
      printf("\n");
}

int copiarConjunto(Conjunto* C1, Conjunto* C2) {
   if (C1 == NULL || C2 == NULL)
      return false;

   int i;
   C2->tamanho = C1->tamanho;
   for (i = 0; i < C1->tamanho; i++)
      C2->numeros[i] = C1->numeros[i];

   return true;
}

int destroiConjunto(Conjunto* C) {
   if (C != NULL) {
      free(C->numeros);
      free(C);

      return true;
   }

   return false;
}


//---------------CORPO PRINCIPAL----------------

int main() {
   int i, j, qtd_elementos, elemento, elemento_2, elemento_aux, operacao;
   Conjunto* C1, * C2, * C_aux;

   do {
      C1 = criaConjunto();
      C2 = criaConjunto();
      C_aux = criaConjunto();

      menu();
      printf("Insira o numero referente a operacao desejada: ");
      scanf("%d", &operacao);

      if (operacao == 1) {
         system("clear");

         printf("Insira o tamanho do conjunto C: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nA cardinalidade do conjunto C e': %d\n\n", tamanhoConjunto(C1));
         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);

      }
      if (operacao == 2) {
         system("clear");

         printf("Insira o tamanho do conjunto C: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o elemento X: ");
         scanf("%d", &elemento);
         elemento_aux = maior(elemento, C1);
         printf("\nExistem %d elemento(s) maior(es) que X no conjunto C\n\n", elemento_aux);
         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);

      }
      if (operacao == 3) {
         system("clear");

         printf("Insira o tamanho do conjunto C: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o elemento X: ");
         scanf("%d", &elemento);
         elemento_aux = menor(elemento, C1);
         printf("\nExistem %d elemento(s) menor(es) que X no conjunto C\n\n", elemento_aux);
         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 4) {
         system("clear");

         printf("Insira o tamanho do conjunto C: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o elemento X: ");
         scanf("%d", &elemento);
         if (pertenceConjunto(elemento, C1)) {
            printf("\nO elemento %d esta no conjunto\n\n", elemento);
         }
         else {
            printf("\nO elemento %d nao esta no conjunto\n\n", elemento);
         }
         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 5) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         if (conjuntosIdenticos(C1, C2)) {
            printf("\nOs conjuntos C1 e C2 sao identicos\n\n");
         }
         else {
            printf("\nOs conjuntos C1 e C2 sao diferentes\n\n");
         }

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);

      }
      if (operacao == 6) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         if (subconjunto(C1, C2)) {
            printf("\nC1 e' subconjunto de C2\n\n");
         }
         else {
            printf("\nC1 nao e' subconjunto de C2\n\n");
         }

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 7) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         C_aux = complemento(C1, C2);
         mostraConjunto(C_aux, CRESCENTE);

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 8) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         C_aux = uniao(C1, C2);
         mostraConjunto(C_aux, CRESCENTE);

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 9) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         C_aux = interseccao(C1, C2);
         mostraConjunto(C_aux, CRESCENTE);

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 10) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         printf("\nInsira o tamanho do conjunto C2: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C2);
         }

         C_aux = diferenca(C1, C2);
         mostraConjunto(C_aux, CRESCENTE);

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }
      if (operacao == 11) {

      }
      if (operacao == 12) {
         system("clear");

         printf("Insira o tamanho do conjunto C1: ");
         scanf("%d", &qtd_elementos);
         printf("\n");

         for (i = 0; i < qtd_elementos; i++) {
            printf("Insira o %do elemento do conjunto: ", i + 1);
            scanf("%d", &elemento);
            insereElementoConjunto(elemento, C1);
         }

         copiarConjunto(C1, C2);
         mostraConjunto(C2, CRESCENTE);

         printf("Pressione 0 para voltar ao menu anterior ");
         scanf("%d", &j);
      }

      destroiConjunto(C1);
      destroiConjunto(C2);
      destroiConjunto(C_aux);

   } while (operacao != 0);


   return 0;
}

void menu() {
   system("clear");
   printf("ESCOLHA UMA OPERACAO\n\n");
   printf("1 - Calcular a cardinalidade de um conjunto C\n");
   printf("2 - Determinar a quantidade de elementos do conjunto C que são maiores que x\n");
   printf("3 - Determinar a quantidade de elementos do conjunto C que são menores que x\n");
   printf("4 - Verificar se o elemento x pertence ao conjunto C\n");
   printf("5 - Comparar se dois conjuntos, C1 e C2 são idênticos\n");
   printf("6 - Identificar se o conjunto C1 é subconjunto do conjunto C2\n");
   printf("7 - Gerar o complemento do conjunto C1 em relação ao conjunto C2\n");
   printf("8 - Gerar a união do conjunto C1 com o conjunto C2\n");
   printf("9 - Gerar a intersecção do conjunto C1 com o conjunto C2\n");
   printf("10 - Gerar a diferença entre o conjunto C1 e o conjunto C2\n");
   printf("11 - Gerar o conjunto das partes do conjunto C\n");
   printf("12 - Copiar o conjunto C1 para o conjunto C2\n");
   printf("0 - Sair do programa\n\n");
}