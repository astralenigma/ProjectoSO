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
public class Pergunta {

    private char respostaCerta;

    Pergunta() {
        Random rd = new Random();
        switch ((rd.nextInt(4) + 1)) {
            case 1:
                respostaCerta = 'A';
                break;
            case 2:
                respostaCerta = 'B';
                break;
            case 3:
                respostaCerta = 'C';
                break;
            case 4:
                respostaCerta = 'D';
                break;
        }

    }
}
