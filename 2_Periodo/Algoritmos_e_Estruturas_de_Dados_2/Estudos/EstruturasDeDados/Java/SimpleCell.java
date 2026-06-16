public class SimpleCell 
{
    public int  data; // valor da célula 
    public SimpleCell next; // link para a próxima célula

    SimpleCell ( )
    {
        this.data = 0;
        this.next = null;
    } // end Cell ( )

    SimpleCell ( int data )
    {
        this.data = data;
        this.next = null;
    } // end Cell ( )

    SimpleCell ( int data,  SimpleCell next )
    {
        this.data = data;
        this.next = next;
    } // enc Cell ( )

    void setData ( int data )
    {
        this.data = data;
    } // end setData ( )

    int getData ( )
    {
        return ( this.data );
    } // end getData ( )

    void setNext ( SimpleCell next )
    {
        this.next = next;
    } // end setNext ( )

    SimpleCell getNext ( )
    {
        return ( this.next );
    } // end getNext ( )
} // end class
