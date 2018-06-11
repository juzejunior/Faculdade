package comando;

import banco.CopaDoMundoBanco;

public class Excluir extends Comando {

    public Excluir(String nome) { super(nome); }

    @Override
    public String resolver() {
        String retorno = "";
        CopaDoMundoBanco banco = CopaDoMundoBanco.getInstance();
        String jogador = banco.excluir(nome);
        if (jogador.equals("")) System.err.println("Não foi possível excluir o Jogador");
        else System.out.println(jogador);
        return retorno;
    }

}
