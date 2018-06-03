#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector
{
    private:
        T* data;//底层实现
        int sizes;//当前数组大小
        int capaity;//当前数组最长长度
        //重新分配空间
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
          delete[] data;//释放空间
        }

        //插入新的元素
        void push_backs(T element){
          if(sizes==capaity){
            resizes(2*capaity);
          }
          data[sizes++]=element;
        }

        //弹出最后的元素
        T pop_backs(){
          if(sizes>0){
             sizes=sizes-1;
             T ret = data[sizes];//记录要返回的数
             if(sizes==capaity/4){
                resizes(capaity/2);//复用重新设置数组方法
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
