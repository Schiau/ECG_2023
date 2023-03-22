#include "transform.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3.h"
#include "mat4.h"

namespace egc {
    mat3 translate(const vec2 translateArray)
    {
        float v[9];

        v[0] = 1;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
        v[4] = 1;
        v[5] = 0;
        v[6] = translateArray.x;
        v[7] = translateArray.y;
        v[8] = 1;

        return mat3(v);
    }
    mat3 translate(float tx, float ty)
    {
        return translate(vec2({tx,ty,1}));
    }

    mat3 scale(const vec2 scaleArray)
    {
        float v[9];

        v[0] = scaleArray.x;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
        v[4] = scaleArray.y;
        v[5] = 0;
        v[6] = 0;
        v[7] = 0;
        v[8] = 1;

        return mat3(v);
    }
    mat3 scale(float sx, float sy)
    {
        return scale(vec2({ sx,sy,1 }));
    }

    mat3 rotate(float angle)
    {
        float aux = PI * angle / 180;
        mat3 result = mat3();

        result.at(0, 0) = cos(aux);
        result.at(0, 1) = -1 * sin(aux);
        result.at(1, 0) = sin(aux);
        result.at(1, 1) = cos(aux);

        return result;
    }

    mat4 translate(const vec3 translateArray)
    {
        float v[16];

        v[0] = 1;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;

        v[4] = 0;
        v[5] = 1;
        v[6] = 0;
        v[7] = 0;

        v[8] = 0;
        v[9] = 0;
        v[10] = 1;
        v[11] = 0;

        v[12] = translateArray.x;
        v[13] = translateArray.y;
        v[14] = translateArray.z;
        v[15] = 1;

        return mat4(v);
    }
    mat4 translate(float tx, float ty, float tz)
    {
        return translate(vec3({ tx,ty,tz,1 }));
    }

    mat4 scale(const vec3 scaleArray)
    {
        float v[16];

        v[0] = scaleArray.x;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;

        v[4] = 0;
        v[5] = scaleArray.y;
        v[6] = 0;
        v[7] = 0;

        v[8] = 0;
        v[9] = 0;
        v[10] = scaleArray.z;
        v[11] = 0;

        v[12] = 0;
        v[13] = 0;
        v[14] = 0;
        v[15] = 1;

        return mat4(v);
    }
    mat4 scale(float sx, float sy, float sz)
    {
        return scale(vec3({ sx, sy, sz, 1 }));
    }

    mat4 rotateX(float angle)
    {
        float aux = PI * angle / 180;
        mat4 result=mat4();

        result.at(1, 1) = cos(aux);
        result.at(1, 2) = -1*sin(aux);
        result.at(2, 2) = cos(aux);
        result.at(2, 1) = sin(aux);

        return result;
    }

    mat4 rotateY(float angle)
    {
        float aux = PI * angle / 180;
        mat4 result = mat4();

        result.at(0, 0) = cos(aux);
        result.at(0, 2) = sin(aux);
        result.at(2, 0) = -1*sin(aux);
        result.at(2, 2) = cos(aux);

        return result;
    }

    mat4 rotateZ(float angle)
    {
        float aux = PI * angle / 180;
        mat4 result = mat4();

        result.at(0, 0) = cos(aux);
        result.at(0, 1) = -1 * sin(aux);
        result.at(1, 0) = sin(aux);
        result.at(1, 1) = cos(aux);

        return result;
    }

}