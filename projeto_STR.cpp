#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

//funções para definir prioridade
void prioridadeAbaixoNormal(){
int x;
cout<<"digite o pid do processo "<<endl;
cin>>x;
HANDLE hProcesso = OpenProcess(PROCESS_ALL_ACCESS, 0, x);
SetPriorityClass(hProcesso,ABOVE_NORMAL_PRIORITY_CLASS);
cout<<"prioridade definida como abaixo do normal"<<endl;
}
void prioridadeNormal(){
int x;
cout<<"digite o pid do processo"<<endl;
cin>>x;
HANDLE hProcesso = OpenProcess(PROCESS_ALL_ACCESS, 0, x);
SetPriorityClass(hProcesso,NORMAL_PRIORITY_CLASS);
cout<<"prioridade definida como normal"<<endl;
}
void prioridadeAlta(){
int x;
cout<<"digite o pid do processo"<<endl;
cin>>x;
HANDLE hProcesso = OpenProcess(PROCESS_ALL_ACCESS, 0, x);
SetPriorityClass(hProcesso,HIGH_PRIORITY_CLASS);
cout<<"prioridade definida como acima do normal"<<endl;
}
// funcao de matar processo
void matar(){
    int x;
    cout<<"digite o PID do processo o qual deseja matar"<<endl;
    cin>>x;
HANDLE hProcesso = OpenProcess(PROCESS_TERMINATE, 0, x);
if(TerminateProcess(hProcesso, 0)){
    cout << "Processo finalizado com sucesso." << endl;
  }
  else{
    cout << "Erro ao finalizar o processo: " <<
      GetLastError() << endl;
  }
}
//filtros por PID
void filtroPidMaior(){
    string com;
    string v = " /v";
    string f=" /fi";

    string pi=" \" PID gt \"";
    string x;
    cout<<"digite o PID"<<endl;
    cin>>x;
    //int p;
       //system("tasklist");
     //cout << "Hello world!" << endl;
     //cout<<"digite o pid do processo que deve morrer"<<endl;
     //cin>>p;
     com = "tasklist" + v +f+ pi + x;
     system(com.c_str());


}
void filtroPidIgual(){
 string com;
    string v = " /v";
    string f=" /fi";

    string pi=" \" PID eq \"";
    string x;
    cout<<"digite o PID"<<endl;
    cin>>x;
   // int p;

     com = "tasklist" + v +f+ pi + x;
     system(com.c_str());


}
void filtroPidMenor(){

 string com;
    string v = " /v";
    string f=" /fi";

    string pi=" \" PID lt \"";
    string x;
    cout<<"digite o PID"<<endl;
    cin>>x;


     com = "tasklist" + v +f+ pi + x;
     system(com.c_str());

}

//filtros por KB
void filtroKBMenorIgual(){
string com;
    string v = " /v";
    string f=" /fi";

    string pi=" \" MEMUSAGE le \"";
    string x;
    cout<<"digite o KB"<<endl;
    cin>>x;


     com = "tasklist" + v +f+ pi + x;
     system(com.c_str());

}
void filtroKBmaior(){
string com;
    string v = " /v";
    string f=" /fi";

    string pi=" \" MEMUSAGE EQ \"";
    string x;
    cout<<"digite o KB"<<endl;
    cin>>x;


     com = "tasklist" + v +f+ pi + x;
     system(com.c_str());

}

int main()
{
    while(1){
        int op;
        // MENU INICIAL//
        system("tasklist");
        cout<<"esses sao os processos em execução"<<endl<<endl;
        cout<<"digite 1 para aplicar um filtro"<<endl<<endl;
        cout<<"digite 2 para mudar prioridade de um processo"<<endl<<endl;
        cout<<"digite 3 para matar um processo"<<endl<<endl;
        cin>>op;

        switch(op){
                         //filtros
        case 1:
                int f1;
                cout<<"digite 1 para aplicar filtro por PID"<<endl<<endl;
                cout<<"digite 2 para aplicar filtro por KB"<<endl<<endl;
                cin>>f1;
            // filtro por PID //
            if(f1==1){
                        int f;// variavel para filtro
            cout<<"digite 1 para listar processos com PID acima do digitado"<<endl<<endl;
            cout<<"digite 2 para listar processos com PID igual do digitado"<<endl<<endl;
            cout<<"digite 3 para listar processos com PID abaixo do digitado"<<endl<<endl;
            cin>>f;
            switch(f){
            case 1:
                filtroPidMaior();
                Sleep(7000);
                    break;

            case 2:
                filtroPidIgual();
                Sleep(7000);
                    break;

            case 3 :
                filtroPidMenor();
                Sleep(7000);
            break;

                }
            if(f1==2){
            cout<<"digite 1 para listar processos com KB acima de 1000"<<endl<<endl;
            cout<<"digite 2 para listar processos com KB abaixo ou igual de 1000"<<endl<<endl;
            int k;
            cin>>k;
                switch(k){
            case 1:
                filtroKBmaior();
                Sleep(7000);
                break;
            case 2:
                filtroKBMenorIgual();
                Sleep(7000);
                break;
                }
            }

            break;
                //prioridade
            case 2 :
                int f2;
            cout<<"digite 1 para mudar para prioridade baixa"<<endl;
            cout<<"digite 2 para mudar para prioridade para normal "<<endl;
            cout<<"digite 3 para mudar para prioridade alta"<<endl;
            cin>>f2;
            if(f2==1){
                prioridadeAbaixoNormal();
                 Sleep(3000);

            }
            if(f2==2){
                prioridadeNormal();
                 Sleep(3000);
            }
            if(f2==3){
                prioridadeAlta();
                Sleep(3000);
            }
            break;
            // matar processo
            case 3:
                matar();
                Sleep(2000);
        }

    }


    }
return 0;
}

