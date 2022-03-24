#include "muur.hpp"

//"...".at(0) = X
//"...".at(1) = Y
void muur::draw(hwlib::window &w) {
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
	this->draw(w);
}

void muur::check_collission(std::vector<ball *> objects){
	//checken voor elke ball of er een botsing plaatsvind
	for(auto & obj : objects){
		if(obj-> collided == false){
		int radius = obj->getradius();
		std::vector<float> location_ball = obj->getlocation();
		std::vector<float> speed_ball = obj->getspeed();
		
		//korte naam om coordinaten van een muur te pakken
		int start_x = start.at(0);
		int end_x = end.at(0);
		int start_y = start.at(1);
		int end_y = end.at(1);
		
		
		
		int col_x = 0;
		int col_y = 0;
		//Bewegen in x richting
		if(speed_ball.at(0) > 0){
			col_x = location_ball.at(0) + radius;
			
		//bewegen in y richting
		}else{
			col_x = location_ball.at(0) - radius;
		}
		
		//bewegen in y richting
		if(speed_ball.at(1) > 0){
			col_y = location_ball.at(1) + radius;
		}else{
			col_y = location_ball.at(1) - radius;
		}
		
		//check voor botsing
		
		//bots zijde x
		if(col_x <= end_x){
			if(col_x >= start_x){
				//bots zijde y
				if(col_y <= end_y){
					if(col_y >= start_y){
						
						if((end_x-start_x) >= (end_y-start_y)){
							//botst tegen een horizontale muur
							obj->collide(false, true);
						}else{
							//botst tegen een verticale muur
							obj->collide(true, false);
						}
					}
				}
			}
		}
		}
	}
}