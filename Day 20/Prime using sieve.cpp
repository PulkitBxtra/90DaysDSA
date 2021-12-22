class Solution {
public:
    int countPrimes(int n) {
        
        int counter=0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        
        for(int i=2;i<n;i++){
            
            if(prime[i]==1){
                counter++;
            }
            
            for(int j=2*i;j<n;j=j+i){
                prime[j]=0;
            }
        }
        
        return counter;
    }
};
