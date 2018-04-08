/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package weather;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author jose
 */
public class IPInfoServer  {
   
     public static void main(String[] args) {
        try {
            Registry reg = LocateRegistry.createRegistry(5099);
            reg.rebind("IPInfo", new IpInfo());
            System.out.println("Waiting for calls...");
        } catch(Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
