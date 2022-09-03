#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MATRIX_SIZE 100

typedef struct submatrix submatrix;

struct submatrix
{
  int xi, yi;
  int xf, yf;
  int **values;
};

void matrix_create();

void submatrix_create(submatrix *c);

void submatrix_print(submatrix *c);

void multiplicate_transpose(submatrix *c);

//void get_coord(submatrix *c);

void matrix_create()
{
  srand(time(NULL));
  int random_value = rand() % 100;
  FILE *file_ptr = fopen("src/matrix.txt", "w");

  if (file_ptr == NULL)
  {
    printf("Error: could not open file\n");
    return;
  }

  for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++)
  {
    if (i > 0 && i % MATRIX_SIZE == 0)
      fprintf(file_ptr, "\n");
    if ((random_value) < 10)
      fprintf(file_ptr, "0");
    fprintf(file_ptr, "%d ", random_value);
    random_value = rand() % 100;
  }

  fclose(file_ptr);
}

void submatrix_create(submatrix *c)
{

  FILE *file_ptr = fopen("src/matrix.txt", "r");

  c->values = (int **)malloc(sizeof(int *) * (c->xf - c->xi) + 1);
  for (int i = 0; i <= c->xf - c->xi; i++)
  {
    c->values[i] = (int *)malloc(sizeof(int) * (c->yf - c->yi) + 1);
  }
  int value;

  for (int i = 0; i <= (c->xf - c->xi); i++)
  {
    fseek(file_ptr,
          ((MATRIX_SIZE * 3 + 1) * (c->xi - 1 + i)) + ((c->yi - 1) * 3),
          SEEK_SET);

    for (int j = 0; j <= (c->yf - c->yi); j++)
    {
      fscanf(file_ptr, "%d", &value);
      c->values[i][j] = value;
    }
  }
  fclose(file_ptr);
  submatrix_print(c);
}

void submatrix_print(submatrix *c)
{
  for (int i = 0; i <= (c->xf - c->xi); i++)
  {
    for (int j = 0; j <= (c->yf - c->yi); j++)
    {
      printf("%d ", c->values[i][j]);
    }
    printf("\n");
  }
}

void multiplicate_transpose(submatrix *c)
{
  submatrix t;

  t.xi = c->yi;
  t.xf = c->yf;
  t.yi = c->xi;
  t.yf = c->xf;

  t.values = (int **)malloc(sizeof(int *) * (t.xf - t.xi) + 1);
  for (int i = 0; i <= t.xf - t.xi; i++)
  {
    t.values[i] = (int *)malloc(sizeof(int) * (t.yf - t.yi) + 1);
  }

  for (int i = 0; i <= (t.xf - t.xi); i++)
  {
    for (int j = 0; j <= (t.yf - t.yi); j++)
    {
      t.values[j][i] = c->values[i][j];
    }
  }
  printf("\n\n");
  submatrix_print(&t);

  submatrix r;

  // produto de matrizes m x n * n x k = m x k

  r.xi = c->xi;
  r.xf = c->xf;
  r.yi = r.xi;
  r.yf = r.xf;

  r.values = (int **)malloc(sizeof(int *) * (r.xf - r.xi) + 1);
  for (int i = 0; i <= r.xf - r.xi; i++)
  {
    r.values[i] = (int *)malloc(sizeof(int) * (r.yf - r.yi) + 1);
  }

  for (int i = 0; i <= (c->xf - c->xi); i++)
  {
    for (int j = 0; j <= (t.yf - t.yi); j++)
    {
      r.values[i][j] = 0;
      for (int k = 0; k <= (c->yf - c->yi); k++)

        r.values[i][j] += c->values[i][k] * t.values[k][j];
    }
  }
  printf("\n\n");
  submatrix_print(&r);

  *c = r;
}

#endif