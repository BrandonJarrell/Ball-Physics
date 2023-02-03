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

	olc::vf2d * spawnPos = nullptr;




	std::list<Circle>::iterator index;
	std::list<Circle> objectsList = 
	{ Circle(40,30, 10), Circle(-40,30, 20), Circle(-40,-30, 20)
		, Circle(40,-30, 20), Circle(-80,-150, 10),Circle(0,0, 10),
	Circle(50,-20, 12), Circle(10,50, 8), Circle(150,-10, 8)
	, Circle(100,-50, 20), Circle(-80,-10, 12),Circle(1,10, 10)
	, Circle(100,-56, 20), Circle(-88,-10, 12),Circle(1,20, 10)
	, Circle(110,-50, 20), Circle(-86,-10, 12),Circle(1,30, 10)
	, Circle(100,-70, 20), Circle(-89,-10, 12),Circle(1,40, 10)
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

			FillCircle(screenX, screenY, index->radius, index->color);
		}
		return;
	}

	// Convert Screen coordinates to world coordinates
	olc::vi2d screenToWorldCoordinates(int x, int y)
	{	
		return olc::vi2d(x - screenCenterX, screenCenterY - y);
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
			// Time is currently multiplied by 2 just to speed test it
			index->calcVelocity(fElapsedTime*2, objectsListP);
		}


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
		if (GetMouse(olc::Mouse::LEFT).bPressed)
		{
			// CONVERT SCREEN SPACE TO WORLD SPACE 
			olc::vi2d pos = screenToWorldCoordinates(GetMouseX(), GetMouseY());
			spawnPos = new olc::vf2d(pos.x, pos.y);
		}

		if (GetMouse(olc::Mouse::LEFT).bReleased)
		{

			Circle newCircle = Circle(spawnPos->x, spawnPos->y, 10);

			olc::vi2d pos = screenToWorldCoordinates(GetMouseX(), GetMouseY());

			newCircle.dx = (spawnPos->x - pos.x)*1.5;
			newCircle.dy = (spawnPos->y - pos.y)*1.5;

			objectsListP->push_back(newCircle);
			delete spawnPos;
		}

		/**************************************************************
		* UI UPDATE
		**************************************************************/
		FillCircle(screenCenterX, screenCenterY, 2, olc::Pixel(0,255,0));

		// Horizontal
		//DrawLine(0, screenCenterY, ScreenWidth(), screenCenterY, olc::Pixel(0, 255, 0));
		// Vertical
		//DrawLine(screenCenterX, 0, screenCenterX, ScreenHeight(), olc::Pixel(0, 255, 0));


		return true;
	}
};


int main()
{
	Example game;
	if (game.Construct(1080, 720, 1, 1))
		game.Start();

	return 0;
}
