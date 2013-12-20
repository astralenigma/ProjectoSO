//Método que iniciliza os semáforos
void inicializarSemaforos(){
	fullDescarga=init_sem(0);
	emptyDescarga=init_sem(maxUZCargo);
	fullCarga=init_sem(0);
	emptyCarga=init_sem(maxLZCargo);
	semaNaviosAEspera = init_sem(0);
	mutexCarga=init_sem(1);
	mutexDescarga=init_sem(1);
}
//Método que inicia a simulação
simular(){
	/* exclusao mutua */
	inicializarSemaforos();
	shmid = shmget(SHMKEY, 128, 0777|IPC_CREAT);
	addr = (char*) shmat(shmid, 0, 0);
	//A alocar as variáveis na memória
	int *ptr;
	ptr = (int*) addr;
	apNmrNaviosAEspera=(int*)ptr++;
	barcosAtracados=(int*)ptr++;
	nmrCamioes=(int*)ptr++;
	nmrContentoresZC=(int*)ptr++;
	nmrContentoresZD=(int*)ptr++;
	esMaxTN=(int*)ptr++;
	esMinTN=(int*)ptr++;
	esMedTN=(int*)ptr++;
	esMaxIC=(int*)ptr++;
	esMinIC=(int*)ptr++;
	esMedIC=(int*)ptr++;
    	//indeciso sobre o que usar
    	//apontador=(tipo do apntador*)ptr++;
    	//Inicializar as variáveis na memória
	*esMaxTN=0;
	*esMinTN=0;
	*esMedTN=0;
	*esMaxIC=0;
	*esMinIC=0;
	*esMedIC=0;
	*nmrContentoresZD=0;
	*nmrContentoresZC=0;
	*barcosAtracados=0;
	*apNmrNaviosAEspera=0;
	int child_pid[maxChilds];
	fflush(stdout);
	for (i = 0; i < maxChilds; i++) {
                child_pid[i] = fork();
                switch (child_pid[i]) {
                        case -1: /* error: no process created*/
                                perror("fork failed");
                                exit(1);
                        break;
                        case 0: /*child process*/
                                if (i == 0) {
                                	printf("Não estás a funcar pq?");
                                        criarNavios();
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
                                        printf( "Atracaram %d* Navios.\n"
                                        	"Ficaram %d Navios por atender.\n"
                                        	"Ficaram %d Contentores na Zona de Carga\n"
                                        	"Ficaram %d Contentores na Zona de Descarga\n",*barcosAtracados,*apNmrNaviosAEspera,*contentoresNaZC,*contentoresNaZD);
                                        //rel_sem(mutex);
                                        rel_sem(fullDescarga);
                                        rel_sem(emptyDescarga);
                                        rel_sem(fullCarga);
                                        rel_sem(emptyCarga);
                                        rel_sem(semaNaviosAEspera);
                                        rel_sem(mutexCarga);
                                        rel_sem(mutexDescarga);
                                        shmdt(addr);
                                        shmctl(shmid, IPC_RMID, 0);
                                }
                        break;
                } /*end switch*/
        }
}
//Métoddo que altera o número de camioes
alterarNumeroCamioesEmpresa(){
	printf("Insira o número maximo de camiões da empresa\n");
	scanf("%d", &maxCamioes);
	printf("Numero de camioes disponiveis da empresa %d.\n", maxCamioes);
}   
//Métoddo que altera a dimensão da zona de carga
alterarDimensaoZC(){
     	printf("Insira a dimensão da Zona de Carga\n");
	scanf("%d", &maxLZCargo);
	printf("Dimensão da zona de Carga %d.\n", maxLZCargo);
}
//Métoddo que altera a dimensão da zona de descarga
alterarDimensaoZD(){
	printf("Insira a dimensão da Zona de Descarga\n");
	scanf("%d", &maxUZCargo);
	printf("Dimensão da zona de Descarga %d.\n", maxUZCargo);
}
estatisticas(){
 printf("HELLLLOOOOO");
}
