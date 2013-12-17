Produto gerarInventario(){
  srand(time(NULL));
  Produto produto={ rand()%3,rand()%365, rand()%10};
  return produto;
}

void carregarCamiao(){
  carregarContentorCamiao();
  printf("O camião partiu.");
}

void descarregarCamiao(){
  printf("O camião chegou.");
  descarregarContentorCamiao();
}

void mover(){
  printf("O camião está a andar.");
}

void controloCamiao(){
  for(;;){
    carregarCamiao();
    mover();
    descarregarCamiao();
  }
}
