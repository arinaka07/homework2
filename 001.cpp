#include <cstdio>
#include <cstdlib>

//абстрактный класс 

class Complex {
    public:
    virtual void print() = 0;
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
    printf("%f + %fi", Re, Im);
}


int main()
{
    return 0;
}


