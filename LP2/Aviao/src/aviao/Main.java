package aviao;

public class Main {
	public static void main(String[] args)
	{
		Aviao v = new Aviao("a","adsf","solda", 20, 10);
	
		v.alugarAssento();
		System.out.println("Disponivel: "+v.getAssentosDisp());
	}
	
	
}
