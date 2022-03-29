#include <hwlib.hpp>
#include <vector>
#include "muur.hpp"
#include "victim.h"

int main(){
	uint_fast16_t radius = 5;
	hwlib::target::window w( hwlib::xy( 180, 180));
	
	//Muren
	muur muur1(w, 5,5,9,145, 100);
	muur muur2(w, 5,5,145,9, 100);
	muur muur3(w, 5,141,145,145, 100);
	muur muur4(w, 141,5,145,145, 100);
	
	//Victim
	victim v(w, 45, 45, 60, 60, 1);
	
	//Ball
	ball bb(w, 90,50, radius, 1.4F, 1.0F);
	
	//Vectors
	std::vector<muur *> objects = {&muur1, &muur2, &muur3, &muur4};
	std::vector<ball *> moveable_objects = {&bb};
 
	   for(;;){ 
		   w.poll();
		   hwlib::wait_ms(40);
		   w.clear();
			for(auto & obj : objects){
				obj->update();
			}
			v.update();
			v.check_collission(moveable_objects);
			
			for(auto & obj : moveable_objects){
				obj->update();
                obj->check_collission(objects);
			}
			w.flush();
		}
}