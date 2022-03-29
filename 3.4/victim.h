#ifndef V2CPSE1_EXAMPLES_VICTIM_H
#define V2CPSE1_EXAMPLES_VICTIM_H
#include "muur.hpp"
#include "ball.h"

//Victim
class victim : public muur{
protected:
    bool hitted;
    int decrease_factor;
public:
    victim(hwlib::window & w, int start_x, int start_y, int end_x, int end_y, int decrease) :
            muur(w, start_x, start_y, end_x, end_y, -1),
            hitted(false),
            decrease_factor(decrease)
    {}

    void check_collission(std::vector<ball *> objects);
    void update() override;
};

#endif //V2CPSE1_EXAMPLES_VICTIM_H
