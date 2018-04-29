import java.util.*;

public class PedidoNormal extends Pedido {
	
	public double getTotal(){
		double total=0;
		Iterator<?> it = this.cItem.iterator();
		while (it.hasNext()){
			Item i =(Item) it.next();
			total =total + i.getTotalItem();
		}
		return total;
	}

	public String getTipoPedido(){
		return " normal"; 
	}

	@Override
	public void update(double indice) {
		for(Item item : this.cItem) {
			item.setValorUnitario(item.getValorUnitario()*indice);
		}
	}

}
