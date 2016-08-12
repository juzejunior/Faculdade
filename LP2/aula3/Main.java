package aula3;

import javax.smartcardio.CardTerminal;
import java.util.ArrayList;
import java.util.Calendar;

/**
 * Created by diogo on 24/07/16.
 */
public class Main {
    public static  void main(String[] args)
    {
        Calendar c;
        c = Calendar.getInstance();
        Data data_atual = new Data();
        data_atual.setDia(c.get(Calendar.DAY_OF_MONTH));
        data_atual.setMes(c.get(Calendar.MONTH)+1);
        data_atual.setAno(c.get(Calendar.YEAR));

        CarteiraMotorista carteira = new CarteiraMotorista(data_atual);

    }
}
