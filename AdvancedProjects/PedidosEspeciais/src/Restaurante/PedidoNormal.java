package Restaurante;

import java.util.*;

public class PedidoNormal extends Pedido {
	
	public double getTotal(){
		double total=0;
		Iterator it = this.cItem.iterator();
		while (it.hasNext()){
			Item i =(Item) it.next();
			total =total + i.getTotalItem();
		}
		return total;
	}

	public String getTipoPedido(){
		return " normal"; 
	}

}
