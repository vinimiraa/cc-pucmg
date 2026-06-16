/*********
 * ARVORE B+ 
 * 
 * Os nomes dos métodos foram mantidos em inglês
 * apenas para manter a coerência com o resto da
 * disciplina:
 * - boolean create(RegistroArvoreBMais objeto)   
 * - int[] read(RegistroArvoreBMais objeto)
 * - boolean delete(RegistroArvoreBMais objeto)
 * 
 * Implementado pelo Prof. Marcos Kutova
 * v2.0 - 2021
 */
package model;

import java.io.*;
import java.util.ArrayList;
import java.lang.reflect.Constructor;

import interfaces.RegistroArvoreBMais;

// Esta versão da árvore funciona apenas como um conjunto de par de chaves.
// A primeira chave pode repetir na árvore, mas não o par de chaves, 
// isto é, quando a primeira chave de dois elementos for igual, a segunda chave,
// deve ser necessariamente diferente.

public class ArvoreBMais<T extends RegistroArvoreBMais<T>> {

    private int ordem; // Número máximo de filhos que uma página pode conter
    private int maxElementos; // Variável igual a ordem - 1 para facilitar a clareza do código
    private int maxFilhos; // Variável igual a ordem para facilitar a clareza do código
    private RandomAccessFile arquivo; // Arquivo em que a árvore será armazenada
    private String nomeArquivo;
    private Constructor<T> construtor;

    // Variáveis usadas nas funções recursivas (já que não é possível passar valores
    // por referência)
    private T elemAux;
    private long paginaAux;
    private boolean cresceu;
    private boolean diminuiu;

    // Esta classe representa uma página da árvore (folha ou não folha).
    private class Pagina {

        protected int ordem; // Número máximo de filhos que uma página pode ter
        protected Constructor<T> construtor;
        protected int maxElementos; // Variável igual a ordem - 1 para facilitar a clareza do código
        protected int maxFilhos; // Variável igual a ordem para facilitar a clareza do código
        protected int TAMANHO_ELEMENTO; // Os elementos são de tamanho fixo
        protected int TAMANHO_PAGINA; // A página será de tamanho fixo, calculado a partir da ordem

        protected ArrayList<T> elementos; // Elementos da página
        protected ArrayList<Long> filhos; // Vetor de ponteiros para os filhos
        protected long proxima; // Próxima folha, quando a página for uma folha

        // Construtor da página
        public Pagina(Constructor<T> ct, int o) throws Exception {

            // Inicialização dos atributos
            this.construtor = ct;
            this.ordem = o;
            this.maxFilhos = this.ordem;
            this.maxElementos = this.ordem - 1;
            this.elementos = new ArrayList<>(this.maxElementos);
            this.filhos = new ArrayList<>(this.maxFilhos);
            this.proxima = -1;

            // Cálculo do tamanho (fixo) da página
            // cada elemento -> depende do objeto
            // cada ponteiro de filho -> 8 bytes
            // último filho -> 8 bytes
            // ponteiro próximo -> 8 bytes
            this.TAMANHO_ELEMENTO = this.construtor.newInstance().size();
            this.TAMANHO_PAGINA = 4 + this.maxElementos * this.TAMANHO_ELEMENTO + this.maxFilhos * 8 + 8;
        }

        // Retorna o vetor de bytes que representa a página para armazenamento em
        // arquivo
        protected byte[] toByteArray() throws IOException {

            // Um fluxo de bytes é usado para construção do vetor de bytes
            ByteArrayOutputStream ba = new ByteArrayOutputStream();
            DataOutputStream out = new DataOutputStream(ba);

            // Quantidade de elementos presentes na página
            out.writeInt(this.elementos.size());

            // Escreve todos os elementos
            int i = 0;
            while (i < this.elementos.size()) {
                out.writeLong(this.filhos.get(i).longValue());
                out.write(this.elementos.get(i).toByteArray());
                i++;
            }
            if (this.filhos.size() > 0)
                out.writeLong(this.filhos.get(i).longValue());
            else
                out.writeLong(-1L);

            // Completa o restante da página com registros vazios
            byte[] registroVazio = new byte[TAMANHO_ELEMENTO];
            while (i < this.maxElementos) {
                out.write(registroVazio);
                out.writeLong(-1L);
                i++;
            }

            // Escreve o ponteiro para a próxima página
            out.writeLong(this.proxima);

            // Retorna o vetor de bytes que representa a página
            return ba.toByteArray();
        }

