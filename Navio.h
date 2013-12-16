//Metodo que devolve um navio usar para criar o navio.
void criarNavio(void){
	alarm(LIFETIME);
	srand(time(NULL));
	for(;;){
		//TODO Inserir código de criar navio
		
		//Código de espera para criar o novo navio
		int random=(rand()%61);
		sleep(300+random);
		V(nmrNaviosAEspera);
		//TODO Inserir teste de mandar o navio embora
		
		//TODO Inserir código de mandar o navio embora
	}	
};

//Metodo para colocar o navio activo
void atracarNavio(void){
	srand(time(NULL));
	P(nmrNaviosAEspera);
	Navio navio ={(MAX_SCARGO*0.8+(rand()%(int)(MAX_SCARGO*0.2)+1)), 0};
	*ship=navio;
};

void controloNavio{
	alarm(LIFETIME);
	for(;;){
		P(nmrNaviosAEspera);
		atracarNavio();
		while(!(nmrNaviosAEspera>0 && *ship.contentoreVazios>40)){
			while(*ship.contentoresCheios!=0){
				descarregarContentorNavio();
			}
			carregarContentorNavio();
		}
	}
}
