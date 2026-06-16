public class MyLog 
{
    private int comparisons;
    private int moves;
    private int subarrays;
    private long endTime;
    private long startTime;
    private double totalTime;

    public MyLog ( ) {
        this.comparisons = 0;
        this.moves = 0;
        this.subarrays = 0;
    }

    public void incrementComparisons ( ) {
        this.comparisons++;
    }

    public void incrementComparisons ( int amount ) {
        this.comparisons += amount;
    }

    public void incrementMoves ( ) {
        this.moves++;
    }

    public void incrementMoves ( int amount ) {
        this.moves += amount;
    }

    public void incrementSubArrays ( ) {
        this.subarrays++;
    }

    public void incrementSubArrays ( int amout ) {
        this.subarrays += amout;
    }

    public void startTimer ( )
    {
        this.startTime = System.nanoTime( );
    }

    public void endTimer ( )
    {
        this.endTime = System.nanoTime( );
    }

    private double calculateTime ( )
    {
        long totalTime = this.endTime - this.startTime;
        this.totalTime = totalTime / 1_000_000.0;
        return ( this.totalTime );
    }

    public void reset ( ) 
    {
        this.comparisons = 0;
        this.moves       = 0;
        this.subarrays   = 0;
    }

    public void printMetrics ( ) 
    {
        System.out.println( "\n***Algorithm Analysis***\n");
        System.out.println( "Runtime                    : " + calculateTime( ) );
        System.out.println( "Number of comparisons      : " + this.comparisons );
        System.out.println( "Number of moves            : " + this.moves       );
        System.out.println( "Number of subarrays created: " + this.subarrays   );
        System.out.println( "\n***End Analysis***\n");
    }
}
