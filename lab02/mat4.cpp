#include "mat4.h"
#include "mat3.h"

namespace egc {

    //get element by (row, column)
    float& mat4::at(int i, int j)
    {
        return matrixData[j * 4 + i];
    }
    const float& mat4::at(int i, int j) const
    {
        return matrixData[j * 4 + i];
    }

    mat4& mat4::operator =(const mat4& srcMatrix)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                this->at(i, j) = srcMatrix.at(i, j);
        return *this;
    }

    mat4 mat4::operator *(float scalarValue) const
    {
        mat4 aux;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                aux.at(i, j) = this->at(i, j) * scalarValue;
        return aux;
    }

    mat4 mat4::operator *(const mat4& srcMatrix) const
    {
        mat4 aux;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    aux.at(i, j) += this->at(i, k) * srcMatrix.at(k, j);
        for (int i = 0; i < 4; i++)
            aux.at(i, i) -= 1;
        return aux;
    }

    vec4 mat4::operator *(const vec4& srcVector) const
    {
        vec4 aux;
        aux.x += this->at(0, 0) * srcVector.x + this->at(0, 1) * srcVector.y + this->at(0, 2) * srcVector.z + this->at(0, 3) * srcVector.w;
        aux.y += this->at(1, 0) * srcVector.x + this->at(1, 1) * srcVector.y + this->at(1, 2) * srcVector.z + this->at(1, 3) * srcVector.w;
        aux.z += this->at(2, 0) * srcVector.x + this->at(2, 1) * srcVector.y + this->at(2, 2) * srcVector.z + this->at(2, 3) * srcVector.w;
        aux.w += this->at(3, 0) * srcVector.x + this->at(3, 1) * srcVector.y + this->at(3, 2) * srcVector.z + this->at(3, 3) * srcVector.w;
        return aux;
    }
    mat4 mat4::operator +(const mat4& srcMatrix) const
    {
        mat4 aux;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                aux.at(i, j) = this->at(i, j) + srcMatrix.at(i, j);
        return aux;
    }

    float mat4::determinant() const
    {
        mat4 aux= this->matrixData;
        float c, r = 1;
        for (int i = 0; i < 4; i++) {
            for (int k = i + 1; k < 4; k++) {
                c = aux.at(k,i) / aux.at(i, i);
                for (int j = i; j < 4; j++)
                    aux.at(k, j) = aux.at(k, j) - c * aux.at(i, j);
 
            }
        }
        for (int i = 0; i < 4; i++)
            r *= aux.at(i, i);
        return r;
    }
    mat4 mat4::inverse() const
    {
        mat4 invers;
        float v[9];
        mat3 aux;
        mat4 trans = this->transpose();
        float invDet = this->determinant();
        if (invDet == 0) return invers;
        invDet = 1 / invDet;

        v[0] = trans.at(1, 1); 
        v[1] = trans.at(2, 1);
        v[2] = trans.at(3, 1);
        v[3] = trans.at(1, 2);
        v[4] = trans.at(2, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(1, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(0, 0) = aux.determinant();

        v[0] = trans.at(1, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(1, 2);
        v[4] = trans.at(2, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(1, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(0, 1) = aux.determinant();

        v[0] = trans.at(1, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(1, 1);
        v[4] = trans.at(2, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(1, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(0, 2) = aux.determinant();

        v[0] = trans.at(1, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(1, 1);
        v[4] = trans.at(2, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(1, 2);
        v[7] = trans.at(2, 2);
        v[8] = trans.at(3, 2);
        aux = mat3(v);
        invers.at(0, 3) = aux.determinant();

        v[0] = trans.at(0, 1);
        v[1] = trans.at(2, 1);
        v[2] = trans.at(3, 1);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(2, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(1, 0) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(2, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(1, 1) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(2, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(2, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(1, 2) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(2, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(2, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(0, 2);
        v[7] = trans.at(2, 2);
        v[8] = trans.at(3, 2);
        aux = mat3(v);
        invers.at(1, 3) = aux.determinant();

        v[0] = trans.at(0, 1);
        v[1] = trans.at(1, 1);
        v[2] = trans.at(3, 1);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(1, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(2, 0) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(1, 2);
        v[5] = trans.at(3, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(2, 1) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(1, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(3, 3);
        aux = mat3(v);
        invers.at(2, 2) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(3, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(1, 1);
        v[5] = trans.at(3, 1);
        v[6] = trans.at(0, 2);
        v[7] = trans.at(1, 2);
        v[8] = trans.at(3, 2);
        aux = mat3(v);
        invers.at(2, 3) = aux.determinant();

        v[0] = trans.at(0, 1);
        v[1] = trans.at(1, 1);
        v[2] = trans.at(2, 1);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(1, 2);
        v[5] = trans.at(2, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(2, 3);
        aux = mat3(v);
        invers.at(3, 0) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(2, 0);
        v[3] = trans.at(0, 2);
        v[4] = trans.at(1, 2);
        v[5] = trans.at(2, 2);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(2, 3);
        aux = mat3(v);
        invers.at(3, 1) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(2, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(1, 1);
        v[5] = trans.at(2, 1);
        v[6] = trans.at(0, 3);
        v[7] = trans.at(1, 3);
        v[8] = trans.at(2, 3);
        aux = mat3(v);
        invers.at(3, 2) = aux.determinant();

        v[0] = trans.at(0, 0);
        v[1] = trans.at(1, 0);
        v[2] = trans.at(2, 0);
        v[3] = trans.at(0, 1);
        v[4] = trans.at(1, 1);
        v[5] = trans.at(2, 1);
        v[6] = trans.at(0, 2);
        v[7] = trans.at(1, 2);
        v[8] = trans.at(2, 2);
        aux = mat3(v);
        invers.at(3, 3) = aux.determinant();

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                invers.at(i, j) *= invDet;
                if ((i + j) % 2 != 0) invers.at(i, j) *= -1;
            }
        return invers;
    }
    mat4 mat4::transpose() const
    {
        mat4 aux;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4 ;j++)
                aux.at(i, j) = this->at(j, i);
        return aux;
    }
}