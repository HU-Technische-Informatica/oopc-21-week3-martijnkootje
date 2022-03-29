#include "ball.h"

//draw functie circel uit hwlib, paar waaren aangepast
void ball::draw(){
	using namespace hwlib;
	
	// don't draw anything when the size would be 0 
      if( radius < 1 ){
         return;       
      }
	color ink = black;
	xy start = xy(location.at(0), location.at(1));
   
      int_fast16_t fx = 1 - radius;
      int_fast16_t ddFx = 1;
      int_fast16_t ddFy = -2 * radius;
      int_fast16_t x = 0;
      int_fast16_t y = radius;
    
      // top and bottom
      w.write( start + xy( 0, + radius ), ink );
      w.write( start + xy( 0, - radius ), ink );

      // left and right 
      w.write( start + xy( + radius, 0 ), ink );
      w.write( start + xy( - radius, 0 ), ink );
         
      // filled circle
      if(0){
   
         // top and bottom
         w.write( start + xy( 0, + radius ), ink );
         w.write( start + xy( 0, - radius ), ink );

         // left and right
         line(  
              start - xy( radius, 0 ), 
              start + xy( radius, 0 ), 
              ink 
          ).draw( w );
      } 
    
      while( x < y ){
      
         // calculate next outer circle point
         if( fx >= 0 ){
           y--;
           ddFy += 2;
           fx += ddFy;
         }
         x++;
         ddFx += 2;
         fx += ddFx;   
                    
         w.write( start + xy( + x, + y ), ink );
         w.write( start + xy( - x, + y ), ink );
         w.write( start + xy( + x, - y ), ink );
         w.write( start + xy( - x, - y ), ink );
         w.write( start + xy( + y, + x ), ink );
         w.write( start + xy( - y, + x ), ink );
         w.write( start + xy( + y, - x ), ink );
         w.write( start + xy( - y, - x ), ink );
            
         // filled circle
         if(0) if( ! ink.is_transparent()  ){
            line( 
               start + xy( -x,  y ), 
               start + xy(  x,  y ), 
               ink ).draw( w );
            line( 
               start + xy( -x, -y ), 
               start + xy(  x, -y ), 
               ink ).draw( w );
            line( 
               start + xy( -y,  x ), 
               start + xy(  y,  x ), 
               ink ).draw( w );
            line( 
               start + xy( -y, -x ), 
               start + xy(  y, -x ), 
               ink ).draw( w );
         }
      }
   } 

//bewegen van de ball
void ball::update(){
	
	location.at(0) = (location.at(0) + speed.at(0));
	location.at(1) = (location.at(1) + speed.at(1));
	draw();
	collided = false;
}

void ball::collide(bool x, bool y){
	
	//botsing tegen een verticale muur
	if(x){
		speed.at(0) = (speed.at(0) * -1);
	}
	//botsing tegen een horizontale muur
	if(y){
		speed.at(1) = (speed.at(1) * -1);
	}
	//beveiliging tegen dubbel botsen tegen de zelfde muur
	collided = true;
}

void ball::check_collission(std::vector<muur *> objects) {
    //checken voor elke ball of er een botsing plaatsvind
    for (auto &obj: objects) {
        if(!collided) {
            int col_x = 0;
            int col_y = 0;
            //Bewegen in x richting
            if (speed.at(0) > 0) {
                col_x = location.at(0) + radius;
            } else {
                col_x = location.at(0) - radius;
            }
            //bewegen in y richting
            if (speed.at(1) > 0) {
                col_y = location.at(1) + radius;
            } else {
                col_y = location.at(1) - radius;
            }

            //korte naam om coordinaten van een muur te pakken
            int start_x = obj->getlocationstart().at(0);
            int end_x = obj->getlocationend().at(0);
            int start_y = obj->getlocationstart().at(1);
            int end_y = obj->getlocationend().at(1);

//          check voor botsing
            if (col_x <= end_x) {
                if (col_x >= start_x) {
                    //bots zijde y
                    //bots zijde x
                    if ((end_x - start_x) <= (end_y - start_y)) {
                        //botst tegen een verticale muur
                        std::cout << "v" <<hwlib::endl;
                        collide(true, false);
                    }
                }
            }
            if (col_y <= end_y) {
                if (col_y >= start_y) {
                    if ((end_x - start_x) >= (end_y - start_y)) {
                        //botst tegen een horizontale muur
                        std::cout << "h" <<hwlib::endl;
                        collide(false, true);
                    }
                }
            }
        }
    }
}