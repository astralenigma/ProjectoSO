semaphore mutexDescarga=init_sem(1);
semaphore fullDescarga;
semaphore emptyDescarga;

semaphore mutexCarga=init_sem(1);
semaphore fullCarga;
semaphore emptyCarga;
 


void descarregarContentorNavio() {
	int out = 0;
	while(*ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		P(emptyDescarga);
		P(mutexDescarga);
		out++;
		*ship.contentoresCheios--;
		printf("O navio descarregou %d contentores",out);	
		sleep(5);
		//Aumentar o nº de contentores na zona de descarga
		V(fullDescarga);
		V(mutexDescarga);
		
	}
}

void carregarContentorNavio() {
int in = 0;	
	
	while(!(*ship.contentoresVazios>=40&&nmrNaviosAEspera>0)){
		//Decrementar o nº de contentores na zona de carga
		P(fullCarga);
		P(mutexCarga);
		//Incrementar o nº de contentores do navio no porto
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
	P(mutexDescarga);
	sleep(5);
	//Incrementar o nº de espaços na zona de carga
	V(emptyDescarga);
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
