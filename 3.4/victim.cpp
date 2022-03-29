#include "victim.h"
	
void victim::update(){
	if(hitted == true){
		if(start.at(0) > 0 && start.at(1) > 0 && end.at(0) > 0 && end.at(1) > 0){
			start.at(0) = (start.at(0) + decrease_factor);
			start.at(1) = (start.at(1) + decrease_factor);
			end.at(0) = (end.at(0) - decrease_factor);
			end.at(1) = (end.at(1) - decrease_factor);
		}
	}
	draw();
}
//check of ball victim raakt
void victim::check_collission(std::vector<ball *> objects){
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
						
						if((end_x-start_x) > (end_y-start_y)){
							//botst tegen een X muur
							hitted = true;
						}else{
							//botst tegen een Y muur
							hitted = true;
						}
					}
				}
			}
		}
		}
	}
}