        // Reconstrói uma página a partir de um vetor de bytes lido no arquivo
        public void fromByteArray(byte[] buffer) throws Exception {

            // Usa um fluxo de bytes para leitura dos atributos
            ByteArrayInputStream ba = new ByteArrayInputStream(buffer);
            DataInputStream in = new DataInputStream(ba);

            // Lê a quantidade de elementos da página
            int n = in.readInt();

            // Lê todos os elementos (reais ou vazios)
            int i = 0;
            this.elementos = new ArrayList<>(this.maxElementos);
            this.filhos = new ArrayList<>(this.maxFilhos);
            T elem;
            while (i < n) {
                this.filhos.add(in.readLong());
                byte[] registro = new byte[TAMANHO_ELEMENTO];
                in.read(registro);
                elem = this.construtor.newInstance();
                elem.fromByteArray(registro);
                this.elementos.add(elem);
                i++;
            }
            this.filhos.add(in.readLong());
            in.skipBytes((this.maxElementos - i) * (TAMANHO_ELEMENTO + 8));
            this.proxima = in.readLong();
        }
    }

    // ------------------------------------------------------------------------------

    public ArvoreBMais(Constructor<T> c, int o, String na) throws Exception {

        // Inicializa os atributos da árvore
        construtor = c;
        ordem = o;
        maxElementos = o - 1;
        maxFilhos = o;
        nomeArquivo = na;

        // Abre (ou cria) o arquivo, escrevendo uma raiz empty, se necessário.
        arquivo = new RandomAccessFile(nomeArquivo, "rw");
        if (arquivo.length() < 16) {
            arquivo.writeLong(-1); // raiz empty
            arquivo.writeLong(-1); // pointeiro lista excluídos
        }
    }

    // Testa se a árvore está empty. Uma árvore empty é identificada pela raiz == -1
    public boolean empty() throws IOException {
        long raiz;
        arquivo.seek(0);
        raiz = arquivo.readLong();
        return raiz == -1;
    }

    // Busca recursiva por um elemento a partir da chave. Este metodo invoca
    // o método recursivo read1, passando a raiz como referência.
    // O método retorna a lista de elementos que possuem a chave (considerando
    // a possibilidade chaves repetidas)
    public ArrayList<T> read(T elem) throws Exception {
        // Recupera a raiz da árvore
        long raiz;
        arquivo.seek(0);
        raiz = arquivo.readLong();

        // Executa a busca recursiva
        if (raiz != -1)
            return read1(elem, raiz);
        else {
            ArrayList<T> resposta = new ArrayList<>();
            return resposta;
        }
    }

