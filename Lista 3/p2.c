#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define MENOR -1
#define IGUAL 0
#define MAIOR 1

//-------------------data.h---------------------

typedef struct data Data;

//Cria, de maneira dinâmica, uma data a partir dos valores para dia, mês e ano fornecidos.
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano);

//Cria uma cópia da data d, retornando-a.
Data* copiaData(Data* d);

//Destrói a data indicada por d.
void liberaData(Data* d);

//Retorna uma data que é dias dias posteriores à data d.
Data* somaDiasData(Data* d, unsigned int dias);

//Retorna uma data que é dias dias anteriores à data d.
Data* subtrairDiasData(Data* d, unsigned int dias);

//Atribui, à data d, a data dia/mes/ano especificada.
void atribuirData(Data* d, unsigned int dia, unsigned int mes, unsigned int ano);

//Retorna a componente dia da data d.
unsigned int obtemDiaData(Data* d);

//Retorna a componente mes da data d.
unsigned int obtemMesData(Data* d);

//Retorna a componente ano da data d.
unsigned int obtemAnoData(Data* d);

//Retorna TRUE se a data pertence a um ano bissexto. Do contrário, retorna FALSE.
unsigned int bissextoData(Data* d);

//Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2.
int comparaData(Data* d1, Data* d2);

//Retorna o número de dias que existe entre as datas d1 e d2.
unsigned int numeroDiasDatas(Data* d1, Data* d2);

//Se d1 e d2 estão no mesmo mês/ano, então o número de meses é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroMesesDatas(Data* d1, Data* d2);

//Se d1 e d2 estão no mesmo ano, então o número de anos é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroAnosDatas(Data* d1, Data* d2);

//Retorna o dia da semana correspodente à data d.
unsigned int obtemDiaSemanaData(Data* d);

//Retorna uma string com a data “formatada” de acordo com o especificado em formato.
char* imprimeData(Data* d, char* formato);

//imprime o menu
void menu();

//-------------------data.c---------------------

struct data
{
   unsigned int dia;
   unsigned int mes;
   unsigned int ano;
};

Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
   Data* p = (Data*)malloc(sizeof(Data));

   if (p != NULL)
   {
      p->dia = dia;
      p->mes = mes;
      p->ano = ano;

      return p;
   }
}

Data* copiaData(Data* d)
{
   Data* p = (Data*)malloc(sizeof(Data));

   if (p != NULL || d != NULL)
   {
      p->dia = d->dia;
      p->mes = d->mes;
      p->ano = d->ano;

      return p;
   }
}

void liberaData(Data* d)
{
   if (d != NULL)
      free(d);
}

Data* somaDiasData(Data* d, unsigned int dias)
{
   unsigned int dia, mes, ano;
   Data* data_retorno;

   ano = dias / 365;
   mes = (dias % 365) / 30;
   dia = (dias % 365) % 30;

   dia = d->dia + dia;
   mes = d->mes + mes;
   ano = d->ano + ano;

   if (dia > 30)
   {
      dia = dia - 30;
      mes++;
   }

   if (mes > 12)
   {
      mes = 1;
      ano++;
   }

   data_retorno = criaData(dia, mes, ano);

   if (data_retorno != NULL)
      return data_retorno;
}

Data* subtrairDiasData(Data* d, unsigned int dias)
{
   int dia, mes, ano, dias_int;
   Data* data_retorno;

   dias_int = (int)dias;

   ano = dias_int / 365;
   mes = (dias_int % 365) / 30;
   dia = (dias_int % 365) % 30;

   dia = d->dia - dia;
   mes = d->mes - mes;
   ano = d->ano - ano;

   if (dia < 1)
   {
      dia = dia + 30;
      mes--;
   }

   if (mes < 1)
   {
      mes = 12;
      ano--;
   }

   data_retorno = criaData(dia, mes, ano);

   if (data_retorno != NULL)
      return data_retorno;
}

void atribuirData(Data* d, unsigned int dia, unsigned int mes, unsigned int ano)
{
   if (d != NULL)
   {
      d->dia = dia;
      d->mes = mes;
      d->ano = ano;
   }
}

unsigned int obtemDiaData(Data* d)
{
   if (d != NULL)
      return d->dia;
}

unsigned int obtemMesData(Data* d)
{
   if (d != NULL)
      return d->mes;
}

unsigned int obtemAnoData(Data* d)
{
   if (d != NULL)
      return d->ano;
}

unsigned int bissextoData(Data* d)
{
   if (d != NULL)
   {
      if (d->ano % 400 == 0 || ((d->ano % 4 == 0) && (d->ano % 100 != 0)))
      {
         return true;
      }
      else
         return false;
   }
}

int comparaData(Data* d1, Data* d2)
{
   if (d1 == NULL || d2 == NULL)
   {
      EXIT_FAILURE;
   }

   if (d1->ano < d2->ano)
   {
      return MENOR;
   }

   if (d1->ano > d2->ano)
   {
      return MAIOR;
   }

   if (d1->ano == d2->ano)
   {

      if (d1->mes < d2->mes)
      {
         return MENOR;
      }

      if (d1->mes > d2->mes)
      {
         return MAIOR;
      }

      if (d1->mes == d2->mes)
      {

         if (d1->dia < d2->dia)
         {
            return MENOR;
         }

         if (d1->dia > d2->dia)
         {
            return MAIOR;
         }

         if (d1->dia == d2->dia)
         {
            return IGUAL;
         }
      }
   }
}

