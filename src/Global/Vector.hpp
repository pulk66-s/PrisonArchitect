#ifndef __GLOBAL_VECTOR_HPP__
    #define __GLOBAL_VECTOR_HPP__

    #include "GlobalNamespace.hpp"
    #include <ostream>

struct PA::Vector2i {
    int x;
    int y;

    Vector2i(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Vector2i() {
        this->x = 0;
        this->y = 0;
    }

    PA::Vector2i operator%(PA::Vector2i other) {
        return (PA::Vector2i(this->x % other.x, this->y % other.y));
    }

    PA::Vector2i operator*(const PA::Vector2i& other) {
        return (PA::Vector2i(this->x * other.x, this->y * other.y));
    }

    PA::Vector2i operator+(const PA::Vector2i &other) const {
        return (PA::Vector2i{this->x + other.x, this->y + other.y});
    }

    PA::Vector2i operator-(const PA::Vector2i &other) const {
        return (PA::Vector2i{this->x - other.x, this->y - other.y});
    }

    PA::Vector2i operator+= (const PA::Vector2i &other) {
        this->x += other.x;
        this->y += other.y;
        return (*this);
    }

    PA::Vector2i operator-= (const PA::Vector2i &other) {
        this->x -= other.x;
        this->y -= other.y;
        return (*this);
    }

    PA::Vector2i operator/ (const int &other) {
        return (PA::Vector2i{this->x / other, this->y / other});
    }

    PA::Vector2i operator/= (const int &other) {
        this->x /= other;
        this->y /= other;
        return (*this);
    }

    PA::Vector2i operator/= (const PA::Vector2i &other) {
        this->x /= other.x;
        this->y /= other.y;
        return (*this);
    }

    PA::Vector2i operator/ (const PA::Vector2i &other) {
        return (PA::Vector2i{this->x / other.x, this->y / other.y});
    }

    bool operator==(const PA::Vector2i &other) const {
        return (this->x == other.x && this->y == other.y);
    }

    bool operator<(const PA::Vector2i &other) const {
        return (this->x < other.x || (this->x == other.x && this->y < other.y));
    }

    friend std::ostream &operator<<(std::ostream &os, const PA::Vector2i &vector) {
        os << "(" << vector.x << ", " << vector.y << ")";
        return (os);
    }
};

#endif