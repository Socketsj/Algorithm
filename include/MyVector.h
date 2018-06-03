#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector
{
    private:
        T* data;//�ײ�ʵ��
        int sizes;//��ǰ�����С
        int capaity;//��ǰ���������
        //���·���ռ�
        void resizes(int newcapacity){
           T* newdata=new T[newcapacity];
           for(int i=0;i<sizes;i++){
            newdata[i]=data[i];
           }
           delete[] data;
           data=newdata;
           capaity=newcapacity;
        }

    public:
        MyVector() {
          data=new T[10];
          capaity=10;
          sizes=0;

        }
        ~MyVector() {
          delete[] data;//�ͷſռ�
        }

        //�����µ�Ԫ��
        void push_backs(T element){
          if(sizes==capaity){
            resizes(2*capaity);
          }
          data[sizes++]=element;
        }

        //��������Ԫ��
        T pop_backs(){
          if(sizes>0){
             sizes=sizes-1;
             T ret = data[sizes];//��¼Ҫ���ص���
             if(sizes==capaity/4){
                resizes(capaity/2);//���������������鷽��
             }
             return ret;
          }
        }

        T &operator[](int i)
        {
            if(i>=sizes){
                return data[0];
            }
           return data[i];
        }

    protected:
};

#endif // MYVECTOR_H
