#ifndef V2CPSE1_EXAMPLES_BALL_H
#define V2CPSE1_EXAMPLES_BALL_H
#include "muur.hpp"

//Ball
class ball : public drawable{
protected:
    hwlib::window &w;
    std::vector <float> location;
    uint_fast16_t radius;
    std::vector<float> speed;

public:
    ball(hwlib::window &w, float loc_x, float loc_y, uint_fast16_t radius, float speed_x, float speed_y) :
            drawable(w),
            w(w),
            location({loc_x, loc_y}),
            radius(radius),
            speed({speed_x, speed_y})
    {}

    bool collided = false;
    int getradius(){return radius;}
    std::vector<float> getlocation(){return location;}
    std::vector<float> getspeed(){return speed;}

    void draw() override;
    void collide(bool x, bool y);
    void check_collission(std::vector<muur *> objects);
    void update() override;
};

#endif //V2CPSE1_EXAMPLES_BALL_H
