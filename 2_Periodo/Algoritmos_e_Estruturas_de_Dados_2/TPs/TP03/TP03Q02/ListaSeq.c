/*
 *  -------------------------- Documentacao
 *   
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP03Q02 - 28 / 05 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o ListaSeq ListaSeq.c
 *       Windows: gcc -o ListaSeq ListaSeq.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./ListaSeq
 *       Windows: ListaSeq
 *   
*/

// ---------------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>

// ---------------------------------- Struct Pesonagem

typedef struct s_Personagem
{
    char*   id              ; 
    char*   name            ; 
    char*   alternateNames  ;
    char*   house           ; 
    char*   ancestry        ; 
    char*   species         ; 
    char*   patronus        ; 
    bool    hogwartsStaff   ;  
    bool    hogwartsStudent ;  
    char*   actorName       ; 
    bool    alive           ;
    char*   alternateActors ; 
    char*   dateOfBirth     ; 
    int     yearOfBirth     ; 
    char*   eyeColour       ; 
    char*   gender          ; 
    char*   hairColour      ; 
    bool    wizard          ; 
} Personagem;

// ---------------------------------- Funções - Personagem

/**
 *  Verificar existencia de espaço para o Personagem.
*/
bool exist_Personagem( Personagem *perso )
{
    bool exist = false;
    if( perso != NULL && 
        perso->id != NULL && perso->name != NULL && perso->alternateNames != NULL && perso->house != NULL &&
        perso->ancestry != NULL && perso->species != NULL && perso->patronus != NULL && perso->actorName != NULL &&
        perso->alternateActors != NULL && perso->dateOfBirth != NULL && perso->eyeColour != NULL && 
        perso->gender != NULL && perso->hairColour != NULL )
    {
        exist = true;
    } // end if
    return ( exist );
} // end exist_Personagem ( )

/**
 *  Alocar o espaço de memória para o Personagem.
*/
Personagem* new_Personagem( void )
{
    Personagem *perso = (Personagem*) malloc ( 1 * sizeof(Personagem) );
    if( perso != NULL )
    {
        perso->id              = (char*) calloc (  50, sizeof(char) );
        perso->name            = (char*) calloc (  50, sizeof(char) );
        perso->alternateNames  = (char*) calloc ( 300, sizeof(char) );
        perso->house           = (char*) calloc (  50, sizeof(char) );
        perso->ancestry        = (char*) calloc (  50, sizeof(char) );
        perso->species         = (char*) calloc (  50, sizeof(char) );
        perso->patronus        = (char*) calloc (  50, sizeof(char) );
        perso->hogwartsStaff   = false                               ; 
        perso->hogwartsStudent = false                               ; 
        perso->actorName       = (char*) calloc (  50, sizeof(char) );
        perso->alive           = false                               ; 
        perso->alternateActors = (char*) calloc ( 255, sizeof(char) );
        perso->dateOfBirth     = (char*) calloc (  50, sizeof(char) );
        perso->yearOfBirth     = -1                                  ; 
        perso->eyeColour       = (char*) calloc (  50, sizeof(char) );
        perso->gender          = (char*) calloc (  50, sizeof(char) );
        perso->hairColour      = (char*) calloc (  50, sizeof(char) );
        perso->wizard          = false                               ; 

        if( !exist_Personagem( perso ) )
        {
            printf( "\n%s\n", "ERROR: Unable to alloc memory for \'Personagem\'." );
        } // end if
    } // end if
    return ( perso );
} // end new_Personagem ( )

