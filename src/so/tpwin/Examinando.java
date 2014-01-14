/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rui
 */
public class Examinando extends Thread {

    private int id;
    private Exame teste;
    private Barreira barreira;

    public Examinando(int id,Barreira barreira) {
        this.id = id;
        teste = new Exame();
        this.barreira=barreira;
    }

    public void responderAPergunta() throws InterruptedException {
        for (int i = 0; i < teste.getNmrPerguntas(); i++) {
            System.out.println(teste.getPergunta(i));
            char resposta=responder(teste.getPergunta(i).getNmrRespostas());
            System.out.println("O aluno "+id+" respondeu "+resposta);
            teste.responder(resposta,i);
        }
    }

    public boolean avaliar() {
        return teste.passou();
    }

    public char responder(int i) throws InterruptedException {
        Random r = new Random();
        Thread.sleep(r.nextInt(8) * 1000 + 2000);

        switch (r.nextInt(i)) {
            case 0:
                return 'A';
            case 1:
                return 'B';
            case 2:
                return 'C';
            case 3:
                return 'D';
            default:
                return 'H';
        }
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                responderAPergunta();
                
            } catch (InterruptedException ex) {
                Logger.getLogger(Examinando.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
