#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n];
    int aux=0;
    
    for(int i=2;i<n;i++){
        v[0]=0;
        v[1]=1;
        v[i]=v[i-1]+ v[i-2];
        aux=v[n-1];

    }


cout<<aux;
    return 0;
}
