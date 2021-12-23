int countOccurences(int arr[], int n, int X)
{
	int counter=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==X){
            counter++;
        }
    }
    return counter;
}

