#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

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
        virtual double getReal() const = 0;
        virtual double getImag() const = 0;

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

        double getReal() const override;
        double getImag() const override;
        //сеттеры
        void setRe(double);
        void setIm(double);


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
    double AlgebraComplex::getReal() const
    {
        return getRe();
    }

    double AlgebraComplex::getImag() const
    {
        return getIm();
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
        double getReal() const override;
        double getImag() const override;

        //операторы
        TrigonomComplex operator*(const TrigonomComplex& right) const;
        TrigonomComplex operator-() const;
        TrigonomComplex operator+(const TrigonomComplex& right) const;
        TrigonomComplex operator-(const TrigonomComplex& right) const;
        bool operator==(const TrigonomComplex& right) const;
        TrigonomComplex& operator+=(const TrigonomComplex& right);
        friend ostream& operator<<(ostream& os, const TrigonomComplex& c);

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
    double TrigonomComplex::getReal() const {
        return R * std::cos(Phi);
    }

    double TrigonomComplex::getImag() const {
        return R * std::sin(Phi);
    }

    TrigonomComplex TrigonomComplex::operator*(const TrigonomComplex& right) const {
        return TrigonomComplex(
            this->R * right.R, this->Phi + right.Phi);
    }
    TrigonomComplex TrigonomComplex::operator-() const {
        return TrigonomComplex(this->R, this->Phi + std::acos(-1.0));
    }
    TrigonomComplex TrigonomComplex::operator+(const TrigonomComplex& right) const {
        double re = this->getReal() + right.getReal();
        double im = this->getImag() + right.getImag();

        double r = std::sqrt(re * re + im * im);
        double phi = std::atan2(im, re);

        return TrigonomComplex(r, phi);
    }
    TrigonomComplex TrigonomComplex::operator-(const TrigonomComplex& right) const {
        return *this + (-right);
    }
    bool TrigonomComplex::operator==(const TrigonomComplex& right) const {
        return this->getReal() == right.getReal()
            && this->getImag() == right.getImag();
    }
    TrigonomComplex& TrigonomComplex::operator+=(const TrigonomComplex& right) {
        *this = *this + right;
        return *this;
    }
    ostream& operator<<(ostream& os, const TrigonomComplex& c) {
        return os << "{" << c.getR() << "; " << c.getPhi() << "}";
    }
    struct SquareRoots {
        AlgebraComplex first;
        AlgebraComplex second;

        SquareRoots(const AlgebraComplex& first, const AlgebraComplex& second) : first(first), second(second){}
    };

    SquareRoots squareRoots(const Complex& z) {
        double re = z.getReal();
        double im = z.getImag();

        double r = std::sqrt(re * re + im * im);
        double phi = std::atan2(im, re);

        double rootR = std::sqrt(r);
        double rootPhi = phi / 2.0;

        AlgebraComplex root1(
            rootR * std::cos(rootPhi),
            rootR * std::sin(rootPhi)
        );

        AlgebraComplex root2(
            -root1.getRe(),
            -root1.getIm()
        );

        return SquareRoots(root1, root2);
    }


}



