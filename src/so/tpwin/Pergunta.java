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
    private int nmrPerguntas;
    private int respostaCerta;

    public Pergunta(String pergunta, int nmrPerguntas, int respostaCerta) {
        this.pergunta = pergunta;
        this.nmrPerguntas = nmrPerguntas;
        this.respostaCerta = respostaCerta;
    }

    

    public int getNmrRespostas() {
        return 3;
    }

    public int getRespostaCerta() {
        return respostaCerta;
    }
}
