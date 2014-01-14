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
    private int examinandosQueAcabaramOExame;

    public Barreira(int examinandosNoExame) {
        this.examinandosNoExame = examinandosNoExame;
        this.examinandosQueAcabaramOExame = 0;
    }
    
    public synchronized void acabouOExame(){
        examinandosQueAcabaramOExame++;
        if(examinandosNoExame!=examinandosQueAcabaramOExame){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Barreira.class.getName()).log(Level.SEVERE, null, ex);
            }
        }else{
            notifyAll();
            examinandosQueAcabaramOExame=0;
        }
    }
}
