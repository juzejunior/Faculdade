/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lugar.cpp
 * Author: jose diogo
 * 
 * Created on November 7, 2016, 10:25 AM
 */

#include "Rua.h"

Rua::Rua() 
{
}

Rua::Rua(std::string nome, int id)
{
    this->id = id;
    this->nome = nome;
}

int Rua::getId()
{
    return this->id;
}

std::string Rua::getNome()
{
    return this->nome;
}

void Rua::setNome(std::string nome)
{
    this->nome = nome;
}

void Rua::setId(int id)
{
    this->id = id;
}