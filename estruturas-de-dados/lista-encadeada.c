#include <stdio.h>
#include <locale.h>

struct no
{
  int info;
  struct no *proximo;
};

struct no *iniciarLista()
{
  return NULL;
}

void mostrarLista(struct no *lista)
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

struct no *adicionarNo(struct no *lista, int info)
{
  struct no *novoNo = (struct no *)malloc(sizeof(struct no));
  novoNo->info = info;
  novoNo->proximo = lista;
  return novoNo;
}

void buscarNo(struct no *lista, int info)
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
  struct no *lista = iniciarLista();
  lista = adicionarNo(lista, 45);
  lista = adicionarNo(lista, 90);
  mostrarLista(lista);
  buscarNo(lista, 90);
}