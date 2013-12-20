//método para descarregar um contentor do Navio para zona de descarga
void descarregarContentorNavio() {
	int out = 0;
	while(ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		P(emptyDescarga);
		out++;
		ship.contentoresCheios--;
		printf("O navio está a descarregar\n");
		sleep(5);
		++*nmrContentoresZD;
		printf("O navio descarregou %d contentores.\n",out);
		//Aumentar o nº de contentores na zona de descarga
		V(fullDescarga);
	}
}
//Método para carregar um contentor do Navio da zona de carga
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
		++*nmrContentoresZC;
		V(emptyCarga);
		if(ship.contentoresVazios == 50){
			break;
		}	
	}
}
//Método para carregar um contentor de um Camiao da zona de descarga
void carregarContentorCamiao() {
	//Diminuir o nº de contentores na zona de descarga 
	P(fullDescarga);
	++*nmrContentoresZD;
	printf("Um camião está a carregar um contentor.\n");
	sleep(5);
	printf("Um camião foi carregado com um contentor.\n");
	//Incrementar o nº de espaços na zona de descarga
	V(emptyDescarga);
}
//Método para descarregar um contentor de um Camiao para zona de carga
void descarregarContentorCamiao() {
	//Decrementar o nº de espaços na zona de carga
	P(emptyCarga);
	printf("Um camião está a descarregar um contentor.\n");
	sleep(4);
	++*nmrContentoresZC;
	printf("Um Camião descarregou um contentor.\n");
	//Aumentar o nº de contentores na zona de carga 
	V(fullCarga);
}
