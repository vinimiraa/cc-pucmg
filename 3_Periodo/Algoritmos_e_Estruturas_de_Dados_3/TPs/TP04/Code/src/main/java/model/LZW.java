package model;

/**
 *  A classe {@code LZW} codifica e decodifica uma string usando uma sequência
 *  de índices. Esses índices são armazenados na forma de uma sequência de bits,
 *  com o apoio da classe VetorDeBits.
 * 
 *  A codificação não é exatamente de caracteres (Unicode), mas dos bytes que
 *  representam esses caracteres.
 *  
 *  @author Marcos Kutova
 *  PUC Minas
 */
import java.util.ArrayList;

public class LZW {

    public static final int BITS_POR_INDICE = 12; // Mínimo de 9 bits por índice (512 itens no dicionário)

    // public static void main(String[] args) {

    //     try {

    //         // Codificação
    //         String msg = "O sabiá não sabia que o sábio sabia que o sabiá não sabia assobiar.";
    //         byte[] msgBytes = msg.getBytes();
    //         byte[] msgCodificada = codifica(msgBytes); // Vetor de bits que contém os índices

    //         // Cria uma cópia dos índices, como se fosse uma leitura em um arquivo
    //         // Assim, para armazenar o vetor em um arquivo, basta armazenar o vetor de bytes
    //         byte[] copiaMsgCodificada = (byte[]) msgCodificada.clone();

    //         // Decodificação - Cria uma nova string
    //         byte[] msgBytes2 = decodifica(copiaMsgCodificada);
    //         String msg2 = new String(msgBytes2);

    //         // Relatório
    //         int i;

    //         System.out.println("\nMensagem já decodificada: ");
    //         System.out.println(msg2);

    //         System.out.println("\nBytes originais (" + msgBytes.length + "): ");
    //         for (i = 0; i < msgBytes.length; i++) {
    //             System.out.print(msgBytes[i] + " ");
    //         }
    //         System.out.println();

    //         System.out.println("\nBytes compactados (" + msgCodificada.length + "): ");
    //         for (i = 0; i < msgCodificada.length; i++)
    //             System.out.print(msgCodificada[i] + " ");
    //         System.out.println();

