Produto produto;
int percursos[11][11]={//origem,destino
    //P,L1,L2,L3,L4,L5,L6,L7,L8,L9,L10
    {0,6,13,17,18,23,23,23,18,11,15},//Porto
    {20,0,7,11,12,17,17,17,12,5,9},//L1
    {27,7,0,4,5,10,15,24,19,12,16},//L2
    {31,11,4,0,9,14,19,28,23,16,20},//L3
    {29,12,5,9,0,5,10,26,15,17,18},//L4
    {24,17,10,14,5,0,5,21,10,17,13},//L5
    {19,17,15,19,10,5,0,16,5,12,8},//L6
    {7,17,24,28,26,21,16,0,11,12,8},//L7
    {14,12,19,23,15,10,5,11,0,7,3},//L8
    {15,5,12,16,17,17,12,12,7,0,4},//L9
    {11,9,16,20,18,13,8,8,3,4,0}//L10
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
  printf(ANSI_COLOR_BLUE "O camião nº %d foi carregado com o contentor.\n"ANSI_COLOR_RESET, nmrCamiao);
  produto=gerarInventario();
  printf(ANSI_COLOR_BLUE "O camião nº %d tem um produto %s para a loja %d\n"ANSI_COLOR_RESET, nmrCamiao,produtosTipo[produto.tp],produto.destino);
  printf(ANSI_COLOR_BLUE "O camião nº %d partiu.\n"ANSI_COLOR_RESET, nmrCamiao);
}

void descarregarCamiao(){
  printf(ANSI_COLOR_BLUE "O camião  nº %d chegou.\n"ANSI_COLOR_RESET,nmrCamiao);
  descarregarContentorCamiao();
}

void mover(int destino){
    printf(ANSI_COLOR_BLUE "O condutor do camião nº %d está a planear a rota\n"ANSI_COLOR_RESET,nmrCamiao);
    //printf("O tempo a pecorrer é %d.\n", ((int)(destino/velocidade)));
    printf(ANSI_COLOR_BLUE "O camião nº %d está a andar.\n"ANSI_COLOR_RESET,nmrCamiao);
    sleep(((int)(destino/velocidade)));
    printf(ANSI_COLOR_BLUE "O camião  nº %d chegou ao destino.\n"ANSI_COLOR_RESET,nmrCamiao);
}

void controloCamiao(){
  for(;;){
    carregarCamiao();
    mover(percursos[0][(produto.destino)]);
    mover(percursos[(produto.destino)][0]);
    descarregarCamiao();
  }
}

void entregarProduto(){
  printf(ANSI_COLOR_BLUE"O camião  nº %d entregou o produto na loja %d"ANSI_COLOR_RESET,nmrCamiao,produto.destino);
  //somar variàvel na memória relacionado aos produtos entregados.
}
