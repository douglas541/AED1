#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
   char operation;
   int i, n;
   float paran1, paran2, paran3, result, p;

   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      scanf(" %c", &operation);

      if (operation == 'C') {
         scanf("%f", &paran1);
         result = PI * pow(paran1, 2);

         printf("%d\n", (int)round(result));
      }

      if (operation == 'E') {
         scanf("%f %f", &paran1, &paran2);
         result = PI * paran1 * paran2;

         printf("%d\n", (int)round(result));
      }

      if (operation == 'T') {
         scanf("%f %f %f", &paran1, &paran2, &paran3);
         p = (paran1 + paran2 + paran3) / 2;
         result = sqrt(p * (p - paran1) * (p - paran2) * (p - paran2));

         printf("%d\n", (int)round(result));
      }

      if (operation == 'Z') {
         scanf("%f %f %f", &paran1, &paran2, &paran3);
         result = (paran3 * (paran1 + paran2)) / 2;

         printf("%d\n", (int)round(result));
      }
   }

   return 0;
}