#include <stdio.h>
#include <locale.h>

typedef struct
{
  int info;
  struct no *proximo;
} no;

no *iniciarLista()
{
  return NULL;
}

void mostrarLista(no *lista)
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

no *adicionarNo(no *lista, int info)
{
  no *novoNo = (no *)malloc(sizeof(no));
  novoNo->info = info;
  novoNo->proximo = lista;
  return novoNo;
}

void buscarNo(no *lista, int info)
{
  if (lista)
  {
    do
    {
      if (lista->info == info)
      {
        printf("%d foi achado no endereco de memoria %p. \n", lista->info, lista);
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
  no *lista = iniciarLista();
  lista = adicionarNo(lista, 45);
  lista = adicionarNo(lista, 90);
  mostrarLista(lista);
  buscarNo(lista, 90);
}