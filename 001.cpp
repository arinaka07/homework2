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

        //операторы
        AlgebraComplex operator+(const AlgebraComplex& right) const;
        AlgebraComplex operator*(const AlgebraComplex& right) const;
        AlgebraComplex operator-() const;
        AlgebraComplex operator-(const AlgebraComplex& right) const;
        AlgebraComplex& operator+=(const AlgebraComplex& right);
        bool operator==(const AlgebraComplex& right) const;
        // Перегрузка оператора вывода на поток.
        // Объявляем дружественной функцией, чтобы иметь доступ к приватным полям
        friend ostream& operator<<(ostream& os, const AlgebraComplex& c);

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

    AlgebraComplex AlgebraComplex::operator+(const AlgebraComplex& right) const {
        return AlgebraComplex(this->Re + right.Re, this->Im + right.Im);
    }
    AlgebraComplex AlgebraComplex::operator*(const AlgebraComplex& right) const {
        return AlgebraComplex(
            this->Re * right.Re - this->Im * right.Im,
            this->Re * right.Im + this->Im * right.Re
        );
    }
    AlgebraComplex AlgebraComplex::operator-() const {
        return AlgebraComplex(-this->Re, -this->Im);
    }
    AlgebraComplex AlgebraComplex::operator-(const AlgebraComplex& right) const {
        return *this + (-right);
    }
    AlgebraComplex& AlgebraComplex::operator+=(const AlgebraComplex& right) {
        this->Re += right.Re;
        this->Im += right.Im;
        return *this;
    }
    bool AlgebraComplex::operator==(const AlgebraComplex& right) const {
        return this->Re == right.Re && this->Im == right.Im;
    }
    ostream& operator<<(ostream& os, const AlgebraComplex& c) {
        return os << "{" << c.getRe() << "; " << c.getIm() << "}";
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
}



