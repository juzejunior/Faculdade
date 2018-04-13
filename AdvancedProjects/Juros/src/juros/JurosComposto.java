/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package juros;

/**
 *
 * @author jose
 */
public class JurosComposto extends Juros {

    public JurosComposto(int numero_meses_, double valor_, double percentual_) {
        super(numero_meses_, valor_, percentual_);
    }

    @Override
    public double taxa() {
        return this.valor * Math.pow(1+this.percentual, this.numero_meses);      
    }

    @Override
    public String tipo() {
        return "juros compostos";
    }
    
}
