
//Inserir métodos para transferir os contentores
void descarregarContentorNavio() {
	
	for (;;) {//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		P(mutexDescarga);
		sleep(5);
		//Aumentar o nº de contentores na zona de descarga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		V(mutexDescarga);
	}
}

void carregarContentorNavio() {
	

	for (;;) {//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(mutexCarga);
		sleep(7);
		//Incrementar o nº de contentores do navio no porto
		//Alterar os semáforos
		V(mutexCarga);
	}
}

void carregarContentorCamiao() {
	

	for (;;) {//O Ciclo tem de ser alterado
		//Decrementar o nº de contentores na zona de descarga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(mutexCarga);
		sleep(5);
		//Gerar o inventário e caminho
		//Alterar os semáforos
		V(mutexCarga);
	}
}

void descarregarContentorCamiao() {
	

	for (;;) {//O Ciclo tem de ser alterado
		//Incrementar o nº de contentores na zona de carga (se calhar vai ser necessario usar semaforos)
		//Alterar os semáforos
		P(mutexCarga);
		sleep(4);
		//Alterar os semáforos
		V(mutexCarga);
	}
}
