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
    private char respostaCerta;

    public Pergunta(String pergunta, char respostaCerta) {
        this.pergunta = pergunta;
        this.respostaCerta = respostaCerta;
    }

    public int getNmrRespostas() {
        return 3;
    }

    public char getRespostaCerta() {
        return respostaCerta;
    }

    @Override
    public String toString() {
        return pergunta;
    }
}
