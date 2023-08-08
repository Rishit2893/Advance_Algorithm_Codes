#include <iostream>

using namespace std;

long long gcd(long long a,long long b ){
    if(a<b)
        return gcd(b,a);
    else if(a%b==0){
        return b;
    }
    else
        return gcd(b,a%b);
}

long long Power(long long a,long long n,long long p){
    long long res=1;
    a=a%p;
    while(n>0){
        if(n&1){
            res=(res*a)%p;
        }
        n=n/2;
        a=(a*a)%p;
    }
    return res;
}

bool is_prime(long long n){
    
    if(n<=1||n==4){
        return false;
    }
    if(n<=3){
        return true;
    }
    int k=21;
    while(k>0){
        srand(time(0));
        long long a=2+rand()%(n-4);
        if(gcd(n,a)!=1)
            return false;
        if(Power(a,n-1,n)!=1)
            return false;
        k--;
    }
    return true;
    
}

float find_liars(long long n){
    int count=0;
    for(long long a=2;a<=n-2;a++){
        if(Power(a,n-1,n)==1){
            count++;
        }
    }
    float prob=(float)count/(n-3);
    return prob;
}

int main()
{
    long long n;
    cin>>n;
    cout<<is_prime(n)<<endl;
    cout<<find_liars(n)<<endl;
    return 0;
}
