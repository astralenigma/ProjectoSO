//método para descarregar um contentor do Navio para zona de descarga
void descarregarContentorNavio() {
	int out = 0;
	while(ship.contentoresCheios !=0 ) {
		//Decrementar o nº de contentores do navio no porto
		
		P(emptyDescarga);
		P(mutexDescarga);
		out++;
		ship.contentoresCheios--;
		printf(ANSI_COLOR_RED"O navio está a descarregar\n"ANSI_COLOR_RESET);
		sleep(5);
		*nmrMaxContentoresZD=max(*nmrMaxContentoresZD,++*nmrContentoresZD);
		printf(ANSI_COLOR_MAGENTA"A zona tem agora %d contentores.\n"ANSI_COLOR_RESET,*nmrContentoresZD);
		printf(ANSI_COLOR_RED"O navio descarregou %d contentores.\n"ANSI_COLOR_RESET,out);
		//Aumentar o nº de contentores na zona de descarga
		V(fullDescarga);
		V(mutexDescarga);
	}
}
//Método para carregar um contentor do Navio da zona de carga
void carregarContentorNavio() {
int in = 0;	
	
	while(!(ship.contentoresVazios>=40&& *apNmrNaviosAEspera>0)){
		//Decrementar o nº de contentores na zona de carga
		P(fullCarga);
		P(mutexCarga);
		//Incrementar o nº de contentores do navio no porto
		in++;
		ship.contentoresVazios++;
		printf(ANSI_COLOR_RED"O navio está a carregar.\n"ANSI_COLOR_RESET);
		sleep(7);
		*nmrMinContentoresZC=min(*nmrMinContentoresZC,--*nmrContentoresZC);
		printf(ANSI_COLOR_MAGENTA"A zona tem agora %d contentores.\n"ANSI_COLOR_RESET,*nmrContentoresZC);
		printf(ANSI_COLOR_RED"O navio carregou %d contentores.\n"ANSI_COLOR_RESET,in);
		V(emptyCarga);
		V(mutexCarga);
		if(ship.contentoresVazios == 50){
			break;
		}	
	}
}
//Método para carregar um contentor de um Camiao da zona de descarga
void carregarContentorCamiao() {
	//Diminuir o nº de contentores na zona de descarga
	P(fullDescarga);
	P(mutexDescarga);
	printf(ANSI_COLOR_YELLOW"Um camião está a carregar um contentor.\n"ANSI_COLOR_RESET);
	sleep(5);
	
	*nmrMinContentoresZD=min(*nmrMinContentoresZD,--*nmrContentoresZD);
	printf(ANSI_COLOR_MAGENTA"A zona tem agora %d contentores.\n"ANSI_COLOR_RESET,*nmrContentoresZD);
	printf(ANSI_COLOR_YELLOW "Um camião foi carregado com um contentor.\n"ANSI_COLOR_RESET);
	//Incrementar o nº de espaços na zona de descarga
	V(emptyDescarga);
	V(mutexDescarga);
}
//Método para descarregar um contentor de um Camiao para zona de carga
void descarregarContentorCamiao() {
	//Decrementar o nº de espaços na zona de carga
	P(emptyCarga);
	P(mutexCarga);	
	printf(ANSI_COLOR_YELLOW "Um camião está a descarregar um contentor.\n"ANSI_COLOR_RESET);
	sleep(4);
	*nmrMaxContentoresZC=max(*nmrMaxContentoresZC,++*nmrContentoresZC);
	printf(ANSI_COLOR_MAGENTA"A zona tem agora %d contentores.\n"ANSI_COLOR_RESET,*nmrContentoresZC);
	printf(ANSI_COLOR_YELLOW "Um Camião descarregou um contentor.\n"ANSI_COLOR_RESET);
	//Aumentar o nº de contentores na zona de carga 
	V(fullCarga);
	V(mutexCarga);
}
