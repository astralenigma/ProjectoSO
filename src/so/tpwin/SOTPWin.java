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
        System.out.println("Bem vindo ao centro de exames.");
        Barreira b=new Barreira(2);
         new Examinando(1,b).start();
         new Examinando(2,b).start();
    }
}
