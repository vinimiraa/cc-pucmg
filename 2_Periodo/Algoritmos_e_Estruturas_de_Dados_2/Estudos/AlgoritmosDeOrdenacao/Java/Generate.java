import java.util.Random;

public class Generate extends MyLog
{
    protected int [] array; 
    protected int    length;
    
    public Generate ( )
    {
        this.array  = null;
        this.length = -1;
    }

    public Generate ( int length )
    {
        if( length > 0 )
        {
            this.array = new int[ length ];
            this.length = length;
        }
    }

    public void fillAscending ( ) 
    {
        for( int i = 0; i < this.length; i++ )
        {
            array[i] = i;
        }
    }

    public void fillDescending ( ) 
    {
        for( int i = 0; i < this.length; i++ )
        {
            array[i] = length - 1- i;
        }
    }

    public void fillRandom ( )
    {
        Random random = new Random ( 0 ); 
        for( int i = 0; i < this.length; i++ )
        {
            array[i] = random.nextInt() % 101;
        }
    }

    public void print ( int k ) 
    {
		System.out.print( "[" );
		for( int i = 0; i < k; i++ ) 
        {
			System.out.print( " ("+array[i]+")" );
		}
		System.out.println( "]" );
	}

    public void print (  ) 
    {
		System.out.print( "[" );
		for( int i = 0; i < this.length; i++ ) 
        {
			System.out.print( " ("+array[i]+")" );
		}
		System.out.println( "]" );
	}

    public void swap ( int i, int j ) 
    {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
    }
    
    public boolean isSort ( )
    {
        boolean resp = true;
        for( int i = 1; i < this.length; i++ ) 
        {
            if( array[i] < array[i-1] ) 
            {
                i = length;
                resp = false;
            }
        }
        return ( resp );
    }

    public void sort ( ) { }

    public void sort ( MyLog log ) { }

} // end class
