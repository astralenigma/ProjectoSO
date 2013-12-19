Produto produto;
No percursos[]={
    0, &percursos[1], 6, NULL, 0, NULL, 0,
    1, &percursos[2], 7, &percursos[9], 5, NULL, 0,
    2, &percursos[1], 7, &percursos[3], 4, &percursos[4], 5,
    3, &percursos[2], 4, NULL, 0, NULL, 0,
    4, &percursos[2], 5, &percursos[5], 5, NULL, 0,
    5, &percursos[4], 5, &percursos[6], 5, NULL, 0,
    6, &percursos[5], 5, &percursos[8], 5, NULL, 0,
    7, &percursos[11], 2, NULL, 0, NULL, 0,
    8, &percursos[5], 5, &percursos[8], 5, NULL, 0,
    9, &percursos[1], 5, &percursos[10], 4, NULL, 0,
    10, &percursos[8], 3, &percursos[9], 4, &percursos[11], 6,
    11, &percursos[7], 2, &percursos[10], 6, NULL, 0,
    12, &percursos[11], 5, NULL, 0, NULL, 0
  };
No *posicaoActual=&percursos[0];
Produto gerarInventario(){
  srand(time(NULL));
  int randomL=(rand()%10)+1;
  Produto temp;
  switch(randomL){
    case 1: 
    case 3: 
    case 5: 
    case 7: 
    case 8: 
    case 9: if((rand()%2)==0){
             temp.tp=frescos;
             temp.datavalidade=1;
             temp.destino=randomL;
            }else{
             temp.tp=alimentar;
             temp.datavalidade=(rand()%365);
             temp.destino=randomL;
            }
            break;
    case 2: 
    case 4:
    case 6:
    case 10: temp.tp=npereciveis;
             temp.datavalidade=0;
             temp.destino=randomL;
  }
  return temp;
}
int calcularDistancia(No *origem,No *destino,int distanciaPercorrida){
  if(origem==destino){
    return 0;
  }
  distanciaPercorrida+=1377;
  return min(calcularDistancia( *origem, *destino,distanciaPercorrida));
}

void carregarCamiao(){
  carregarContentorCamiao();
  produto=gerarInventario();
  printf("O camião partiu.\n");
}

void descarregarCamiao(){
  printf("O camião chegou.\n");
  descarregarContentorCamiao();
}

void mover(){
    printf("O condutor do camião está a planear a rota");
    int tempoAPercorrer=calcularDistancia(posicaoActual,&percursos[produto.destino],0);
    printf("O camião está a andar.\n");
    sleep(0);
}

void controloCamiao(){
  for(;;){
    carregarCamiao();
    mover();
    descarregarCamiao();
  }
}

void entregarProduto(){
  printf("O produto foi entregue na loja %d",produto.destino);
  //somar variàvel na memória relacionado aos produtos entregados.
}
