/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package juros;

import java.text.DecimalFormat;
import java.text.NumberFormat;

/**
 *
 * @author jose
 */
public abstract class Juros {

    protected int numero_meses;
    protected double valor;
    protected double percentual;

    public Juros(int numero_meses_, double valor_, double percentual_) {
        this.numero_meses = numero_meses_;
        this.valor = valor_;
        this.percentual = percentual_;
    }

    public abstract double taxa();

    public abstract String tipo();

    public String getImpResultado() {
        NumberFormat formatter = new DecimalFormat("#0.00");     
        return "O valor total da aplicacao de "+ tipo() +
                "com a taxa de "+this.percentual*100+"% "+
                "sobre o valor: " +this.valor+" para " +this.numero_meses+
                " meses é de R$ "+ formatter.format(taxa());
        // retorne uma String com as informações sobre o juros
// Exemplo de retorno para Juros Compostos: O valor total depois da aplicação de Juros Composto com a taxa de:10% sobre o valor: 100.0  para:  3 meses é de: 133.10        
// Exemplo de retorno para Juros Simples: O valor total depois da aplicação de Juros Simples com a taxa de:10% sobre o valor: 100.0  para:  3 meses é de: 130
    }

}
