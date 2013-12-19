Produto produto;

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
int calcularDistancia(int origem,int destino){
  if(origem==destino){
    return 0;
  }
  
  return
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
  produto=NULL;
}