/**
 *  Desalocar o espaço de momória do personagem.
*/
void delete_Personagem( Personagem *perso )
{
    if( perso != NULL )
    {
        if( exist_Personagem( perso ) ) 
        {
            free( perso->id              ); perso->id              = NULL;
            free( perso->name            ); perso->name            = NULL;
            free( perso->alternateNames  ); perso->alternateNames  = NULL;
            free( perso->house           ); perso->house           = NULL;
            free( perso->ancestry        ); perso->ancestry        = NULL;
            free( perso->species         ); perso->species         = NULL;
            free( perso->patronus        ); perso->patronus        = NULL;
            free( perso->actorName       ); perso->actorName       = NULL;
            free( perso->alternateActors ); perso->alternateActors = NULL;
            free( perso->dateOfBirth     ); perso->dateOfBirth     = NULL;
            free( perso->eyeColour       ); perso->eyeColour       = NULL;
        }
        free( perso ); perso = NULL;  
    } // end if
} // end delete_Personagem ( )

/**
 *  Funções GET.
*/
char* getId              ( Personagem *perso ) { return ( perso->id              ); }
char* getName            ( Personagem *perso ) { return ( perso->name            ); }
char* getAlternateNames  ( Personagem *perso ) { return ( perso->alternateNames  ); }
char* getHouse           ( Personagem *perso ) { return ( perso->house           ); }
char* getAncestry        ( Personagem *perso ) { return ( perso->ancestry        ); }
char* getSpecies         ( Personagem *perso ) { return ( perso->species         ); }
char* getPatronus        ( Personagem *perso ) { return ( perso->patronus        ); }
bool  getHogwartsStaff   ( Personagem *perso ) { return ( perso->hogwartsStaff   ); }
bool  getHogwartsStudent ( Personagem *perso ) { return ( perso->hogwartsStudent ); }
char* getActorName       ( Personagem *perso ) { return ( perso->actorName       ); }
bool  getAlive           ( Personagem *perso ) { return ( perso->alive           ); }
char* getAlternateActors ( Personagem *perso ) { return ( perso->alternateActors ); }
char* getDateOfBirth     ( Personagem *perso ) { return ( perso->dateOfBirth     ); }
int   getYearOfBirth     ( Personagem *perso ) { return ( perso->yearOfBirth     ); }
char* getEyeColour       ( Personagem *perso ) { return ( perso->eyeColour       ); }
char* getGender          ( Personagem *perso ) { return ( perso->gender          ); }
char* getHairColour      ( Personagem *perso ) { return ( perso->hairColour      ); }
bool  getWizard          ( Personagem *perso ) { return ( perso->wizard          ); }

/**
 *  Funções SET.
*/
void setId              ( Personagem *perso, char* id              ) { strcpy( perso->id              , id             ) ; }
void setName            ( Personagem *perso, char* name            ) { strcpy( perso->name            , name           ) ; }
void setAlternateNames  ( Personagem *perso, char* alternateNames  ) { strcpy( perso->alternateNames  , alternateNames ) ; } 
void setHouse           ( Personagem *perso, char* house           ) { strcpy( perso->house           , house          ) ; }
void setAncestry        ( Personagem *perso, char* ancestry        ) { strcpy( perso->ancestry        , ancestry       ) ; }
void setSpecies         ( Personagem *perso, char* species         ) { strcpy( perso->species         , species        ) ; }
void setPatronus        ( Personagem *perso, char* patronus        ) { strcpy( perso->patronus        , patronus       ) ; }
void setHogwartsStaff   ( Personagem *perso, bool  hogwartsStaff   ) {         perso->hogwartsStaff   = hogwartsStaff    ; }
void setHogwartsStudent ( Personagem *perso, bool  hogwartsStudent ) {         perso->hogwartsStudent = hogwartsStudent  ; }
void setActorName       ( Personagem *perso, char* actorName       ) { strcpy( perso->actorName       , actorName      ) ; }
void setAlive           ( Personagem *perso, bool  alive           ) {         perso->alive           = alive            ; }
void setAlternateActors ( Personagem *perso, char* alternateActors ) { strcpy( perso->alternateActors , alternateActors) ; }
void setDateOfBirth     ( Personagem *perso, char* dateOfBirth     ) { strcpy( perso->dateOfBirth     , dateOfBirth    ) ; }
void setYearOfBirth     ( Personagem *perso, int   yearOfBirth     ) {         perso->yearOfBirth     = yearOfBirth      ; }
void setEyeColour       ( Personagem *perso, char* eyeColour       ) { strcpy( perso->eyeColour       , eyeColour      ) ; }
void setGender          ( Personagem *perso, char* gender          ) { strcpy( perso->gender          , gender         ) ; }
void setHairColour      ( Personagem *perso, char* hairColour      ) { strcpy( perso->hairColour      , hairColour     ) ; }
void setWizard          ( Personagem *perso, bool  wizard          ) {         perso->wizard          = wizard           ; }

