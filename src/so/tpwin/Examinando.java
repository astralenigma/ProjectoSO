/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.Random;

/**
 *
 * @author Rui
 */
public class Examinando extends Thread {

    private int id;

    public Examinando(int id) {
        this.id = id;
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
}
