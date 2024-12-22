#include <iostream>

using namespace std;


class Fraction
{
	int num;
	int den;
	
	public:
		
		
		Fraction()
		{
			num = 0;
			den = 1;
	//		cout<<num<<"/"<<den<<endl;
		}
		
		Fraction(int numerator, int denominator)
		{
			num = numerator;
			//den = denominator;
	//		cout<<num<<"/"<<den<<endl;
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            den = 1;
        } else {
            den = denominator;
        }
        compute();
		}
		
		int gcd(int a, int b)
		{
			if (b==0)
			{
				return a;
			}
			else
			{
				return gcd(b, a%b);
			}
		}
		
		void compute()
		{
	
			int divisor = gcd(num, den);
			num /= divisor;
			den /= divisor;
		}
		
		Fraction operator +(Fraction& obj1)
		{
			int Num = (num*obj1.den) + (obj1.num*den);
			int Den = den*obj1.den;
			Fraction result(Num, Den);
			result.compute();
			return result;
		}
		
		Fraction operator -(Fraction& obj2)
		{
			int Num = (num*obj2.den) - (obj2.num*den);
			int Den = (den * obj2.den);
			Fraction result(Num, Den);
			result.compute();
			return result;
		}
		
		Fraction operator *(Fraction& obj2)
		{
			int Num = num*obj2.num;
			int Den = den*obj2.den;
			Fraction result(Num, Den);
			result.compute();
			return result;

		}
		
		Fraction operator /(Fraction& obj2)
		{
			int Num = num * obj2.den;
			int Den = den*obj2.num;
			Fraction result(Num, Den);
			result.compute();
			return result;

		}
		
		
		bool operator ==(Fraction& obj1)
		{
   			compute();  
    		obj1.compute();  
			return (num*obj1.den == obj1.num*den);
		}
		
		
		friend ostream& operator <<(ostream& COUT, Fraction& obj1)
		{
			COUT<<obj1.num<<"/"<<obj1.den<<endl;
			return COUT;
		}
		
//		friend istream& operator >>(istream& CIN, Fraction& obj1)
//		{
//			cout<<"Enter Numerator: ";
//			CIN>>obj1.num;
//			
//			cout<<"Enter denominator: ";
//			CIN>>obj1.den;
//			
////		if (obj1.den == 0) {
////        	cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
////        	obj1.den = 1;
////    }
//    		obj1.compute();
//			return CIN;
//		}


    friend istream& operator >>(istream& CIN, Fraction& obj1) {
        cout << "Enter Numerator: ";
        CIN >> obj1.num;

        cout << "Enter Denominator: ";
        CIN >> obj1.den;

        if (obj1.den == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            obj1.den = 1;
        }

        obj1.compute();
        return CIN;
    }
		
};



// Sample main function to test the implementation
int main() {
    Fraction f1, f2, result;

    // Input two fractions
    cout << "Enter first fraction (numerator and denominator): ";
    cin >> f1;
    cout << "Enter second fraction (numerator and denominator): ";
    cin >> f2;

    // Perform addition
    result = f1 + f2;
    cout << "Sum: " << result << endl;

    // Perform subtraction
    result = f1 - f2;
    cout << "Difference: " << result << endl;

    // Perform multiplication
    result = f1 * f2;
    cout << "Product: " << result << endl;

    // Perform division
    result = f1 / f2;
    cout << "Quotient: " << result << endl;

    // Check equality
    if (f1 == f2)
        cout << "The fractions are equal." << endl;
    else
        cout << "The fractions are not equal." << endl;

    return 0;
}
