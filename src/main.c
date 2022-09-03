#include "hash.h"

int main()
{
  submatrix c;

  hash_table h;

  int m = 10;

  long long int key;

  initialize(&h, m);

  int user_entry = 99;

  while (user_entry != 0)
  {
    printf("----------------MENU----------------\n");
    printf("[1] GERAR SUBMATRIZ\n");
    printf("[2] CALCULAR SUBMATRIZ X TRANSPOSTA\n");
    printf("[3] IMPRIMIR SUBMATRIZ RESULTADO\n");
    printf("[4] IMPRIMIR TABELA HASH\n");
    printf("[5] GERAR NOVO ARQUIVO COM MATRIZ ALEATORIA\n");
    printf("[0] SAIR\n");
    printf("------------------------------------\n");

    scanf("%d", &user_entry);

    switch (user_entry)
    {
    case 1:
      printf("Gerando Submatriz...\n");
      key = get_key(&c);
      if (linear_search(&h, key))
      {
        printf("Matriz já calculada anteriormente. Resultado:\n");
        submatrix_print(get_value(&h, key));
      }
      else
      {
        submatrix_create(&c);
        insert(&h, key, &c);
        printf("Matriz criada com sucesso.\n");
      }
      break;

    case 2:
      printf("Calculando multiplicação de matrizes...\n");
      multiplicate_transpose(&c);
      printf("Submatriz resultante calculada.\n");
      break;

    case 3:
      printf("Matriz resultado:\n");
      submatrix_print(&c);
      break;

    case 4:
      printf("Imprimindo HASH...\n");
      print(&h);
      printf("\nHASH impressa com sucesso.\n");
      break;

    case 5:
      printf("Gerando nova Matriz Aleatoria...\n");
      matrix_create();
      printf("Matriz criada com sucesso.\n");
      break;

    case 0:
      printf("Encerrando...\n");
      break;

    default:
      printf("Digite um valor valido.\n");
      break;
    }
  }
  return 0;
}