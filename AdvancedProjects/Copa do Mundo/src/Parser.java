import comando.Atualizar;
import comando.Comando;
import comando.Excluir;
import comando.Listar;

import java.io.InputStream;

class Parser {

    private Lexer lexer;
    private int token;
    private String tokenString = "";

    Parser(InputStream inputStream) {
        this.lexer = new Lexer(inputStream);
    }

    Comando parse() throws Exception {
        nextToken();
        Comando c = comando();
        expect( Lexer.EOF, Lexer.EOL);
        return c;
    }

    private Comando comando() throws Exception {
        Comando comando = null;
        switch (token) {
            case Lexer.LISTE: comando = listar(); break;
            case Lexer.ATUALIZE: comando = atualizar(); break;
            case Lexer.REMOVA: comando = remover(); break;
        }
        return comando;
    }

    private Comando listar() throws Exception {
        nextToken();
        expect(Lexer.STRING);
        Comando comando = new Listar(this.tokenString);
        nextToken();
        return comando;
    }

    private Comando atualizar() throws Exception {
        nextToken();
        expect(Lexer.STRING);
        Comando comando = new Atualizar(this.tokenString);
        nextToken();
        return comando;
    }

    private Comando remover() throws Exception {
        nextToken();
        expect(Lexer.STRING);
        Comando comando = new Excluir(this.tokenString);
        nextToken();
        return comando;
    }

    private void nextToken() throws Exception {
        this.token = lexer.nextToken();
        this.tokenString = Lexer.tokenAtual;
        System.out.println("Token atual -> " + this.tokenName(this.token));
    }

    private String tokenName(int token2) {
        String token;
        switch(token2) {
            case Lexer.EOF: token = "FIM DO ARQUIVO"; break;
            case Lexer.EOL: token = "FIM DA LIHA"; break;
            case Lexer.LISTE: token = "LISTE"; break;
            case Lexer.STRING: token = this.tokenString; break;
            case Lexer.NUMBER: token = this.tokenString; break;
            case Lexer.REMOVA: token = "REMOVER"; break;
            case Lexer.ATUALIZE: token = "ATUALIZAR"; break;
            default: token = "DEFAULT"; break;
        }
        return token;
    }

    private void expect(Integer...args) {
        boolean result = false;
        String msg = "Foi encontrado " + tokenName(this.token) + " quando se esperava ";
        for (Integer arg : args) {
            if (arg == Lexer.STRING) msg += "String ou ";
            else if (arg == Lexer.NUMBER) msg += "Numero ou ";
            else msg += tokenName(arg) + " ou ";
            if (this.token == arg) {
                result = true;
            }
        }

        msg = msg.substring(0, msg.length()-4);
        if(!result) { System.err.println("Syntax Error: " + msg); }
    }


}
