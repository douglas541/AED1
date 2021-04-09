#include <stdio.h>
#define N 500

//char** é a matriz de setas à ser manipulada, os 3 ints se referem à linha, coluna e n de celulas respectivamente
int setas(char matrix[N][N], int, int, int, int);

int main() {
   int nColunas, nCelulas, l, c, i, j, celulasSeguras = 0;
   char matrix[N][N];

   scanf("%d", &nColunas);
   for (i = 0; i < nColunas; i++) {
      for (j = 0; j < nColunas; j++) {
         scanf(" %c", &matrix[i][j]);
      }
   }

   nCelulas = nColunas * nColunas;
   // printf("%d\n", nCelulas);

   for (i = 0; i < nColunas; i++) {
      for (j = 0; j < nColunas; j++) {
         // printf("chamada iterativa i:%d, j:%d\n", i, j);
         celulasSeguras = celulasSeguras + setas(matrix, i, j, nCelulas, nColunas);
         // printf("%d, i: %d, j: %d\n", setas(matrix, i, j, nCelulas, nColunas), i, j);
      }
   }

   printf("%d\n", celulasSeguras);

   return 0;
}

//se a celula [l][c] for segura retorna 1 senao retorna 0
int setas(char matrix[N][N], int l, int c, int nCelulas, int nColunas) {
   if (nCelulas == 0){
      // printf("caso base nColunas == 0\n");
      return 1;
   }
   if (l < 0 || c < 0){
      // printf("caso base l ou c < 0\n");
      return 0;
   }
   if (l > nColunas - 1 || c > nColunas - 1){
      // printf("caso base l ou c > nColunas\n");
      return 0;
   }

   if (matrix[l][c] == 'V') {
      // printf("chamada recursiva 1\n");
      return setas(matrix, l + 1, c, nCelulas - 1, nColunas);
   }
   if (matrix[l][c] == 'A') {
      // printf("chamada recursiva 2\n");
      return setas(matrix, l - 1, c, nCelulas - 1, nColunas);
   }
   if (matrix[l][c] == '>') {
      // printf("chamada recursiva 3\n");
      return setas(matrix, l, c + 1, nCelulas - 1, nColunas);
   }
   if (matrix[l][c] == '<') {
      // printf("chamada recursiva 4\n");
      return setas(matrix, l, c - 1, nCelulas - 1, nColunas);
   }

   // if (matrix[l][c] == 'V')
   //    printf("V\n");
   // if (matrix[l][c] == 'A')
   //    printf("A\n");
   // if (matrix[l][c] == '>')
   //    printf(">\n");
   // if (matrix[l][c] == '<')
   //    printf("<\n");

}