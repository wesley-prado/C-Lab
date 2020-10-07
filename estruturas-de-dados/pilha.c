#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int info;
  struct no *proximo;
} No;

typedef struct pilha
{
  No *topo;
} Pilha;

Pilha *iniciarPilha(void)
{
  Pilha *nova_pilha = (Pilha *)malloc(sizeof(Pilha));
  nova_pilha->topo = NULL;
  return nova_pilha;
}

No *inserir(No *lista, int info)
{
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->info = info;
  novo_no->proximo = lista;
  return novo_no;
}

void push(Pilha *pilha, int info)
{
  pilha->topo = inserir(pilha->topo, info);
}

void pop(Pilha *pilha)
{
  No *aux = pilha->topo;
  pilha->topo = aux->proximo;
  free(aux);
}

void verificarPilha(No *lista)
{
  if (lista)
  {
    printf("inicio da lista. \n");
    do
    {
      printf("%d \n", lista->info);
      lista = lista->proximo;
    } while (lista);
    printf("Fim da lista. \n \n");
  }
  else
    printf("Nao ha uma pilha. \n");
}

void main()
{
  Pilha *pilha = iniciarPilha();
  push(pilha, 42);
  push(pilha, 82);
  push(pilha, 33);
  push(pilha, 25);
  verificarPilha(pilha->topo);
  push(pilha, 100);
  push(pilha, 200);
  verificarPilha(pilha->topo);
  pop(pilha);
  verificarPilha(pilha->topo);
}