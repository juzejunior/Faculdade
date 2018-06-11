package comando;

import banco.CopaDoMundoBanco;
import banco.Jogador;

public class Cadastrar extends Comando {

    private Jogador jogador;

    public Cadastrar(String nome, int idade, String posicao){
        super(nome);
        jogador = new Jogador(nome, idade, posicao);
    }

    @Override
    public String resolver() {
        String retorno = "";
        CopaDoMundoBanco banco = CopaDoMundoBanco.getInstance();
        String jogadorString = banco.cadastrar(jogador);
        if (jogadorString.equals("")) System.err.println("Não foi possível cadastrar o Jogador");
        else System.out.println(jogadorString);
        return retorno;
    }

}