/**
 *  Função para inicializar um Personagem com valores.
*/
void init_Personagem ( Personagem *perso,
                        char* id             , char* name       , char* alternateNames , char* house          , 
                        char* ancestry       , char* species    , char* patronus       , bool  hogwartsStaff  ,
                        bool  hogwartsStudent, char* actorName  , bool  alive          , char* alternateActors, 
                        char* dateOfBirth    , int   yearOfBirth, char* eyeColour      , char* gender         , 
                        char* hairColour     , bool wizard )
{
    if( exist_Personagem( perso ) ) 
    {
        setId              ( perso, id              );
        setName            ( perso, name            );
        setAlternateNames  ( perso, alternateNames  );
        setHouse           ( perso, house           );
        setAncestry        ( perso, ancestry        );
        setSpecies         ( perso, species         );
        setPatronus        ( perso, patronus        );
        setHogwartsStaff   ( perso, hogwartsStaff   );
        setHogwartsStudent ( perso, hogwartsStudent );
        setActorName       ( perso, actorName       );
        setAlive           ( perso, alive           );
        setAlternateActors ( perso, alternateActors );
        setDateOfBirth     ( perso, dateOfBirth     );
        setYearOfBirth     ( perso, yearOfBirth     );
        setEyeColour       ( perso, eyeColour       );
        setGender          ( perso, gender          );
        setHairColour      ( perso, hairColour      );
        setWizard          ( perso, wizard          );
    }
    else {
        printf( "\n%s\n", "ERROR: Unable to inicialize the \'Personagem\'." );
    } // end if
} // end init_Personagem ( )

/**
 *  Função para clonar um Personagem.
*/
Personagem* clone( Personagem *perso )
{
    Personagem *copy = new_Personagem( );
    if( exist_Personagem ( perso ) && exist_Personagem( copy ) )
    {
        init_Personagem(copy,
                        getId              ( perso ),
                        getName            ( perso ),
                        getAlternateNames  ( perso ),
                        getHouse           ( perso ),
                        getAncestry        ( perso ),
                        getSpecies         ( perso ),
                        getPatronus        ( perso ),
                        getHogwartsStaff   ( perso ),
                        getHogwartsStudent ( perso ),
                        getActorName       ( perso ),
                        getAlive           ( perso ),
                        getAlternateActors ( perso ),
                        getDateOfBirth     ( perso ),
                        getYearOfBirth     ( perso ),
                        getEyeColour       ( perso ),
                        getGender          ( perso ),
                        getHairColour      ( perso ),
                        getWizard          ( perso )  );
    } 
    else {
        printf( "\n%s\n", "ERROR: Unable to clone the \'Personagem\'." );    
    }// end if
    return ( copy );
} // end clone ( )

/**
 *  Função para imprimir um Personagem.
*/
void imprimir ( Personagem *perso )
{
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
            getId              ( perso ),
            getName            ( perso ),
            getAlternateNames  ( perso ),
            getHouse           ( perso ),
            getAncestry        ( perso ),
            getSpecies         ( perso ),
            getPatronus        ( perso ),
            getHogwartsStaff   ( perso ) ? "true" : "false",
            getHogwartsStudent ( perso ) ? "true" : "false",
            getActorName       ( perso ),
            getAlive           ( perso ) ? "true" : "false",
            getDateOfBirth     ( perso ),
            getYearOfBirth     ( perso ),
            getEyeColour       ( perso ),
            getGender          ( perso ),
            getHairColour      ( perso ),
            getWizard          ( perso ) ? "true" : "false" ); 
} // end imprimir ( )

