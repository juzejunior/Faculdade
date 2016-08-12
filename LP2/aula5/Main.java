/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matriculaaluno;

import aula5.ContratoAluguel;

/**
 *
 * @author aluno
 */
public class Main {
    
    public static void main(String[] args) {
       
        ContratoAluguel valor1 = new ContratoAluguel(1234, 500, 2, 0, 20, 10, 3);
        System.out.println(valor1.valorJuros());
        valor1.pagarPrest(100);
        
        
    }
    
    
}
