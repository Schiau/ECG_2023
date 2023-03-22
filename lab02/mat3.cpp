#include "mat3.h"

namespace egc {

    //get element by (row, column)
    float& mat3::at(int i, int j)
    {
        return matrixData[j*3+i];
    }
    const float& mat3::at(int i, int j) const
    {
        return matrixData[j * 3 + i];
    }

    mat3& mat3::operator =(const mat3& srcMatrix)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->at(i, j) = srcMatrix.at(i, j);
        return *this;
                
    }

    mat3 mat3::operator *(float scalarValue) const
    {
        mat3 aux;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                aux.at(i, j) = this->at(i,j)*scalarValue;
        return aux;
    }

    mat3 mat3::operator *(const mat3& srcMatrix) const
    {
        mat3 aux;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for(int k=0;k<3;k++)
                aux.at(i, j) += this->at(i, k) * srcMatrix.at(k,j);
        for (int i = 0; i < 3; i++)
            aux.at(i, i) -= 1;
        return aux;
    }

    vec3 mat3::operator *(const vec3& srcVector) const
    {
        vec3 aux;
        aux.x += this->at(0, 0) * srcVector.x + this->at(0, 1) * srcVector.y + this->at(0, 2) * srcVector.z;
        aux.y += this->at(1, 0) * srcVector.x + this->at(1, 1) * srcVector.y + this->at(1, 2) * srcVector.z;
        aux.z += this->at(2, 0) * srcVector.x + this->at(2, 1) * srcVector.y + this->at(2, 2) * srcVector.z;
        return aux;
    }
    mat3 mat3::operator +(const mat3& srcMatrix) const
    {
        mat3 aux;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                    aux.at(i,j) = this->at(i, j) + srcMatrix.at(i, j);
        return aux;
    }
    
    float mat3::determinant() const
    {
        return this->at(0, 0) * this->at(1, 1) * this->at(2, 2) + this->at(0, 1) * this->at(1, 2) * this->at(2, 0) + this->at(1, 0) * this->at(2, 1) * this->at(0, 2) - this->at(0,2) * this->at(1,1) * this->at(2,0) -this->at(1,0) * this->at(0, 1) * this->at(2, 2) - this->at(1, 2) * this->at(2, 1) * this->at(0, 0);
    }
    mat3 mat3::inverse() const
    {
        mat3 aux;
        float invDet =  this->determinant();
        if (invDet == 0) return aux;
        invDet = 1 / invDet;

        aux.at(0, 0) = this->at(1, 1) * this->at(2, 2) - this->at(2, 1) * this->at(1, 2);
        aux.at(1,0) = this->at(1, 0) * this->at(2, 2) - this->at(1,2) * this->at(2,0);
        aux.at(2,0) = this->at(1, 0) * this->at(2, 1) - this->at(1,1) * this->at(2,0);

        aux.at(0,1) = this->at(0, 1) * this->at(2, 2) - this->at(0, 2) * this->at(2, 1);
        aux.at(1,1) = this->at(0, 0) * this->at(2, 2) - this->at(0, 2) * this->at(2, 0);
        aux.at(2,1) = this->at(0, 0) * this->at(2, 1) - this->at(0, 1) * this->at(2, 0);

        aux.at(0,2) = this->at(0, 1) * this->at(1, 2) - this->at(0, 2) * this->at(1, 1);
        aux.at(1,2) = this->at(0, 0) * this->at(1, 2) - this->at(0, 2) * this->at(1, 0);
        aux.at(2,2) = this->at(0, 0) * this->at(1, 1) - this->at(0, 1) * this->at(1, 0);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                aux.at(i, j) *= invDet;
                if ((i + j) % 2 != 0) aux.at(i, j) *= -1;
            }
        return aux;
    }
    mat3 mat3::transpose() const
    {
        mat3 aux;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                aux.at(i, j) = this->at(j, i);
        return aux;
    }
}