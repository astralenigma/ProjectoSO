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
	
	while(!(*ship.contentoresVazios>=40&&nmrNaviosAEspera>0)){//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(fullCarga);
		P(mutexCarga);
		//Incrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		in++;
		*ship.contentoresVazios++;
		printf("Foi inserido %d contentores no navio", in);
		sleep(7);
		V(emptyCarga);
		V(mutexCarga);
		if(*ship.contentoresVazios == 50){
			break;
		}	
	}
}
	
	


void carregarContentorCamiao() {
int nmrContentores = 0;	
	while(nmrContentores == 0 && nmrContentores < 1) {//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de descarga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(fullCarga);
		P(mutexCarga);
		sleep(5);
		//Gerar o inventário e caminho
		//Alterar os semáforos
		V(emptyDescarga)
		V(mutexDescarga);
		
	}
}

void descarregarContentorCamiao() {
int nmrContentores =1;
int out = 0;

		//O Ciclo tem de ser alterado
		//Incrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		while(nmrContentores != 0){
		
		P(emptyDescarga);
		P(mutexDescarga);
		nmrContentores--;
		out++;
		printf("O Camiao descarregou %d contentores na zona de carga",out);	
		sleep(5);
		//Aumentar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		V(fullCarga);
		V(mutexCarga);
		
		}
}
