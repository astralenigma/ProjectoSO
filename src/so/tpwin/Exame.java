/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author Rui
 */
public class Exame {

    private ArrayList<Pergunta> perguntas = new ArrayList<>();
    private int respostasCertas;
    private int respostasRespondidas;

    public Exame() {
        Random rd = new Random();
        ArrayList<Integer> al = new ArrayList<>();
//        );
        al.add(rd.nextInt(ListaPerguntas.getNmrPerguntas()));
        for (int i = 0; i < 9; i++) {
            int j;
            do {
                j = rd.nextInt(ListaPerguntas.getNmrPerguntas());
            } while (al.contains(j));
            al.add(j);
        }
        while (!al.isEmpty()) {
            perguntas.add(ListaPerguntas.getPergunta(al.remove(0)));
        }
        respostasCertas = 0;
        respostasRespondidas = 0;
    }

    public int getNmrPerguntas() {
        return perguntas.size();
    }

    public Pergunta getPergunta(int i) {
        return perguntas.get(i);
    }

    public boolean passou() {
        return respostasCertas > 7;
    }

    public int getRespostasRespondidas() {
        return respostasRespondidas;
    }

    public int getRespostasCertas() {
        return respostasCertas;
    }

    
    public boolean responder(int resposta, int i) {
        respostasRespondidas++;
        if (resposta == perguntas.get(i).getRespostaCerta()) {
            respostasCertas++;
            return false;
        }
        return true;
    }
}
