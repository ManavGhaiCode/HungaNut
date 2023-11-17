#ifndef _PHYSICS_VECT_H_
#define _PHYSICS_VECT_H_

namespace Physics {
    struct Vector2 {
        int x;
        int y;

        Vector2() {};
        Vector2(int _x, int _y) {
            x = _x;
            y = _y;
        }

        Vector2 operator+(const Vector2& rhs) {
            Vector2 vect;

            vect.x = x + rhs.x;
            vect.y = y + rhs.y;

            return vect;
        }

        Vector2 operator-(const Vector2& rhs) {
            Vector2 vect;

            vect.x = x - rhs.x;
            vect.y = y - rhs.y;

            return vect;
        }

        Vector2 operator*(const Vector2& rhs) {
            Vector2 vect;

            vect.x = x * rhs.x;
            vect.y = y * rhs.y;

            return vect;
        }

        Vector2 operator/(const Vector2& rhs) {
            Vector2 vect;

            vect.x = x / rhs.x;
            vect.y = y / rhs.y;

            return vect;
        }

        void operator+=(const Vector2& rhs) {
            x += rhs.x;
            y += rhs.y;
        }

        void operator-=(const Vector2& rhs) {
            x -= rhs.x;
            y -= rhs.y;
        }

        void operator*=(const Vector2& rhs) {
            x *= rhs.x;
            y *= rhs.y;
        }

        void operator/=(const Vector2& rhs) {
            x /= rhs.x;
            y /= rhs.y;
        }
    };
}

#endif