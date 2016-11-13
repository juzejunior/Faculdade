#ifndef STREET_H
#define STREET_H

#include <QString>

class Street
{
public:
    Street(QString name);//constructor
    //get & set
    void setName(QString name);
    QString getName();
private:
  QString name;//nome da rua
};

#endif //STREET_H
