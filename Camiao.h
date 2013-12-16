Produto gerarInventario(){
  srand(time(NULL));
  Produto produto={ rand()%3,rand()%365, rand()%10};
  return produto;
}

void carregarCamiao(){
  carregarContentorCamiao();
  
}

void descarregarCamiao(){
  descarregarContentorCamiao();
}

void mover(){};
