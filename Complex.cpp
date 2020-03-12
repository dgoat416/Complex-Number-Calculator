#include "pch.h"
#include "Complex.h"	

Complex::Complex()
{
	re = 0;
	im = 0;
	dem = 1;
}

Complex::Complex(int r, int i, int d)
{
	re = r;
	im = i;
	dem = d;
	
	// denominator can't be 0
	if (dem == 0)
		dem = 1;
}

Complex Complex::operator+(Complex right)
{
	Complex sum;

	// produces possible unsimplified answer

	if (right.dem != dem) // if need to find common denominator
	{
		sum.re = (re * right.dem) + (right.re * dem);
		sum.im = (im * right.dem) + (right.im * dem);
	}

	else // denominator is already common
	{
		sum.re = re + right.re;
		sum.im = im + right.im;
	}
		
		sum.dem = lcm(right.dem, dem);


	// holds the og gcd for the numerator 
	int GCD = abs(gcd(sum.re, sum.im));

	// simplify 
	if (sum.dem % GCD == 0
		|| GCD % sum.dem == 0)
	{
		// determine which number to divide denom and numerator
		// by finding smaller one and dividing by the smaller one
		if (sum.dem > GCD)
		{
			sum.re /= GCD;
			sum.im /= GCD;
			sum.dem /= GCD;
		}
		
		else if (sum.dem <= GCD)
		{
			sum.re /= sum.dem;
			sum.im /= sum.dem;
			sum.dem /= sum.dem;
		}
	}
	
	return sum;
}

Complex Complex::operator-(Complex right)
{
	Complex difference;

	// produces possible unsimplified answer

	if (right.dem != dem) // if need to find common denominator
	{
		difference.re = (re * right.dem) - (right.re * dem);
		difference.im = (im * right.dem) - (right.im * dem);
	}

	else // denominator is already common
	{
		difference.re = re - right.re;
		difference.im = im - right.im;
	}

	difference.dem = lcm(right.dem, dem);

	// holds the og gcd for the numerator 
	int GCD = abs(gcd(difference.re, difference.im));

	// simplify 
	if (difference.dem % GCD == 0
		|| GCD % difference.dem == 0)
	{
		// determine which number to divide denom and numerator
		// by finding smaller one and dividing by the smaller one
		if (difference.dem > GCD)
		{
			difference.re /= GCD;
			difference.im /= GCD;
			difference.dem /= GCD;
		}

		else if (difference.dem <= GCD)
		{
			difference.re /= difference.dem;
			difference.im /= difference.dem;
			difference.dem /= difference.dem;
		}
	}

	return difference;
}

Complex Complex::operator*(Complex right)
{
	Complex product;

	// produces possible unsimplified answer
	product.re = re * right.re 
					 - im * right.im;
	product.im = re * right.im
					+ im * right.re;
	product.dem = dem * right.dem;

	// holds the og gcd for the numerator 
	int GCD = abs(gcd(product.re, product.im));

	// simplify 
	if (product.dem % GCD == 0
		|| GCD % product.dem == 0)
	{
		// determine which number to divide denom and numerator
		// by finding smaller one and dividing by the smaller one
		if (product.dem > GCD)
		{
			product.re /= GCD;
			product.im /= GCD;
			product.dem /= GCD;
		}

		else if (product.dem <= GCD)
		{
			product.re /= product.dem;
			product.im /= product.dem;
			product.dem /= product.dem;
		}
	}

	return product;
}

Complex Complex::operator/(Complex right)
{
	Complex quotient;

	// produces possible unsimplified answer
	quotient.re = re * right.re + im * right.im;
	quotient.im = im * right.re - re * right.im;
	quotient.dem = dem * right.dem * (pow (right.re, 2) + pow (right.im, 2));

	// holds the og gcd for the numerator 
	int GCD = abs(gcd(quotient.re, quotient.im));

	// simplify 
	if (quotient.dem % GCD == 0
		|| GCD % quotient.dem == 0)
	{
		// determine which number to divide denom and numerator
		// by finding smaller one and dividing by the smaller one
		if (quotient.dem > GCD)
		{
			quotient.re /= GCD;
			quotient.im /= GCD;
			quotient.dem /= GCD;
		}

		else if (quotient.dem <= GCD)
		{
			quotient.re /= quotient.dem;
			quotient.im /= quotient.dem;
			quotient.dem /= quotient.dem;
		}
	}

	return quotient;
}

bool Complex::operator==(const Complex & right)
{
	// find common denominator then compare
	Complex _right = right;
	Complex _this = *this;

	if (_right.dem != _this.dem) // if need to find common denominator
	{
		// find common denominator and update this object
		_this.re *=  _right.dem;
		_this.im *= _right.dem;
		

		// find common denominator and update right object
		_right.re *= _this.dem;
		_right.im *= _this.dem;

		// update the denominators of both objects
		_this.dem *= _right.dem;
		_right.dem = _this.dem;
	}

	
	return (_this.re == _right.re && _this.im == _right.im && _this.dem == _right.dem);

}

bool Complex::operator!=(const Complex& right)
{
	if (*this == right)
	{
		return false;
	}

	else
		return true;


}

bool Complex::operator>=(const Complex & right)
{
	// find common denominator then compare
	Complex _right = right;
	Complex _this = *this;

	if (_right.dem != _this.dem) // if need to find common denominator
	{
		// find common denominator and update this object
		_this.re *= _right.dem;
		_this.im *= _right.dem;


		// find common denominator and update right object
		_right.re *= _this.dem;
		_right.im *= _this.dem;

		// update the denominators of both objects
		_this.dem *= _right.dem;
		_right.dem = _this.dem;
	}


	return (_this.re >= _right.re && _this.im >= _right.im && _this.dem >= _right.dem);
}

string Complex::toString() const
{
	string temp = "";

	if (im < 0)
		temp = '[' + to_string(re) + to_string(im) + 'i' + ']' + '/' + to_string(dem);

	else
		temp = '[' + to_string(re) + '+' + to_string(im) + 'i' + ']' + '/' + to_string(dem);

	return temp;
}

int Complex::gcd(int a, int b)
{
	// prevent division by 0
	if (a == 0 || b == 0)
		return 1;

	int greater = 0,
		smaller = 0,
		lastDivisor = 0;

	if (a > b)
	{
		greater = a;
		smaller = b;
	}

	else if (a < b)
	{
		greater = b;
		smaller = a;
	}

	else // they are equal so the gcd is itself
		return a;
		
	do
	{
		lastDivisor = smaller;
		smaller = greater % smaller;
		greater = lastDivisor;
	} while (smaller != 0);

	return greater;
}

int Complex::lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

ostream & operator<<(ostream & stream, const Complex & a)
{
	stream << a.toString();

	return stream;
}
