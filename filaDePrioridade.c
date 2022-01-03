/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"
#define MAX 5

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->referencias = (PONT*) malloc(sizeof(PONT)*MAX);
  res->heap = (PONT*) malloc(sizeof(PONT)*MAX);
  int i;
  for (i=0;i<MAX;i++) {
    res->referencias[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}


bool exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int tam = 0;
  tam = f->elementosNoHeap;
  return tam;
}

PONT buscarID(PFILA f, int id){
	int i = 0;
  PONT atual;
  for (i=0;i < f->elementosNoHeap; i++)
  {
    atual = f->heap[i];
		if (atual->id == id) 
      return atual;
  }
	return NULL;
}

void maxHeapfy(PFILA f, int i)
{
  int e = 2*i + 1;
  int d = 2*i + 2;
  int maior;
  if(e < f->elementosNoHeap && f->heap[e]->prioridade > f->heap[i]->prioridade)
    maior = e;
  else
    maior = i;
  if(d < f->elementosNoHeap && f->heap[d]->prioridade > f->heap[maior]->prioridade)
    maior = d;
  if(maior != i) //se o m6aior não é o pai
  {
    PONT tmp;
    tmp = f->heap[i];
    f->heap[i] = f->heap[maior];
    f->heap[maior] = tmp;
    maxHeapfy(f, (i-1)/2);
  }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool res = false;

  if(id < 0 || id >= MAX || f->referencias[id] != NULL)
    return res;
  
  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  
  novo->id = id;
  novo->prioridade = prioridade;
  f->referencias[id] = novo;

  int i = 0;
  PONT atual;
  while(i < f->elementosNoHeap)
    i++;
  f->heap[i] = novo;
  novo->posicao = i;
  res = true;

  f->elementosNoHeap++;
  
  if(f->elementosNoHeap > 1)
    maxHeapfy(f, (i-1)/2);
  
  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
  
  /* COMPLETAR */
  
  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;

  if(id < 0 || id >= MAX || f->referencias[id] == NULL)
    return res;
  
  *resposta = f->referencias[id]->prioridade;

  res = true;
  return res;
}
int main()
{
  PFILA f = criarFila();
  exibirLog(f);



  if(inserirElemento(f, 1, 1)) printf("ok\n");
  else printf("nok (1)\n");
  exibirLog(f);

  if(inserirElemento(f, 2, 2)) printf("ok\n");
  else printf("nok (1)\n");
  exibirLog(f);
  if(inserirElemento(f, 4, 3)) printf("ok\n");
  else printf("nok (2)\n");
  exibirLog(f);
  if(inserirElemento(f, 3, 5)) printf("ok\n");
  else printf("nok (2)\n");
  exibirLog(f);
  if(inserirElemento(f, 0, 1)) printf("ok\n");
  else printf("nok (2)\n");
  exibirLog(f);


  float prioridade;
if(consultarPrioridade(f, 2, &prioridade)) printf("ok %f\n", prioridade);
  else printf("nok (1)\n");

    int tam;
  tam = tamanho(f);
  printf("%d\n", tam);
}