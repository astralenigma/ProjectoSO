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
  int contetoresVazios;
}Navio;

semaphore mutex;
Navio *ship;
int nmrNaviosAEspera=0;
