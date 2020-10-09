#include <stdio.h>

typedef struct arvore
{
  int info;
  struct arvore *sae;
  struct arvore *sad;
} Arv;

Arv *iniciar(int valor)
{
  Arv *p = (Arv *)malloc(sizeof(Arv));
  p->info = valor;
  p->sad = NULL;
  p->sae = NULL;
  return p;
}

void adicionar(Arv *raiz, int valor)
{
  if (valor > raiz->info)
  {
    if (raiz->sad)
    {
      adicionar(raiz->sad, valor);
    }
    else
    {
      raiz->sad = iniciar(valor);
    }
  }
  if (valor < raiz->info)
  {
    if (raiz->sae)
    {
      adicionar(raiz->sae, valor);
    }
    else
    {
      raiz->sae = iniciar(valor);
    }
  }
  else
    return;
}

//imprime em pre-ordem
void imprime(Arv *raiz)
{
  printf("<");
  if (raiz)
  {
    printf("%d", raiz->info);
    imprime(raiz->sae);
    printf(",");
    imprime(raiz->sad);
  }
  printf(">");
}

void main()
{
  Arv *raiz = iniciar(15);
  adicionar(raiz, 30);
  adicionar(raiz, 40);
  adicionar(raiz, 10);
  adicionar(raiz, 9);
  adicionar(raiz, 13);
  adicionar(raiz, -3);
  imprime(raiz);
}