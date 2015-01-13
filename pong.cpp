
#include "pong.h"
#include "renderer.h"
#include <vector>

const int PADDLE_WIDTH = 3;
const int PADDLE_HEIGHT = 100;




Pong::Pong(int mode){

	gameMode = mode;
	endGame = false;


}

void Pong::StartGame(){
	cout << "start game" <<endl;

	Renderer *renderer = new Renderer(screenWidth, screenHeight);


	Shape *player_1 = new Shape();

	player_1->SetWidth(PADDLE_WIDTH);
    player_1->SetHeight(PADDLE_HEIGHT);
    player_1->SetCenter(10,screenHeight/2.0);

    Shape *player_2 = new Shape();

    player_2->SetWidth(PADDLE_WIDTH);
    player_2->SetHeight(PADDLE_HEIGHT);
    player_2->SetCenter(screenWidth-10,screenHeight/2.0);

    // shape->SetVelocity(3.0, 4.0);

    size_t size = 2;
    std::vector<Shape*> shapes;

    shapes.push_back(player_1);
    shapes.push_back(player_2);


 

    SDL_Event event; 


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

        }



        //logic
        //need these
        // cout << shape->GetVelocity().magnitude << endl;
        // cout << shape->GetVelocity().direction << endl;






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

void Pong::TogglePause(){
	cout << "pause game" <<endl;
}


void Pong::SetScreen(int width, int height){
	screenWidth = width;
    screenHeight = height;
}



//event handling

//