    // Busca recursiva. Este método recebe a referência de uma página e busca
    // pela chave na mesma. A busca continua pelos filhos, se houverem.
    private ArrayList<T> read1(T elem, long pagina) throws Exception {
        // Como a busca é recursiva, a descida para um filho inexistente
        // (filho de uma página folha) retorna um vetor vazio.
        if (pagina == -1) {
            ArrayList<T> resposta = new ArrayList<>();
            return resposta;
        }

        // Reconstrói a página passada como referência a partir
        // do registro lido no arquivo
        arquivo.seek(pagina);
        Pagina pa = new Pagina(construtor, ordem);
        byte[] buffer = new byte[pa.TAMANHO_PAGINA];
        arquivo.read(buffer);
        pa.fromByteArray(buffer);

        // Encontra o ponto em que a chave deve estar na página
        // Nesse primeiro passo, todas as chaves menores que a chave buscada
        // são ultrapassadas
        int i = 0;
        while (elem != null && i < pa.elementos.size() && elem.compareTo(pa.elementos.get(i)) > 0) {
            i++;
        }

        // Chave encontrada (ou pelo menos o ponto onde ela deveria estar).
        // Segundo passo - testa se a chave é a chave buscada e se está em uma folha
        // Obs.: em uma árvore B+, todas as chaves válidas estão nas folhas
        if (i < pa.elementos.size() && pa.filhos.get(0) == -1
                && (elem == null || elem.compareTo(pa.elementos.get(i)) == 0)) {

            // Cria a lista de retorno e insere os elementos encontrados
            ArrayList<T> lista = new ArrayList<>();
            while (elem == null || elem.compareTo(pa.elementos.get(i)) <= 0) {

                if (elem == null || elem.compareTo(pa.elementos.get(i)) == 0)
                    lista.add(pa.elementos.get(i));
                i++;

                // Se chegar ao fim da folha, então avança para a folha seguinte
                if (i == pa.elementos.size()) {
                    if (pa.proxima == -1)
                        break;
                    arquivo.seek(pa.proxima);
                    arquivo.read(buffer);
                    pa.fromByteArray(buffer);
                    i = 0;
                }
            }
            return lista;
        }

        // Terceiro passo - se a chave não tiver sido encontrada nesta folha,
        // testa se ela está na próxima folha. Isso pode ocorrer devido ao
        // processo de ordenação.
        else if (i == pa.elementos.size() && pa.filhos.get(0) == -1) {

            // Testa se há uma próxima folha. Nesse caso, retorna um vetor vazio
            if (pa.proxima == -1) {
                ArrayList<T> resposta = new ArrayList<>();
                return resposta;
            }

            // Lê a próxima folha
            arquivo.seek(pa.proxima);
            arquivo.read(buffer);
            pa.fromByteArray(buffer);

            // Testa se a chave é a primeira da próxima folha
            i = 0;
            if (elem.compareTo(pa.elementos.get(i)) <= 0) {

                // Cria a lista de retorno
                ArrayList<T> lista = new ArrayList<>();

                // Testa se a chave foi encontrada, e adiciona todas as chaves
                // secundárias
                while (elem.compareTo(pa.elementos.get(i)) <= 0) {
                    if (elem.compareTo(pa.elementos.get(i)) == 0)
                        lista.add(pa.elementos.get(i));
                    i++;
                    if (i == pa.elementos.size()) {
                        if (pa.proxima == -1)
                            break;
                        arquivo.seek(pa.proxima);
                        arquivo.read(buffer);
                        pa.fromByteArray(buffer);
                        i = 0;
                    }
                }

                return lista;
            }

            // Se não houver uma próxima página, retorna um vetor vazio
            else {
                ArrayList<T> resposta = new ArrayList<>();
                return resposta;
            }
        }

        // Chave ainda não foi encontrada, continua a busca recursiva pela árvore
        if (elem == null || i == pa.elementos.size() || elem.compareTo(pa.elementos.get(i)) <= 0)
            return read1(elem, pa.filhos.get(i));
        else
            return read1(elem, pa.filhos.get(i + 1));
    }

