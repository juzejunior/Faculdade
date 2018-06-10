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

    public String listar(String nome){

        String retorno = "";
        for(int i = 0; i < listaJogador.size(); i++){
            if(listaJogador.get(i).getNome().equals(nome)) retorno += listaJogador.get(i).toString();

        }
        return retorno;
    }

}
