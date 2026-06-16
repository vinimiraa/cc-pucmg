class List 
{
    private int[] array;
    private int n;

    public List ( ) {
        this(6);
    } // end List ( )

    public List ( int tamanho ) 
    {
        array = new int[tamanho];
        n = 0;
    } // end List ( )

    public void insertFirst ( int x ) throws Exception 
    {
        // validar insercao
        if( n >= array.length ) {
            throw new Exception("Erro ao inserir!");
        } // end if
        // levar elementos para o fim do array
        for (int i = n; i > 0; i--) {
            array[i] = array[i - 1];
        } // end for
        array[0] = x;
        n++;
    } // end insertFirst ( )

    public void insertLast ( int x ) throws Exception 
    {
        // validar insercao
        if( n >= array.length ) {
            throw new Exception("Erro ao inserir!");
        } // end if
        array[n] = x;
        n++;
    } // end insertLast ( )

    public void insert ( int x, int pos ) throws Exception 
    {
        // validar insercao
        if( n >= array.length || pos < 0 || pos > n ) {
            throw new Exception("Erro ao inserir!");
        } // end if
        // levar elementos para o fim do array
        for( int i = n; i > pos; i-- ) {
            array[i] = array[i - 1];
        } // end for
        array[pos] = x;
        n++;
    } // end insert ( )

    public int removeFirst ( ) throws Exception 
    {
        // validar remocao
        if( n == 0 ) {
            throw new Exception("Erro ao remover!");
        } // end if
        int resp = array[0];
        n--;
        for( int i = 0; i < n; i++ ) {
            array[i] = array[i + 1];
        } // end for
        return ( resp );
    } // end removeFirst ( )

    public int removeLast ( ) throws Exception 
    {
        // validar remocao
        if( n == 0 ) {
            throw new Exception("Erro ao remover!");
        } // end if
        return ( array[--n] );
    } // end removeLast ( )

    public int remove ( int pos ) throws Exception 
    {
        // validar remocao
        if (n == 0 || pos < 0 || pos >= n) {
            throw new Exception("Erro ao remover!");
        }
        int resp = array[pos];
        n--;
        for (int i = pos; i < n; i++) {
            array[i] = array[i + 1];
        }
        return ( resp );
    } // end remove ( )

    public void print ( ) 
    {
        System.out.print("[ ");
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println("]");
    } // end print ( )

    public boolean search ( int x ) 
    {
        boolean retorno = false;
        for (int i = 0; i < n && retorno == false; i++) {
            retorno = (array[i] == x);
        }
        return retorno;
    } // end search ( )
} // end class