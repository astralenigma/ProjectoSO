Produto produto;

Produto gerarInventario(){
  srand(time(NULL));
  int randomL=(rand()%10)+1;
  switch(randomL){
    case 1: 
    case 3: 
    case 5: 
    case 7: 
    case 8: 
    case 9: if((rand()%2)==0){
              return (struct { TipoDeProduto frescos, 1, randomL});
            }else{
              return (struct { TipoDeProduto alimentar,(rand()%365), randomL});
            }
    case 2: 
    case 4:
    case 6:
    case 10: return (struct { TipoDeProduto npereciveis,0, randomL});
  }
  
}

void carregarCamiao(){
  carregarContentorCamiao();
  gerarInventario();
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
