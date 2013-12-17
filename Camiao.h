Produto gerarInventario(){
  srand(time(NULL));
  Produto produto={ rand()%3,rand()%365, rand()%10};
  return produto;
}

void carregarCamiao(){
  carregarContentorCamiao();
  printf("O camião partiu.\n");
}

void descarregarCamiao(){
  printf("O camião chegou.\n");
  descarregarContentorCamiao();
}

void mover(){
  printf("O camião está a andar.\n");
}

void controloCamiao(){
  for(;;){
    carregarCamiao();
    mover();
    descarregarCamiao();
  }
}
