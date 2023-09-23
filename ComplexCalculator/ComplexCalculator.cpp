#include <iostream>

#include <cmath>

#include <stdexcept>

using namespace std;

template <class R>
class ComplexCalculator{

    private:
        R real=0, imaginary=0;

    public:
        ComplexCalculator(){}

        ComplexCalculator(R real, R imaginary=0) : real(real), imaginary(imaginary){}
        R getReal(){
            return real;
        }
        R getImaginary(){
            return imaginary;
        }

        void displayComplex(){
            if (imaginary==0) {
                cout<<real<<endl;
            }
            else if (real==0)
            {
                cout<<imaginary<<"i"<<endl;
            }
            else
            {
                cout<<real<<" + "<<imaginary<<"i"<<endl;
            }  
        }


        void setComplex(R real, R imaginary=0){
            this->real=real;
            this->imaginary=imaginary;
        }


        ComplexCalculator operator+(ComplexCalculator& other){
            return ComplexCalculator(real + other.real, imaginary + other.imaginary);
        }


        ComplexCalculator operator-(ComplexCalculator& other){
            return ComplexCalculator(real - other.real, imaginary - other.imaginary);
        }


        ComplexCalculator operator*(ComplexCalculator& other){
            return ComplexCalculator(real*other.real-imaginary*other.imaginary,real*other.imaginary+imaginary*other.real);
        }


        ComplexCalculator operator^(int power){
            if (power == 0)
            {
                return ComplexCalculator(1);
            }

            else if (power == 1)
            {
                return *this;
            }

            else if (power > 1)
            {   
                ComplexCalculator<R> TEMP(this->real,this->imaginary);
                for (int i=2;i<=power;i++)
                {
                    ComplexCalculator<R> temp =  (TEMP)*(*this);
                    TEMP.real = temp.real;
                    TEMP.imaginary = temp.imaginary;
                }
                return TEMP;
            }

            else if (power < 0)
            {
                return ComplexCalculator(1)/(*this)^(-power);
            }
            else 

            {
                throw runtime_error("");
                return 1;
            }
        }


        ComplexCalculator<R> operator/(const ComplexCalculator& other){
            R a,b,c,d;
            a = R(real);
            b = R(imaginary);
            c = R(other.real);
            d = R(other.imaginary);
            return ComplexCalculator<R>(((a*c+b*d)/(c*c+d*d)),((b*c-a*d)/(c*c+d*d)));
        }


        static ComplexCalculator<R> ComplexSin(ComplexCalculator &obj){
            R a = R(obj.real);
            R b = R (obj.imaginary);
            return ComplexCalculator<R>(sin(a)*cosh(b)+cos(a)*sinh(b),0);
        }


        static ComplexCalculator<R> ComplexCos(ComplexCalculator &obj){
            R a = R(obj.real);
            R b = R (obj.imaginary);
            return ComplexCalculator<R>(cos(a)*cosh(b)-sin(a)*sinh(b),0);            
        }


        static ComplexCalculator<R> ComplexTan( ComplexCalculator &obj){
            R a = R(obj.real);
            R b = R (obj.imaginary);            
            return ComplexCalculator<R>((tan(a)+tanh(b))/(1-tan(a)*tanh(b)),0); 
        }


        static ComplexCalculator<R> ComplexCot( ComplexCalculator obj) {
            return ComplexCalculator<R>(1) / ComplexTan(obj);
        }


        static ComplexCalculator<R> ComplexSec(ComplexCalculator &obj){
            return ComplexCalculator<R>(1) / ComplexCos(obj);
        }


        static ComplexCalculator<R> ComplexCsc(ComplexCalculator &obj){
            return ComplexCalculator<R>(1) / ComplexSin(obj);
        }


        static ComplexCalculator<R> ComplexLn(ComplexCalculator &obj){
            R a,b,r,Q;
            a = R(obj.real);
            b = R(obj.imaginary);
            r = sqrt(a*a + b*b);
            Q = atan(b/a);
            return ComplexCalculator<R>(log(r),Q);
        }

        
        static ComplexCalculator<R> ComplexLog(ComplexCalculator obj, R base){
            return ComplexLn(obj)/ComplexCalculator(log(base));
        }
};
int main(){

    ComplexCalculator<int> num1(3,4);
    ComplexCalculator<int> num2(5,6);

    (num1/num2).displayComplex();

    return 0;
}