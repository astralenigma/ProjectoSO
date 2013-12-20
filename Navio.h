

//Metodo que cria Navios
void criarNavio(){
	V(semaNaviosAEspera);
	(*apNmrNaviosAEspera)++;
	printf(ANSI_COLOR_GREEN"Estão %d navios à espera."ANSI_COLOR_RESET,*apNmrNaviosAEspera);
}
//Metodo que adiciona navios à lista de espera.
void criarNavios(){
	criarNavio();
	alarm(LIFETIME);
	srand(time(NULL));
	for(;;){
		int random=(300+rand()%61);
		sleep(random);
		criarNavio();
	}	
}
//Metodo para colocar o navio activo
void atracarNavio(){
	srand(time(NULL));
	P(semaNaviosAEspera);
	(*apNmrNaviosAEspera)--;
	Navio navio ={++(*barcosAtracados),(maxSCargo*0.8+(rand()%(int)(maxSCargo*0.2)+1)), 0};
	ship=navio;
}

//Metodo que controla as accoes dos navios
void controloNavio(){
	alarm(LIFETIME);
	for(;;){
		atracarNavio();
		printf(ANSI_COLOR_GREEN"O navio nº %d atracou.\n"ANSI_COLOR_RESET,ship.id);
		descarregarContentorNavio();
		carregarContentorNavio();
		printf(ANSI_COLOR_GREEN"O navio nº %d partiu.\n"ANSI_COLOR_RESET,ship.id);
	}
}
