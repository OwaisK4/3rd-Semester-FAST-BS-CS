#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};
int main(){
    Complex *ptr = new Complex[5];
    ptr->setData(1, 54); 
    ptr->getData();  

    (ptr+1)->setData(1, 56); 
    (ptr+1)->getData(); 
    
    Complex *ptr1[5];
    ptr1[0]= new Complex;
    
    
    ptr1[0]->setData(1, 57); 
    ptr1[0]->getData(); 



    return 0;
}

