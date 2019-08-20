#include <iostream>

using namespace std;

int main()
{
  int x[5],aux;
    for(int i=0;i<5;i++){
        cout<<"Digite o "<<x+1<<" numero:"<<endl;
        cin>>x[i];
    }

    for(int j=0;j<5;j++){

        for(int i=4;i>=j;i--){
            if(x[i]<x[i-1]){
                aux = x[i];
                x[i] = x[i-1];
                x[i-1] = aux;
            }
        }
    }
    for(int i=0;i<5;i++){

        cout<<i+1<<"o numero: " <<x[i]<<endl;
    }
    return 0;
}
