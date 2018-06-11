import comando.Comando;

public class CopaDoMundo {

    public static void main(String[] args) throws Exception {
        System.out.println("\n\nBem Vindo ao Sistema de Gerenciamento da Copa do Mundo!");
        while (true) {
            System.out.print("Digite o que desejas fazer: ");
            Parser parser = new Parser(System.in);
            Comando c = parser.parse();
            try {
                System.out.println(c.resolver());
            } catch (Exception ex) {}
        }

    }

}
