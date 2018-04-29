import java.util.*;

public abstract class  Pedido implements Observer {

	protected Integer id;
	protected String descricao;
	protected List<Item> cItem = new ArrayList<Item>();
	protected Observable subject;
	
	public void adicionaItem(Item i){
		this.cItem.add(i);
	}
	
	public abstract double getTotal();
	
	public abstract String getTipoPedido();
	
	public String toString(){
		
		String temp="Pedido"+this.getTipoPedido()+ "\n";
		temp=temp+"Id:"+this.id+"\n";
		temp=temp+"Descrição:"+this.descricao+"\n"; 
		temp=temp+"Valor Total:"+this.getTotal()+ " reais \n Itens \n";
	
		Iterator<Item> it = this.cItem.iterator();
		int count=1;
		while (it.hasNext()){
			Item i =(Item) it.next();
		    temp=temp+count+":"+i.toString()+"\n";
		    count++;
		}    
		return temp;
	}
	public Integer getId() {
		
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	public List<Item> getcItem() {
		return cItem;
	}
	public void setcItem(List<Item> cItem) {
		this.cItem = cItem;
	}

}
