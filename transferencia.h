#include <stdio.h>
#include "sema.h"
#include "cvs.h"
#include "Navio.h"

semaphore mutexDescarga;
semaphore fullDescarga;
semaphore emptyDescarga;

semaphore mutexCarga;
semaphore fullCarga;
semaphore emptyCarga;

semaphore mutexCamiaoCarga;
semaphore fullCamiaoCarga;
semaphore emptyCamiaoCarga;

semaphore mutexCamiaoDescarga;
semaphore fullCamiaoDescarga;
semaphore emptyCamiaoDescarga; 


//Navio 
Navio n = criarNavio();

//Inserir métodos para transferir os contentores
void descarregarContentorNavio() {
	int out = 0;
	while(n.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		P(emptyDescarga);
		P(mutexDescarga);
		out++;
		n.contentoresCheios--;
		printf("O navio descarregou %d contentores",out);	
		sleep(5);
		//Aumentar o nº de contentores na zona de descarga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		V(fullDescarga);
		V(mutexDescarga);
		
	}
}

void carregarContentorNavio() {
int in = 0;	

	for (;;){//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(mutexCarga);
		sleep(7);
		//Incrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		V(mutexCarga);
	}
}

void carregarContentorCamiao() {
	for (;;) {//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de descarga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(fullDescarga);
		P(mutexDescarga);
		sleep(5);
		//Gerar o inventário e caminho
		//Alterar os semáforos
		V(emptyCarga)
		V(mutexCarga);
		
	}
}

void descarregarContentorCamiao() {
int nrContentores =1;	

	for (;;) {//O Ciclo tem de ser alterado
		//Incrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(mutexCarga);
		sleep(4);
		//Alterar os semáforos
		V(mutexCarga);
	}
}
