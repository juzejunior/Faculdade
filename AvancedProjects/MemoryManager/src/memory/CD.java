package memory;

/**
 *
 * @author jose
 */
public class CD extends MemoriaS {

    private static final int ABERTO = 0;
    private static final int FECHADO = 1;
    
    private int estado;
    
    public CD(int newTotal, int newUnidade) {
        super(newTotal, newUnidade);
        estado = ABERTO;
    }

    @Override
    public double getPerda() {
        return 0.98;
    }

    @Override
    protected double getEspacoDisponivelRealKB() {
        return getEspacoDisponivelKB() * getPerda();
    }
    
    @Override
     public boolean gravaKB(int newTamanho) {
       if (estado == ABERTO) {
           return super.gravaKB(newTamanho);
       }
       return false;
    }
 
    public String getEstado() {
        return (estado == ABERTO) ? "ABERTO" : "FECHADO"; 
    }
    
    @Override
    public String toString() {
       return "Percentual disponível "+getPercentualDisponível()*100 + "% Espaço Total "
               +getConverteKB(total)+ "KB Espaço Disponível Real "+getEspacoDisponivelRealKB()+"KB Perda "+getPerda()*100+"%";
    }
    
    public void exibirEstado() {
        System.out.println("Estado do CD: "+this.getEstado());
    }
}
