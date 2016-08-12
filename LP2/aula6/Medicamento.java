/**
 * Created by diogo on 31/07/16.
 */
public class Medicamento {
    private int codigo;
    private String nome;
    private String principioAtivo;
    private String fabricante;
    private Data validade;
    private double preco;

    public Medicamento(int codigo, String nome, String principioAtivo, String fabricante, Data validade, double preco) {
        setCodigo(codigo);
        setNome(nome);
        setPrincipioAtivo(principioAtivo);
        setFabricante(fabricante);
        setValidade(validade);
        setPreco(preco);
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPrincipioAtivo() {
        return principioAtivo;
    }

    public void setPrincipioAtivo(String principioAtivo) {
        this.principioAtivo = principioAtivo;
    }

    public String getFabricante() {
        return fabricante;
    }

    public void setFabricante(String fabricante) {
        this.fabricante = fabricante;
    }

    public String getValidade() {
        return validade.dia+"/"+validade.mes+"/"+validade.ano;
    }

    public void setValidade(Data validade) {
        this.validade = validade;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        if(preco > 0)
            this.preco = preco+preco*0.30;
    }

    public void imprimirDados(){
        System.out.println("Codigo:"+getCodigo()+"  Nome: "+getNome());
        System.out.println("PA:"+getPrincipioAtivo()+"  Fabricante: "+getFabricante());
        System.out.println("Validade:"+getValidade()+"  Preço R$: "+getPreco());

    }

}
