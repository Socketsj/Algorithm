#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int hig,int target){
    while(low<=hig){
        int mid = low + (hig-low)/2;
        if(arr[mid]>target) hig=mid-1;
        else if(arr[mid]<target) low=mid+1;
        else return mid;
    }
    return -1;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> num(n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        num[i]=x;
    }
    sort(num.begin(), num.end());
    int sum=0,len=num.size();
    if(binarySearch(num,0,len,num[0]-k)!=-1){
        sum = 1;
    }
    for(int i=1;i<len;i++){
        if(num[i]!=num[i-1]){
            int t = num[i] - k;
            if(binarySearch(num,0,len-1,t)!=-1) sum++;
        }
    }
    printf("%d",sum);


}
