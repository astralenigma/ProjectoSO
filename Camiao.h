Produto produto;

Produto gerarInventario(){
  srand(time(NULL));
  switch(rand()%3){
    case 0: return struct { frescos, 1, rand()%10};
    case 1: return struct { alimentar,rand()%365, rand()%10};
    case 2: return struct { npereciveis,0, rand()%10};
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