unsigned int numeroDiasDatas(Data* d1, Data* d2)
{
   unsigned int dias;

   dias = d1->dia - d2->dia;
   if (dias < 0)
      dias = dias * -1;

   return dias;
}

unsigned int numeroMesesDatas(Data* d1, Data* d2)
{
   unsigned int meses;

   meses = d1->mes - d2->mes;
   if (meses < 0)
      meses = meses * -1;

   return meses;
}

unsigned int numeroAnosDatas(Data* d1, Data* d2)
{
   unsigned int anos;

   anos = d1->ano - d2->ano;
   if (anos < 0)
      anos = anos * -1;

   return anos;
}

char* imprimeData(Data* d, char* formato) {
   char* saida;

   if (strcmp(formato, "ddmmaaaa"))
   {
      strcat(saida, "");
   }
}

//---------------CORPO PRINCIPAL----------------

int main()
{
   int i, j, qtd_elementos, dia, mes, ano, qtd_dias, elemento, operacao;
   Data* d1, * d2, * d_aux;

   do
   {
      d1 = criaData(1, 1, 1);
      d2 = criaData(1, 1, 1);
      d_aux = criaData(1, 1, 1);

      menu();
      printf("Insira o numero referente a operacao desejada: ");
      scanf("%d", &operacao);

      if (operacao == 1)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);
         printf("\ndigite a quantidade de dias: ");
         scanf("%d", &qtd_dias);

         atribuirData(d1, dia, mes, ano);

         d_aux = somaDiasData(d1, qtd_dias);
         printf("\nData posterior eh: %u/%u/%u\ndigite 0 para voltar ao menu anterior: ", d_aux->dia, d_aux->mes, d_aux->ano);
         scanf("%d", &j);
      }
      if (operacao == 2)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);
         printf("\ndigite a quantidade de dias: ");
         scanf("%d", &qtd_dias);

         atribuirData(d1, dia, mes, ano);

         d_aux = subtrairDiasData(d1, qtd_dias);
         printf("\nData anterior eh: %u/%u/%u\ndigite 0 para voltar ao menu anterior: ", d_aux->dia, d_aux->mes, d_aux->ano);
         scanf("%d", &j);
      }
      if (operacao == 3)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         elemento = obtemDiaData(d1);
         printf("\nComponente dia eh: %u\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }
      if (operacao == 4)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         elemento = obtemMesData(d1);
         printf("\nComponente mes eh: %u\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }
      if (operacao == 5)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         elemento = obtemAnoData(d1);
         printf("\nComponente ano eh: %u\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }
      if (operacao == 6)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         if (bissextoData(d1))
         {
            printf("Ano bissexto!\n");
         }
         else
         {
            printf("Ano nao bissexto!\n");
         }
      }
      if (operacao == 7)
      {
         printf("\ndigite o dia referente a data d: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         if (bissextoData(d1))
         {
            printf("Ano bissexto!\n");
         }
         else
         {
            printf("Ano nao bissexto!\n");
         }
      }
      if (operacao == 8)
      {
         printf("\ndigite o dia referente a data d1: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d1: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d1: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         printf("\ndigite o dia referente a data d2: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d2: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d2: ");
         scanf("%d", &ano);

         atribuirData(d2, dia, mes, ano);

         elemento = numeroDiasDatas(d1, d2);

         printf("\nO numero de dias entre d1 e d2 eh: %d\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }
      if (operacao == 9)
      {
         printf("\ndigite o dia referente a data d1: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d1: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d1: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         printf("\ndigite o dia referente a data d2: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d2: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d2: ");
         scanf("%d", &ano);

         atribuirData(d2, dia, mes, ano);

         elemento = numeroMesesDatas(d1, d2);

         printf("\nO numero de dias entre d1 e d2 eh: %d\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }
      if (operacao == 10)
      {
         printf("\ndigite o dia referente a data d1: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d1: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d1: ");
         scanf("%d", &ano);

         atribuirData(d1, dia, mes, ano);

         printf("\ndigite o dia referente a data d2: ");
         scanf("%d", &dia);
         printf("\ndigite o mes referente a data d2: ");
         scanf("%d", &mes);
         printf("\ndigite o ano referente a data d2: ");
         scanf("%d", &ano);

         atribuirData(d2, dia, mes, ano);

         elemento = numeroAnosDatas(d1, d2);

         printf("\nO numero de dias entre d1 e d2 eh: %d\ndigite 0 para voltar ao menu anterior: ", elemento);
         scanf("%d", &j);
      }

      liberaData(d1);
      liberaData(d2);
      liberaData(d_aux);

   } while (operacao != 0);

   return 0;
}

void menu()
{
   system("clear");
   printf("ESCOLHA UMA OPERACAO\n\n");
   printf("1 - Calcular uma data que é x dias posteriores à data d.\n");
   printf("2 - Calcular uma data que é x dias anteriores à data d.\n");
   printf("3 - Retornar a componente dia da data d.\n");
   printf("4 - Retornar a componente mes da data d.\n");
   printf("5 - Retornar a componente ano da data d.\n");
   printf("6 - Descobrir se uma data pertence a um ano bissexto\n");
   printf("7 - Comparar duas datas\n");
   printf("8 - Retornar o número de dias que existe entre as datas d1 e d2.\n");
   printf("9 - Retornar o número de meses que existe entre as datas d1 e d2.\n");
   printf("10 - Retornar o número de anos que existe entre as datas d1 e d2.\n");
   printf("0 - Sair do programa\n\n");
}