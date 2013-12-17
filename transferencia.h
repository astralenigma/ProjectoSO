void inicializarSemaforos(){
	mutexDescarga=init_sem(1);
	fullDescarga=init_sem(0);
	emptyDescarga=init_sem(MAX_UZCARGO);
	mutexCarga=init_sem(1);
	fullCarga=init_sem(0);
	emptyCarga=init_sem(MAX_LZCARGO);
	semaNaviosAEspera = init_sem(0);
}
void descarregarContentorNavio() {
	int out = 0;
	while(ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		P(emptyDescarga);
		P(mutexDescarga);
		out++;
		ship.contentoresCheios--;
		printf("O navio está a descarregar\n");
		sleep(5);
		printf("O navio descarregou %d contentores.\n",out);
		//Aumentar o nº de contentores na zona de descarga
		V(fullDescarga);
		V(mutexDescarga);
		
	}
}

void carregarContentorNavio() {
int in = 0;	
	
	while(!(ship.contentoresVazios>=40&&nmrNaviosAEspera>0)){
		//Decrementar o nº de contentores na zona de carga
		P(fullCarga);
		P(mutexCarga);
		//Incrementar o nº de contentores do navio no porto
		in++;
		ship.contentoresVazios++;
		printf("O navio está a carregar.\n");
		sleep(7);
		printf("O navio carregou %d contentores.\n",in);
		V(emptyCarga);
		V(mutexCarga);
		if(ship.contentoresVazios == 50){
			break;
		}	
	}
}

void carregarContentorCamiao() {
	//Diminuir o nº de contentores na zona de carga 
	P(fullDescarga);
	P(mutexDescarga);
	//Incrementar o nº de espaços na zona de carga
	printf("Um camião está a carregar um contentor");
	sleep(5);
	printf("Um camião foi carregado com um contentor.");
	V(emptyDescarga);
	V(mutexDescarga);
}

void descarregarContentorCamiao() {
	//Decrementar o nº de espaços na zona de carga
	P(emptyCarga);
	P(mutexCarga);
	printf("Um camião está a descarregar um contentor");
	sleep(4);
	//Aumentar o nº de contentores na zona de carga 
	printf("Um Camião descarregou um contentor.");
	V(fullCarga);
	V(mutexCarga);
}
