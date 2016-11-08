/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rua.h
 * Author: jose diogo
 *
 * Created on November 7, 2016, 10:25 AM
 */

#ifndef RUA_H
#define RUA_H

#include <string>

class Rua {

public:
    Rua();
    Rua(std::string nome, int id);
    //sets & gets
    std::string getNome();
    void setNome(std::string nome);
    int getId();
    void setId(int id);
    
private:
   std::string nome;
   int id; 
};

#endif /*RUA_H*/

