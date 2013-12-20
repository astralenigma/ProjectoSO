#include "sema.h"
#include "cvs.h"
#include "Transferencia.h"
#include "Camiao.h"
#include "Navio.h"
#include "Simular.h"
main(){
	maxCamioes=10;
	maxChilds = maxCamioes + 2;
	maxSCargo = 50;
	maxUZCargo = 30;
	maxLZCargo = 20;
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
    	barcosAtracados=(int*)ptr++;
    	nmrCamioes=(int*)ptr++;
    	*barcosAtracados=0;
    	*apNmrNaviosAEspera=0;
    	//indeciso sobre o que usar
    	//apNmrNaviosAEspera=(int*)ptr++; 
	for( ; ;){	
	printf("---------------------Menu---------------------\n");
	printf("----------Opção 1- Iniciar Simulação----------\n");
	printf("----------Opção 2- Alterar Valores------------\n");
	printf("----------Opção 3- Estatisticas---------------\n");
	printf("----------Opção 4- Sair-----------------------\n");
	int x=0;
	*char erro;
	printf("Introduza a opção que deseja efectuar\n");
	scanf("%d", &x);
	switch (x){
		case 1:
			simular();
			break;
		case 2: 
		printf("---------------------------Menu------------------------------------\n"
			"----------Opção 1- Alterar Número de Camiões-----------------------\n"
			"----------Opção 2- Alterar Dimensão da Zona de Carga---------------\n"
			"----------Opção 3- Alterar Dimensão da Zona de Descarga------------\n"
			"----------Opção 4- Sair--------------------------------------------\n");
			printf("Introduza a opção que deseja efectuar\n");
			int y;
			scanf("%d", &y);
			switch(y){
			case 1:alterarNumeroCamioesEmpresa();
			break;
			case 2:alterarDimensaoZC();
			break;
			case 3:alterarDimensaoZD();
			}
			break;
		case 3:
			estatisticas();
			break;
		default : 
			printf("O numero que introduziu esta incorrecto.");
			
			break;
		};
		scanf("%s",erro);
	
       }
	
}
