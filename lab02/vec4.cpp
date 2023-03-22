#include "vec4.h"

namespace egc {

	vec4& vec4::operator =(const vec4& srcVector)
	{
		x = srcVector.x;
		y = srcVector.y;
		z = srcVector.z;
		w = srcVector.w;
		return *this;
	}

	vec4 vec4::operator +(const vec4& srcVector) const
	{
		vec4 aux;

		aux.x = x + srcVector.x;
		aux.y = y + srcVector.y;
		aux.z = z + srcVector.z;
		aux.w = w + srcVector.w;

		return aux;
	}

	vec4& vec4::operator +=(const vec4& srcVector)
	{
		x += srcVector.x;
		y += srcVector.y;
		y += srcVector.z;
		w += srcVector.w;

		return *this;
	}

	vec4 vec4::operator *(float scalarValue) const
	{
		vec4 rez;
		rez.x = x * scalarValue;
		rez.y = y * scalarValue;
		rez.z = z * scalarValue;
		rez.w = w * scalarValue;
		return rez;
	}

	vec4 vec4::operator -(const vec4& srcVector) const
	{
		vec4 rez;
		rez.x = x - srcVector.x;
		rez.y = y - srcVector.y;
		rez.z = z - srcVector.z;
		rez.w = w - srcVector.w;
		return rez;
	}

	vec4& vec4::operator -=(const vec4& srcVector)
	{
		x -= srcVector.x;
		y -= srcVector.y;
		z -= srcVector.z;
		w -= srcVector.w;

		return *this;
	}

	vec4 vec4::operator -() const
	{
		vec4 rez;
		rez.x = -x;
		rez.y = -y;
		rez.z = -z;
		rez.w = -w;
		return rez;
	}

	float vec4::length() const
	{
		return sqrt(x * x + y * y + z * z + w*w);
	}
	vec4& vec4::normalize() {
		float modul = this->length();
		float aux = 1 / modul;
		x *= aux;
		y *= aux;
		z *= aux;
		w *= aux;
		return *this;
	}

}