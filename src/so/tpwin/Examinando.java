/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package so.tpwin;

import java.util.ArrayList;
import java.util.Calendar;
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
    private ArrayList<Pergunta> perguntasErradas;

    public Examinando(int id, Barreira barreira) {
        this.id = id;
        teste = new Exame();
        this.barreira = barreira;
        perguntasErradas = new ArrayList<>();
    }

    public void responderAPergunta() throws InterruptedException {
        Calendar tempoInicial = Calendar.getInstance();
        int i;
        for (i = 0; i < teste.getNmrPerguntas(); i++) {
            if ((Calendar.getInstance().getTimeInMillis() - tempoInicial.getTimeInMillis()) >= 60000) {
                while (i < teste.getNmrPerguntas()) {
                    perguntasErradas.add(teste.getPergunta(i++));
                }
                break;
            }
            System.out.println("Aluno " + id + " a pensar.");
            char resposta = responder(teste.getPergunta(i).getNmrRespostas());
            System.out.println(teste.getPergunta(i));
            System.out.println("O aluno " + id + " respondeu " + resposta);
            if (teste.responder(resposta, i)) {
                perguntasErradas.add(teste.getPergunta(i));
            }
        }
    }

    public String avaliar() {
        if (teste.passou()) {
            return "Aprovado";
        }
        return "Reprovado";
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

    public void avaliacao() {
        String str = "Avaliacao do aluno " + id + "\nAcertou em " + (teste.getNmrPerguntas() - perguntasErradas.size());
        while (!perguntasErradas.isEmpty()) {
            Pergunta p = perguntasErradas.remove(0);
            str += "\n" + p.avaliarResposta()+"\n";
        }
        System.out.println(str + "\n" + avaliar());
    }

    @Override
    public void run() {
        try {
            barreira.esperar();
            responderAPergunta();
            barreira.esperar();
            avaliacao();

        } catch (InterruptedException ex) {
            Logger.getLogger(Examinando.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
