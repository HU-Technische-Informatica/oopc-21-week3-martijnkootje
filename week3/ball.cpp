#include "muur.hpp"

//draw functie circel uit hwlib, paar waaren aangepast
void ball::draw(hwlib::window &w){
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
	this->draw(w);
	this->collided = false;
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