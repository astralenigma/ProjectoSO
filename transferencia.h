#include "criar.h"

//Inserir métodos para transferir os contentores
void descarregarContentorDoNavio() {
    alarm(30);

    for (;;) {
        sleep(5);
        //Verificar os semáforos
        P(emptyA);
        P(mutexDescarga);
        //estes apontadores não estão correctos
	      n = *(p + out);
        *(zonaCarga + inA) = n.contentoresCheios;
        //Verificar os semáforos
        V(mutexDescarga);
        V(fullA);
    }
}

