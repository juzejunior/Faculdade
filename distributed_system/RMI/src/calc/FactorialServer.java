/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author jose
 */
public class FactorialServer  {
   
     public static void main(String[] args) {
        try {
            Registry reg = LocateRegistry.createRegistry(5099);
            reg.rebind("CalcFactorial", new CalcInfo());
            System.out.println("Waiting for calls...");
        } catch(Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
