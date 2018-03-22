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
public abstract class MemoriaS {
    
    public static final int BYTE = 0;
    public static final int KB = 1;
    public static final int MB = 2;
    public static final int GB = 3;
    
    protected double total, utilizadoKB;
    protected int unidade;
    
    public MemoriaS(int newTotal, int newUnidade) {
        this.total = newTotal;
        this.unidade = newUnidade;
        this.utilizadoKB = 0;
    }
    
    public MemoriaS(int newTotal) {
      this(newTotal, KB);
    }
    
    public abstract double getPerda();
    protected abstract double getEspacoDisponivelRealKB();
    
    public double getEspacoDisponivelKB() {
        return getConverteKB(this.total) - utilizadoKB;
    }
    
    public boolean gravaKB(int newTamanho) {
        if (getEspacoDisponivelRealKB() >= getConverteKB(newTamanho)) {
            utilizadoKB += getConverteKB(newTamanho);
            return true;
        }
        return false;
    }
    
    public double getConverteKB(double valor) {
       switch(unidade) {
           case MB:
               return valor * 1024;
           case BYTE:
               return valor / 1024; 
           case GB:
               return (valor * 1024) * 1024;
           default:
               return valor;
       } 
    }
    
    public String getUnidade() {
        switch(unidade) {
            case BYTE:
                return "BYTE";
            case GB:
                return "GB";
            case MB:
                return "MB";
            default:
                return "KB";
        }
    }
    
    public double getPercentualDisponível() {
        return (getEspacoDisponivelRealKB() * 100) / getConverteKB(total);
    }
    
    @Override
    public String toString() {
       return "Percentual disponível "+getPercentualDisponível() + "% Espaço Total "
               +getConverteKB(total)+ "KB Espaço Disponível Real "+getEspacoDisponivelRealKB()+"KB Perda "+getPerda()*100+"%";
    }
}
