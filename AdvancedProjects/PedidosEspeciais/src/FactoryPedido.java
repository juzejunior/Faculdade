
public class FactoryPedido {
	public static final int NORMAL = 1;
	public static final int ESPECIAL = 2;
	
	public Pedido getPedido(int tipo) {
		switch(tipo) {
		case NORMAL:
			return new PedidoNormal();
		case ESPECIAL:
			return new PedidoAdapter();
		}
		return null;
 	}
	
}
