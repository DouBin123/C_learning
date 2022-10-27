# include <cmath>
# include "vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);//atan()返回弧度
	//private method
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
		{
			ang = 0.0;
		}
		else
			ang = atan2(y, x);
	
	}
	void Vector::set_x()
	{
		x = mag*cos(ang);
	}
	void Vector::set_y()
	{
		y = mag*sin(ang);
	}
	//public method
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	
	}
	Vector::Vector(double n1, double n2, Mode form)//将会产生临时对象，而set直接修改
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() ";
			cout << "vector set to 0\n";
			x = y = ang = mag = 0.0;
			mode = RECT;
		}
	
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() ";
			cout << "vector set to 0\n";
			x = y = ang = mag = 0.0;
			mode = RECT;
		}
	}//
	Vector ::~Vector()//destructor
	{
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	// operator overloading
	Vector Vector::operator+(const Vector &b)const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector &b)const
	{
		return Vector(x - b.x, y - b.y);
	}

	//reverse sign of vector
	Vector Vector::operator-()const
	{
		return Vector(-x, -y);
	}
	//multiply vector by n
	Vector Vector::operator*(double n)const
	{
		return Vector(n*x, n*y);
	}

	//friend method
	Vector operator*(double n, const Vector &a)
	{
		return a*n;//had overload
	
	}
	std::ostream &operator<<(std::ostream &os, const Vector &v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = ( " << v.x << "," << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << "," << v.ang*Rad_to_deg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	
	}
}