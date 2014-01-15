/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

/**
 *
 * @author Rui
 */
public class SOTPWin {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ListaPerguntas listaPerguntas = new ListaPerguntas();
        int nmrExaminandos=5;
        
        System.out.println("Bem vindo ao centro de exames.");
        Barreira b=new Barreira(nmrExaminandos);
        for (int i = 0; i < nmrExaminandos; i++) {
            new Examinando(i+1,b).start();
        }
    }
}
