#define MAX_CAMIOES	10       /* max. # of child processes	*/
#define LIFETIME	1440	/* max. lifetime of a process	*/
#define SLOADINGTIME	7	/* max. time for loading cargo to the ship	*/
#define SUNLOADINGTIME 	5	/* max. time for unloading cargo from the ship	*/
#define MAX_SCARGO	50	/* max. cargo of the ship	*/
#define MAX_UZCARGO	30	/* max. cargo of the unloading zone	*/
#define MAX_LZCARGO	20	/* max. cargo of the loading zone	*/
#define TUNLOADINGTIME	4	/* max. time for unloading cargo from the trucks	*/
#define TLOADINGTIME	5	/* max. time for unloading cargo from the trucks	*/
#define SHMKEY (key_t)0x10
semaphore mutex;

typedef enum {
frescos='f',alimentar='v',npereciveis='n'
}TipodeProduto;

typedef struct {
tipodeproduto tp;
int datavalidade;
int destino;
}Produto;


typedef struct {
produto p;
}Contentor;

typedef struct {
semaphore full;
semaphore empty;
}Navio;
