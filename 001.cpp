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

};

AlgebraComplex::AlgebraComplex() : Re(0.0), Im(0.0) 
{

}
AlgebraComplex::AlgebraComplex(double Re, double Im) : Re(Re), Im(Im)
{

}

int main()
{
    return 0;
}


