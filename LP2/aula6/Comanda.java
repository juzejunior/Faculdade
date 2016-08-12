import java.util.Calendar;

/**
 * Created by diogo on 31/07/16.
 */
public class Comanda {

    private int num;
    private Calendar data;
    private int quantComida;
    private int quantBebida;
    private int quantSobremesa;
    private String formaPagamento;

    public Comanda(int num) {
        this.num = num;
        this.data = Calendar.getInstance();
        setQuantSobremesa(0);
        setQuantBebida(0);
        setQuantComida(0);
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getQuantComida() {
        return quantComida;
    }

    public boolean setQuantComida(int quantComida) {
        if(quantComida < 0) return false;
        this.quantComida = quantComida;
        return true;
    }

    public int getQuantBebida() {
        return quantBebida;
    }

    public boolean setQuantBebida(int quantBebida) {
        if(quantBebida < 0) return false;
        else this.quantBebida = quantBebida;
        return true;
    }

    public int getQuantSobremesa() {
        return quantSobremesa;
    }

    public boolean setQuantSobremesa(int quantSobremesa) {
        if(quantBebida < 0) return false;
        this.quantSobremesa = quantSobremesa;
        return  true;
    }

    public String getFormaPagamento() {
        return formaPagamento;
    }

    public void setFormaPagamento(String formaPagamento) {
        this.formaPagamento = formaPagamento;
    }

    public String getData(){
        return data.get(Calendar.DAY_OF_MONTH)+"/"+data.get(Calendar.DAY_OF_MONTH)+1+"/"+data.get(Calendar.YEAR);
    }
    
    private double totalConta(int quantComida, int quantBebida, int quantSobremesa){
        double total;
        if(setQuantComida(quantComida) && setQuantBebida(quantBebida) && setQuantSobremesa(quantSobremesa)){
            total = 30*getQuantComida() + 3.50*getQuantSobremesa() + 2*getQuantBebida();
        }else {
            System.out.println("Há erros relacionados a quantidade dos alimentos!");
            total = 0.0;
        }
        return desconto(total);
    }

    public double desconto(double total){
        if(getFormaPagamento().toLowerCase().equals("dinheiro")){
            return total-total*0.10;
        }else if(getFormaPagamento().toLowerCase().equals("debito")){
            return total-total*0.05;
        }
        return total;
    }
}
