package Restaurante;

import java.util.*;
public class ColecaoPedidos {
	
	private Map cPedido = new HashMap();
	
	public Map getcPedido() {
		return cPedido;
	}
        
	public void setcPedido(Map cPedido) {
		this.cPedido = cPedido;
	}
        
	public boolean adicionaPedido(Pedido p){
		if (!this.cPedido.containsKey(p.getId())){
			this.cPedido.put(p.getId(), p);
			return true;
		}else{
			return false;
		}
	}
        
	public boolean removePedido(Integer id){
		if (this.cPedido.containsKey(id)){
			this.cPedido.remove(id);
			return true;
		}else{
			return false;
		}
	}
        
	public Pedido getPedido(Integer id){
		if (this.cPedido.containsKey(id)){
			
			return (Pedido) this.cPedido.get(id);
		}else{
			return null;
		}
	}
        
        public void updateIndiceItens(Double indice) {
            List<Pedido> list = new ArrayList(cPedido.values());
            list.stream().forEach((pedido) -> {
             if (!pedido.getClass().getName().equals("PedidoAdapter")) {
                pedido.setIndice(indice);
             }   
            });
        }
}
