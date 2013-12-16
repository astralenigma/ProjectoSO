Produto gerarInventario(){
  srand(time(NULL));
  return { rand()%3,rand()%365, rand()%10};
}

void carregarCamiao(){
  carregarContentorCamiao();
  
}

void descarregarCamiao(){
  descarregarContentorCamiao();
}

void mover(){};
