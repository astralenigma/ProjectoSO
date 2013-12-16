#include "sema.h"
#include "cvs.h"
#include "transferencia.h"
#include "Camiao.h"
#include "Navio.h"

main(){
	int shmid;// id da memoria partilhada
	char *addr;
	int valorPid[MAX_CAMIOES], aguardaPid, aguardacliente, estadoCliente, child_stat;
	int n, numeroCaxa, numeroP;
	mutex = init_sem(1);		/* exclusao mutua */
	inicializarSemaforos();
	shmid = shmget(SHMKEY, MAX_CAMIOES, 0777|IPC_CREAT);
	addr = (char*) shmat(shmid, 0, 0);
	for (int i = 0; i < MAX_CHILD; ++i) {
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
                		if (i <= 2) {
					controloCamiao();
                		}
			break;
			default: /*parent process*/
				if (i == (MAX_CHILD - 1)) /* all childs created ?*/ { /* yes -> wait for termination	*/
                    			for (int j = 0; j < MAX_CHILD; ++j) {
                        			wait_pid = wait(&child_stat);
						if (wait_pid == -1) {
	                            			perror("wait failed");
						};
                    			};
					printf("All child processes have terminated.\n");
					rel_sem(mutex);
					rel_sem(mutexDescarga);
					rel_sem(fullDescarga);
					rel_sem(emptyDescarga);
					rel_sem(mutexCarga);
					rel_sem(fullCarga);
					rel_sem(emptyCarga);
					shmdt(addr);
					shmctl(shmid, IPC_RMID, 0);
                		};
			break;
		}; /*end switch*/
	}; /*end for*/
}
