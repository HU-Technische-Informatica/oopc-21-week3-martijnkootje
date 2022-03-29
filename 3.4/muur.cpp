#include "muur.hpp"

void muur::draw() {
	int_fast16_t xDraw, yDraw;
	for(int i = start.at(0); i <= end.at(0); i++){
		for(int j = start.at(1); j <= end.at(1); j++){
			xDraw = i;
			yDraw = j;
			
			//Gevulde muren
			if(filled == true){
				w.write(hwlib::xy(xDraw, yDraw) , hwlib::black);
				
			//open muren
			}else if(j == start.at(0) || i == start.at(1) || j == end.at(0) || i == end.at(1) || i == start.at(0) || i == end.at(0) || j == start.at(1) || j == end.at(1)){
				w.write(hwlib::xy(xDraw, yDraw) , hwlib::black);
			}	
		}
	}
}

void muur::update(){
	update_count +=1;
	if(update_count == toggle_interval){
		filled = !filled;
		update_count = 0;
	}
	draw();
}