    // Inclusão de novos elementos na árvore. A inclusão é recursiva. A primeira
    // função chama a segunda recursivamente, passando a raiz como referência.
    // Eventualmente, a árvore pode crescer para cima.
    public boolean create(T elem) throws Exception {

        // Carrega a raiz
        arquivo.seek(0);
        long pagina;
        pagina = arquivo.readLong();

        // O processo de inclusão permite que os valores passados como referência
        // sejam substituídos por outros valores, para permitir a divisão de páginas
        // e crescimento da árvore. Assim, são usados os valores globais elemAux
        // e chave2Aux. Quando há uma divisão, as chaves promovidas são armazenadas
        // nessas variáveis.
        elemAux = elem.clone();

        // Se houver crescimento, então será criada uma página extra e será mantido um
        // ponteiro para essa página. Os valores também são globais.
        paginaAux = -1;
        cresceu = false;

        // Chamada recursiva para a inserção do par de chaves
        boolean inserido = create1(pagina);

        // Testa a necessidade de criação de uma nova raiz.
        if (cresceu) {

            // Cria a nova página que será a raiz. O ponteiro esquerdo da raiz
            // será a raiz antiga e o seu ponteiro direito será para a nova página.
            Pagina novaPagina = new Pagina(construtor, ordem);
            novaPagina.elementos = new ArrayList<>(this.maxElementos);
            novaPagina.elementos.add(elemAux);
            novaPagina.filhos = new ArrayList<>(this.maxFilhos);
            novaPagina.filhos.add(pagina);
            novaPagina.filhos.add(paginaAux);

            // Acha o espaço em disco. Testa se há páginas excluídas.
            arquivo.seek(8);
            long end = arquivo.readLong();
            if (end == -1) {
                end = arquivo.length();
            } else { // reusa um endereço e atualiza a lista de excluídos no cabeçalho
                arquivo.seek(end);
                Pagina pa_excluida = new Pagina(construtor, ordem);
                byte[] buffer = new byte[pa_excluida.TAMANHO_PAGINA];
                arquivo.read(buffer);
                pa_excluida.fromByteArray(buffer);
                arquivo.seek(8);
                arquivo.writeLong(pa_excluida.proxima);
            }
            arquivo.seek(end);
            long raiz = arquivo.getFilePointer();
            arquivo.write(novaPagina.toByteArray());
            arquivo.seek(0);
            arquivo.writeLong(raiz);
            inserido = true;
        }

        return inserido;
    }

