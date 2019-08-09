#include <iostream>

using namespace std;
int fatorial(int n){
    if((n==0)||(n==1)){
        return 1;
    }
return n*fatorial(n-1);
}

int main()
{
  int fat;
  cin>>fat;
  cout<<fatorial(fat);
}
