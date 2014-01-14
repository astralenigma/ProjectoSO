
import java.util.ArrayList;
import so.tpwin.Pergunta;

public class ListaPerguntas {

    private ArrayList<Pergunta> perguntas;
    private char respostaCerta;

    public ListaPerguntas() {
        perguntas = new ArrayList<>();
        perguntas.add(new Pergunta("Nos motociclos, a travagem com recurso aos dois travões, em alternativa à travagem só com o travão da frente, pressupõe:\n"
                + "Opções:\n"
                + "		 A-Maior esforço da suspensão dianteira e maior desgaste do pneu da frente.\n"
                + "		 B-Menor esforço da suspensão dianteira e menor desgaste do pneu da frente.\n"
                + "		 C-Menor esforço da suspensão traseira e menor desgaste do pneu da retaguarda.", 'B'));
        perguntas.add(new Pergunta("Circulando à retaguarda de um automóvel pesado, que posição devo ocupar na via?\n"
                + "Opções:\n"
                + "		 A-A mais afastada possível do automóvel para evitar a deslocação de ar que ele provoca.\n"
                + "		 B-A mais próxima possível do automóvel para realizar a sua ultrapassagem rápida e em segurança.\n"
                + "		 C-Aquela que me permita percepcionar a via para além do automóvel.", 'C'));
        perguntas.add(new Pergunta("O bom estado de funcionamento dos amortecedores poderá contribuir:\n"
                + "Opções:\n"
                + "		 A-Para a redução da distância de paragem aumentando a de travagem.\n"
                + "		 B-Para o aumento da distância de paragem.\n"
                + "		 C-Para uma menor distância de travagem.", 'C'));
        perguntas.add(new Pergunta("Um motociclista em andamento não pode:\n"
                + "Opções:\n"
                + "		 A-Tirar os pés dos pisa-pés.\n"
                + "		 B-Tirar uma das mãos do guiador.\n"
                + "		 C-Ultrapassar pela esquerda.", 'A'));

        perguntas.add(new Pergunta("Na condução de motociclos em curva, e dependendo da velocidade e do ângulo de cada curva, a acção da força centrífuga tende a projectar o veículo:\n"
                + "Opções:\n"
                + "		 A-Para a frente, aumentando a velocidade de circulação.\n"
                + "		 B-Para o exterior da curva.\n"
                + "		 C-Para o interior da curva.", 'B'));
        perguntas.add(new Pergunta("O condutor deve verificar, periodicamente, no seu motociclo:\n"
                + "Opções:\n"
                + "		 A-A folga da correia da ventoinha.\n"
                + "		 B-A funcionalidade de todas as luzes.\n"
                + "		 C-O aperto do eixo da roda da frente.", 'B'));
        perguntas.add(new Pergunta("A presença de um conta-rotações num motociclo é importante?\n"
                + "Opções:\n"
                + "		 A-Não, serve somente para encarecer o produto final.\n"
                + "		 B-Sim, pois é um elemento estético que empresta ao motociclo um aspecto desportivo e moderno.\n"
                + "		 C-Sim, pois permite ao condutor verificar se as rotações máximas aconselhadas não são ultrapassadas.", 'C'));
        perguntas.add(new Pergunta("Apenas os condutores de motociclos com potência igual ou superior a 35 Kw devem utilizar botas de protecção. Concorda com esta afirmação?\n"
                + "Opções:\n"
                + "		 A-Não, todos os condutores devem utilizar botas de protecção.\n"
                + "		 B-Sim, porque circulam a maior velocidade.\n"
                + "		 C-Sim, porque são veículos de maior cilindrada.", 'A'));

        perguntas.add(new Pergunta("Nesta situação, devo:\n"
                + "Opções:\n"
                + "		 A-Adequar a velocidade ao limite máximo dentro de uma localidade, tendo especial atenção à circulação de peões.\n"
                + "		 B-Reduzir a velocidade até 50 km/h, prosseguindo sem qualquer outro cuidado especial.\n"
                + "		 C-Utilizar as luzes de estrada e os sinais sonoros, sempre que seja necessário assinalar a minha presença.", 'A'));;
        perguntas.add(new Pergunta("Na condução de motociclos, a presença de gasóleo derramado na via, pode:\n"
                + "Opções:\n"
                + "		 A-Dificultar a travagem, aumentando a distância de paragem.\n"
                + "		 B-Dificultar a travagem, aumentando a distância de segurança.\n"
                + "		 C-Dificultar a travagem, diminuindo a distância de paragem.", 'A'));
        perguntas.add(new Pergunta("Nesta situação, devo circular na pista obrigatória?\n"
                + "Opções:\n"
                + "		A-Não, a pista é reservada aos velocípedes.\n"
                + "		B-Não, excepto se quiser mudar de direcção.\n"
                + "		C-Sim, pois conduzo um veículo de duas rodas.", 'A'));
        perguntas.add(new Pergunta("A pintura de um motociclo pode mais facilmente ganhar ferrugem, se for utilizado essencialmente em zonas não urbanas?\n"
                + "Opções:\n"
                + "		A-Não, excepto se a zona não urbana for junto ao mar.\n"
                + "		B-Sim, pois existe menos poluição.\n"
                + "		C-Sim, porque circula com velocidades maiores.", 'A'));
        perguntas.add(new Pergunta("Conduzir de modo a ver e a ser visto e com capacidade de previsão e antecipação dos perigos que podem surgir na via:\n"
                + "Opções:		\n"
                + "		A-São regras a seguir, unicamente, pelos condutores de ciclomotores e motociclos dada a fragilidade destes veículos.\n"
                + "		B-São regras que fazem parte da condução defensiva.\n"
                + "		C-São regras que os condutores se encontram, unicamente, obrigados a observar quando o tempo está chuvoso ou com grande intensidade de trânsito.", 'B'));
        perguntas.add(new Pergunta("Para uma eficaz recolha de informação, o condutor de um motociclo deve ter particular atenção com o bom estado:\n"
                + "Opções:\n"
                + "		A-De conservação e limpeza dos espelhos retrovisores.\n"
                + "		B-Do sistema de travagem dos motociclos.\n"
                + "		C-Dos sistemas de sinalização luminosa existentes nos veículos.", 'A'));
        perguntas.add(new Pergunta("Nos motociclos, o nível do óleo do motor é normalmente controlado:\n"
                + "Opções:\n"
                + "		A-Apenas através de uma vareta de nível.\n"
                + "		B-Através de um visor ou de uma vareta de nível.\n"
                + "		C-Através de uma lâmpada no painel de instrumentos.", 'B'));;
        perguntas.add(new Pergunta("O indicador de temperatura, que se encontra no painel de instrumentos de um motociclo, indica:\n"
                + "Opções:		\n"
                + "		A-A temperatura ambiente.\n"
                + "		B-A temperatura da caixa de velocidades.\n"
                + "		C-A temperatura do motor.", 'C'));
        perguntas.add(new Pergunta("O condutor de um motociclo deve utilizar botas de protecção?\n"
                + "Opções:		\n"
                + "		A-Não, excepto se conduzir motociclos com três rodas.\n"
                + "		B-Sim, constitui um elemento de segurança passiva.\n"
                + "		C-Sim, mas apenas em situação de competição desportiva.", 'B'));
        perguntas.add(new Pergunta("Os comandos de pé de um motociclo devem ser accionados:\n"
                + "Opções:		\n"
                + "		A-De modo a que só um dos pés se afaste dos apoios.\n"
                + "		B-Sem que os pés se afastem significativamente dos apoios.\n"
                + "		C-Sem que os pés tenham de sair dos apoios.", 'C'));
        perguntas.add(new Pergunta("O condutor de um motociclo, ao transitar durante o dia e com boa visibilidade, é obrigado a circular com algum dispositivo de iluminação aceso?\n"
                + "Opções:		\n"
                + "		A-Não, devendo ligar apenas um dispositivo de sinalização luminosa.\n"
                + "		B-Não, os dispositivos de iluminação apenas devem ser utilizados durante o dia se as condições meteorológicas tornarem a visibilidade suficiente.\n"
                + "		C-Sim, deve transitar com a luz de cruzamento acesa.", 'C'));
        perguntas.add(new Pergunta("Neste entroncamento de visibilidade reduzida devo:\n"
                + "Opções:		\n"
                + "		A-Circular com especial prudência e velocidade moderada.\n"
                + "		B-Circular o mais à esquerda possível.\n"
                + "		C-Ligar as luzes de estrada para ver e ser visto pelos restantes utentes.", 'A'));
    }
}
