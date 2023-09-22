#include <iostream>

#include <cmath>

#include <stdexcept>

using namespace std;

template <class R, class I>
class ComplexCalculator{

    private:
        R real=0;
        I imaginary=0;

    public:
        ComplexCalculator(){}

        ComplexCalculator(R real, I imaginary=0) : real(real), imaginary(imaginary){}
        R getReal(){
            return real;
        }
        I getImaginary(){
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
                ComplexCalculator<R,I> TEMP(this->real,this->imaginary);
                for (int i=2;i<=power;i++)
                {
                    ComplexCalculator<R,I> temp =  (TEMP)*(*this);
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


        ComplexCalculator<double,double> operator/(const ComplexCalculator& other){
            double a,b,c,d;
            a = double(real);
            b = double(imaginary);
            c = double(other.real);
            d = double(other.imaginary);
            return ComplexCalculator<double,double>(((a*c+b*d)/(c*c+d*d)),((b*c-a*d)/(c*c+d*d)));
        }


        static ComplexCalculator<double,double> ComplexSin(ComplexCalculator &obj){
            double a = double(obj.real);
            double b = double (obj.imaginary);
            return ComplexCalculator<double,double>(sin(a)*cosh(b)+cos(a)*sinh(b),0);
        }


        static ComplexCalculator<double,double> ComplexCos(ComplexCalculator &obj){
            double a = double(obj.real);
            double b = double (obj.imaginary);
            return ComplexCalculator<double,double>(cos(a)*cosh(b)-sin(a)*sinh(b),0);            
        }


        static ComplexCalculator<double,double> ComplexTan( ComplexCalculator &obj){
            double a = double(obj.real);
            double b = double (obj.imaginary);            
            return ComplexCalculator<double,double>((tan(a)+tanh(b))/(1-tan(a)*tanh(b)),0); 
        }


        static ComplexCalculator<double, double> ComplexCot( ComplexCalculator obj) {
            return ComplexCalculator<double, double>(1) / ComplexTan(obj);
        }


        static ComplexCalculator<double,double> ComplexSec(ComplexCalculator &obj){
            return ComplexCalculator<double, double>(1) / ComplexCos(obj);
        }


        static ComplexCalculator<double,double> ComplexCsc(ComplexCalculator &obj){
            return ComplexCalculator<double, double>(1) / ComplexSin(obj);
        }


        static ComplexCalculator<double,double> ComplexLn(ComplexCalculator &obj){
            double a,b,r,Q;
            a = double(obj.real);
            b = double(obj.imaginary);
            r = sqrt(a*a + b*b);
            Q = atan(b/a);
            return ComplexCalculator<double,double>(log(r),Q);
        }

        
        static ComplexCalculator<double,double> ComplexLog(ComplexCalculator obj, double base){
            return ComplexLn(obj)/ComplexCalculator(log(base));
        }
};
int main(){
    return 0;
}