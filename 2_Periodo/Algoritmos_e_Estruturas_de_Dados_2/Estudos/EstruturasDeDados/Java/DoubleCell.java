public class DoubleCell 
{
    public int data;        // valor da célula
    public DoubleCell prev; // link para a célula anterior
    public DoubleCell next; // link para a próxima célula

    DoubleCell ( )
    {
        this.data = 0;
        this.prev = this.next = null;
    } // end CellDouble ( )
    
    DoubleCell ( int value )
    {
        this.data = value;
        this.prev = this.next = null;
    } // end CellDouble ( )

    DoubleCell ( int value, DoubleCell prev, DoubleCell next )
    {
        this.data = value;
        this.prev = prev;
        this.next = next;
    }

    void setData ( int data )
    {
        this.data = data;
    } // end setData ( )

    int getData ( )
    {
        return ( this.data );
    } // end getData ( )

    void setPrev ( DoubleCell prev )
    {
        this.prev = prev;
    } // end setPrev ( )

    DoubleCell getPrev ( )
    {
        return ( this.prev );
    } // end getPrev ( )

    void setNext ( DoubleCell next )
    {
        this.next = next;
    } // end setNext ( )

    DoubleCell getNext ( )
    {
        return ( this.next );
    } // end getNext ( )
} // end class 
