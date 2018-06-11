package banco;

import java.util.ArrayList;

public class CopaDoMundoBanco {

    private static CopaDoMundoBanco instance = null;

    private ArrayList<Jogador> listaJogador = new ArrayList<Jogador>();

    public CopaDoMundoBanco() {
        Jogador jogador1 = new Jogador("Neymar",25, "Atacante");
        Jogador jogador2 = new Jogador("Marcelo",28, "Defensor");

        listaJogador.add(jogador1);
        listaJogador.add(jogador2);
    }

    public static CopaDoMundoBanco getInstance(){
        if (instance == null) instance = new CopaDoMundoBanco();
        return instance;
    }

    public String cadastrar(Jogador jogador){
        String retorno = "";
        listaJogador.add(jogador);
        retorno = jogador.toString();
        return retorno;
    }

    public String listar(String nome){
        String retorno = "";
        for (Jogador jogador : listaJogador)
            if (jogador.getNome().equals(nome)) retorno += jogador.toString();
        return retorno;
    }

    public String excluir(String nome){
        String retorno = "";
        for (Jogador jogador : listaJogador) {
            if (jogador.getNome().equals(nome)) {
                listaJogador.remove(jogador);
                retorno += jogador.toString();
            }
        }
        return retorno;
    }

}
