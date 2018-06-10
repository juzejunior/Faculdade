package comando;

import banco.CopaDoMundoBanco;

public class Listar extends Comando {

    public Listar(String nome) { super(nome); }

    @Override
    public String resolver() {
        String retorno = "";
        CopaDoMundoBanco banco = CopaDoMundoBanco.getInstance();
        System.out.println(banco.listar(nome));
        return retorno;
    }

}
