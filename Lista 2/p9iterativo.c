#include <stdio.h>

int hanoi(char, char, char, int);

int main() {
   int n;

   scanf("%d", &n);
   hanoi('O', 'D', 'A', n);

   return 0;
}

int hanoi(char O, char D, char A, int n) {
   if (n == 2) {
      printf("(%c,%c)\n", O, A);
      printf("(%c,%c)\n", O, D);
      printf("(%c,%c)\n", A, D);
      return 0;
   }
   else {
      hanoi(O, A, D, n-1);
      printf("(%c,%c)\n", O, D);
      printf("(%c,%c)\n", A, O);
      printf("(%c,%c)\n", A, D);
      printf("(%c,%c)\n", O, D);
   }
}