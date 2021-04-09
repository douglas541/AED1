#include <stdio.h>

int main() {
   char operacao;
   int matrix1[10][10], matrix2[10][10], outMatrix[10][10], m, n, i, j, k;

   scanf("%d %d", &m, &n);
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   scanf(" %c", &operacao);

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }

   if (operacao == '+') {
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++) {
            outMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
         }
      }
   }
   if (operacao == 'x') {
      if (m != n) {
         printf("ERROR\n");
         return 0;
      }
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++) {
            outMatrix[i][j] = 0;
            for (k = 0; k < n; k++) {
               outMatrix[i][j] = outMatrix[i][j] + (matrix1[i][k] * matrix2[k][j]);
            }
         }
      }
   }

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("%d ", outMatrix[i][j]);
      }
      printf("\n");
   }

   // for (i = 0; i < m; i++) {
   //    for (j = 0; j < n; j++) {
   //       printf("%d ", matrix1[i][j]);
   //    }
   //    printf("\n");
   // }
   // printf("%c\n", operacao);
   // for (i = 0; i < m; i++) {
   //    for (j = 0; j < n; j++) {
   //       printf("%d ", matrix2[i][j]);
   //    }
   //    printf("\n");
   // }

   return 0;
}