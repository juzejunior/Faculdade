

public class PedidoEspecial {

	private Integer id;
	private String descricao;
	private Item item = new Item();
	
	
	public double getTotalItem(){
		
			return this.item.getTotalItem();
		
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
	public Item getItem() {
		return this.item;
	}
	public void setItem(Item item) {
		this.item = item;
	}
	
	

}
