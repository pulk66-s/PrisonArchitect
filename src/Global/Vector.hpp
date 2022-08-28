#ifndef __GLOBAL_VECTOR_HPP__
    #define __GLOBAL_VECTOR_HPP__

    #include "GlobalNamespace.hpp"
    #include <ostream>

template <typename T>
struct PA::Vector2 {
    T x;
    T y;

    Vector2<T>(T x, T y) {
        this->x = x;
        this->y = y;
    }

    Vector2<T>() {
        this->x = 0;
        this->y = 0;
    }

    PA::Vector2<T> operator%(PA::Vector2<T> other) {
        return (PA::Vector2<T>(this->x % other.x, this->y % other.y));
    }

    PA::Vector2<T> operator*(const PA::Vector2<T>& other) {
        return (PA::Vector2<T>(this->x * other.x, this->y * other.y));
    }

    PA::Vector2<T> operator*=(const PA::Vector2<T>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return (*this);
    }

    PA::Vector2<T> operator+(const PA::Vector2<T> &other) const {
        return (PA::Vector2<T>{this->x + other.x, this->y + other.y});
    }

    PA::Vector2<T> operator-(const PA::Vector2<T> &other) const {
        return (PA::Vector2<T>{this->x - other.x, this->y - other.y});
    }

    PA::Vector2<T> operator+= (const PA::Vector2<T> &other) {
        this->x += other.x;
        this->y += other.y;
        return (*this);
    }

    PA::Vector2<T> operator-= (const PA::Vector2<T> &other) {
        this->x -= other.x;
        this->y -= other.y;
        return (*this);
    }

    PA::Vector2<T> operator/ (const T &other) {
        return (PA::Vector2<T>{this->x / other, this->y / other});
    }

    PA::Vector2<T> operator/= (const T &other) {
        this->x /= other;
        this->y /= other;
        return (*this);
    }

    PA::Vector2<T> operator/= (const PA::Vector2<T> &other) {
        this->x /= other.x;
        this->y /= other.y;
        return (*this);
    }

    PA::Vector2<T> operator/ (const PA::Vector2<T> &other) {
        return (PA::Vector2<T>{this->x / other.x, this->y / other.y});
    }

    bool operator==(const PA::Vector2<T> &other) const {
        return (this->x == other.x && this->y == other.y);
    }

    bool operator<(const PA::Vector2<T> &other) const {
        return (this->x < other.x || (this->x == other.x && this->y < other.y));
    }

    friend std::ostream &operator<<(std::ostream &os, const PA::Vector2<T> &vector) {
        os << "(" << vector.x << ", " << vector.y << ")";
        return (os);
    }
};

#endif