/**
 *  Função para imprimir um Personagem.
*/
void imprimir2 ( int id, Personagem *perso )
{
    printf( "[%d ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
            id                          ,
            getId              ( perso ),
            getName            ( perso ),
            getAlternateNames  ( perso ),
            getHouse           ( perso ),
            getAncestry        ( perso ),
            getSpecies         ( perso ),
            getPatronus        ( perso ),
            getHogwartsStaff   ( perso ) ? "true" : "false",
            getHogwartsStudent ( perso ) ? "true" : "false",
            getActorName       ( perso ),
            getAlive           ( perso ) ? "true" : "false",
            getDateOfBirth     ( perso ),
            getYearOfBirth     ( perso ),
            getEyeColour       ( perso ),
            getGender          ( perso ),
            getHairColour      ( perso ),
            getWizard          ( perso ) ? "true" : "false" ); 
} // end imprimir ( )

/**
 *  Função para tratamento das cadeia de caracteres "booleana"
*/
char* tratamentoBool( char* strbool )
{
    char* tratada = strbool;
    tratada[strcspn(tratada,"\n")] = '\0';
    tratada[strcspn(tratada,"\r")] = '\0';
    return ( tratada );
} // end tratamentoBool ( )

/**
 *  Função para tratamento da formatação da Data.
*/
char* tratamentoData( char* dateOfBirth )
{
    char *tratada = dateOfBirth;
    int len = strlen( dateOfBirth );
    if( len < 10 )
    {
        tratada = (char*) calloc ( 11, sizeof(char) );
        strcpy( tratada, dateOfBirth );
        for( int x = len; x > 3; x = x - 1 )
        {
            tratada[x] = tratada[x-1];
        }
        tratada[3] = '0';
    } // end if
    return ( tratada );
} // end tratamentoData ( )

