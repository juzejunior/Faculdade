/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jose
 */
public class CalcInfo extends UnicastRemoteObject implements CalcInfoInterface {

    public CalcInfo() throws RemoteException {
        super();
    }
    
    @Override
    public String getFactorial(int number) throws RemoteException {
          try {
            return Calc.getFactorial(number);
        } catch (Exception ex) {
            Logger.getLogger(FactorialServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        return "Error on factorial calc call!";
    }
    
}
