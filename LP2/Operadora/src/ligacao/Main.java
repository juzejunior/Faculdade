package ligacao;

import hora.Hora;

public class Main {
  
  public static void main(String[] args)
  {
	  
	  Hora inicio, fim;
	  inicio = new Hora(2,0,0);
	  fim = new Hora(3,01,00);
	  
	  Ligacao ligacao1 = new Ligacao("34086169","casa","141344","trabalho", inicio, fim);
	  Ligacao ligacao2 = new Ligacao("34086169","casa","3241","motel", inicio, fim);

	  ContaTelefonica conta1 = new ContaTelefonica(8, 2016, 1);
	  conta1.addLigacao(ligacao1);
	  conta1.addLigacao(ligacao2);
  
	  System.out.println("Total Conta R$: "+conta1.valorConta());
  }
}
