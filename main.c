#include "sema.h"
#include "cvs.h"
#include "Transferencia.h"
#include "Camiao.h"
#include "Navio.h"
#include "Simular.h"
int main(void){
	maxCamioes=10;
	maxChilds = maxCamioes + 2;
	maxSCargo = 50;
	maxUZCargo = 30;
	maxLZCargo = 20;
	
	for(;;){	
		printf("---------------------Menu---------------------\n");
		printf("----------Opção 1- Iniciar Simulação----------\n");
		printf("----------Opção 2- Alterar Valores------------\n");
		printf("----------Opção 3- Estatisticas---------------\n");
		printf("----------Opção 4- Sair-----------------------\n");
		char x;
		printf("Introduza a opção que deseja efectuar\n");
		scanf("%s", &x);
		switch (x){
			case '1':
				simular();
				break;
			case '2': 
			printf("---------------------------Menu------------------------------------\n"
				"----------Opção 1- Alterar Número de Camiões-----------------------\n"
				"----------Opção 2- Alterar Dimensão da Zona de Carga---------------\n"
				"----------Opção 3- Alterar Dimensão da Zona de Descarga------------\n"
				"----------Opção 4- Sair--------------------------------------------\n");
				printf("Introduza a opção que deseja efectuar\n");
				char y;
				scanf("%s", &y);
				switch(y){
				case '1':alterarNumeroCamioesEmpresa();
				break;
				case '2':alterarDimensaoZC();
				break;
				case '3':alterarDimensaoZD();
				}
				break;
			case '3':
				estatisticas();
				break;
			case '4':
				return 0;
			default : 
				printf("O caracter introduzido é invalido.\n");
				break;
		}
       }
}
