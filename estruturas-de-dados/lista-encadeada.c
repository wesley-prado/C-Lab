#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
  int info;
  struct no *proximo;
} No;

No *iniciarLista()
{
  return NULL;
}

void mostrarLista(No *lista)
{
  printf("Mostrando a lista \n");
  if (lista)
  {
    do
    {
      printf("%d \n", lista->info);
      lista = lista->proximo;
    } while (lista);
  }
  else
    printf("Lista vazia \n");
}

No *adicionarNo(No *lista, int info)
{
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->info = info;
  novoNo->proximo = lista;
  return novoNo;
}

No *removerNo(No *lista, int info)
{
  No *anterior = NULL, *aux = lista;
  while (aux != NULL && aux->info != info)
  {
    anterior = aux;
    aux = aux->proximo;
  }
  if (!aux)
  {
    return lista;
  }
  if (!anterior)
  {
    lista = aux->proximo;
  }
  else
  {
    anterior->proximo = aux->proximo;
  }
  free(aux);
  return lista;
}

void buscarNo(No *lista, int info)
{
  int count = 0;
  if (lista)
  {
    do
    {
      count++;
      if (lista->info == info)
      {
        printf("%d foi achado no endereco de memoria %p e na posicao %d. \n", lista->info, lista, count);
        return;
      }
      lista = lista->proximo;
    } while (lista);
    printf("Nao foi possivel achar esta informacao. \n");
  }
}

void main()
{
  setlocale(LC_ALL, "");
  No *lista = iniciarLista();
  lista = adicionarNo(lista, 90);
  lista = adicionarNo(lista, 45);
  lista = adicionarNo(lista, 888);
  mostrarLista(lista);
  buscarNo(lista, 90);
  lista = removerNo(lista, 90);
  buscarNo(lista, 90);
}