#ifndef ALGORITHMS_H
#define ALGORITHMS_H


class algorithms
{
    public:
        algorithms();
        int* generateRandArr(int maxl);//���ɳ���Ϊmax���������
        int binarySearch1(int arr[],int n,int target);//���ֲ���
        int binarySearch2(int arr[],int low,int hig,int target);//���ֲ��ң��ݹ飩
        void merges(int arr[],int low,int mid,int hig);//��������鲢
        void mergesSort(int arr[],int low,int hig);//�鲢����
        void swap1(int arr[],int i,int j);//���齻������
        int partion(int arr[],int low,int hig);//��������Ѱ��partion
        void quicksort(int arr[],int low,int hig);//��������
        void FixHeap(int arr[],int i,int n);//������
        void MakeHeap(int arr[],int n);//����󶥶�
        void deleteHeap(int arr[],int i,int n);//ɾ����������һ��Ԫ��
        void HeapSort(int arr[],int n);//������
        int Backpack(int v[],int w[],int n,int c);//0 1����
        int Backpackinfine(int v[],int w[],int n,int c);//���ޱ�������
        int* GetNext(char s[],int n);//��string��next����
        int kmp(char str[],char pattern[]);//kmpģʽƥ��
        virtual ~algorithms();
    protected:
    private:

};

#endif // ALGORITHMS_H
