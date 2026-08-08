#include<iostream>
using namespace std;

class complex 
{
private:
    int real;
    int imag;

public:
    //Default constructor
    complex()
    {
        real = 0;
        imag = 0;
    }

    //Parameterized Constructor
    complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    //Overload + operator
    complex operator +(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    //Overload * operator
    complex operator *(complex c)
    {
        complex temp;
        temp.real = (real * c.real ) - (imag * c.imag);
        temp.imag = (real * c.imag ) + (imag * c.real);
        return temp;
    }

    // Overload >> operator
    friend istream& operator >>(istream& in, complex& c);

    // Overload >> operator
    friend ostream& operator <<(ostream& out, complex& c);

};

//Definition of >> operator 
istream& operator >>(istream& in, complex& c)
{
    cout <<"Enter Real Part :";
    cin >> c.real;

    cout <<"Enter Imaginary Part:";
    cin >> c.imag;

    return in;
}
//Definition of << operator
ostream& operator <<(ostream& out, complex& c)
{
    out << c.real;

    if(c.imag >= 0)
        cout<<"+"<< c.imag <<"i";

    else
        cout<< c.imag << "i";

    return out;
}

//Main Function
int main()
{
    complex c1, c2, sum, product;

    cout<<"------------Enter First Complex Number------------"<<endl;
    cin>>c1;

    cout<<"\n------------Enter Second Complex Number:------------"<<endl;
    cin>>c2;

    sum = c1 + c2;
    product = c1* c2;

    cout<<"\nFirst Complex Number = "<< c1 << endl;
    cout<<"\nSecond Complex Number = "<< c2 << endl;

    cout<<"\nAddition = "<< sum << endl;
    cout<<"\nMultiplication = "<< product << endl;

    return 0;
}