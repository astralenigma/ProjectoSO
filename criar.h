#include "cvs.h"

Navio criarNavio(int maxcontentores){
	srand(time(NULL));
	int random=(MAX_SCARGO*0.8+(rand()%(int)(MAX_SCARGO*0.2)+1));
	Navio navio ={(init_sem(random)), (init_sem(MAX_SCARGO-random))};
	return navio;
}
