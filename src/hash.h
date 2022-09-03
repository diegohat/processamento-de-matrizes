#ifndef HASH_H
#include "matrix.h"

#define HASH_H

#define hash(v, m) (v % m)

typedef struct data_table data_table;
typedef struct hash_table hash_table;

struct data_table
{
  long long int key;
  submatrix *c;
};

struct hash_table
{
  data_table *table;
  int m;
};

void initialize(hash_table *h, int m);
void print(hash_table *h);
long long int get_key(submatrix *c);
submatrix *get_value(hash_table *h, long long int key);
void insert(hash_table *h, long long int key, submatrix *c);
bool linear_search(hash_table *h, long long int key);


void initialize(hash_table *h, int m)
{
  h->table = (data_table *)malloc(m * sizeof(data_table));

  for (int i = 0; i < m; i++)
  {
    h->table[i].key = -1;
    h->table[i].c = NULL;
  }

  h->m = m;
}

void print(hash_table *h)
{
  for (int i = 0; i < h->m; i++)
  {
    printf("KEY:%lld VALUE: ", h->table[i].key);
    if (h->table[i].c == NULL)
      printf("NULL\n");
    else
    {
      printf("\n");
      submatrix_print(h->table[i].c);
    }
  }
}

submatrix *get_value(hash_table *h, long long int key)
{
  int idx = hash(key, h->m);
  int aux = idx;

  while (h->table[idx].key != key)
  {
    idx = (idx + 1) % h->m;
    if (idx == aux)
    {
      return NULL;
    }
  }

  return h->table[idx].c;
}

void insert(hash_table *h, long long int key, submatrix *c)
{
  int idx = hash(key, h->m);
  int aux = idx;

  while (h->table[idx].key != -1)
  {
    idx = (idx + 1) % h->m;
    if (idx == aux)
    {
      printf("OPENED HASH IS FULL!\n");
      return;
    }
  }

  h->table[idx].key = key;
  h->table[idx].c = c;
}

long long int get_key(submatrix *c)
{
  FILE *file_ptr = fopen("src/key.txt", "r");

  /*   if (file_ptr == NULL)
    {
      printf("Error: could not open file\n");
      return;
    }

    c->xi = 0; */

  char *aux_string;
  char key_string[32] = {'\0'};
  size_t bytes = 32;
  aux_string = (char *)malloc(bytes + 1);
  getline(&aux_string, &bytes, file_ptr);
  char *token;
  token = (char *)malloc(bytes + 1);
  token = strtok(aux_string, " ");
  int i = 0;

  while (token != NULL)
  {
    strcat(key_string, token);

    if (i == 0)
      c->xi = atoi(token);
    if (i == 1)
      c->yi = atoi(token);
    if (i == 2)
      c->xf = atoi(token);
    if (i == 3)
      c->yf = atoi(token);
    
    token = strtok(NULL, " ");
    
    i++;
  }

  // printf("%s\n", key_string);

  char *eptr;
  long long int key = strtol(key_string, &eptr, 10);
  // printf("%lld\n", key);
  /*   printf("%d\n", c->xi);
    printf("%d\n", c->yi);
    printf("%d\n", c->xf);
    printf("%d\n", c->yf); */

  /*   for(int i = 0; i < 4; i++)
    {
      fseek(file_ptr, i*3, SEEK_SET);
      fscanf(file_ptr, "%d", &c->xi + i);
    } */
  fclose(file_ptr);
  return key;
}

bool linear_search(hash_table *h, long long int key)
{
  int idx = hash(key, h->m);
  int aux = idx;

  while (h->table[idx].key != key)
  {
    idx = (idx + 1) % h->m;
    if (idx == aux)
    {
      return false;
    }
  }

  return true;
}




#endif