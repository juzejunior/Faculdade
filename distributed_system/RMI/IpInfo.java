/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package weather;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jose
 */
public class IpInfo extends UnicastRemoteObject implements IPInfoInterface{

    public IpInfo() throws RemoteException {
        super();
    }
    
    @Override
    public String getMyIP() throws RemoteException {
          try {
            return HttpConnetion.getIP();
        } catch (Exception ex) {
            Logger.getLogger(IPInfoServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        return "Error on search IP!";
    }
    
}
