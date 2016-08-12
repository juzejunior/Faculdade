#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){

    double cedula,moedas;
    int dezena,resto,unidade;

    cin >> cedula;

    cout << "NOTAS:"<<endl;
    /*notas de 100*/
    cout <<(int)cedula/100<<" nota(s) de R$ 100.00"<<endl;

    dezena = (int)cedula % 100;

    /*Se a dezena for igual ou maior que 50*/
    if(dezena >= 50){
        cout << dezena/50 << " nota(s) de R$ 50.00" << endl;
        resto = dezena - 50;

        /*para 20*/
        cout << resto/20 << " nota(s) de R$ 20.00" << endl;

        /*para 10*/
        cout << (resto/20) / 10 << " nota(s) de R$ 10.00" << endl;

        /*pegando unidade*/
        unidade = resto%10;

        /*para 5*/
        cout << unidade/5 << " nota(s) de R$ 5.00" << endl;

        /*para 2*/
       cout << (unidade%5)/2 << " nota(s) de R$ 2.00" << endl;

       /*Imprimindo moedas*/
        cout <<"MOEDAS:"<<endl;
       /*para 1*/
       cout << ((unidade%5)%2)/1 << " moeda(s) de R$ 1.00" << endl;

       moedas = cedula-floor(cedula);

       cout << floor(moedas/ 0.50) << " moeda(S) de R$ 0.50"<<endl;

      //printa moeda cout << fixed << setprecision(2) << moedas;


    }

    return 0;
}
