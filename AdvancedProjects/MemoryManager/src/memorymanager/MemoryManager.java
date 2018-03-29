/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package memorymanager;
import memory.*;
/**
 *
 * @author jose
 */
public class MemoryManager {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MemoriaS hd = new HD("46327",10, MemoriaS.MB);
        MemoriaS cd = new CD(650, MemoriaS.MB);
        ((HD) hd).exibirNumeroSerialEValorDePerda();
        ((CD) cd).exibirEstado();
    }
    
}
