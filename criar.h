#include "cvs.h"

//Metodo que devolve um navio usar para criar o navio.
Navio criarNavio(void){
	srand(time(NULL));
	int random=(MAX_SCARGO*0.8+(rand()%(int)(MAX_SCARGO*0.2)+1));
	Navio navio ={(init_sem(random)), (init_sem(MAX_SCARGO-random))};
	return navio;
}

//Metodo para colocar o navio activo
atracarNavio(){
	srand(time(NULL));
	for(;;){
		//TODO Inserir código de criar navio
		
		//Código de espera para criar o novo navio
		int random=(rand()%61);
		sleep(300+random);
		
		//TODO Inserir teste de mandar o navio embora
		
		//TODO Inserir código de mandar o navio embora
		
	}
}

