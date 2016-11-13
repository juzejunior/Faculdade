#include "street.h"

//construtor
Street::Street(QString name)
{
    this->name = name;
}
//adiciona um nome a rua
void Street::setName(QString name)
{
    this->name = name;
}
//retorna o nome da rua
QString Street::getName()
{
    return this->name;
}
