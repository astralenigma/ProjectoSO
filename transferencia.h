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

//Inserir métodos para transferir os contentores
void descarregarContentorNavio() {
	int out = 0;
	while(*ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		P(emptyDescarga);
		P(mutexDescarga);
		out++;
		*ship.contentoresCheios--;
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

	while(*ship.contentoresVazios<50){//O Ciclo tem de ser alterado
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
int out = 0;

		//O Ciclo tem de ser alterado
		//Incrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		while(nrContentores != 0){
		
		P(emptyCamiaoDescarga);
		P(mutexCamiaoDescarga);
		nrContentores--;
		out++;
		printf("O Camiao descarregou %d contentores na zona de carga",out);	
		sleep(5);
		//Aumentar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		V(fullCamiaoDescarga);
		V(mutexCamiaoDescarga);
		
		}
}
