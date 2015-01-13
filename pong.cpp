
#include "pong.h"
#include "renderer.h"
#include <vector>
#include <math.h>



const int PADDLE_WIDTH = 3;
const int PADDLE_HEIGHT = 100;
const int BALL_DIAMETER = 7;




Pong::Pong(int mode){

	gameMode = mode;
	endGame = false;


}

void Pong::StartGame(){
	cout << "start game" <<endl;

	Renderer *renderer = new Renderer(screenWidth, screenHeight);

    Shape *ball = new Shape();

    ball->SetWidth(BALL_DIAMETER);
    ball->SetHeight(BALL_DIAMETER);
    ball->SetCenter(screenWidth/2.0, screenHeight/2.0);
    ball->SetVelocity(3, 0);


	Shape *player_1 = new Shape();

	player_1->SetWidth(PADDLE_WIDTH);
    player_1->SetHeight(PADDLE_HEIGHT);
    player_1->SetCenter(10,screenHeight/2.0);

    Shape *player_2 = new Shape();

    player_2->SetWidth(PADDLE_WIDTH);
    player_2->SetHeight(PADDLE_HEIGHT);
    player_2->SetCenter(screenWidth-10,screenHeight/2.0);





    
    std::vector<Shape*> shapes;

    shapes.push_back(player_1);
    shapes.push_back(player_2);
    shapes.push_back(ball);


 

    SDL_Event event; 

    bool upPressed = false;
    bool downPressed = false;

    while (!endGame)
    {


        while (SDL_PollEvent(&event))
        {
         
            if (event.type == SDL_QUIT)
            {
                endGame = true;
            }
            
            if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE))//release a key
            {
                endGame = true;
            }

            if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_p) )
            {
            	if (!isPaused) isPaused = true;
            	else isPaused = false;
            }

            if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) )
            {
                upPressed = true;
            }
            else
            {
                upPressed = false;
            }


            if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) )
            {
                downPressed = true;
            }
            else
            {
                downPressed = false;
            }

        }


        //logic 

        //paddle 1 movement
        int paddle_1_y = player_1->GetY();
        Rect paddle_1_rect;
        paddle_1_rect.X1 = 10-(PADDLE_WIDTH/2.0);
        paddle_1_rect.X2 = 10+(PADDLE_WIDTH/2.0);
        paddle_1_rect.Y1 = paddle_1_y-(PADDLE_HEIGHT/2.0);
        paddle_1_rect.Y2 = paddle_1_y+(PADDLE_HEIGHT/2.0);

        if (upPressed)
        {
            if (paddle_1_y - (PADDLE_HEIGHT/2.0) > 0)
                player_1->SetY(player_1->GetY() - 5);
   
            
        }
        else if (downPressed)
        {
            
            if (paddle_1_y + (PADDLE_HEIGHT / 2.0) < screenHeight)
                player_1->SetY(player_1->GetY() + 5);

    
        }




        //network
        //need player 2's y.
        //I send my y



    

        //listen on network for location

        int paddle_2_y = player_2->GetY();
        Rect paddle_2_rect;
        paddle_2_rect.X1 = (screenWidth-10)-(PADDLE_WIDTH/2.0);
        paddle_2_rect.X2 = (screenWidth-10)+(PADDLE_WIDTH/2.0);
        paddle_2_rect.Y1 = paddle_2_y-(PADDLE_HEIGHT/2.0);
        paddle_2_rect.Y2 = paddle_2_y+(PADDLE_HEIGHT/2.0);





        


        //ball movement and interaction
        Velocity v = ball->GetVelocity();
        int vx = v.x;
        int vy = v.y;

        Point current_center = ball->GetCenter();

        Rect ball_rect;
        ball_rect.X1 = current_center.x-(BALL_DIAMETER/2.0);
        ball_rect.X2 = current_center.x+(BALL_DIAMETER/2.0);
        ball_rect.Y1 = current_center.y-(BALL_DIAMETER/2.0);
        ball_rect.Y2 = current_center.y+(BALL_DIAMETER/2.0);

        if(RectInRect(ball_rect, paddle_1_rect) || RectInRect(ball_rect, paddle_2_rect)){
             ball->SetVelocity(vx*-1, vy);
        } 


        if ( (current_center.x - (BALL_DIAMETER/2.0) < 0 ) || ( current_center.x + (BALL_DIAMETER/2.0) > screenWidth) ) 
        {
            ball->SetVelocity(vx*-1, vy);
        }

        if ( (current_center.y - (BALL_DIAMETER/2.0) < 0 ) || ( current_center.y + (BALL_DIAMETER) > screenHeight) ) 
        {
            ball->SetVelocity(vx, vy*-1);
        }

        ball->SetCenter(current_center.x + ball->GetVelocity().x, current_center.y + ball->GetVelocity().y);






        //render
        renderer -> InitRenderFrame();

        for (int i = 0; i < shapes.size(); ++i)
        {
             renderer -> RenderFrame(shapes.at(i)); 
        }
        

        renderer -> CleanRenderFrame();

        // SDL_Delay(100);//ms

   }

	
}

bool Pong::RectInRect(Rect rect1, Rect rect2){

    if (rect1.X1 < rect2.X2 && rect1.X2 > rect2.X1 &&
    rect1.Y1 < rect2.Y2 && rect1.Y2 > rect2.Y1){
        return true;
    } 

    return false;
}

void Pong::TogglePause(){
	cout << "pause game" <<endl;
}


void Pong::SetScreen(int width, int height){
	screenWidth = width;
    screenHeight = height;
}



//event handling

//