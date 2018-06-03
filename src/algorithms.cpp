#include "algorithms.h"
#include <stdio.h>
#include<stdlib.h>
#include <ctime>
#include<windows.h>
#include<algorithm>
#include <string>

using namespace std;

algorithms::algorithms()
{
    //ctor
}

algorithms::~algorithms()
{
    //dtor
}

int* algorithms::generateRandArr(int maxl)
{
    int *arr=new int[maxl];
    srand((unsigned)time(0)); time(0);//time(NULL)
    for(int i=0;i<maxl;i++){
        arr[i]=rand()%100;
    }
    return arr;
}

//二分查找
int algorithms::binarySearch1(int arr[],int n,int target)
{
    int res=-1;
    int l=0,h=n-1;
    while(h>=l){
        int mid=l+(h-l)/2;
        if(arr[mid]>target) h=mid-1;
        else if(arr[mid]<target) l=mid+1;
        else return mid;
    }

    return res;
}


//二分查找（递归）
int algorithms::binarySearch2(int arr[],int low,int hig,int target)
{
    if(hig>=low){
        int mid=low+(hig-low)/2;
        if(arr[mid]>target) return binarySearch2(arr,low,mid-1,target);
        else if(arr[mid]<target) return binarySearch2(arr,mid+1,hig,target);
        else return mid;

    }else{
     return -1;
    }

}

//有序数组归并
void algorithms::merges(int arr[],int low,int mid,int hig)
{
    int temp[hig];
    int i=low,j=mid+1,t=0;
    while(i<=mid&&j<=hig){
        if(arr[i]<=arr[j]){
            temp[t++]=arr[i++];
        }else{
            temp[t++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[t++]=arr[i++];
    }
    while(j<=hig){
        temp[t++]=arr[j++];
    }
    t=0;
    for(int k=low;k<=hig;k++){
        arr[k]=temp[t++];
    }

}

//归并排序
void algorithms::mergesSort(int arr[],int low,int hig)
{
    if(hig>low){
    int mid=(hig+low)/2;
    mergesSort(arr,low,mid);
    mergesSort(arr,mid+1,hig);
    merges(arr,low,mid,hig);
    /*for(int i=0;i<10;i++) printf("%d ",arr[i]);
    putchar('\n');*/
    }

}

void algorithms::swap1(int arr[],int i,int j)//数组交换函数
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int algorithms::partion(int arr[],int low,int hig)//快速排序寻找partion
{
    int pro=hig;
    while(low<hig) if(arr[low++]>arr[pro]) swap1(arr,--low,--hig);
    swap1(arr,pro,low);
    return low;
}
void algorithms::quicksort(int arr[],int low,int hig)//快速排序
{
    int m;
    if(low<hig){
        m=partion(arr,low,hig);
        /*for(int i=0;i<10;i++) printf("%d ",arr[i]);
        putchar('\n');*/
        quicksort(arr,low,m-1);
        quicksort(arr,m+1,hig);
    }
}

//调整大顶堆 n为堆的长度 i为要调整的位置
void algorithms::FixHeap(int arr[],int i,int n)
{
    int temp=arr[i];
    int j=2*i+1;//求得i的左子树
    while(j<n){
        if(j+1<n&&arr[j]<arr[j+1]) j++;//如果i有右子树或者i的右子树比左子树大 j指向右子树
        if(arr[j]<temp) break;//若比最大的子树大则符合大顶堆 不符合则交换位置
        arr[i]=arr[j];
        i=j;
        j=2*i+1;
    }
    arr[i]=temp;
}

//构造大顶堆
void algorithms::MakeHeap(int arr[],int n)
{
    //构建大顶堆的过程就是从倒数第二层开始确保都符合大顶堆一直调整
    for(int i=(n-2)/2;i>=0;i--){
        FixHeap(arr,i,n);
    }
}

//删除大顶堆任意元素
void algorithms::deleteHeap(int arr[],int i,int n)
{
    int temp=arr[i];
    arr[i]=arr[n-1];
    arr[n-1]=temp;
    FixHeap(arr,i,n-1);
}

//堆排序
void algorithms::HeapSort(int arr[],int n)
{
    int temp;
    MakeHeap(arr,n);//构造堆
    for(int i=n-1;i>=0;i--){
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        FixHeap(arr,0,i);

    }

}
/**
背包问题 v[i]代表第i个物品的价值 w[i]代表第i个物品的重量
n物品数量 c背包容量
 求有限的背包容量下求拿取n个物品的最大价值
*/
int algorithms::Backpack(int v[],int w[],int n,int c)
{
    int dp[n][c+1];//d[i][j] 表示背包容量问j时的时候 放入第i个物件获取的最大价值
    int i,j;
    for(i=0;i<=c;i++){
        if(w[0]<=i){
            dp[0][i]=v[0];
        }
        else{
            dp[0][i]=0;
        }
    }

    for(i=1;i<n;i++){
        for(j=0;j<=c;j++){
            dp[i][j]=dp[i-1][j];
            if(w[i]<=j) dp[i][j]=max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
        }
    }
    return dp[n-1][c];

}

//跟01背包问题一样 里面的物品有无限多
int algorithms::Backpackinfine(int v[],int w[],int n,int c)
{
    int dp[c+1]={0};
    for(int i=0;i<=c;i++){
        for(int j=0;j<n;j++){
           if(w[j]<=i) dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
        }
    }
    return dp[c];
}


int*  algorithms::GetNext(char s[],int n)
{
    int i=0,k=-1;
    int *next = new int[n];
    next[0]=-1;
    while(i<n-1){
        if(k==-1||s[i]==s[k]){
            next[++i]=++k;
        }else{
            k=next[k];
        }
    }

    return next;
}
int algorithms::kmp(char str[],char pattern[])
{
    int n=strlen(pattern),m=strlen(str),i=0,j=0;
    int* next=GetNext(pattern,n);
    while(j<m&&i<n){
        if(i==-1||str[j]==pattern[i]){
            i++;
            j++;
        }else{
         i=next[i];
        }
    }
    if(i==n) return j-i;
    return -1;

}

