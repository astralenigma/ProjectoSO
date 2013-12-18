#include "sema.h"
#include "cvs.h"
#include "Transferencia.h"
#include "Camiao.h"
#include "Navio.h"
#include "Simular.h"


main(){
	printf("Insira o número maximo de camiões da empresa\n");
	scanf("%d", &maxCamioes);
	printf("Insira a dimensão da Zona de Carga \n");
	scanf("%d", &maxLZCargo);
	printf("Insira a dimensão da Zona de Descarga\n");
	scanf("%d", &maxUZCargo);
	//maxCamioes=10;
	maxChilds = maxCamioes + 2;
	maxSCargo = 50;
	//maxUZCargo = 30;
	//maxLZCargo = 20;
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
	
	printf("---------------------Menu---------------------\n");
	printf("----------Opção 1- Iniciar Simulação----------\n");
	printf("----------------------------------------------\n");
	
	int x;
	printf("Introduza a opção que deseja efectuar\n");
	scanf("%d", &x);
	switch (x){
		case 1:
			simular();
			break;
		default : 
			printf("O numero que introduziu esta incorrecto.");
			
	};
		
}
