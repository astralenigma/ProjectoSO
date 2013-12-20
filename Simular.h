void inicializarSemaforos(){
	fullDescarga=init_sem(0);
	emptyDescarga=init_sem(maxUZCargo);
	fullCarga=init_sem(0);
	emptyCarga=init_sem(maxLZCargo);
	semaNaviosAEspera = init_sem(1);
}

simular(){
	int child_pid[maxChilds];
	for (i = 0; i < maxChilds; i++) {
                // printf("%d\n", i);
                child_pid[i] = fork();
                switch (child_pid[i]) {
                        case -1: /* error: no process created*/
                                perror("fork failed");
                                exit(1);
                        break;
                        case 0: /*child process*/
                                if (i == 0) {
                                        criarNavio();
                                }
                                if (i == 1) {
                                        controloNavio();
                                }
                                if (i >= 2) {
                                	nmrCamiao=i-1;
                                        controloCamiao();
                                }
                        break;
                        default: /*parent process*/
                                if (i == (maxChilds - 1)) /* all childs created ?*/ { /* yes -> wait for termination        */
                                            for ( j = 0; j < maxChilds; j++) {
                                                wait_pid = wait(&child_stat);
                                                if (wait_pid == -1) {
                                                            perror("wait failed");
                                                }
                                            }
                                        printf("Atracaram %d* Navios.\nFicaram %d Navios por atender.\nFicaram %d Contentores na Zona de Carga\nFicaram %d Contentores na Zona de Descarga\n",*barcosAtracados,*apNmrNaviosAEspera,*contentoresNaZC,*contentoresNaZD);
                                        //rel_sem(mutex);
                                        rel_sem(fullDescarga);
                                        rel_sem(emptyDescarga);
                                        rel_sem(fullCarga);
                                        rel_sem(emptyCarga);
                                        shmdt(addr);
                                        shmctl(shmid, IPC_RMID, 0);
                                }
                        break;
                } /*end switch*/
        }
}       
alterarNumeroCamioesEmpresa(){
	printf("Insira o número maximo de camiões da empresa\n");
	scanf("%d", &maxCamioes);
	printf("Numero de camioes disponiveis da empresa %d.\n", maxCamioes);
	
}   
     
alterarDimensaoZC(){
     	printf("Insira a dimensão da Zona de Carga\n");
	scanf("%d", &maxLZCargo);
	printf("Dimensão da zona de Carga %d.\n", maxLZCargo);
	
}
     
alterarDimensaoZD(){
	printf("Insira a dimensão da Zona de Descarga\n");
	scanf("%d", &maxUZCargo);
	printf("Dimensão da zona de Descarga %d.\n", maxUZCargo);
     	
}

estatisticas(){
 printf("HELLLLOOOOO");
}

