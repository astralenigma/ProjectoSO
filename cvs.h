#define LIFETIME	1440	/* max. lifetime of a process	*/
#define SLOADINGTIME	7	/* max. time for loading cargo to the ship	*/
#define SUNLOADINGTIME 	5	/* max. time for unloading cargo from the ship	*/
#define TUNLOADINGTIME	4	/* max. time for unloading cargo from the trucks	*/
#define TLOADINGTIME	5	/* max. time for unloading cargo from the trucks	*/
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define SHMKEY (key_t)0x10

//-------Variáveis alteradas pelo utilizador
int maxCamioes;       /* max. # of truck processes        */
int maxChilds;        /* max. # of child processes        */
int maxSCargo;        /* max. cargo of the ship        */
int maxUZCargo;        /* max. cargo of the unloading zone        */
int maxLZCargo;        /* max. cargo of the loading zone        */

//---------Processos e memória
int wait_pid;
int shmid;// id da memoria partilhada
char *addr;
int /*valorPid[MAX_CAMIOES], aguardaPid, estadoCliente,*/ child_stat;
int *ptr;

//---------Variáveis Diversas
int i,j, nmrCamiao;
double velocidade=0.8333333333333333;

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

typedef struct node{
  int id;
  struct node *no1;
  int distanciaNo1;
  struct node *no2;
  int distanciaNo2;
  struct node *no3;
  int distanciaNo3;
}No;

//------Semáforos
semaphore fullDescarga;
semaphore emptyDescarga;
semaphore fullCarga;
semaphore emptyCarga;
 
semaphore semaNaviosAEspera;

//------Memória partilhada
Navio ship;

int *apNmrNaviosAEspera;
int nmrNaviosCriados;
int *barcosAtracados;
int *contentoresNaZC;
int *contentoresNaZD;
int *nmrCamioes;
int *esMaxTN;
int *esMinTN;
int *esMedTN;
int *esMaxIC;
int *esMinIC;
int *esMedIC;
int *esMaxZDC;
int *esMaxZCC;
int *nmrContentoresZD;
int *nmrContentoresZC;
