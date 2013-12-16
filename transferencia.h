semaphore mutexDescarga;
semaphore fullDescarga;
semaphore emptyDescarga;

semaphore mutexCarga;
semaphore fullCarga;
semaphore emptyCarga;
 

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
	//Diminuir o nº de contentores na zona de carga 
	P(fullDescarga);
	P(mutexDesCarga);
	sleep(5);
	//Incrementar o nº de espaços na zona de carga
	V(emptyDescarga)
	V(mutexDescarga);
}

void descarregarContentorCamiao() {
	//Decrementar o nº de espaços na zona de carga
	P(emptyCarga);
	P(mutexCarga);
	sleep(4);
	//Aumentar o nº de contentores na zona de carga 
	V(fullCarga);
	V(mutexCarga);
}
