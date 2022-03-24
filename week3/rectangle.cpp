#include "muur.hpp"

	void rectangle::draw(hwlib::window &w){
			int_fast16_t xDraw, yDraw;
			for(int i = start.at(0); i <= end.at(0); i++){
				for(int j = start.at(1); j <= end.at(1); j++){
					xDraw = i;
					yDraw = j;
					if(j == start.at(0) || i == start.at(1)|| j == end.at(0) || i == end.at(1)){
						w.write(hwlib::xy(xDraw, yDraw) , hwlib::black);
					}
				}
			}
	}
