import comando.Comando;

public class CopaDoMundo {

    public static void main(String[] args) throws Exception {
        System.out.print("\n\nBem Vindo ao Sistema de Gerenciamento da Copa do Mundo!\nDigite o que desejas fazer: ");
        Parser parser = new Parser(System.in);
        Comando c = parser.parse();
        System.out.println(c.resolver());
    }

}
