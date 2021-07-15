#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        
        ll N, x, k ;
        scanf("%d %d %d", &N, &x, &k);
        //cin >> N >> x >> k;
        
        bool flag = false;
        
        //from 0 to n-1
        for(ll i =0; i<=N+1; i=i*k) {
            
            if( i == x ) {
                printf("yes\n");
                flag = true;
                break;
            }
            if(i==0) ++i;
        }
        
        if(flag == false) {
            
            for(ll i = N+1, j=0; i<=0; i = i-(j*k)) {
                
                if( i == x) {
                    printf("yes\n");
                    flag = true;
                    break;
                }
                
                ++j;
            }        
        }    
        
        if(flag == false) {
            printf("no\n");
        }
    }
    
    return 0;
}