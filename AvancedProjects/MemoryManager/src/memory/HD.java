/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package memory;

/**
 *
 * @author jose
 */
public class HD extends MemoriaS {

    private String numeroSerie;
    
    public HD(String newNumeroSerie, int newTotal, int newUnidade) {
        super(newTotal, newUnidade);
        this.numeroSerie = newNumeroSerie;
    }

    @Override
    public double getPerda() {
        return this.getConverteKB(this.total) / 10240 / 100;
    }

    @Override
    protected double getEspacoDisponivelRealKB() {
        return getEspacoDisponivelKB() * (1 - getPerda());
    }

    public String getNumeroSerie() {
        return numeroSerie;
    }

     @Override
    public String toString() {
       return "Percentual disponível "+getPercentualDisponível() + "% Espaço Total "
               +getConverteKB(total)+ "KB Espaço Disponível Real "+getEspacoDisponivelRealKB()+"KB Perda "+getPerda()*100+"%";
    }
    
    public void exibirNumeroSerialEValorDePerda() {
       System.out.println("Nº Série: "+getNumeroSerie() +" Perda: "+ getPerda()*100 + "%.");
    }
    
}
