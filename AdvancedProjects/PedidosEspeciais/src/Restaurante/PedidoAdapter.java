/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Restaurante;

/**
 *
 * @author diogo
 */
public class PedidoAdapter extends Pedido {
    private PedidoEspecial pedidoEspecial;
    
    public void setPedidoEspecial(PedidoEspecial pedidoEspecial) {
        this.pedidoEspecial = pedidoEspecial;
    }
    
    public void setDadosDoPedido() {
      this.id = this.pedidoEspecial.getId();
      this.descricao = this.pedidoEspecial.getDescricao();
      this.adicionaItem(this.pedidoEspecial.getItem());
    }

    public PedidoEspecial getPedidoEspecial() {
        return pedidoEspecial;
    }
    
   
    @Override
    public double getTotal() {
        return pedidoEspecial.getTotalItem();
    }

    @Override
    public String getTipoPedido() {
        return " especial"; //To change body of generated methods, choose Tools | Templates.
    }
    
}
