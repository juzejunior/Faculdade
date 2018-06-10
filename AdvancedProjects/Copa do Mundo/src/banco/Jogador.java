package banco;

public class Jogador {

    private String nome;
    private int idade;
    private String posicao;

    public Jogador(String nome, int idade, String posicao) {
        this.nome = nome;
        this.idade = idade;
        this.posicao = posicao;
    }

    public String getNome() { return nome; }

    public void setNome(String nome) { this.nome = nome; }

    public int getIdade() { return idade; }

    public void setIdade(int idade) { this.idade = idade; }

    public String getPosicao() { return posicao; }

    public void setPosicao(String posicao) { this.posicao = posicao; }

    @Override
    public String toString() {
        return "Jogador{" +
                "nome='" + nome + '\'' +
                ", idade=" + idade +
                ", posicao='" + posicao + '\'' +
                '}';
    }
}
