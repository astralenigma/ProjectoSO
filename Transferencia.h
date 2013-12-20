void descarregarContentorNavio() {
	int out = 0;
	while(ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		P(emptyDescarga);
		out++;
		ship.contentoresCheios--;
		printf("O navio está a descarregar\n");
		sleep(5);
		printf("O navio descarregou %d contentores.\n",out);
		//Aumentar o nº de contentores na zona de descarga
		V(fullDescarga);
		
		
	}
}

void carregarContentorNavio() {
int in = 0;	
	
	while(!(ship.contentoresVazios>=40&& *apNmrNaviosAEspera>0)){
		//Decrementar o nº de contentores na zona de carga
		P(fullCarga);
		//Incrementar o nº de contentores do navio no porto
		in++;
		ship.contentoresVazios++;
		printf("O navio está a carregar.\n");
		sleep(7);
		printf("O navio carregou %d contentores.\n",in);
		V(emptyCarga);
		if(ship.contentoresVazios == 50){
			break;
		}	
	}
}

void carregarContentorCamiao() {
	//Diminuir o nº de contentores na zona de carga 
	P(fullDescarga);
	//Incrementar o nº de espaços na zona de carga
	printf("Um camião está a carregar um contentor.\n");
	sleep(5);
	printf("Um camião foi carregado com um contentor.\n");
	V(emptyDescarga);
}

void descarregarContentorCamiao() {
	//Decrementar o nº de espaços na zona de carga
	P(emptyCarga);
	printf("Um camião está a descarregar um contentor.\n");
	sleep(4);
	//Aumentar o nº de contentores na zona de carga 
	printf("Um Camião descarregou um contentor.\n");
	V(fullCarga);
}
