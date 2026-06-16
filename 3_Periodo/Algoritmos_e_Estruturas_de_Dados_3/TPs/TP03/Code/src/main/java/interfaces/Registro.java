package interfaces;

import java.io.IOException;

/**
 *  Classe Registro
 * 
 *  <p>Interface que representa um registro.</p>
 *  <p>Define os métodos necessários para manipulação de registros.</p>
 */
public interface Registro 
{
    public void setId( int i );

    public int getId( );

    public byte[] toByteArray( ) throws IOException;

    public void fromByteArray( byte[] b ) throws IOException;
    
} // end interface Registro