    // Função recursiva de inclusão. A função passa uma página de referência.
    // As inclusões são sempre feitas em uma folha.
    private boolean create1(long pagina) throws Exception {

        // Testa se passou para o filho de uma página folha. Nesse caso,
        // inicializa as variáveis globais de controle.
        if (pagina == -1) {
            cresceu = true;
            paginaAux = -1;
            return false;
        }

        // Lê a página passada como referência
        arquivo.seek(pagina);
        Pagina pa = new Pagina(construtor, ordem);
        byte[] buffer = new byte[pa.TAMANHO_PAGINA];
        arquivo.read(buffer);
        pa.fromByteArray(buffer);

        // Busca o próximo ponteiro de descida. Como pode haver repetição
        // da primeira chave, a segunda também é usada como referência.
        // Nesse primeiro passo, todos os pares menores são ultrapassados.
        int i = 0;
        while (i < pa.elementos.size() && (elemAux.compareTo(pa.elementos.get(i)) > 0)) {
            i++;
        }

        // Testa se o registro já existe em uma folha. Se isso acontecer, então
        // a inclusão é cancelada.
        if (i < pa.elementos.size() && pa.filhos.get(0) == -1 && elemAux.compareTo(pa.elementos.get(i)) == 0) {
            cresceu = false;
            return false;
        }

        // Continua a busca recursiva por uma nova página. A busca continuará até o
        // filho inexistente de uma página folha ser alcançado.
        boolean inserido;
        if (i == pa.elementos.size() || elemAux.compareTo(pa.elementos.get(i)) < 0)
            inserido = create1(pa.filhos.get(i));
        else
            inserido = create1(pa.filhos.get(i + 1));

        // A partir deste ponto, as chamadas recursivas já foram encerradas.
        // Assim, o próximo código só é executado ao retornar das chamadas recursivas.

        // A inclusão já foi resolvida por meio de uma das chamadas recursivas. Nesse
        // caso, apenas retorna para encerrar a recursão.
        // A inclusão pode ter sido resolvida porque o par de chaves já existia
        // (inclusão inválida)
        // ou porque o novo elemento coube em uma página existente.
        if (!cresceu)
            return inserido;

        // Se tiver espaço na página, faz a inclusão nela mesmo
        if (pa.elementos.size() < maxElementos) {

            // Puxa todos elementos para a direita, começando do último
            // para gerar o espaço para o novo elemento e insere o novo elemento
            pa.elementos.add(i, elemAux);
            pa.filhos.add(i + 1, paginaAux);

            // Escreve a página atualizada no arquivo
            arquivo.seek(pagina);
            arquivo.write(pa.toByteArray());

            // Encerra o processo de crescimento e retorna
            cresceu = false;
            return true;
        }

        // O elemento não cabe na página. A página deve ser dividida e o elemento
        // do meio deve ser promovido (sem retirar a referência da folha).

        // Cria uma nova página
        Pagina np = new Pagina(construtor, ordem);

        // Move a metade superior dos elementos para a nova página,
        // considerando que maxElementos pode ser ímpar
        int meio = maxElementos / 2;
        np.filhos.add(pa.filhos.get(meio)); // COPIA o primeiro ponteiro
        for (int j = 0; j < (maxElementos - meio); j++) {
            np.elementos.add(pa.elementos.remove(meio)); // MOVE os elementos
            np.filhos.add(pa.filhos.remove(meio + 1)); // MOVE os demais ponteiros
        }

        // Testa o lado de inserção
        // Caso 1 - Novo registro deve ficar na página da esquerda
        if (i <= meio) {
            pa.elementos.add(i, elemAux);
            pa.filhos.add(i + 1, paginaAux);

            // Se a página for folha, seleciona o primeiro elemento da página
            // da direita para ser promovido, mantendo-o na folha
            if (pa.filhos.get(0) == -1)
                elemAux = np.elementos.get(0).clone();

            // caso contrário, promove o maior elemento da página esquerda
            // removendo-o da página
            else {
                elemAux = pa.elementos.remove(pa.elementos.size() - 1);
                pa.filhos.remove(pa.filhos.size() - 1);
            }
        }

        // Caso 2 - Novo registro deve ficar na página da direita
        else {

            int j = maxElementos - meio;
            while (elemAux.compareTo(np.elementos.get(j - 1)) < 0)
                j--;
            np.elementos.add(j, elemAux);
            np.filhos.add(j + 1, paginaAux);

            // Seleciona o primeiro elemento da página da direita para ser promovido
            elemAux = np.elementos.get(0).clone();

            // Se não for folha, remove o elemento promovido da página
            if (pa.filhos.get(0) != -1) {
                np.elementos.remove(0);
                np.filhos.remove(0);
            }

        }

        // Obtém um endereço para a nova página (página excluída ou fim do arquivo)
        arquivo.seek(8);
        long end = arquivo.readLong();
        if (end == -1) {
            end = arquivo.length();
        } else { // reusa um endereço e atualiza a lista de excluídos no cabeçalho
            arquivo.seek(end);
            Pagina pa_excluida = new Pagina(construtor, ordem);
            buffer = new byte[pa_excluida.TAMANHO_PAGINA];
            arquivo.read(buffer);
            pa_excluida.fromByteArray(buffer);
            arquivo.seek(8);
            arquivo.writeLong(pa_excluida.proxima);
        }

        // Se a página era uma folha e apontava para outra folha,
        // então atualiza os ponteiros dessa página e da página nova
        if (pa.filhos.get(0) == -1) {
            np.proxima = pa.proxima;
            pa.proxima = end;
        }

        // Grava as páginas no arquivo
        paginaAux = end;
        arquivo.seek(paginaAux);
        arquivo.write(np.toByteArray());

        arquivo.seek(pagina);
        arquivo.write(pa.toByteArray());

        return true;
    }

