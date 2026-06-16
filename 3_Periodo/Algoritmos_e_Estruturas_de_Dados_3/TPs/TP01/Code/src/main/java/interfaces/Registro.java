package interfaces;

import java.io.IOException;

/**
 * Registro: Interface que define os métodos que devem ser implementados por uma classe que deseja ser um registro.
 */
public interface Registro {
    public void setId ( int i );

    public int getId ( );

    public byte[] toByteArray ( ) throws IOException;

    public void fromByteArray ( byte[] b ) throws IOException;
} // end interface Registro
