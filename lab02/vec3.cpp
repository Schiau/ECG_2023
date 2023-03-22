#include "vec3.h"

namespace egc {

	vec3& vec3::operator =(const vec3& srcVector)
	{
		x = srcVector.x;
		y = srcVector.y;
		z = srcVector.z;
		return *this;
	}

	vec3 vec3::operator +(const vec3& srcVector) const
	{
		vec3 aux;

		aux.x = x + srcVector.x;
		aux.y = y + srcVector.y;
		aux.z = z + srcVector.z;

		return aux;
	}

	vec3& vec3::operator +=(const vec3& srcVector)
	{
		x += srcVector.x;
		y += srcVector.y;
		y += srcVector.z;

		return *this;
	}

	vec3 vec3::operator *(float scalarValue) const
	{
		vec3 rez;
		rez.x = x * scalarValue;
		rez.y = y * scalarValue;
		rez.z = z * scalarValue;
		return rez;
	}

	vec3 vec3::operator -(const vec3& srcVector) const
	{
		vec3 rez;
		rez.x = x - srcVector.x;
		rez.y = y - srcVector.y;
		rez.z = z - srcVector.z;
		return rez;
	}

	vec3& vec3::operator -=(const vec3& srcVector)
	{
		x -= srcVector.x;
		y -= srcVector.y;
		z -= srcVector.z;

		return *this;
	}

	vec3 vec3::operator -() const
	{
		vec3 rez;
		rez.x = -x;
		rez.y = -y;
		rez.z = -z;
		return rez;
	}

	float vec3::length() const
	{
		return sqrt(x * x + y * y + z*z);
	}
	vec3& vec3::normalize() {
		float modul = this->length();
		float aux = 1 / modul;
		x *= aux;
		y *= aux;
		z *= aux;
		return *this;
	}

	float dotProduct(const vec3& v1, const vec3& v2) {
		float lungime1 = v1.length();
		float lungime2 = v2.length();
		float cosUnghi = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		return lungime1 * lungime2 * cosUnghi;
	}

	vec3 crossProduct(const vec3& v1, const vec3& v2)
	{
		vec3 result;

		result.x = v1.y * v2.z - v1.z * v2.y;
		result.y = v1.z * v2.x - v1.x * v2.z;
		result.z = v1.x * v2.y - v1.y * v2.x;

		return result;
	}


}