    // Remoção elementos na árvore. A remoção é recursiva. A primeira
    // função chama a segunda recursivamente, passando a raiz como referência.
    // Eventualmente, a árvore pode reduzir seu tamanho, por meio da exclusão da
    // raiz.
    public boolean delete(T elem) throws Exception {

        // Encontra a raiz da árvore
        arquivo.seek(0);
        long pagina;
        pagina = arquivo.readLong();

        // variável global de controle da redução do tamanho da árvore
        diminuiu = false;

        // Chama recursivamente a exclusão de registro (na elemAux e no
        // chave2Aux) passando uma página como referência
        boolean excluido = delete1(elem, pagina);

        // Se a exclusão tiver sido possível e a página tiver reduzido seu tamanho,
        // por meio da fusão das duas páginas filhas da raiz, elimina essa raiz
        if (excluido && diminuiu) {

            // Lê a raiz
            arquivo.seek(pagina);
            Pagina pa = new Pagina(construtor, ordem);
            byte[] buffer = new byte[pa.TAMANHO_PAGINA];
            arquivo.read(buffer);
            pa.fromByteArray(buffer);

            // Se a página tiver 0 elementos, apenas atualiza o ponteiro para a raiz,
            // no cabeçalho do arquivo, para o seu primeiro filho e insere a raiz velha
            // na lista de páginas excluídas
            if (pa.elementos.size() == 0) {
                arquivo.seek(0);
                arquivo.writeLong(pa.filhos.get(0));

                arquivo.seek(8);
                long end = arquivo.readLong(); // cabeça da lista de páginas excluídas
                pa.proxima = end;
                arquivo.seek(8);
                arquivo.writeLong(pagina);
                arquivo.seek(pagina);
                arquivo.write(pa.toByteArray());
            }
        }

        return excluido;
    }

