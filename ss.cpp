#include <iostream>


class A
{
  public:
    A ():m_iVal(0){test();}
    virtual void func() { std::cout<<m_iVal<<' ';}
    virtual void hello(){std::cout<<"I am A"<<std::endl;}
    void test(){func();}
  public:
      int m_iVal;
};
class B : public A
{
  public:
    B(){test();}
    /*virtual void func()
    {
      ++m_iVal;
      std::cout<<m_iVal<<' ';
      }*/

};
