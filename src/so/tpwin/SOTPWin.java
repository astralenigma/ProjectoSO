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
        System.out.println("Bem vindo ao centro de exames.");
         new Examinando(1).start();
         new Examinando(2).start();
    }
}