    // Função recursiva de exclusão. A função passa uma página de referência.
    // As exclusões são sempre feitas em folhas e a fusão é propagada para cima.
    private boolean delete1(T elem, long pagina) throws Exception {

        // Declaração de variáveis
        boolean excluido = false;
        int diminuido;

        // Testa se o registro não foi encontrado na árvore, ao alcançar uma folha
        // inexistente (filho de uma folha real)
        if (pagina == -1) {
            diminuiu = false;
            return false;
        }

        // Lê o registro da página no arquivo
        arquivo.seek(pagina);
        Pagina pa = new Pagina(construtor, ordem);
        byte[] buffer = new byte[pa.TAMANHO_PAGINA];
        arquivo.read(buffer);
        pa.fromByteArray(buffer);

        // Encontra a página em que o par de chaves está presente
        // Nesse primeiro passo, salta todas os pares de chaves menores
        int i = 0;
        while (i < pa.elementos.size() && elem.compareTo(pa.elementos.get(i)) > 0) {
            i++;
        }

        // Chaves encontradas em uma folha
        if (i < pa.elementos.size() && pa.filhos.get(0) == -1 && elem.compareTo(pa.elementos.get(i)) == 0) {

            // Puxa todas os elementos seguintes para uma posição anterior, sobrescrevendo
            // o elemento a ser excluído
            pa.elementos.remove(i);
            pa.filhos.remove(i + 1);

            // Atualiza o registro da página no arquivo
            arquivo.seek(pagina);
            arquivo.write(pa.toByteArray());

            // Se a página contiver menos elementos do que o mínimo necessário,
            // indica a necessidade de fusão de páginas
            diminuiu = pa.elementos.size() < maxElementos / 2;
            return true;
        }

        // Se a chave não tiver sido encontrada (observar o return true logo acima),
        // continua a busca recursiva por uma nova página. A busca continuará até o
        // filho inexistente de uma página folha ser alcançado.
        // A variável diminuído mantem um registro de qual página eventualmente
        // pode ter ficado com menos elementos do que o mínimo necessário.
        // Essa página será filha da página atual
        if (i == pa.elementos.size() || elem.compareTo(pa.elementos.get(i)) < 0) {
            excluido = delete1(elem, pa.filhos.get(i));
            diminuido = i;
        } else {
            excluido = delete1(elem, pa.filhos.get(i + 1));
            diminuido = i + 1;
        }

        // A partir deste ponto, o código é executado após o retorno das chamadas
        // recursivas do método

        // Testa se há necessidade de fusão de páginas
        if (diminuiu) {

            // Carrega a página filho que ficou com menos elementos do
            // do que o mínimo necessário
            long paginaFilho = pa.filhos.get(diminuido);
            Pagina pFilho = new Pagina(construtor, ordem);
            arquivo.seek(paginaFilho);
            arquivo.read(buffer);
            pFilho.fromByteArray(buffer);

            // Cria uma página para o irmão (da direita ou esquerda)
            long paginaIrmaoEsq = -1, paginaIrmaoDir = -1;
            Pagina pIrmaoEsq = null, pIrmaoDir = null; // inicializados com null para controle de existência

            // Carrega os irmãos (que existirem)
            if (diminuido > 0) { // possui um irmão esquerdo, pois não é a primeira filho do pai
                paginaIrmaoEsq = pa.filhos.get(diminuido - 1);
                pIrmaoEsq = new Pagina(construtor, ordem);
                arquivo.seek(paginaIrmaoEsq);
                arquivo.read(buffer);
                pIrmaoEsq.fromByteArray(buffer);
            }
            if (diminuido < pa.elementos.size()) { // possui um irmão direito, pois não é o último filho do pai
                paginaIrmaoDir = pa.filhos.get(diminuido + 1);
                pIrmaoDir = new Pagina(construtor, ordem);
                arquivo.seek(paginaIrmaoDir);
                arquivo.read(buffer);
                pIrmaoDir.fromByteArray(buffer);
            }

            // Verifica se o irmão esquerdo existe e pode ceder algum elemento
            if (pIrmaoEsq != null && pIrmaoEsq.elementos.size() > maxElementos / 2) {

                // Se for folha, copia o elemento do irmão, já que o do pai será extinto ou
                // repetido
                if (pFilho.filhos.get(0) == -1)
                    pFilho.elementos.add(0, pIrmaoEsq.elementos.remove(pIrmaoEsq.elementos.size() - 1));

                // Se não for folha, desce o elemento do pai
                else
                    pFilho.elementos.add(0, pa.elementos.get(diminuido - 1));

                // Copia o elemento vindo do irmão para o pai (página atual)
                pa.elementos.set(diminuido - 1, pFilho.elementos.get(0));

                // Reduz o elemento no irmão
                pFilho.filhos.add(0, pIrmaoEsq.filhos.remove(pIrmaoEsq.filhos.size() - 1));

            }

            // Senão, verifica se o irmão direito existe e pode ceder algum elemento
            else if (pIrmaoDir != null && pIrmaoDir.elementos.size() > maxElementos / 2) {
                // Se for folha
                if (pFilho.filhos.get(0) == -1) {

                    // move o elemento do irmão
                    pFilho.elementos.add(pIrmaoDir.elementos.remove(0));
                    pFilho.filhos.add(pIrmaoDir.filhos.remove(0));

                    // sobe o próximo elemento do irmão
                    pa.elementos.set(diminuido, pIrmaoDir.elementos.get(0));
                }

                // Se não for folha, rotaciona os elementos
                else {
                    // Copia o elemento do pai, com o ponteiro esquerdo do irmão
                    pFilho.elementos.add(pa.elementos.get(diminuido));
                    pFilho.filhos.add(pIrmaoDir.filhos.remove(0));

                    // Sobe o elemento esquerdo do irmão para o pai
                    pa.elementos.set(diminuido, pIrmaoDir.elementos.remove(0));
                }
            }

            // Senão, faz a fusão com o irmão esquerdo, se ele existir
            else if (pIrmaoEsq != null) {
                // Se a página reduzida não for folha, então o elemento
                // do pai deve descer para o irmão
                if (pFilho.filhos.get(0) != -1) {
                    pIrmaoEsq.elementos.add(pa.elementos.remove(diminuido - 1));
                    pIrmaoEsq.filhos.add(pFilho.filhos.remove(0));
                }
                // Senão, apenas remove o elemento do pai
                else {
                    pa.elementos.remove(diminuido - 1);
                    pFilho.filhos.remove(0);
                }
                pa.filhos.remove(diminuido); // remove o ponteiro para a própria página

                // Copia todos os registros para o irmão da esquerda
                pIrmaoEsq.elementos.addAll(pFilho.elementos);
                pIrmaoEsq.filhos.addAll(pFilho.filhos);
                pFilho.elementos.clear();
                pFilho.filhos.clear();

                // Se as páginas forem folhas, copia o ponteiro para a folha seguinte
                if (pIrmaoEsq.filhos.get(0) == -1)
                    pIrmaoEsq.proxima = pFilho.proxima;

                // Insere o filho na lista de páginas excluídas
                arquivo.seek(8);
                pFilho.proxima = arquivo.readLong();
                arquivo.seek(8);
                arquivo.writeLong(paginaFilho);

            }

            // Senão, faz a fusão com o irmão direito, assumindo que ele existe
            else {
                // Se a página reduzida não for folha, então o elemento
                // do pai deve descer para o irmão
                if (pFilho.filhos.get(0) != -1) {
                    pFilho.elementos.add(pa.elementos.remove(diminuido));
                    pFilho.filhos.add(pIrmaoDir.filhos.remove(0));
                }
                // Senão, apenas remove o elemento do pai
                else {
                    pa.elementos.remove(diminuido);
                    pFilho.filhos.remove(0);
                }
                pa.filhos.remove(diminuido + 1); // remove o ponteiro para o irmão direito

                // Move todos os registros do irmão da direita
                pFilho.elementos.addAll(pIrmaoDir.elementos);
                pFilho.filhos.addAll(pIrmaoDir.filhos);
                pIrmaoDir.elementos.clear();
                pIrmaoDir.filhos.clear();

                // Se a página for folha, copia o ponteiro para a próxima página
                pFilho.proxima = pIrmaoDir.proxima;

                // Insere o irmão da direita na lista de páginas excluídas
                arquivo.seek(8);
                pIrmaoDir.proxima = arquivo.readLong();
                arquivo.seek(8);
                arquivo.writeLong(paginaIrmaoDir);

            }

            // testa se o pai também ficou sem o número mínimo de elementos
            diminuiu = pa.elementos.size() < maxElementos / 2;

            // Atualiza os demais registros
            arquivo.seek(pagina);
            arquivo.write(pa.toByteArray());
            arquivo.seek(paginaFilho);
            arquivo.write(pFilho.toByteArray());
            if (pIrmaoEsq != null) {
                arquivo.seek(paginaIrmaoEsq);
                arquivo.write(pIrmaoEsq.toByteArray());
            }
            if (pIrmaoDir != null) {
                arquivo.seek(paginaIrmaoDir);
                arquivo.write(pIrmaoDir.toByteArray());
            }
        }
        return excluido;
    }

