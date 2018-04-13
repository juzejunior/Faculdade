/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fabricaagenda;

/**
 *
 * @author jose
 */
public class Agenda {
    
    private static Agenda fabricAgenda;
    
    private Agenda() {}
    
    public static Agenda getInstance() {
        if (Agenda.fabricAgenda == null) {
            Agenda.fabricAgenda = new Agenda();
        }
        return Agenda.fabricAgenda;
    }
    
   public void getSomething() {
       System.out.println("Something");
   }
}
