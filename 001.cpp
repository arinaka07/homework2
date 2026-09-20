#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin, std::cout, std::endl, std::ostream

namespace my_scope
{
    //абстрактный класс 

    class Complex {
        public:
        virtual void print() const = 0;
    };

    //алгебраический вид
    class AlgebraComplex : public Complex
    {
        private:
        double Re;
        double Im;

        public:
        AlgebraComplex();//конструктор по умолчанию
        AlgebraComplex(double Re, double Im);

        //геттеры
        double getRe() const;
        double getIm() const;
        //сеттеры
        void setRe(double);
        void setIm(double);

        void print() const override;//функция из class comlex

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
    void AlgebraComplex::print() const
    {
        cout << Re << " + " << Im << "i";
    }

    //тригонометрическая (аналогично алгебраической)
    class TriginomComlex : public AlgebraComplex
    {
        private:
        double R;
        double Fi;

        public:
        TrigonomComplex();
        TrigonomComplex(double R, double Fi);

        double getR() const;
        double getFi() const;
        void setR(double);
        void setFi(double);

        void print() const override;

    };
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

    return 0;
}


