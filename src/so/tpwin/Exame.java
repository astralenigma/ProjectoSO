/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.ArrayList;

/**
 *
 * @author Rui
 */
public class Exame {

    private ArrayList<Pergunta> perguntas = new ArrayList<>();
    private int respostasCertas;

    public Exame() {
        for (int i = 0; i < 10; i++) {
            perguntas.add(i, new Pergunta());
        }
        respostasCertas=0;
    }

    public int getNmrPerguntas(){
        return perguntas.size();
    }
    
    public Pergunta getPergunta(int i) {
        return perguntas.get(i);
    }

    public boolean passou() {
        return respostasCertas > 7;
    }
    public void responder(int resposta,int i){
        if (resposta==perguntas.get(i).getRespostaCerta()) {
            respostasCertas++;
        }
    }
}
