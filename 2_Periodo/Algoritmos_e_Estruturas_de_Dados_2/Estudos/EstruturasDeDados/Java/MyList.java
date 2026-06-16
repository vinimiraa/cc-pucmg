import java.util.Random;

public class MyList 
{
    // ---------------------------------------- atributos

    protected int[] array;     // arranjo
    protected int   size;      // tamanho real
    protected int   capacity;  // capacidade total

    // ---------------------------------------- Construtores

    public MyList( ) 
    {
        this(10); // capacidade padrao de 10
    } // end Lista ( );

    public MyList( int length ) 
    {
        if( length > 0 )
        {
            this.capacity = length+4;
            this.array = new int[this.capacity];
            this.size = length;
        } // end if
    } // end Lista ( )

    // ---------------------------------------- GETs / SETs

    public int getSize( ) 
    {
        return ( this.size );
    } // end getSize ( )

    public int getCapacity( ) 
    {
        return ( this.capacity );
    } // end getCapacity ( )

    public void set( int index, int value )
    {
        this.array[index] = value;
    } // end set ( )

    public int get( int index )
    {
        int value = 0;
        if( index >= 0 && index < size )
        {
            value = this.array[index];
        } // end if
        return ( value );
    } // end get ( )

    // ----------------------------------------  Outros Metodos

    private void increaseCapacity( ) 
    {
        int newCapacity = capacity * 2; // Aumenta em 50%
        int[] newArray = new int[newCapacity];
        System.arraycopy(array, 0, newArray, 0, size); // Copia os elementos para o novo array
        System.arraycopy(newArray, 0, array, 0, size); // Copia os elementos para o novo array
        array = newArray;
        capacity = newCapacity;
    } // end increaseCapacity ( )

    public void add( int value ) 
    {
        if( size >= capacity ) 
        {
            increaseCapacity( ); // Aumenta a capacidade se necessário
        } // end if
        array[size++] = value;
    } // end add ( )

    public void randValue( ) 
    {
        Random gerador = new Random( );
        for( int x = 0; x < size; x = x + 1 )
        {
            array[x] = Math.abs( gerador.nextInt( ) % 50 );
        } // end for
    } // end randValue ( )

    public void printLista( )
    {
        System.out.print( "[ " );
        for( int x = 0; x < size; x = x + 1 )
        {
            System.out.print( array[x] + " " );
        } // end for
        System.out.println( "]" );
    } // end printLista ( )

    // ---------------------------------------- Algoritmos de Pesquisa

    /**
     *  <p>Algoritmo de busca sequencial.</p>
     *  
     *  <p>Itera pelo arranjo comparando cada elemento com o valor procurado até encontrar 
     *  uma correspondência ou alcançar o final do array.</p>
     *  
     *  @param value : O valor a ser procurado no arranjo.
     *  @return {@code true} se o valor for encontrado, {@code false} caso contrário.
     */
    public boolean sequentialSearch( int value ) 
    {
        boolean found = false;
        for( int i = 0; i < size && !found; i++ ) 
        {
            if( array[i] == value ) 
            {
                found = true;
            } // end if
        } // end for
        return ( found );
    } // end sequentialSearch ( )
    
    /**
     *  <p>Algoritmo de busca binária.</p>
     *  
     *  <p>Funciona em um array ordenado e divide repetidamente o intervalo de busca pela 
     *  metade até que o valor seja encontrado ou o intervalo se torne vazio.</p>
     *  
     *  @param value :  O valor a ser procurado no array.
     *  @param left : O índice esquerdo do intervalo de busca.
     *  @param right : O índice direito do intervalo de busca.
     *  @return O índice do valor encontrado, ou -1 se o valor não for encontrado.
     */
    public int binarySearch( int value, int left, int right ) 
    {
        if( left > right ) {
            return -1; // not found
        } 
        else 
        {
            int mid = (left + right) / 2;
            if( value == array[mid] ) {
                return mid;
            } else if (value > array[mid]) {
                return binarySearch( value, mid+1, right) ;
            } else {
                return binarySearch( value, left, mid-1 );
            } // end if
        } // end if
    } // end binarySearch ( )

    // ---------------------------------------- Algoritmos de Ordenação
    
