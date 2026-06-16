import aed3.*;

public class ArquivoCategoria extends aed3.Arquivo<Categoria> {

    Arquivo<Categoria> arqCategorias;

    public ArquivoCategoria() throws Exception {
        super("categorias", Categoria.class.getConstructor());
    }

}