/**
 *  Função para ler os personagens de um arquivo.
*/
Personagem* ler( char* filename, char* id_procurado ) 
{
    Personagem *perso = new_Personagem( );
    FILE* file = fopen( filename, "rt" );

    if( file == NULL || !exist_Personagem( perso ) ) {
        printf( "\n%s\n", "ERROR: Unable to read.");
    }
    else
    {
        char line[500];
        bool idFound = false;

        // Ignora a linha de cabeçalho
        fgets( line, sizeof(line), file );
        // Lê as demais linhas do arquivo
        while( fgets( line, sizeof(line), file ) != NULL && !idFound ) 
        {
            char* token = strtok( line, ";" );
            char *atributos[18];
            int index = 0;
            while( token != NULL ) 
            {
                atributos[index++] = strdup( token );
                token = strtok( NULL, ";" );
            } // end while

            // Tratamento do atributo 'alternateNames'
            char temp[500] = {0};
            int pos = 0;
            int len = strlen( atributos[2] );
            for( int x = 0; x < len; x = x + 1 ) 
            {
                if( atributos[2][x] == '[' ) {
                    temp[pos] = '{';
                } else if( atributos[2][x] == ']' ) {
                    temp[pos] = '}';
                } else if( atributos[2][x] == '\'' ) {
                    continue; 
                } else {
                    temp[pos] = atributos[2][x];
                }
                pos++; 
            }
            temp[pos] = '\0'; 
            // Desalocar o atributo 'alternateNames' e atribuir a string tratada
            free( atributos[2] ) ; atributos[2] = strdup(temp);

            // Verificar se os atributos são iguais
            if( strcmp(atributos[0], id_procurado) == 0 ) 
            {
                idFound = true;
                // inicializar o Personagem com os dados lidos
                if( index < 18 )
                {
                    if( index > 16 ) 
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(atributos[6], "VERDADEIRO") == 0,
                                 strcmp(atributos[7], "VERDADEIRO") == 0,
                                        atributos[8], 
                                 strcmp(atributos[9], "VERDADEIRO") == 0,
                                        atributos[10], 
                         tratamentoData(atributos[11]),
                                   atoi(atributos[12]), 
                                        atributos[13], atributos[14],atributos[15], 
                                 strcmp(tratamentoBool(atributos[16]), "VERDADEIRO") == 0 );
                    } 
                    else
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(atributos[6], "VERDADEIRO") == 0,
                                 strcmp(atributos[7], "VERDADEIRO") == 0, "", 
                                 strcmp(atributos[8], "VERDADEIRO") == 0,
                                        atributos[9],
                         tratamentoData(atributos[10]),
                                   atoi(atributos[11]), atributos[12], 
                                        atributos[13],atributos[14], 
                                 strcmp(tratamentoBool(atributos[15]), "VERDADEIRO") == 0 );
                    } // end if
                }
                else
                {
                    init_Personagem(perso,
                                    atributos[0], atributos[1], atributos[2], atributos[3],
                                    atributos[4], atributos[5], atributos[6],
                             strcmp(atributos[7], "VERDADEIRO") == 0,
                             strcmp(atributos[8], "VERDADEIRO") == 0,
                                    atributos[9], 
                             strcmp(atributos[10], "VERDADEIRO") == 0,
                                    atributos[11], 
                     tratamentoData(atributos[12]),
                               atoi(atributos[13]), 
                                    atributos[14], atributos[15],
                                    atributos[16], 
                             strcmp(tratamentoBool(atributos[17]), "VERDADEIRO") == 0 );
                } // end if
            } // end if
            // Libera memória alocada para atributos
            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            } // end for
        } // end while 
        fclose(file);
    } // end if
    return ( perso );
} // end ler ( )

// ---------------------------------- Struct Lista Sequencial

typedef struct s_Lista
{
    Personagem** perso;
    int tamanho;
    int MAXTAM;
} Lista;

// ---------------------------------- Funções - Lista Sequencial

Lista* new_Lista ( int tamanho )
{
    Lista* lista = (Lista*) malloc( sizeof(Lista) );
    if( lista != NULL )
    {
        if( tamanho > 0 )
        {
            lista->perso = (Personagem**) malloc ( tamanho * sizeof(Personagem*) );
            lista->tamanho = 0;
        } // end if
    } // end if
    lista->MAXTAM = 405;
    return( lista );
} // end new_Lista ( )

void delete_Lista ( Lista* lista )
{
    if( lista != NULL )
    {
        if( lista->perso != NULL )
        {
            for( int i = 0; i < lista->tamanho; i = i + 1 ) 
            {
                delete_Personagem( lista->perso[i] ); 
            } // end for
        } // end if
        free( lista->perso ); lista->perso = NULL;
        free( lista ); lista = NULL;
    } // end if
} // end delete_Lista ( )

void inserirFim ( Lista* lista, Personagem* perso )
{
    if( lista->tamanho >= lista->MAXTAM ) {
        printf( "\n%s\n", "ERRO: Nao foi possivel inserir (fim)!" );
        exit( 1 );
    } // end if
    lista->perso[lista->tamanho] = perso;
    lista->tamanho++;
} // end inserirFim ( )

void inserirInicio ( Lista* lista, Personagem* perso )
{
    if( lista->tamanho >= lista->MAXTAM ) {
        printf ( "\n%s\n", "ERRO: Nao foi possivel inserir (inicio)!");
        exit( 1 );
    } // end if
    for( int i = lista->tamanho; i > 0; i = i - 1 )
    {
        lista->perso[i] = lista->perso[i-1];
    } // end for
    lista->perso[0] = perso;
    lista->tamanho++;
} // end inserirInicio ( )