    /**
     *  <p>Troca os elementos de posição no array, dados os índices i e j.</p>
     *  
     *  <p>Complexidade: O(1).         </p>
     *  <p>Número de comparações: 0.   </p> 
     *  <p>Número de movimentações: 3. </p>
     *  
     *  @param i : posição do primeiro valor.
     *  @param j : posição do segundo valor:
     */
    public void swap( int i, int j ) 
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } // end swap ( )

    /**
     *  <p>Bubble Sort é um algoritmo de ordenação simples, que percorre repetidamente
     *  a lista, compara elementos adjacentes e os troca se estiverem na ordem
     *  errada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    public void bubbleSort( )
    {
        for( int i = 1; i < size; i = i + 1 )
        {
            for( int j = 1; j < size; j = j + 1 )
            {
                if( array[j] > array[j+1] )
                {
                    // int temp = array[j+1];
                    swap( j, j+1 );
                } // end if
            } // end for
        } // end for
    } // end bubbleSort ( )

    /**
     *  <p>Bubble Sort melhorado.</p>
     */
    public void bubbleSortBest( )
    {
        boolean swapped = true;
        for( int i = 0; i < size-1 && swapped; i = i + 1 )
        {
            swapped = false;
            for( int j = 0; j < size-i-1; j = j + 1 )
            {
                if( array[j] > array[j+1] )
                {
                    swap( j, j+1 );
                    swapped = true;
                } // end if
            } // end for
        } // end for
    } // end bubbleSortBest ( )

    /**
     *  <p>Selection Sort é um algoritmo de ordenação que divide a lista em duas partes:
     *  uma parte ordenada e outra não ordenada. Ele seleciona repetidamente o menor
     *  elemento da parte não ordenada e o move para o final da parte ordenada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso.             </p> 
     *  <p>Número de comparações: O(n^2). -> n^2/2 - n/2  </p>
     *  <p>Número de movimentações: O(n). -> 3(n-1)       </p>
     */
    public void selectionSort( ) 
    {
        for( int i = 0; i < size - 1; i = i + 1 ) 
        {
            int minIndex = i;
            for( int j = i + 1; j < size; j++ ) 
            {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                } // end if
            } // end for
            swap( i, minIndex );
        } // end for
    } // end selectionSort ( )

    /**
     *  <p>Insertion Sort é um algoritmo de ordenação que constrói uma lista ordenada
     *  um item por vez, movendo cada novo item para a posição correta na lista
     *  ordenada.</p> 
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    public void insertionSort( )
    {
        for( int i = 1; i < size; i = i + 1 ) 
        {
            int key = array[i];
            int j = i - 1;
            while( ( j >= 0 ) && ( array[j-1] > array[j] ) ) 
            {
                array[j+1] = array[j]; // deslocamento
                j--;
            } // end while
            array[j+1] = key;
        } // end for
    } // end insertionSort ( )

    /**
     * <p>Algoritmo de Inserção modificado para ser utilizado no ShellSort.</p>
     *  
     *  @param startIndex : posição inicial do sub-arranjo.
     *  @param gap : valor do intervalor entre sub-arranjos.
     */
    void insertionShell( int startIndex, int gap )
    {
        for( int x = ( gap + startIndex ); x < size; x = x + gap ) 
        {
            int temp = array[x];
            int y = x - gap;
            while( ( y >= 0 ) && ( array[y] > temp ) ) 
            {
                array[y+gap] = array[y];
                y = y - gap;
            } // end while
            array[y+gap] = temp;
        } // end for
    } // insertionShell ( )

    /**
     *  <p>Shell Sort é uma melhoria do Insertion Sort, que compara elementos
     *  distanciados por um intervalo maior e então reduz gradualmente esse
     *  intervalo. Isso produz uma lista quase ordenada, facilitando a ordenação
     *  final.</p>
     * 
     *  <p>Complexidade: Depende do intervalo escolhido. Melhor caso é O(n*log(n)), médio e pior caso variam. </p>
     *  <p>Número de comparações e movimentações: Geralmente menor do que o Insertion Sort.                   </p> 
     */
    void shellSort( ) 
    {
        int gap = 1;
        do { 
            gap = (gap * 3) + 1; 
        } while( gap < size ); // end do while
        do 
        {
            gap = gap / 3;
            for( int startIndex = 0; startIndex < gap; startIndex = startIndex + 1 ) {
                insertionShell( startIndex, gap );
            } // end for
        } while( gap != 1 ); // end do while
    } // end shellSOrt ( )
    
    /**
     *  <p>Quick Sort é um algoritmo de ordenação eficiente que divide o array em
     *  partições, selecionando um elemento como pivô, e rearranjando os elementos
     *  de modo que os menores que o pivô fiquem à sua esquerda e os maiores à sua
     *  direita.<p>
     *  
     *  <p>Complexidade: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.            </p>
     *  <p>Número de comparações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.   </p> 
     *  <p>Número de movimentações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso. </p>
     * 
     *  @param left : primeira posição do arranjo.
     *  @param right : ultima posição do arranjo.
     */
    public void quickSort(int left, int right) 
    {
        int i = left, j = right;
        int pivot = array[(left + right) / 2];

        while( i <= j ) 
        {
            while( array[i] < pivot ) {
                i++;
            } // end while
            while( array[j] > pivot ) {
                j--;
            } // end while
            if( i <= j ) {
                swap(i, j);
                i++;
                j--;
            } // end if
        } // end while
        if (left < j) {
            quickSort(left, j);
        } // end if
        if (i < right) {
            quickSort(i, right);
        } // end if
    } // end quickSort ( )

    // ---------------------------------------- Algoritmos de Inserção e Remoção

    /**
     *  <p>Inserir no Início / Push-Front</p>
     *  <p>Insere um novo elemento no início do array.</p>
     *  @param value : O valor a ser inserido no início do array.
     */
    public void insertStart( int value ) throws Exception
    {
        if( size < capacity ) 
        {
            for(int x = size; x > 0; x = x - 1 ) {
                array[x + 1] = array[x];
            } // end for
            array[0] = value;
            size++;
        } 
        else {
            throw new Exception( "ERROR: Unable to inset at start." );
        }// end if
    } // ens insertStart ( )

    /**
     *  <p>Inserir no Fim / Push-Back</p>
     *  <p>Insere um novo elemento no final do array.</p>
     *  @param value : O valor a ser inserido no final do array.
     */
    public void insertEnd( int value ) throws Exception
    {
        if( size < capacity ) 
        {
            array[size] = value;
            size++;
        } 
        else {
            throw new Exception ( "ERROR: Unable to insert at end." );
        } // end if
    } // end insertEnd ( )

    /**
     *  <p>Remover do Início / Pop-Front</p>
     *  <p>Remove o primeiro elemento do array e retorna o valor removido.</p>
     *  @return O valor do primeiro elemento removido, ou 0 se o array estiver vazio.
     */
    public int removeStart( ) throws Exception
    {
        int value = 0;
        if( size > 0 ) 
        {
            value = array[0];
            for (int x = 1; x < size; x = x + 1) {
                array[x - 1] = array[x];
            } // end for
            size--;
        } 
        else {
            throw new Exception( "ERROR: Unable to remove from start." );
        } // end if
        return ( value );
    } // end removeStart ( )

    /**
     *  <p>Remover do Fim / Pop-Back</p>
     *  <p>Remove o último elemento do array e retorna o valor removido.</p>
     *  @return O valor do último elemento removido, ou 0 se o array estiver vazio.
     */
    public int removeEnd( ) throws Exception
    {
        int value = 0;
        if( size > 0 ) 
        {
            value = array[size - 1];
            size--;
        } 
        else {
            throw new Exception( "ERROR: Unable to remove from end." );
        } // end if
        return ( value );
    } // end removeEnd ( )

    /**
     *  <p>Modificado para esta classe.</p>
     *  <p>Insere um novo elemento no final do array.</p>
     *  @param value O valor a ser inserido no final do array.
     */
    public void InsertEnd( int value ) 
    {
        if( size < capacity ) 
        {
            array[size] = value;
            size++;
        } 
        else 
        {
            increaseCapacity();
            array[size] = value;
            size++;
        } // end if
    } // end insertEnd ( )

} // end class 
