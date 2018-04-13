
package calc;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import javax.swing.JOptionPane;

/**
 *
 * @author jose
 */
public class FactorialClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
     try{
       int number = Integer.parseInt(JOptionPane.showInputDialog("Qual o número deseja calcular o fatorial?"));
       CalcInfoInterface stub = (CalcInfoInterface) Naming.lookup("rmi://localhost:5099/CalcFactorial");
       String response = stub.getFactorial(number);
       JOptionPane.showMessageDialog(null, "O fatorial de "+number+" é: "+response);
     } catch (MalformedURLException | NotBoundException | RemoteException e) {
         System.err.println(e.getMessage());
     }
    }
}
