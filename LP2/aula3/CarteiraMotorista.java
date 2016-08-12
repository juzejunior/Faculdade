package aula3;

import java.util.Calendar;

/**
 * Created by diogo on 24/07/16.
 */
public class CarteiraMotorista {

    private int numero;
    private int cpf;
    private int pontos;
    private String tipo;
    private String situacao;
    private Data validade;
    private Data expedicao;


    public CarteiraMotorista(Data expedicao){
        pontos = 0;
        situacao = "Válida";
        this.expedicao = expedicao;
        this.validade = expedicao;
        this.validade.setAno(this.validade.getAno()+5);
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public int getCpf() {
        return cpf;
    }

    public void setCpf(int cpf) {
        this.cpf = cpf;
    }

    public int getPontos() {
        return pontos;
    }

    public void setPontos(int pontos) {
        this.pontos = pontos;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getSituacao() {
        return situacao;
    }

    public void setSituacao(String situacao) {
        this.situacao = situacao;
    }

    public Data getValidade() {
        return validade;
    }

    public void setValidade(Data validade) {
        this.validade = validade;
    }

    public Data getExpedicao() {
        return expedicao;
    }

    public void setExpedicao(Data expedicao) {
        this.expedicao = expedicao;
    }

    public void acrescentarPontos(int pontos){
        this.pontos+= pontos;
        if(this.pontos > 20){
            apreenderCarteira();
        }
    }

    public int consultarPontos(){
         return pontos;
    }

    public void zerarCarteira(){
        pontos = 0;
    }

    public void apreenderCarteira(){
        situacao = "Apreendida";
    }

    public boolean estaValida(){
        return situacao.equals("Válida");
    }

}
