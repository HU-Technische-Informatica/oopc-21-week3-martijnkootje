#ifndef MUUR_HPP
#define MUUR_HPP
#include "hwlib.hpp"
#include <vector>

//Drawable
class drawable{
protected:
	hwlib::window &w;
public:
	drawable(hwlib::window &w) : 
		w(w)
		{}
		
	virtual void draw(){}
	virtual void update(){}
};

//Rectangle
class rectangle : public  drawable{
protected:
	hwlib::window & w;
	std::vector<int> start;
	std::vector<int> end;
public:
	rectangle(hwlib::window & w, int start_x, int start_y, int end_x, int end_y)
		: drawable(w),
		w(w), 
		start({start_x, start_y}), 
		end({end_x, end_y})
		{}
		
	void draw() override;
};
//Muur
class muur : public rectangle{
protected:
    int update_count;
    bool filled;
    int toggle_interval;

public:
    muur(hwlib::window & w, int start_x, int start_y, int end_x, int end_y, int toggle):
            rectangle(w, start_x, start_y, end_x, end_y),
            update_count(1),
            filled(false),
            toggle_interval(toggle)
    {}
    void draw() override;
    void update() override;
    std::vector<int> getlocationstart(){return start;}
    std::vector<int> getlocationend(){return end;}
};

#endif // MUUR_HPP
