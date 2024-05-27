#include <iostream>
#include <unistd.h>

using namespace std;


struct vetor1{

char *dados;

vetor1(){
dados = new char[100];

}



};
struct vetor2{

vetor1 *vetores[100];

vetor2(){

for(int i=0; i<100; i++){
vetores[i] = new vetor1();
}
}

};

struct vetor3{

vetor2 *vetores[100];

vetor3(){
for(int i=0; i<100; i++){
vetores[i] = new vetor2();
}
}




};

struct vetor4{

vetor3 *vetores[100];
vetor4(){
for(int i=0; i<100; i++){
vetores[i] = new vetor3();
}
}

};



int main()
{
    int tam;
    cout << "\n qual o tamanho do cubo? ";
    cin >> tam;

    vetor4 *vetor = new vetor4();

    for(int v3=0; v3<100; v3++){
        for(int v2=0; v2<100; v2++){
            for(int v1=0; v1<100; v1++){
                for(int dd=0; dd<100; dd++){


                    if(v2 < tam){//até acabar a base de cima
                        if(v1 == v2){//cada uma das linhas horizontais na face superior do tubo
                            if(v2 == 0){
                                if(dd >= v2 && dd <= v2+tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha horizontal
                                else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                            } else {
                                if(dd > v2 && dd < v2+tam){
                                    if(dd == tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;
                                    else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 32;
                                }
                                else if(dd == v2 || dd == v2+tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha  diagonal
                                else {
                                    if(v1 == 0) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha vertical
                                    else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                                }
                            }
                        }else if(v1 < v2){
                            if(dd == v2){
                                if(v1 == 0) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha vertical
                                else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 32;
                            } else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                        } else {vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                        }


                    }else if(v2 == tam){
                        if(v1 <= v2+tam && dd == v2) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;
                        else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;

                    } else if(v2 <= tam+tam){
                        if(v1 == v2-tam){//cada uma das linhas horizontais na face superior do tubo
                            if(v2-tam == 0 || v2-tam == tam){
                                if(dd >= v2-tam && dd <= v2+tam-tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha horizontal
                                else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                            } else {
                                if(dd > v2-tam && dd < v2+tam-tam){
                                    if(dd == tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;
                                    else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 32;
                                }
                                else if(dd == v2-tam || dd == v2+tam-tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha  diagonal
                                else {
                                    if(v1 == 0) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha vertical
                                    else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                                }
                            }
                        }else if(v1 < v2-tam){
                            if(dd == v2-tam){vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 32;
                            } else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                        } else {
                            if(v1 == tam && dd == v2-tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 48;//linha vertical
                            else if(v1 < tam && dd == v2-tam) vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 32;
                            else vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                        }


                    } else {
                        vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] = 0;
                    }

                }

            }
        }
    }

    for(int v3=0; v3<100; v3++){
        for(int v2=0; v2<100; v2++){
                cout << "\n";
            for(int v1=0; v1<100; v1++){
                for(int dd=0; dd<100; dd++){
                    if(vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] != 0)
                    cout << vetor->vetores[v3]->vetores[v2]->vetores[v1]->dados[dd] << " ";


                }
            }
        }
    }





    return 0;
}
