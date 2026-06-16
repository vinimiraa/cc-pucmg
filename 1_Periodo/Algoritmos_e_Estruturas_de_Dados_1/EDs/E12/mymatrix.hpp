/*
    mymatrix.hpp  - v0.0. - 06 / 11 / 2023
    Author: Vinicius Miranda de Araujo

 */

// ----------------------------------------------- definicoes globais

#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

#include <cstdlib>
#include <time.h>

template <typename T>
class Matrix
{
private: // area reservada
    T optional;
    int rows;
    int columns;
    T **data;

public: // area aberta
    Matrix(void)
    {
        // definir valores iniciais
        this->rows = 0;
        this->columns = 0;
        // sem reservar area
        data = nullptr;
    } // end constructor

    Matrix(int rows, int columns, T initial)
    {
        // definir dado local
        bool OK = true;
        // definir valores iniciais
        this->optional = initial;
        this->rows = rows;
        this->columns = columns;
        // reservar area
        data = new T *[rows];
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] != nullptr);
            } // end for
            if (!OK)
            {
                data = nullptr;
            } // end if
        }     // end if
    }         // end constructor

    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete (data[x]);
            } // end for
            delete (data);
            data = nullptr;
        } // end if
    }     // end destructor ( )

    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        } // end if
    }     // end set ( )

    void setRows( int rows )
    {
        this->rows = rows;
    }

    void setColumns( int columns )
    {
        this->columns = columns;
    }

    T get(int row, int column)
    {
        T value = optional;
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        } // end if
        return (value);
    } // end get ( )

    int getRows()
    {
        return (rows);
    } // end getRows ( )

    int getColumns()
    {
        return (columns);
    } // end getColumns ( )

    void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )

    void read()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", "
                    << setw(2) << y << " : ";
                cin >> data[x][y];
            } // end for
        }     // end for
        cout << endl;
    } // end read ( )

    // grava linha, coluna e os valores
    void fprint(string fileName)
    {
        ofstream afile;

        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        }     // end for
        afile.close();
    } // end fprint ( )

    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;

        afile.open(fileName);
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        }
        else
        {
            // guardar a quantidade de dados
            rows = m;
            columns = n;
            // reservar area
            data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
            } // end for
              // ler dados
            for (int x = 0; x < rows; x = x + 1)
            {
                for (int y = 0; y < columns; y = y + 1)
                {
                    afile >> data[x][y];
                } // end for
            }     // end for
        }         // end if
        afile.close();
    } // end fread ( )

    bool isZeros()
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (rows > 0 && columns > 0)
        {
            result = true;
            while (x < rows && result)
            {
                y = 0;
                while (y < columns && result)
                {
                    result = result && (data[x][y] == 0);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        }     // end if
        return (result);
    } // end isZeros ( )

    Matrix &operator=(const Matrix<T> &other)
    {
        if (other.rows == 0 || other.columns == 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            this->rows = other.rows;
            this->columns = other.columns;
            this->data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                this->data[x] = new T[columns];
            } // end for
            for (int x = 0; x < this->rows; x = x + 1)
            {
                for (int y = 0; y < this->columns; y = y + 1)
                {
                    data[x][y] = other.data[x][y];
                } // end for
            }     // end for
        }         // end if
        return (*this);
    } // end operator= ( )

    bool operator!=(const Matrix<T> &other)
    {
        bool result = false;
        int x = 0;
        int y = 0;

        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            x = 0;
            while (x < rows && !result)
            {
                y = 0;
                while (y < columns && !result)
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        }     // end if
        return (result);
    } // end operator!= ( )

    Matrix &operator-(const Matrix<T> &other)
    {
        static Matrix<T> result(1, 1, 0);
        int x = 0;
        int y = 0;

        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];
            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            } // end for

            for (int x = 0; x < result.rows; x = x + 1)
            {
                for (int y = 0; y < result.columns; y = y + 1)
                {
                    result.data[x][y] = data[x][y] - other.data[x][y];
                } // end for
            }     // end for
        }         // end if
        return (result);
    } // end operator- ( )

    Matrix &operator*(const Matrix<T> &other)
    {
        static Matrix<T> result(1, 1, 0);
        int x = 0;
        int y = 0;
        int z = 0;
        int sum = 0;

        if (rows <= 0 || columns == 0 ||
            other.rows <= 0 || other.columns == 0 ||
            columns != other.rows)
        {
            cout << endl << "ERROR: Invalid data." << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];
            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            } // end for

            for (x = 0; x < result.rows; x = x + 1)
            {
                for (y = 0; y < result.columns; y = y + 1)
                {
                    sum = 0;
                    for (z = 0; z < columns; z = z + 1)
                    {
                        sum = sum + data[x][z] * other.data[z][y];
                    } // end for
                    result.data[x][y] = sum;
                } // end for
            }     // end for
        }         // end if
        return (result);
    } // end operator* ( )

    void free()
    {
        if (data != nullptr)
        {
            delete (data);
            data = nullptr;
        } // end if
    } // end free ( )

    void randomIntGenerate( int inferior, int superior )
    {
        srand( time( 0 ) );
        int x = 0;
        int y = 0;
        int z = 0;
        
        for( x = 0; x < rows; x = x + 1 )
        {
            for( y = 0; y < columns; y = y + 1 )
            {
                z = (rand() % (superior - inferior + 1)) + inferior;
                data[x][y] = z;
            } // end for
        } // end for
    } // end randomIntGenerate ( )

    // grava a quantidade total e os valores
    void fprint_b(string fileName)
    {
        ofstream afile;

        afile.open(fileName);
        afile << rows*columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        }     // end for
        afile.close();
    } // end fprint_b ( )

    Matrix scalar( int k )
    {
        Matrix<T> aux( this->rows, this->columns, 0);

        for  (int x = 0; x < aux.rows; x = x + 1 )
        {
            for ( int y = 0; y < aux.columns; y = y + 1 )
            {
                aux.set( x, y, this->get( x, y ) * k) ;
                // aux.data[x][y] = this->data[x][y] * k;
            }
        }

        return ( aux );
    }

    bool identidade( )
    {
        bool result = true;
        int x = 0;
        int y = 0;

        /*
        for( int x = 0; x < this->rows; x = x + 1 )
        {
            for( int y = 0; y < this->columns; y = y + 1 )
            {
                if( x == y && this->data[x][y] == 1 )
                {
                    if( x != y && this->data[x][y] == 0 )
                    {
                        result = true;
                    } // end if
                } // end if
            } // end for
        } // end for
        */
        if( rows != columns )
        {
            result = false;
        }
        else
        {
            x = 0;
            while( x < rows )
            {
                y = 0;
                while( y < columns )
                {
                    if( x == y && data[x][y] != 1)
                    {   
                        result = false;     
                    }
                    else if ( x != y && data[x][y] != 0 )
                    {
                        result = false;
                    } // end if
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if

        return ( result );
    } // end identidade ( )

    bool operator== (const Matrix<T> &other)
    {
        bool result = true;
        int x = 0;
        int y = 0;

        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            result = false;
        }
        else
        {
            x = 0;
            while ( x < rows )
            {
                y = 0;
                while ( y < columns )
                {
                    if ( data[x][y] != other.data[x][y] )
                    {
                        result = false;
                    }
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        }     // end if
        return (result);
    } // end operator== ( )

    Matrix add( const Matrix<T> &other )
    {
        Matrix<T> result( rows, columns, 0 );
        if( rows != other.rows || columns != other.columns )
        {
            cout << endl << "ERROR: Invalid size." << endl;
        }
        else
        {
            result.rows = rows;
            result.columns = columns;
            for( int x = 0; x < result.rows ; x = x + 1 )
            {
                for( int y = 0; y < result.columns; y = y + 1 )
                {
                    result.data[x][y] = data[x][y] + other.data[x][y];
                } // end for
            }  // end for
        } // end if
        return ( result );
    } // end add ( )

    void addRows( int row1, int row2, T k )
    {
        int x = 0;
        for( x = 0; x < columns; x = x + 1 )
        {
            data[row1][x] = (data[row1][x] + data[row2][x]) * k;
        } // end for
    } // end addRows ( )

    void subtractRows( int row1, int row2, T k )
    {
        int x = 0;
        for( x = 0; x < columns; x = x + 1 )
        {
            data[row1][x] = (data[row1][x] - data[row2][x]) * k;
        } // end for
    } // end subtractRows ( )

    bool searchValue( int value )
    {
        bool result = false;
        int x = 0;
        int y = 0;
        /*
        for( x = ; x < rows; x = x + 1 )
        {
            for( y = 0; y < columns; y = y + 1 )
            {
                if( data[x][y] == value )
                {
                    result = true;  
                }
            }
        }
        */
        x = 0;
        while( x < rows && !result)
        {
            y = 0;
            while( y < columns  && !result)
            {
                if( data[x][y] == value )
                {
                    result = true;
                } // end if
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while
        return ( result );
    } // end searchValue ( )

    int searchRows( int value )
    {
        int result = 0;
        int x = 0;
        int y = 0;
        x = 0;
        while( x < rows && !result)
        {
            y = 0;
            while( y < columns  && !result)
            {
                if( data[x][y] == value )
                {
                    result = x;
                } // end if
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while
        return ( result );
    } // end searchRows ( )

    int searchColumns( int value )
    {
        int result = 0;
        int x = 0;
        int y = 0;
        x = 0;
        while( x < rows && !result)
        {
            y = 0;
            while( y < columns  && !result)
            {
                if( data[x][y] == value )
                {
                    result = y;
                } // end if
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while
        return ( result );
    } // end searchColumns ( )

    void transpose(Matrix<T> &result)
    {
        result.setRows(columns);
        result.setColumns(rows);
    
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                //         row col   value
                result.set( y, x, data[x][y] );
            }
        }
    } // end transpose ( )

    void transpose_a( )
    {
        for (int x = 0; x < columns; x++)
        {
            for (int y = 0; y < rows; y++)
            {
                data[x][y] = data[y][x];
            } // end for
        } // end for
    } // end transpose_a ( )

    bool isNormal( )
    {
        bool result = true;

        if( rows != columns )
        {
            result = false;
        }
        else
        {
            for( int x = 0; x < rows - 1; x = x + 1 )
            {
                for( int y = 0; y < columns - 1; y = y + 1 )
                {
                    if( !(data[x][y] < data[x][y + 1] && data[x][y] < data[x + 1][y]) )
                    {
                        result = false;
                    } // end if
                } // end for
            } // end for
        } // end if

        return ( result ); 
    } // end isNormal ( )

}; // end class

#endif