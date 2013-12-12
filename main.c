#include "sema.h"
#include "transferencia.h"



int main(void){
	int shmid;// id da memoria partilhada
	char *addr;
	int valorPid[MAX_CAMIOES], aguardaPid, aguardacliente, 		estadoCliente, child_stat;
	int n, numeroCaxa, numeroP;
	mutex = init_sem(1);		/* exclusao mutua */
	shmid = shmget(SHMKEY, MAX_CAMIOES, 0777|IPC_CREAT);
	addr = (char*) shmat(shmid, 0, 0);
	
	return 0;
}
