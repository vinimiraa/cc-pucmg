// pinos
int led_red    = 13;  // pin led red
int led_yellow = 12;  // pin led yellow
int led_green  = 11;  // pin led green
int led_blue   = 10;  // pin led blue

// variaveis
String memory[100];   // memory
String input = "" ;   // input
const int ds = 4;     // data start
int  ic = 0;          // instruction counter
int  PC = ds;         // program Counter
char W  = 0;          // OP 
char X  = 0;          // A
char Y  = 0;          // B 

// declaracoes
void load_memory ( void );
void load_instruction_to_memory ( String input );
void execute_instruction ( void );
String do_instruction ( char X, char Y, char W );
int hexchar_to_int ( char hexc );
void update_leds ( char result );
String dec_to_bin ( int value );
void print_memory ( int adress );
void print_memory ( void );

void setup ( void ) 
{
    Serial.begin( 9600 );
    pinMode( led_red   , OUTPUT );
    pinMode( led_yellow, OUTPUT );
    pinMode( led_green , OUTPUT );
    pinMode( led_blue  , OUTPUT );
    load_memory( );
} // end setup ( )

void loop ( void ) 
{
    if( Serial.available( ) > 0 ) {
        input = Serial.readString( );
        load_instruction_to_memory( input );
        execute_instruction( );
    } // if 
} // end loop ( )

void load_memory ( void ) 
{
    memory[0] =  PC;
    memory[1] = "0";
    memory[2] = "0";
    memory[3] = "0";
} // end load_memory ( )

void load_instruction_to_memory( String input )
{   
    int size = input.length( );
    int i = 0; 
    while( i < size )
    {
        if( ic < 100 ) {
            memory[ds+ic] = input.substring(i, i+3);
            ic = ic + 1;
            i = i + 4;
        } else {
            Serial.println( "Memory is full!" );
            i = size;
        } // if
    } // while
} // end load_instruction_to_memory ( )

void execute_instruction ( void ) 
{
    String instruction = "";
    while( PC < (ds+ic) )
    {
        memory[0] = String( PC, HEX );
        instruction = memory[PC];

        X = instruction.charAt(0);
        Y = instruction.charAt(1);
        W = instruction.charAt(2);

        String res = do_instruction( X, Y, W );
        W = res.charAt(0);

        memory[1] = W;
        memory[2] = X;
        memory[3] = Y;

        update_leds( hexchar_to_int( W ) );
        print_memory( PC );
        delay( 4000 );

        PC = PC + 1;
    } // while
  	Serial.println( "End of instructions!" );
} // end execute_instruction ( )

String do_instruction( char X, char Y, char W )
{
    int res = 0;
    int A = hexchar_to_int( X );
    int B = hexchar_to_int( Y );
    char OPCODE = W;
    switch ( OPCODE )
    {
    case '0':
        res = 1;
        break;
    case '1':
        res = A|(~B);
        break;
    case '2':
        res = A;
        break;
    case '3':
        res = (~A)^(~B);
        break;
    case '4':
        res = ~(A&B);
        break;
    case '5':
        res = ~A;
        break;
    case '6':
        res = A&(~B);
        break;
    case '7':
        res = (~A)|(~B);
        break;
    case '8':
        res = A^B;
        break;
    case '9':
        res = 0;
        break;
    case 'A':
        res = B;
        break;
    case 'B':
        res = A&B;
        break;
    case 'C':
        res = ~B;
        break;
    case 'D':
        res = ~((~A)&B);
        break;
    case 'E':
        res = A|B;
        break;
    case 'F':
        res = (~A)&B;
        break;
    default:
        Serial.println( "Invalid instruction!" );
        break;
    } // switch
    if( res < 0 ) {
        res = res + 16;
    } // if
    return ( String( res, HEX ) );
} // end do_instruction ( )

int hexchar_to_int ( char hexc ) 
{
    int res = -1;
    if( hexc >= '0' && hexc <= '9' ) {
        res = hexc - '0';
    } else if( hexc >= 'A' && hexc <= 'F' ) {
        res = 10 + (hexc - 'A');
    } else if( hexc >= 'a' && hexc <= 'f' ) {
        res = 10 + (hexc - 'a');
    } // if
    return ( res );
} // end hexchar_to_int ( )

void update_leds ( int result ) 
{
    String bin = dec_to_bin( result );
    digitalWrite( led_red   , bin.charAt(0) == '1' ? HIGH : LOW ); 
    digitalWrite( led_yellow, bin.charAt(1) == '1' ? HIGH : LOW ); 
    digitalWrite( led_green , bin.charAt(2) == '1' ? HIGH : LOW ); 
    digitalWrite( led_blue  , bin.charAt(3) == '1' ? HIGH : LOW ); 
} // end update_leds ( )

String dec_to_bin ( int value )
{
    String binary = "";
    int bit = 0;    
    for( int i = 0; i < 4; i = i + 1 ) 
    {
        bit = value % 2;
        binary = String( bit ) + binary;
        value = value / 2;
    }   
    return ( binary );
} // end dec_to_bin ( )

void print_memory ( int adress ) 
{
    int size = ds+ic;
    for( int i = 0; i < size; i = i + 1 ) {
        if( i >= 4 && i == adress ) {
            Serial.print( "->" );
        } // if
        Serial.print( memory[i] );
        Serial.print( "|" );
    } // for
    Serial.println( "" );
} // end print_memory ( )

void print_memory ( void ) 
{
    int size = ds+ic;
    for( int i = 0; i < size; i = i + 1 ) {
        Serial.print( memory[i] );
        Serial.print( "|" );
    } // for
    Serial.println( "" );
} // end print_memory ( )

/**
Casos de Testes:

FFC
1E3
026
009
FBD
AB5
538
706
7F7
C53
AAA
FBB
FF0
DF1
0EE
FF2
*/