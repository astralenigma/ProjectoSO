
Produto produto;
int percursos[10][2]={
    { 6,15},
    {13,27},
    {17,31},
    {18,29},
    {23,24},
    {23,19},
    {23, 7},
    {18,14},
    {11,15},
    {15,11}
  };
char *produtosTipo[]={
  "Frescos",
  "Com validade",
  "Não Perecíveis"
};
int posicao;
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

void carregarCamiao(){
  carregarContentorCamiao();
  printf("O camião nº %d foi carregado com o contentor.\n", nmrCamiao);
  produto=gerarInventario();
  printf("O camião nº %d tem um produto %s para a loja %d\n", nmrCamiao,produtosTipo[produto.tp],produto.destino);
  printf("O camião nº %d partiu.\n", nmrCamiao);
}

void descarregarCamiao(){
  printf("O camião  nº %d chegou.\n",nmrCamiao);
  descarregarContentorCamiao();
}

void mover(int destino){
    printf("O condutor do camião nº %d está a planear a rota\n",nmrCamiao);
    //printf("O tempo a pecorrer é %d.\n", ((int)(destino/velocidade)));
    printf("O camião nº %d está a andar.\n",nmrCamiao);
    sleep(((int)(destino/velocidade)));
    printf("O camião  nº %d chegou ao destino.\n",nmrCamiao);
}

void controloCamiao(){
  for(;;){
    carregarCamiao();
    mover(percursos[(produto.destino-1)][0]);
    mover(percursos[(produto.destino-1)][1]);
    descarregarCamiao();
  }
}

void entregarProduto(){
  printf("O camião  nº %d entregou o produto na loja %d",nmrCamiao,produto.destino);
  //somar variàvel na memória relacionado aos produtos entregados.
}
