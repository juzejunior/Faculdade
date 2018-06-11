package comando;

import banco.CopaDoMundoBanco;

public class Listar extends Comando {

    public Listar(String nome) { super(nome); }

    @Override
    public String resolver() {
        String retorno = "";
        CopaDoMundoBanco banco = CopaDoMundoBanco.getInstance();
        String jogador = banco.listar(nome);
        if (jogador.equals("")) System.err.println("Não foi possível encontrar o Jogador");
        else System.out.println(jogador);
        return retorno;
    }

}