Personagem* removerInicio( Lista* lista ) 
{
    if( lista->tamanho == 0 ) {
        printf( "\n%s\n", "ERRO: Lista Vazia!" );
        exit( 1 );
    } // end if
    Personagem* resp = lista->perso[0];
    lista->tamanho--;
    for( int i = 0; i < lista->tamanho; i = i + 1 ) {
        lista->perso[i] = lista->perso[i+1];
    } // end for
    return ( resp );
} // end removerInicio ( )

Personagem* removerFim ( Lista* lista )
{
    if( lista->tamanho == 0 ) {
        printf( "\n%s\n", "ERRO: Lista Vazia!" );
        exit( 1 );
    } // end if
    return ( lista->perso[--lista->tamanho] );
} // end removerFim ( )

void inserir ( Lista* lista, Personagem* perso, int index ) 
{
    if( lista->tamanho >= lista->MAXTAM || index < 0 || index > lista->tamanho ) {
        printf( "\n%s\n", "ERRRO: Nao foi possivel inserir!");
        exit( 1 );
    } // end if
    for( int i = lista->tamanho; i > index; i = i - 1 ) {
        lista->perso[i] = lista->perso[i-1];
    } // end for
    lista->perso[index] = perso;
    lista->tamanho++;
} // end inserir ( )

Personagem* remover( Lista* lista, int index ) 
{
    if( lista->tamanho == 0 || index < 0 || index >= lista->tamanho ) {
        printf( "\n%s\n", "Erro ao remover!");
    } // end if
    Personagem* resp = lista->perso[index];
    lista->tamanho--;
    for( int i = index; i < lista->tamanho; i = i + 1 )
    {
        lista->perso[i] = lista->perso[i+1];
    } // end for
    return ( resp );
} // end remover ( )

void mostrar ( Lista* lista )
{
    for( int i = 0; i < lista->tamanho; i = i + 1 )
    {
        imprimir2( i, lista->perso[i] );
    } // end for ( )
} // end mostrar ( )

/**
 *  Função Principal.
*/
int main ( void )
{
    setlocale( LC_CTYPE, "UTF-8" ); // setCharset

    Lista* lista = new_Lista( 405 );
    Personagem* perso = NULL;

    char id [81] = { '\0' };
    char* filename = "/tmp/characters.csv"; 
    int numOp = 0;
    
    scanf( "%s", id ); getchar( );
    while( strcmp( id,"FIM" ) != 0 )
    {
        inserirFim( lista, ler( filename, id ) );
        scanf( "%80s", id ); getchar( );
    } // end while

    // fazer a leitura dos metodos
    scanf( "%d", &numOp ); getchar( );
    for ( int i = 0; i < numOp; i = i + 1 ) 
    {
        char input[81];
        scanf( "%s", input );

        if( strcmp(input, "II") == 0 ) 
        {
            scanf( "%s", id );
            perso = ler( filename, id );
            inserirInicio( lista, perso );
        }
        else if( strcmp(input, "IF") == 0 ) 
        {
            scanf( "%s", id );
            perso = ler( filename, id );
            inserirFim( lista, perso );
        }
        else if( strcmp(input, "I*") == 0 ) 
        {
            int index = 0;
            scanf( "%d %s", &index, id );
            perso = ler( filename, id );
            inserir( lista, perso, index );
        }
        else if( strcmp(input, "RI") == 0 ) 
        {
            perso = removerInicio( lista );
            printf( "(R) %s\n", getName( perso ) );
        }
        else if( strcmp(input, "RF") == 0 ) 
        {
            perso = removerFim( lista );
            printf( "(R) %s\n", getName( perso ) );
        }
        else if( strcmp(input, "R*") == 0 ) 
        {
            int index = 0;
            scanf( "%d", &index );
            perso = remover( lista, index );
            printf( "(R) %s\n", getName( perso ) );
        } // end if
    } // end for
    mostrar( lista );

    delete_Lista( lista );
    
    return ( 0 );
} // end main ( )
