/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc;

/**
 *
 * @author jose
 */
public abstract class Calc {
   
    public static String getFactorial(int number) throws Exception {
        
        int f = number; 
        while(number > 1) f = f*(number-=1); 
        
        return Integer.toString(f);
    }
}
