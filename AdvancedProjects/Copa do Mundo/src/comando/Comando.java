package comando;

public abstract class Comando {
    protected String nome;

    protected Comando(String nome) { this.nome = nome; }

    public abstract String resolver();
}
