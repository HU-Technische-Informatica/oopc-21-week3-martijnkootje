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
		
	virtual void draw(hwlib::window &w){}
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
		
	void draw(hwlib::window &w) override;
};

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
	
	void draw(hwlib::window &w) override;
	void collide(bool x, bool y);
	void update();
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
		
	void check_collission(std::vector<ball *> objects);
	void draw(hwlib::window &w) override;
	void update();
};

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

#endif // MUUR_HPP
