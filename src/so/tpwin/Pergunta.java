/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.StringTokenizer;

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
    
    public String avaliarResposta(){
        StringTokenizer st=new StringTokenizer(pergunta, "\n");
        String avaliacao=st.nextToken();
        switch(respostaCerta){
            case 'C':st.nextToken();
            case 'B':st.nextToken();
            case 'A':return "A resposta à pergunta "+avaliacao+" era:\n"+st.nextToken();
            default:return "";
        }
    }

    @Override
    public String toString() {
        return pergunta;
    }
}
