#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <pthread.h>

struct c {
 int saldo;
};
typedef struct c conta;
conta from, to;
int valor;
pthread_mutex_t regiaoCritica;

// Funcao para cada Thread
int transferencia( void *arg){
  //protecao a regiao critica
  //bloqueando as var from.saldo e to.saldo
  pthread_mutex_lock(&regiaoCritica);
  if (from.saldo >= valor){ // 2
    printf( "Transferindo 10 para a conta c2\n" );
    from.saldo -= valor;
    to.saldo += valor;
  }else{
    printf( "Transferindo 10 para a conta c1\n" );
    from.saldo += valor;
    to.saldo -= valor;
  }
  printf("Transferência concluída com sucesso!\n");
  printf("Saldo de c1: %d\n", from.saldo);
  printf("Saldo de c2: %d\n", to.saldo);
  //desbloqueando as var from.saldo e to.saldo
  pthread_mutex_unlock (&regiaoCritica);
  return 0;
}

int main(){
  //iniciando a variavel mutex
  pthread_mutex_init(&regiaoCritica, NULL);
  //vetor do tipo pthread_t
  pthread_t threads[100];
  int i;
  // Todas as contas começam com saldo 100
  from.saldo = 100;
  to.saldo = 100;
  valor = 10;
  for (i = 0; i < 100; i++) {
  // Criando Thread
    pthread_create(&threads[i], NULL, &transferencia, NULL);
  }
  for (i = 0; i < 100; i++){
  //  Terminando Thread
    pthread_join(threads[i], NULL);
  }
  // Free the stack
  printf("Transferências concluídas e memória liberada.\n");
  return 0;
}