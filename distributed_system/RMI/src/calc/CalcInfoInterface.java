
package calc;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author jose
 */
public interface CalcInfoInterface extends Remote {
    public String getFactorial(int number) throws RemoteException;
}
