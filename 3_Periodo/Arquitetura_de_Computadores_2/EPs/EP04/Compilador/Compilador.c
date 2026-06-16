/**
 * 	Árvore de Sintaxe Abstrata
 * 	
 *          <Exp>
 *        /   |   \
 *       |    |    |
 * 	( <Fator> | <Fator> )
 *  
 * 	<Exp>     ::= <Fator> & <Fator>
 *	
 * 	<Fator>   ::= X | Y | W 
 *				| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F
 *				| umL | AonB | copiaA | nAxnB | AeBn | nA | AenB 
 *				| nAonB | AxB | zeroL | copiaB | AeB | nB | nAeBn | AoB | nAeB
 * 	          
 * 	<Comando> ::= <Fator> <Operador> <Fator> <Terminador>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * 	Finds the index of the first occurrence of a character in a string.
 * 	
 * 	@param _Str The string to search in.
 * 	@param _Char The character to find.
 * 	@return The index of the first occurrence of the character, or -1 if not found.
 */
int str_indexOf ( const char *_Str, const char _Char );

/**
 * 	Extracts a substring from a given string.
 * 	
 * 	@param _Str The original string.
 * 	@param _Start The starting index of the substring.
 * 	@param _End The ending index of the substring.
 * 	@return A pointer to the substring.
 */
char* str_substring ( const char *_Str, size_t _Start, size_t _End );

/**
 * 	Checks if a string contains another string.
 * 
 * 	@param _Str The string to search in.
 * 	@param _Src The string to find.
 * 	@return True if _Src is found in _Str, otherwise false.
 */
bool str_contains ( const char* _Str, const char* _Src );

/**
 * 	Checks if the input string represents the start of a sequence.
 * 
 * 	@param input The input string.
 * 	@return True if the input is a start sequence, otherwise false.
 */
bool is_start ( char* input );

/**
 * 	Checks if the input string represents the end of a sequence.
 * 
 * 	@param input The input string.
 * 	@return True if the input is an end sequence, otherwise false.
 */
bool is_end ( char* input );

/**
 * 	Checks if the input string represents a factor.
 * 
 * 	@param input The input string.
 * 	@return True if the input is a factor, otherwise false.
 */
bool is_factor ( char* input );

/**
 * 	Checks if the input string represents an expression.
 * 
 * 	@param input The input string.
 * 	@return True if the input is an expression, otherwise false.
 */
bool is_expression( char* input );

/**
 * 	Checks if the input string represents a command.
 * 
 * 	@param input The input string.
 * 	@return True if the input is a command, otherwise false.
 */
bool is_command( char* input );

/**
 * 	Finds the instruction corresponding to the input string.
 * 
 * 	@param input The input string.
 * 	@return The character representing the instruction.
 */
char find_instruction ( char* input );

/**
 * 	Reads from an input file and writes to an output file.
 * 	
 * 	@param in_filepath The path to the input file.
 * 	@param out_filepath The path to the output file.
 */
void read_write_file ( char* in_filepath, char* out_filepath );

int main ( void )
{
	char* inputfile = "testeula.ula";
	char* outputfile = "testeula.hex";
	
	read_write_file( inputfile, outputfile );
    
	return ( 0 );
} // end main ( )

void read_write_file( char* in_filepath, char* out_filepath )
{
	char X = '\0';   // X -> Primeira variável
	char Y = '\0';   // Y -> Segunda variável
	char W[8];       // W -> Operação
	char _input[8];  // _input -> Linha a ser lida
	FILE* finput  = fopen( in_filepath, "rt"  );  // finput -> Arquivo de entrada
	FILE* foutput = fopen( out_filepath, "wt" );  // foutput -> Arquivo de saída
	
	// verificar se o arquivo de entrada existe
	if( finput == NULL ) {
		printf( "\n%s\n", "[ERRO] Unable to open input file!" );
	} 
	else 
	{
		// ler comando incial
		fscanf( finput, "%s", _input );
		
		// verificar se e' o comando 'inicio:'
		if( is_start( _input ) == false ) {
			printf( "\n%s\n", "[ERRO] Start not found!" );
		} 
		else 
		{
			// ler linha de comando
			fscanf( finput, "%s", _input );
		
			// enquanto nao encontrar o comando 'fim.'
			while( is_end( _input ) == false ) 
			{
				// verificar se e' um comando valido
				if( is_command( _input ) == true ) 
				{
					// pegar o valor de cada atribuicao
					int len = strlen( _input );
					if( _input[0] == 'X' ) {
						X = _input[len-2];
					} else if( _input[0] == 'Y' ) {
						Y = _input[len-2];
					} else if( _input[0] == 'W' ) {
						strncpy(W, &_input[2], len - 3);
						W[len-3] = '\0';
						char exp = find_instruction( W );
						// escrever no arquivo de saída
						fprintf( foutput, "%c%c%c\n", X, Y, exp );
					} // if
				} // if
				// ler proxima linha
				fscanf( finput, "%s", _input );
			} // while
		} // if
	} // if
	fclose( finput );
	fclose( foutput );
} // end read_from_file ( )

bool is_start( char* input )
{
	return ( strcmp(input, "inicio:") == 0);
} // end is_start ( )

bool is_end( char* input )
{
	return ( strcmp(input, "fim." ) == 0 );
} // end is_end ( )

