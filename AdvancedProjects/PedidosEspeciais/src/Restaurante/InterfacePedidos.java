package Restaurante;


        
class InterfacePedidos {

    private ColecaoPedidos colecaoPedido = new ColecaoPedidos();

    public static final int ADICIONARNORMAL = 1;
    public static final int ADICIONARESPECIAL = 2;
    public static final int CONSULTAR = 3;
    public static final int REMOVER = 4;
    public static final int PRECO = 5;

    InterfacePedidos() {

    }

    public int criaMenuPrincipal() {
        int opcao;
        System.out.println("Menu de Opcoes:");
        System.out.println("-------------------");
        System.out.println("1. Adicionar Pedido Normal");
        System.out.println("2. Adicionar Pedido Especial");
        System.out.println("3. Consultar Pedido");
        System.out.println("4. Remover Pedido  ");
        System.out.println("5. Atualiza Preço");
        System.out.println("6. Sair do Programa");
        System.out.println("-------------------");
        return opcao = Console.readInt();
    }

    public void AdicionarItems(Pedido p) {
        String opcao;
        do {
            System.out.println("Adicionar Items:");
            System.out.println("-------------------");
            System.out.print("Descricao do Item:");
            String descricao = Console.readLine();
            System.out.print("Quantidade do Item:");
            int quantidade = Console.readInt();
            System.out.print("Valor Unitario:");
            double valorunitario = Console.readDouble();
            Item i = new Item();
            i.setDescricao(descricao);
            i.setQuantidade(quantidade);
            i.setValorUnitario(valorunitario);

            if (p.getClass().getName().equals("PedidoAdapter")) {

                PedidoEspecial pedidoEspecial = new PedidoEspecial();
				pedidoEspecial.setDescricao(p.getDescricao());
				pedidoEspecial.setId(p.getId());
				pedidoEspecial.setItem(i);
				((PedidoAdapter) p).setPedidoEspecial(pedidoEspecial);
				((PedidoAdapter) p).setDadosDoPedido();
                return;
            } else {
                p.adicionaItem(i);
            }

            System.out.print("Deseja Adicionar mais um Item? [S|N]: ");
            opcao = Console.readLine();
        } while (opcao.compareTo("S") == 0);
    }

    public void AdicionarPedido(Pedido p) {

        String opcao;
        do {
            System.out.println("Adicionar Pedido:");
            System.out.println("-------------------");
            System.out.print("ID do Pedido:");
            Integer id = new Integer(Console.readInt());
            System.out.print("Descricao do Pedido:");
            String descricao = Console.readLine();

            p.setId(id);
            p.setDescricao(descricao);

            this.AdicionarItems(p);
            this.colecaoPedido.adicionaPedido(p);
            System.out.print("Deseja Adicionar mais um Pedido? [S|N]: ");
            opcao = Console.readLine();
        } while (opcao.compareTo("S") == 0);

    }

    public void RemoverPedido() {
        int opcao;
        System.out.println("Remover Pedido:");
        System.out.println("-------------------");
        System.out.print("Digite o id do Pedido:");
        Integer id = new Integer(Console.readInt());
        Pedido p = this.colecaoPedido.getPedido(id);

        if (this.colecaoPedido.removePedido(id)) {

            System.out.println("O Item abaixo foi removido.");
            System.out.println(p);
        } else {
            System.out.println("Nao existe Pedidos com este ID.");
        }
    }

    public void ConsultarPedido() {
        int opcao;
        System.out.println("Consultar Pedido:");
        System.out.println("-------------------");
        System.out.print("Digite o id do Pedido:");
        Integer id = new Integer(Console.readInt());
        Pedido p = this.colecaoPedido.getPedido(id);
        if (p != null) {
            System.out.println(p);
        } else {
            System.out.println("Nao existe Pedidos com este ID.");
        }
    }

    public void atualizaPreco() {
        System.out.println("Atualiza Preco:");
        System.out.println("-------------------");
        System.out.print("Digite o indice:");
        Double indice = Console.readDouble();
        this.colecaoPedido.updateIndiceItens(indice);
        System.out.println(this.colecaoPedido.getcPedido());

    }

    public static void main(String args[]) {
        InterfacePedidos cp = new InterfacePedidos();
        int opcao;
        while ((opcao = cp.criaMenuPrincipal()) != 6) {
            if (opcao == InterfacePedidos.ADICIONARNORMAL) {
                Pedido p = new PedidoNormal();
                cp.AdicionarPedido(p);
            }
            if (opcao == InterfacePedidos.ADICIONARESPECIAL) {
                PedidoAdapter pedidoEspecial = new PedidoAdapter();
                cp.AdicionarPedido(pedidoEspecial);
            } else if (opcao == InterfacePedidos.CONSULTAR) {
                cp.ConsultarPedido();
            } else if (opcao == InterfacePedidos.REMOVER) {
                cp.RemoverPedido();
            } else if (opcao == InterfacePedidos.PRECO) {
                cp.atualizaPreco();
            } else {
                System.out.println("Escolha uma opcao correta.");
            }
        }
    }
}
