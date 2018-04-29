import java.util.*;

public class ColecaoPedidos implements Observable {
	
	private Map<Integer, Pedido> cPedido = new HashMap<Integer, Pedido>();
	private List<Observer> observers;
	private double indice;
	
	public ColecaoPedidos() {
		observers = new ArrayList<>();
	}
	
	public double getIndice() {
		return indice;
	}

	public void setIndice(double indice) {
		this.indice = indice;
		notifyObservers();
	}

	public Map<Integer, Pedido> getcPedido() {
		return cPedido;
	}
	
	public void setcPedido(Map<Integer, Pedido> cPedido) {
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
	
	@Override
	public void addObserver(Observer observer) {
		observers.add(observer);
	}
	
	@Override
	public void notifyObservers() {
		List<Pedido> pedidos = new ArrayList<>(cPedido.values());
		for (Pedido observer: pedidos) {
			observer.update(indice);
		}
	}

}
