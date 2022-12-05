#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "gameObject.h"
#include "circle.h"

#include <list>
//#include <string>

class Example : public olc::PixelGameEngine
{

private:
	//std::list<gameObject> objects;
	
	double cameraX;
	double cameraY;

	// Calculate once
	int screenCenterX;
	int screenCenterY;

	// GameObject counter
	long int gameObjectCount = 0;



	std::list<Circle>::iterator index;
	std::list<Circle> objectsList = 
	{ Circle(450,50, 10), Circle(100,50, 20), Circle(100,-10, 30)
		, Circle(100,-150, 40), Circle(-80,-150, 50),Circle(0,0, 60),
	//Circle(350,50, 10), Circle(10,50, 20), Circle(150,-10, 8)
	//	, Circle(100,-50, 50), Circle(-80,-10, 10),Circle(1,0, 10) 
	};
	std::list<Circle> *objectsListP = &objectsList;

public:
	Example()
	{
		sAppName = "Game";
	}

	// Draws the object on the screen, while translating world space to screen space
	void drawObject()
	{
		for (index = objectsList.begin(); index != objectsList.end(); index++)
		{
			// convert world space to screen space
			int screenX = int(screenCenterX + index->posX - cameraX);
			int screenY = int(screenCenterY - (index->posY - cameraY));

			// dont draw it if its not in the screen (based on center, not image size)
			/*
			if (screenX > ScreenWidth() || screenX < 0 || screenY > ScreenHeight() || screenY < 0) // || screenY > ScreenHeight() || screenX < 0)
			{
				return;
			}

			// Modify the screen position because drawing starts at top left
			screenX -= object.radius;
			screenY -= object.radius;

			for (int y = 0; y < height; y++)
				for (int x = 0; x < width; x++)
					Draw(screenX + x, screenY + y, object.image2d[x][y]);
			*/

			FillCircle(screenX, screenY, index->radius, olc::Pixel(255, 255, 255));
		}
		return;
	}


	bool OnUserCreate() override
	{
		//circle = new gameObject();
		cameraX = 0.0f;
		cameraY = 0.0f;
		screenCenterX = int(ScreenWidth() / 2);
		screenCenterY = int(ScreenHeight() / 2);
		// Called once at the start, so create things here

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		/**************************************************************
		* PHYSICS UPDATE
		**************************************************************/
		int counter = 0;
		for (index = objectsList.begin();counter < objectsList.size(); index++, counter++)
		{
			index->calcVelocity(fElapsedTime, objectsListP);
		}
		//circle.calcVelocity(fElapsedTime, objectsListP);
		//circle2.calcVelocity(fElapsedTime, objectsListP);
		//circle3.calcVelocity(fElapsedTime, objectsListP);
		//circle4.calcVelocity(fElapsedTime, objectsListP);

		//std::cout << "\n#####################################\n";



		if (GetKey(olc::Key::A).bHeld) cameraX -= 20.0f * fElapsedTime;
		//Right
		if (GetKey(olc::Key::D).bHeld) cameraX += 20.0f * fElapsedTime;
		// Down
		if (GetKey(olc::Key::S).bHeld) cameraY -= 20.0f * fElapsedTime;
		//UP
		if (GetKey(olc::Key::W).bHeld) cameraY += 20.0f * fElapsedTime;

		/**************************************************************
		* PIXEL UPDATE
		**************************************************************/
		Clear(olc::Pixel(0,0,0));
		///////////////////////////////////////////////////////////////

		//std::list<Circle>::iterator index;
		//for (index = objectsList.begin(); index != objectsList.end(); index++)
		//{
		//	//drawObject(index->dx);
		//}

		drawObject();


		/**************************************************************
		* UI UPDATE
		**************************************************************/

		// Horizontal
		DrawLine(0, screenCenterY, ScreenWidth(), screenCenterY, olc::Pixel(0, 255, 0));
		// Vertical
		DrawLine(screenCenterX, 0, screenCenterX, ScreenHeight(), olc::Pixel(0, 255, 0));


		return true;
	}
};


int main()
{
	Example game;
	if (game.Construct(500, 500, 1, 1))
		game.Start();

	return 0;
}