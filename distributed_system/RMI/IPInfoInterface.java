
package weather;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author jose
 */
public interface IPInfoInterface extends Remote {
    public String getMyIP() throws RemoteException;
}
