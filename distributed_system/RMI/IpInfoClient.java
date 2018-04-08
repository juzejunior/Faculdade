
package weather;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

/**
 *
 * @author jose
 */
public class IpInfoClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
     try{
       IPInfoInterface stub = (IPInfoInterface) Naming.lookup("rmi://localhost:5099/IPInfo");
       String response = stub.getMyIP();
       System.out.println("Seu IP é: " + response);
     } catch (MalformedURLException | NotBoundException | RemoteException e) {
         System.err.println(e.getMessage());
     }
    }
}
