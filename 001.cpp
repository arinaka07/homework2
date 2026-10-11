#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

namespace my_scope
{
    //абстрактный класс 

    class Complex {
        public:
        //функция преобразлвания числа в строку
        virtual std::string string() const = 0;

        virtual ~Complex() = default;

    };

    //алгебраический вид
    class AlgebraComplex : public Complex
    {
        private:
        double Re;
        double Im;

        public:
        AlgebraComplex();
        AlgebraComplex(double Re, double Im);

        //геттеры
        double getRe() const;
        double getIm() const;
        //сеттеры
        void setRe(double);
        void setIm(double);

        std::string string() const override;


    };

    AlgebraComplex::AlgebraComplex() : Re(0.0), Im(0.0) 
    {

    }
    AlgebraComplex::AlgebraComplex(double Re, double Im) : Re(Re), Im(Im)
    {

    }

    double AlgebraComplex::getRe() const
    {
        return this->Re;
    }
    double AlgebraComplex::getIm() const
    {
        return this-> Im;
    }
    void AlgebraComplex::setRe(double Re)
    {
        this->Re = Re;
    }
    void AlgebraComplex::setIm(double Im)
    {
        this->Im = Im;
    }
    std::string AlgebraComplex::string() const
    {
        return std::to_string(Re) + //(Im ???)
    
    }

    //тригонометрическая (аналогично алгебраической)
    class TrigonomComplex : public Complex
    {
        private:
        double R;
        double Phi;

        public:
        TrigonomComplex();
        TrigonomComplex(double R, double Phi);

        double getR() const;
        double getPhi() const;
        void setR(double);
        void setPhi(double);

        std::string string() const override; //функция преобразования числа в строку

    };
    TrigonomComplex::TrigonomComplex() : R(0.0), Phi(0.0) 
    {

    }
    TrigonomComplex::TrigonomComplex(double R, double Phi) : R(R), Phi(Phi)
    {

    }

    double TrigonomComplex::getR() const
    {
        return this->R;
    }
    double TrigonomComplex::getPhi() const
    {
        return this-> Phi;
    }
    void TrigonomComplex::setR(double R)
    {
        this->R = R;
    }
    void TrigonomComplex::setPhi(double Phi)
    {
        this->Phi = Phi;
    }
    std::string TrigonomComplex::string() const
    {
        return std::to_string(R) + "(cos(" + std::to_string(Phi) + ") + i * sin(" + std::to_string(Phi) + "))";

    }
}


int main()
{
    my_scope::AlgebraComplex z(2.0, 3.0);
    cout << "Re=" << z.getRe() << endl;
    cout << "Im=" << z.getIm() << endl;
    z.setRe(5.0);
    z.setIm(7.0);
    cout << "Re=" << z.getRe() << endl;
    cout << "Im=" << z.getIm() << endl;
    z.print();
    cout << endl;

    my_scope::TrigonomComplex t(5.0, 1.57);

    cout << "R=" << t.getR() << endl;
    cout << "Fi=" << t.getFi() << endl;
    t.setR(10.0);
    t.setFi(3.14);
    cout << "R=" << t.getR() << endl;
    cout << "Fi=" << t.getFi() << endl;
    t.print();
    cout << endl;

    return 0;
}


