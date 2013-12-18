#define LIFETIME	1440	/* max. lifetime of a process	*/
#define SLOADINGTIME	7	/* max. time for loading cargo to the ship	*/
#define SUNLOADINGTIME 	5	/* max. time for unloading cargo from the ship	*/
#define TUNLOADINGTIME	4	/* max. time for unloading cargo from the trucks	*/
#define TLOADINGTIME	5	/* max. time for unloading cargo from the trucks	*/
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define SHMKEY (key_t)0x10
//---------Processos e memória
int child_pid[MAX_CHILD],wait_pid;
int shmid;// id da memoria partilhada
	char *addr;
	int /*valorPid[MAX_CAMIOES], aguardaPid, estadoCliente,*/ child_stat;
	int *ptr;
//-------Variáveis alteradas pelo utilizador
int maxCamioes = 10;       /* max. # of truck processes	*/
int maxChilds= maxCamioes + 2;	/* max. # of child processes	*/
int maxSCargo = 50	/* max. cargo of the ship	*/
int max_UZCargo = 30	/* max. cargo of the unloading zone	*/
int max_LZCargo = 20	/* max. cargo of the loading zone	*/
//---------Variáveis Diversas
int i,j;
double velocidade=5/6;

typedef enum {
frescos,alimentar,npereciveis
}TipoDeProduto;

typedef struct {
TipoDeProduto tp;
int datavalidade;
int destino;
}Produto;


typedef struct {
Produto p;
}Contentor;

typedef struct {
  int id;
  int contentoresCheios;
  int contentoresVazios;
}Navio;

//------Semáforos
semaphore mutexDescarga;
semaphore fullDescarga;
semaphore emptyDescarga;

semaphore mutexCarga;
semaphore fullCarga;
semaphore emptyCarga;
 
semaphore semaNaviosAEspera;
semaphore mutex;
//------Memória partilhada
Navio ship;
//semaphore *apMutexDescarga;
//semaphore *apFullDescarga;
//semaphore *apEmptyDescarga;
//semaphore *apMutexCarga;
//semaphore *apMutexCarga;
//semaphore *apMutexCarga;

int *apNmrNaviosAEspera;
int nmrNaviosAEspera=1;
int nmrNaviosCriados;
