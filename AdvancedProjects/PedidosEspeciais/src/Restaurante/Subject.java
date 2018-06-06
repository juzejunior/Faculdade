/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Restaurante;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author diogo
 */
public abstract class Subject {
    
    protected final List<Observer> observers = new ArrayList();
    protected Double indice;
    
    public Double getIndice() {
       return indice; 
    }
    
    public void setIndice(Double indice) {
       this.indice = indice; 
       notifyAllObservers();
    }
    
    public void attach(Observer observer) {
        observers.add(observer);
    }
    
    public void notifyAllObservers() {
       observers.stream().forEach((obs) -> {
           obs.update(indice);
       });
    }
}
