#include <iostream>
#include <cmath>
using namespace std;



int main()
{
   int n;
   int cont=-1;
   int cont2=0;
   int aux;
   cin>>n;
    int ult = n%10;
    aux=n/10;
   while(n>10){

    n=n/10;
    cont++;
    
   }
   cout<<n<<endl;
   cout<<ult<<endl;
   int pot = pow(10,cont);
 int x = aux%pot;
 cout<<x<<endl;
 cout<<pot<<endl;
    return 0;
}
