#include "sema.h"
#include "cvs.h"
#include "transferencia.h"
#include "Camiao.h"
#include "Navio.h"
#include "Simular.h"


main(){
	int shmid;// id da memoria partilhada
	char *addr;
	int valorPid[MAX_CAMIOES], aguardaPid, aguardacliente, estadoCliente, child_stat;
	//int n, numeroCaxa, numeroP;
	//mutex = init_sem(1);		/* exclusao mutua */
	inicializarSemaforos();
	shmid = shmget(SHMKEY, 128, 0777|IPC_CREAT);
	addr = (char*) shmat(shmid, 0, 0);
	//pointerNavio = (struct Navio *) addr;
	//pointerZDescarga = (struct ZonaDescarga *) addr;
	//pointerPorto = (struct Navio *) addr;
    	int *ptr;
    	ptr = (int*) addr;
    	apNmrNaviosAEspera=(int*)ptr++;
    	//indeciso sobre o que usar
    	//apNmrNaviosAEspera=(int*)ptr++; 
	
	printf("---------------------Menu---------------------");
	printf("----------Opção 1- Iniciar Simulação----------");
	printf("----------------------------------------------");
	
	int x;
	scanf("Introduza a opção que deseja efectuar", %x);
	switch (x){
		case 1:
			simular();
			break;
		default : 
			printf("O numero que introduziu esta incorrecto.");
			
	};
		
}
