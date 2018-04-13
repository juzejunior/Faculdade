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
public class AplicaJuros {
    private Juros juros;

    public static final int SIMPLES = 1;
    public static final int COMPOSTO = 2;

    public AplicaJuros(int tipo, int numero_meses_, double valor_) {
        switch(tipo) {
            case COMPOSTO:
                this.juros = new JurosComposto(numero_meses_, valor_, 0.1);
                break;
            case SIMPLES:
                this.juros = new JurosSimples(numero_meses_, valor_, 0.1);
                break;
        }
        // Se o tipo for COMPOSTO crie uma instância da classe JurosComposto. Se não, crie uma instancie da classe  JurosSimples.
       // Essas instâncias devem ser referenciadas pelo atributo juros

    }       

    public Juros getJuros() {
        return this.juros;
    }

    public static void main(String args[]) {

        AplicaJuros ap = new AplicaJuros(AplicaJuros.COMPOSTO, 3, 100);

        AplicaJuros ap1 = new AplicaJuros(AplicaJuros.SIMPLES, 3, 100);

        System.out.println(ap.getJuros().getImpResultado());

        System.out.println(ap1.getJuros().getImpResultado());

    }

}
