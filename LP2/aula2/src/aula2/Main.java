package aula2;

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {
        Livro livros;
        String nome;
        
      int dialogButton = JOptionPane.YES_NO_OPTION;
       int resultado = JOptionPane.showConfirmDialog (null, "Deseja cadastrar novo livro?","Warning",dialogButton);
                
        if(resultado == JOptionPane.YES_OPTION){  
             livros = new Livro("Nome do Vento", "Patrick", 2012, 250);
             ContaBanco conta = new ContaBanco(123,345);
             conta.depositar(10);
             livros.comprarLivro(conta, 10);
             conta.consultarSaldo();
             livros.imprimir();
        }else{
            JOptionPane.showMessageDialog(null,"OK BITCH!");

        }
        
 
        
    }
}
