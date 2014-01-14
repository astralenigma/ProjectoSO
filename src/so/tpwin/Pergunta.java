/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

/**
 *
 * @author Rui
 */
public class Pergunta {

    private String pergunta;
    private int respostaCerta;

    public Pergunta() {
        this.pergunta = "othersomething";
        this.respostaCerta = 0;
    }

    public int getNmrRespostas() {
        return 3;
    }

    public int getRespostaCerta() {
        return respostaCerta;
    }
}
