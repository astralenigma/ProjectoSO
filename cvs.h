#define MAX_CAMIOES	10       /* max. # of child processes	*/
#define LIFETIME	1440	/* max. lifetime of a process	*/
#define SLOADINGTIME	7	/* max. time for loading cargo to the ship	*/
#define SUNLOADINGTIME 	5	/* max. time for unloading cargo from the ship	*/
#define MAX_SCARGO	50	/* max. cargo of the ship	*/
#define MAX_UZCARGO	30	/* max. cargo of the unloading zone	*/
#define MAX_LZCARGO	20	/* max. cargo of the loading zone	*/
#define TUNLOADINGTIME	4	/* max. time for unloading cargo from the trucks	*/
#define TLOADINGTIME	5	/* max. time for unloading cargo from the trucks	*/
#define MAX_CHILD MAX_CAMIOES + 2
#define SHMKEY (key_t)0x10
int child_pid[MAX_CHILD],wait_pid;
int i,j;
double velocidade=6/5;

typedef enum {
frescos=0,alimentar=1,npereciveis=2
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


semaphore mutexDescarga;
semaphore fullDescarga;
semaphore emptyDescarga;

semaphore mutexCarga;
semaphore fullCarga;
semaphore emptyCarga;
 
semaphore semaNaviosAEspera;
semaphore mutex;

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
