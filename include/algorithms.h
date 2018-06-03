#ifndef ALGORITHMS_H
#define ALGORITHMS_H


class algorithms
{
    public:
        algorithms();
        int* generateRandArr(int maxl);//生成长度为max的随机数组
        int binarySearch1(int arr[],int n,int target);//二分查找
        int binarySearch2(int arr[],int low,int hig,int target);//二分查找（递归）
        void merges(int arr[],int low,int mid,int hig);//有序数组归并
        void mergesSort(int arr[],int low,int hig);//归并排序
        void swap1(int arr[],int i,int j);//数组交换函数
        int partion(int arr[],int low,int hig);//快速排序寻找partion
        void quicksort(int arr[],int low,int hig);//快速排序
        void FixHeap(int arr[],int i,int n);//调整堆
        void MakeHeap(int arr[],int n);//构造大顶堆
        void deleteHeap(int arr[],int i,int n);//删除堆中任意一个元素
        void HeapSort(int arr[],int n);//堆排序
        int Backpack(int v[],int w[],int n,int c);//0 1背包
        int Backpackinfine(int v[],int w[],int n,int c);//无限背包问题
        int* GetNext(char s[],int n);//求string的next数组
        int kmp(char str[],char pattern[]);//kmp模式匹配
        virtual ~algorithms();
    protected:
    private:

};

#endif // ALGORITHMS_H