    //         System.out.println(
    //                 "Eficiência: " + (100 * (1 - (float) msgCodificada.length / (float) msgBytes.length)) + "%");

    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }

    // }

    // CODIFICAÇÃO POR LZW
    // Usa a mensagem na forma de um vetor de bytes, para
    // eliminar a variação da quantidade de bytes por caráter do UTF-8
    // Os valores de bytes variarão entre -128 e 127, considerando que,
    // em Java, não existe o tipo Unsigned Byte
    public static byte[] codifica(byte[] msgBytes) throws Exception {

        // Cria o dicionário e o preenche com os 256 primeiros valores de bytes
        // O dicionário será um vetor (ArrayList) de vetores de bytes.
        ArrayList<ArrayList<Byte>> dicionario = new ArrayList<>();
        ArrayList<Byte> vetorBytes; // elemento (vetor de bytes) para inclusão no dicionário
        int i, j;
        byte b;
        for (j = -128; j < 128; j++) { // Usamos uma variável int para o laço, pois, em uma variável byte,
                                       // 127 + 1 == -128
            b = (byte) j;
            vetorBytes = new ArrayList<>(); // Cada byte será encaixado no dicionário como um vetor de um único elemento
            vetorBytes.add(b); // Não é necessária a conversão explícita de byte para Byte
            dicionario.add(vetorBytes);
        }

        // Vetor de inteiros para resposta
        ArrayList<Integer> saida = new ArrayList<>();

        // FASE DE CODIFICAÇÃO

        i = 0;
        int indice; // Índice: posição do vetor de bytes no dicionário
        int ultimoIndice; // Indica o último índice encontrado no dicionário
        while (i < msgBytes.length) {

            // Cria um novo vetor de bytes para acumular os bytes
            // Quanto maior for a sequência encontrada no dicionário, melhor será a
            // compressão
            vetorBytes = new ArrayList<>();

            // Adiciona o próximo byte da mensagem ao vetor de bytes, para busca no
            // dicionário
            // Obviamente, é esperado que esse vetor de um único byte já exista no
            // dicionário,
            // já que, algumas linhas acima, criamos o dicionário com todos os bytes
            // individuais possíveis.
            b = msgBytes[i];
            vetorBytes.add(b);
            indice = dicionario.indexOf(vetorBytes);
            ultimoIndice = indice;

            // Tenta acrescentar mais bytes ao vetor de bytes
            while (indice != -1 && i < msgBytes.length - 1) {

                i++;
                b = msgBytes[i];
                vetorBytes.add(b);
                indice = dicionario.indexOf(vetorBytes); // Faz nova busca

                if (indice != -1)
                    ultimoIndice = indice;
            }

            // Acrescenta o último indice encontrado ao vetor de índices a ser retornado
            saida.add(ultimoIndice);

            // Acrescenta o novo vetor de bytes, com o último caráter que provocou a
            // falha na busca, ao dicionário (se couber)
            if (dicionario.size() < (Math.pow(2, BITS_POR_INDICE) - 1))
                dicionario.add(vetorBytes);

            // Testa se os bytes acabaram sem provocar a codificação anterior
            if (indice != -1 && i == msgBytes.length - 1)
                break;
        }

        // Transforma o vetor de índices como uma sequência de bits
        // Para facilitar a operação, escrevi o vetor do fim para o início
        VetorDeBits bits = new VetorDeBits(saida.size() * BITS_POR_INDICE);
        int l = saida.size() * BITS_POR_INDICE - 1;
        for (i = saida.size() - 1; i >= 0; i--) {
            int n = saida.get(i);
            for (int m = 0; m < BITS_POR_INDICE; m++) { // apenas um contador de bits
                if (n % 2 == 0)
                    bits.clear(l);
                else
                    bits.set(l);
                l--;
                n /= 2;
            }
        }

        // Imprime os índices
        // System.out.println("Índices: ");
        // System.out.println(saida);
        // System.out.println("Vetor de bits: ");
        // System.out.println(bits);

        // Retorna o vetor de bits
        return bits.toByteArray();
    }

    // DECODIFICAÇÃO POR LZW
    public static byte[] decodifica(byte[] msgCodificada) throws Exception {

        // Cria o vetor de bits a partir do vetor de bytes
        VetorDeBits bits = new VetorDeBits(msgCodificada);

        // Transforma a sequência de bits em um vetor de índices inteiros
        int i, j, k;
        ArrayList<Integer> indices = new ArrayList<>();
        k = 0;
        for (i = 0; i < bits.length() / BITS_POR_INDICE; i++) {
            int n = 0;
            for (j = 0; j < BITS_POR_INDICE; j++) {
                n = n * 2 + (bits.get(k++) ? 1 : 0);
            }
            indices.add(n);
        }
        // Cria o vetor de bytes para decodificação de cada índice
        ArrayList<Byte> vetorBytes;

        // Cria um vetor de bytes que representa a mensagem original
        ArrayList<Byte> msgBytes = new ArrayList<>();

        // Cria um novo dicionário, inicializado com os primeiros 256 bytes
        ArrayList<ArrayList<Byte>> dicionario = new ArrayList<>();
        byte b;
        for (j = -128, i = 0; j < 128; j++, i++) { // Usamos uma variável int para o laço, pois, em uma variável byte,
                                                   // 127 + 1 == -128
            b = (byte) j;
            vetorBytes = new ArrayList<>(); // Cada byte será encaixado no dicionário como um vetor de um único elemento
            vetorBytes.add(b); // Não é necessária a conversão explícita de byte para Byte
            dicionario.add(vetorBytes);
        }

        // FASE DA DECODIFICAÇÃO

        // Cria um novo vetor de bytes, para que se possa extrair o seu primeiro byte
        // A última sequência decodificada deve ser acrescida desse byte e reinserida no
        // dicionário
        ArrayList<Byte> proximoVetorBytes;

        // Decodifica todos os índices
        i = 0;
        while (i < indices.size()) {

            // Decoficia o índice. É importanter observar que o vetor de bytes obtido no
            // dicionário
            // deve ser clonado, para que se evite que a mudança nesse vetor seja também
            // executada
            // no vetor armazenado no dicionário.
            vetorBytes = (ArrayList<Byte>) (dicionario.get(indices.get(i))).clone();

            // Acrescenta cada byte do vetor retornado à sequência de bytes da mensagem
            // original
            for (j = 0; j < vetorBytes.size(); j++)
                msgBytes.add(vetorBytes.get(j));

            // Adiciona o clone do vetor de bytes ao dicionário, se couber
            // Ainda falta acrescentar o primeiro byte da sequência do próximo índice
            if (dicionario.size() < (Math.pow(2, BITS_POR_INDICE) - 1))
                dicionario.add(vetorBytes);

            // Recupera a sequência de bytes do próximo índice (se houver) e
            // acrescenta o seu primeiro byte à sequência do último índice decodificado
            // (como a variável vetorBytes é uma variável de referência e ainda aponta
            // para essa entrada, a atualização pode ser feita diretamente nela)
            i++;
            if (i < indices.size()) {
                proximoVetorBytes = (ArrayList<Byte>) dicionario.get(indices.get(i));
                vetorBytes.add(proximoVetorBytes.get(0));
            }
        }

        // GERA A STRING A PARTIR DO VETOR DE BYTES

        // Cria um vetor de Byte, a partir do ArrayList
        byte[] msgVetorBytes = new byte[msgBytes.size()];
        for (i = 0; i < msgBytes.size(); i++)
            msgVetorBytes[i] = msgBytes.get(i);

        return msgVetorBytes;
    }

}
