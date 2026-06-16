/*
REGISTRO HASH EXTENSÍVEL

Esta interface apresenta os métodos que os objetos
a serem incluídos na tabela hash extensível devem 
conter.

Implementado pelo Prof. Marcos Kutova
v1.1 - 2021
*/
package interfaces;

import java.io.IOException;

/**
 *  RegistroHashExtensivel: Interface que representa um registro a ser inserido na tabela hash extensível.
 */
public interface RegistroHashExtensivel<T> {

    public int hashCode( ); // chave numérica para ser usada no diretório

    public short size( ); // tamanho FIXO do registro

    public byte[] toByteArray( ) throws IOException; // representação do elemento em um vetor de bytes
    
    public void fromByteArray( byte[] ba ) throws IOException; // vetor de bytes a ser usado na construção do elemento

} // end interface RegistroHashExtensivel
