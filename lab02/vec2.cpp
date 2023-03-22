#include "vec2.h"

namespace egc {

	vec2&/*trimite referinta la un vec2*/ vec2::operator =(const vec2& srcVector)
	{
		this->x = srcVector.x;
		this->y = srcVector.y;
		return *this;
	}

	vec2 vec2::operator +(const vec2& srcVector) const
	{
		vec2 aux;
		
		aux.x = x + srcVector.x;
		aux.y = y + srcVector.y;

		return aux;
	}

	vec2& vec2::operator +=(const vec2& srcVector) {
		x += srcVector.x;
		y += srcVector.y;

		return *this;
	}

	vec2 vec2::operator *(float scalarValue) const
	{
		vec2 rez;
		rez.x = x * scalarValue;
		rez.y = y * scalarValue;
		return rez;
	}
	vec2 vec2::operator -(const vec2& srcVector) const
	{
		vec2 rez;
		rez.x = x - srcVector.x;
		rez.y = y - srcVector.y;
		return rez;
	}

	vec2& vec2::operator -=(const vec2& srcVector)
	{
		x -= srcVector.x;
		y -= srcVector.y;

		return *this;
	}

	vec2 vec2::operator -() const
	{
		vec2 rez;
		rez.x = -x;
		rez.y = -y;
		return rez;
	}
	
	float vec2::length() const
	{
		return sqrt(x * x + y * y);
	}

	vec2& vec2::normalize()
	{
		float modul = this->length();
		float aux = 1 / modul;
		x *= aux;
		y *= aux;
		return *this;
	}

	float dotProduct(const vec2& v1, const vec2& v2)
	{
		float lungime1 = v1.length();
		float lungime2 = v2.length();
		float cosUnghi = v1.x * v2.x + v1.y * v2.y;
		return lungime1 * lungime2 * cosUnghi;
	}

}