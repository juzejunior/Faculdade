
public class PedidoAdapter extends PedidoNormal {
	private PedidoEspecial pedidoEspecial;
	
	public void setPedidoEspecial(PedidoEspecial pedidoEspecial) {
		this.pedidoEspecial = pedidoEspecial;
	}
	
	public void setDadosDoPedido() {
		this.cItem.add(pedidoEspecial.getItem());
	}

	@Override
	public String getTipoPedido() {
		return " especial";
	}
	
	@Override
	public double getTotal() {
		return pedidoEspecial.getTotalItem();
	}
}
