/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rui
 */
public class Barreira {
    private int examinandosNoExame;
    private int examinandosAEspera;

    public Barreira(int examinandosNoExame) {
        this.examinandosNoExame = examinandosNoExame;
        this.examinandosAEspera = 0;
    }
    
    public synchronized void esperar(){
        examinandosAEspera++;
        if(examinandosNoExame!=examinandosAEspera){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Barreira.class.getName()).log(Level.SEVERE, null, ex);
            }
        }else{
            notifyAll();
            examinandosAEspera=0;
        }
    }
}
