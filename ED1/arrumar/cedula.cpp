#include<iostream>

using namespace std;

int main(){

    int cedula,dezena,unidade,resto;

    cin >> cedula;

    cout << cedula << endl;
    /*Imprimindo notas de 100*/
    cout << cedula / 100 <<" nota(s) de R$ 100,00" << endl;

    dezena = cedula % 100;

    /*Se a dezena for igual ou maior que 50*/
    if(dezena >= 50){
        cout << dezena/50 << " nota(s) de R$ 50,00" << endl;
        resto = dezena - 50;

        /*para 20*/
        cout << resto/20 << " nota(s) de R$ 20,00" << endl;

        /*para 10*/
        cout << (resto/20) / 10 << " nota(s) de R$ 10,00" << endl;

        /*pegando unidade*/
        unidade = resto%10;

        /*para 5*/
        cout << unidade/5 << " nota(s) de R$ 5,00" << endl;

        /*para 2*/
       cout << (unidade%5)/2 << " nota(s) de R$ 2,00" << endl;

       /*para 1*/
       cout << ((unidade%5)%2)/1 << " nota(s) de R$ 1,00" << endl;

    }else{
          cout << dezena/50 << " nota(s) de R$ 50,00" << endl;
          cout << dezena/20 << " nota(s) de R$ 20,00" << endl;
          if(dezena >= 20){

                cout << (dezena%20)/10 << " nota(s) de R$ 10,00" << endl;
                 /*pegando unidade*/
                unidade = resto%10;

                /*para 5*/
                cout << unidade/5 << " nota(s) de R$ 5,00" << endl;

                /*para 2*/
                cout << (unidade%5)/2 << " nota(s) de R$ 2,00" << endl;

                /*para 1*/
                cout << ((unidade%5)%2)/1 << " nota(s) de R$ 1,00" << endl;


          }else{
              cout << dezena / 10 << " nota(s) de R$ 10,00" << endl;
              cout << (dezena %10)/ 5 << " nota(s) de R$ 5,00" << endl;
              cout << ((dezena % 10)%5 )/ 2 << " nota(s) de R$ 2,00" << endl;
              cout << (((dezena % 10)% 5) % 2) /1 << " nota(s) de R$ 1,00" << endl;
          }
    }

    return 0;
}
