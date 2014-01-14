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

    ArrayList<Pergunta> perguntas = new ArrayList<>();

    public Exame() {
        for (int i = 0; i < 10; i++) {
            perguntas.add(i, new Pergunta());
        }
    }

    public boolean passou(int respostasCertas) {
        return respostasCertas > 7;
    }
}
