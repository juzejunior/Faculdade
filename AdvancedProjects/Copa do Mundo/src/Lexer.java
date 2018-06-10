import java.io.*;

public class Lexer {

    public static final int INVALIDO = 689;
    public static final int LISTE = 261;
    public static final int ATUALIZE = 467;
    public static final int REMOVA = 777;
    public static final int DE = 391;
    public static final int TUDO = 79;
    public static final int EOF = 64;
    public static final int EOL = 58;
    public static final int NUMBER = 657;
    public static final int STRING = 61;
    public static String tokenAtual = "";
    public int token = 0;

    private StreamTokenizer input;

    public Lexer(InputStream in) {
        BufferedReader r = new BufferedReader(new InputStreamReader(in));
        input = new StreamTokenizer(r);
        input.resetSyntax();
        input.eolIsSignificant(true);
        input.wordChars('a', 'z');
        input.wordChars('A', 'Z');
        input.wordChars('0', '9');
        input.wordChars('^', '^');
        input.whitespaceChars('\u0000', '\u0020');
    }

    public int nextToken() throws Exception {
        int token = 0;
        try {
            switch(input.nextToken()) {
                case StreamTokenizer.TT_EOF:
                    token = EOF;
                    tokenAtual = "fim de arquivo";
                    break;
                case StreamTokenizer.TT_EOL:
                    tokenAtual = "fim de linha";
                    token = EOL;
                    break;
                case StreamTokenizer.TT_WORD:
                    if(input.sval.equalsIgnoreCase("LISTE"))     token = LISTE;
                    else if(input.sval.equalsIgnoreCase("ATUALIZE")) token = ATUALIZE;
                    else if(input.sval.equalsIgnoreCase("REMOVA"))   token = REMOVA;
                    else if(input.sval.equalsIgnoreCase("DE"))       token = DE;
                    else if(input.sval.equalsIgnoreCase("TUDO"))     token = TUDO;
                    else try{
                        Integer.parseInt(input.sval);
                        token = NUMBER;
                    } catch(NumberFormatException nfe) {
                        token = STRING;
                    }

                    tokenAtual = input.sval;
                    break;
                case StreamTokenizer.TT_NUMBER:
                    System.err.println("entrou no TT_NUMBER");
                    break;
                default:
                    token = INVALIDO;
                    throw new Exception("ERRO LEXICO: Cadeia de caracteres invalida.");
            }
        } catch (IOException e) {
            token = EOF;
        }
        return token;
    }

}