    // Imprime a árvore, usando uma chamada recursiva.
    // A função recursiva é chamada com uma página de referência (raiz)
    public void print() throws Exception {
        long raiz;
        arquivo.seek(0);
        raiz = arquivo.readLong();
        System.out.println("Raiz: " + String.format("%04d", raiz));
        if (raiz != -1)
            print1(raiz);
        System.out.println();
    }

    // Impressão recursiva
    private void print1(long pagina) throws Exception {

        // Retorna das chamadas recursivas
        if (pagina == -1)
            return;
        int i;

        // Lê o registro da página passada como referência no arquivo
        arquivo.seek(pagina);
        Pagina pa = new Pagina(construtor, ordem);
        byte[] buffer = new byte[pa.TAMANHO_PAGINA];
        arquivo.read(buffer);
        pa.fromByteArray(buffer);

        // Imprime a página
        String endereco = String.format("%04d", pagina);
        System.out.print(endereco + "  " + pa.elementos.size() + ":"); // endereço e número de elementos
        for (i = 0; i < pa.elementos.size(); i++) {
            System.out.print("(" + String.format("%04d", pa.filhos.get(i)) + ") " + pa.elementos.get(i) + " ");
        }
        if (i > 0)
            System.out.print("(" + String.format("%04d", pa.filhos.get(i)) + ")");
        else
            System.out.print("(-001)");
        for (; i < maxElementos; i++) {
            System.out.print(" ------- (-001)");
        }
        if (pa.proxima == -1)
            System.out.println();
        else
            System.out.println(" --> (" + String.format("%04d", pa.proxima) + ")");

        // Chama recursivamente cada filho, se a página não for folha
        if (pa.filhos.get(0) != -1) {
            for (i = 0; i < pa.elementos.size(); i++)
                print1(pa.filhos.get(i));
            print1(pa.filhos.get(i));
        }
    }

}