char find_instruction( char* input )
{
	char res = 0;
	if( strcmp(input, "umL") == 0 ) {
		res = '0';
	} else if( strcmp(input, "AonB") == 0 ) {
		res = '1';
	} else if( strcmp(input, "copiaA") == 0 ) {
		res = '2';
	} else if( strcmp(input, "nAxnB") == 0 ) {
		res = '3';
	} else if( strcmp(input, "AeBn") == 0 ) {
		res = '4';
	} else if( strcmp(input, "nA") == 0 ) {
		res = '5';
	} else if( strcmp(input, "AenB") == 0 ) {
		res = '6';
	} else if( strcmp(input, "nAonB") == 0 ) {
		res = '7';
	} else if( strcmp(input, "AxB") == 0 ) {
		res = '8';
	} else if( strcmp(input, "zeroL") == 0 ) {
		res = '9';
	} else if( strcmp(input, "copiaB") == 0 ) {
		res = 'A';
	} else if( strcmp(input, "AeB") == 0 ) {
		res = 'B';
	} else if( strcmp(input, "nB") == 0 ) {
		res = 'C';
	} else if( strcmp(input, "nAeBn") == 0 ) {
		res = 'D';
	} else if( strcmp(input, "AoB") == 0 ) {
		res = 'E';
	} else if( strcmp(input, "nAeB") == 0 ) {
		res = 'F';
	} else {
		printf( "\n[ERRO] Instruction \'%s\' not found!\n", input );
	} // if
	return ( res );
} // end find_instruction ( )

bool is_factor( char* input ) 
{
	bool res = false;
	if(    strcmp(input, "X"     ) == 0 || strcmp(input, "Y"     ) == 0 || strcmp(input, "W"     ) == 0 
		|| strcmp(input, "0"     ) == 0 || strcmp(input, "1"     ) == 0 || strcmp(input, "2"     ) == 0
		|| strcmp(input, "3"     ) == 0 || strcmp(input, "4"     ) == 0 || strcmp(input, "5"     ) == 0
		|| strcmp(input, "6"     ) == 0 || strcmp(input, "7"     ) == 0 || strcmp(input, "8"     ) == 0
		|| strcmp(input, "9"     ) == 0 || strcmp(input, "A"     ) == 0 || strcmp(input, "B"     ) == 0
		|| strcmp(input, "C"     ) == 0 || strcmp(input, "D"     ) == 0 || strcmp(input, "E"     ) == 0
		|| strcmp(input, "F"     ) == 0 || strcmp(input, "umL"   ) == 0 || strcmp(input, "AonB"  ) == 0 
		|| strcmp(input, "copiaA") == 0 || strcmp(input, "nAxnB" ) == 0 || strcmp(input, "AeBn"  ) == 0 
		|| strcmp(input, "nA"    ) == 0 || strcmp(input, "AenB"  ) == 0 || strcmp(input, "nAonB" ) == 0 
		|| strcmp(input, "AxB"   ) == 0 || strcmp(input, "zeroL" ) == 0 || strcmp(input, "copiaB") == 0 
		|| strcmp(input, "AeB"   ) == 0 || strcmp(input, "nB"    ) == 0 || strcmp(input, "nAeBn" ) == 0 
		|| strcmp(input, "AoB"   ) == 0 
		|| strcmp(input, "nAeB"  ) == 0 ) 
	{
		res = true;
	} else {
		printf( "\n%s\n", "[ERRO] Invalid factor!" );
	} // if
	return ( res );
} // end is_factor ( )

bool is_expression( char* input )
{
	bool res = false;
	int i = str_indexOf( input, '=' );
    if( i != -1 && is_factor(str_substring(input, 0, i-1)) && is_factor(str_substring(input, i+1, strlen(input)-2)) ) {
        res = true;
    } else {
		printf( "\n%s\n", "[ERRO] Invalid expression!" );
	} // if
	return ( res );
} // end is_expression ( )

bool is_command( char* input ) 
{
    bool res = false;
    if( input[strlen(input)-1] == ';' && str_contains(input, "=") && is_expression(input)  ) {
        res = true;
    } else {
		printf( "\n%s\n", "[ERRO] Invalid command!" );
	}// if
    return ( res );
} // end is_command ( )

bool str_contains (const char* _Str, const char* _Src)
{
    bool _Val = false;
    if( !_Str || !_Src ) {
        _Val = false;
    } 
    else 
    {
        size_t _Len_Str = strlen(_Str);
        size_t _Len_Src = strlen(_Src);

        for( size_t i = 0; i <= _Len_Str - _Len_Src; ++i ) 
        {
            bool found = true;
            for( size_t j = 0; j < _Len_Src; ++j ) 
            {
                if( _Str[i + j] != _Src[j] ) 
                {
                    found = false;
                    j = _Len_Src;
                } // end if
            } // end for
            if( found ) {
                _Val = true;
                i = _Len_Str - _Len_Src + 1;
            } // end if
        } // end for
    } // end if
    return ( _Val );
} // end str_contains ( )

char* str_substring ( const char *_Str, size_t _Start, size_t _End )
{
    char *_Sub = NULL;
    size_t _Len_Str = strlen( _Str );
    if ( _Start < _Len_Str && _End < _Len_Str  && _Start <= _End )
    {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*) malloc( (_Len+1) * sizeof(char) );
        if( _Sub )
        {
            size_t j = 0;
            for ( size_t i = _Start; i <= _End; i = i + 1, j = j + 1 ) {
                *(_Sub+j) = *(_Str+i);
            } // end for
            *(_Sub+j) = '\0';
        } // end if
    } // end if
    return ( _Sub );
} // end str_substring ( )

int str_indexOf ( const char *_Str, const char _Char )
{
    size_t _Val = -1;
    if( _Str )
    {
        size_t _Var = 0; 
        while( *(_Str+_Var) != _Char ) { _Var = _Var + 1; }
        if( *(_Str+_Var) == _Char ) {
            _Val = _Var;
        } // end if
    }
    return ( _Val );
} // end str_indexOf ( )
