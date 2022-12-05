#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <list>
#include "olcPixelGameEngine.h"

class Circle
{
public:
	
	/********* Variables *********/
	double posX;
	double posY;
	float mass;
	float dx;
	float dy;
	float rotation;

	int radius;

	// yes or no to apply gravity
	bool gravity;

	// gives each object a unique ID
	int objectID;

	// object category. Is it a enemy?  a friendly? prevents having to keep track of all friendly players ID
	std::string objectCat;
	
	/***********************************
	* CONSTRUCTORS
	***********************************/
	Circle();
	Circle(double x, double y, int r);
	~Circle();
	/*****************************
	* FUNCTIONS
	******************************/

	void applyGravity(float fElapseTime);
	void calcVelocity(float fElapseTime, std::list<Circle>* objectListP);

}; // END OF GAME-OBJECT






/*****************************
* CONSTRUCTOR
******************************/
	Circle :: Circle()
	{
		objectCat = "None";
		srand(time(0));  // Initialize random number generator.
		objectID = rand() % 100000; // give the object a random number
		// Its possible that multiple objects will get the same ID
		// But its extremely unlikely I believe.
		// Potential fix is to keep a list of all ID's and compare. but I'll do that later.

		gravity = true;
		posX = 10.0f;
		posY = 10.0f;
		mass = 1.0f;
		rotation = 0.0f;
		dx = 0.0f;
		dy = 0.0f;
		radius = 3;
	}

	/*****************************
	* CONSTRUCTORS
	******************************/
	Circle :: Circle(double x, double y, int r)
	{
		objectCat = "None";
		srand(time(NULL));  // Initialize random number generator.
		objectID = rand() % 100000; // give the object a random number
		// Its possible that multiple objects will get the same ID
		// But its extremely unlikely I believe.
		// Potential fix is to keep a list of all ID's and compare. but I'll do that later.

		gravity = true;
		posX = x;
		posY = y;
		mass = 1.0f;
		rotation = 0.0f;
		dx = 120.0f;
		dy = 0.0f;
		radius = r;
	}

	/*****************************
	* CONSTRUCTORS
	******************************/
	Circle :: ~Circle()
	{
		//delete image2d;
		//std::cout<<"done";
		return;
	}


/***************************************
** FUNCTIONS 
****************************************/

	/*****************************
	* APPLYGRAVITY
	******************************/
	void  Circle :: applyGravity(float fElapseTime)
	{
		//if (gravity)
		//	dy -= 400*fElapseTime; 

		float gForce = 400;
		//orbit gravity
		if (posX <= 0)
		{
			// clamp it to 0 is too small
			if (dx < 0.0001 && dx > 0)
				dx = 0;
			dx += gForce * 1.5 * fElapseTime;
		}
		else
		{
			// clamp it to 0 is too small
			if (dx < 0.001 && dx > 0)
				dx = 0;
			dx -= gForce * 1.5 * fElapseTime;
		}
		if (posY <= 0)
			dy += gForce*1.5 * fElapseTime;
		else
			dy -= gForce*1.5 * fElapseTime;

		return;
	}

	/*****************************
	* APPLYGRAVITY
	******************************/
	void  Circle::calcVelocity(float fElapseTime, std::list<Circle> * objectListP)
	{

		// add the previous velocity to the position
		posX += dx * fElapseTime/50;
		posY += dy * fElapseTime/50;


		// check for position and add gravity after because it can go beyond the screen
		if (gravity) applyGravity(fElapseTime);

		//detect collision
		std::list<Circle>::iterator index;
		for (index = objectListP->begin(); index != objectListP->end(); index++)
		{
			// Get the combine the two radi
			float minimum = radius + index->radius; 

			// if we are comparing to ourselves
			if(posX == index->posX && posY == index->posY)
			{
					break;
			}

			// X axis, Y axis
			// the point of reference is the object being compared to
			// this is because an object should (currently) only be
			// able to move itself.. basically, make a point of reference around the second
			float x = posX - index->posX;
			float y = posY - index->posY;

			// not sure what to say.. its m
			float squarer = sqrt(x*x + y*y);

			// if the distance between the two is below the |minimum| (absolute)
			if (squarer < minimum)
			{
				float multiple = minimum / squarer;
				posX = index->posX + x * multiple;
				posY = index->posY + y * multiple;
			}

			//if (collision)
			//{
			//	//			radius *2     this calculates how much we need to
			//	//		______________		multiply x and y by to ensure there is
			//	//		sqrt(x^2 + y^2)   no collision using the magnitude 
			//	//                     (distance between 2 same diameter balls)
			//	
			// 
			//}
		}
		


		/// WORLD RESTRICTIONS
		 //apply world restrictions last so it is always enforced.
		if (posX < -250 + radius)
		{
			posX = -250 + radius;
			dx = -dx/1.2;
		}
		if (posX > 250 - radius)
		{
			posX = 250 - radius;
			dx = -dx/1.2;
		}
		// Bounce in Y axis
		if (posY <= -200 + radius)
		{
			posY = -200 + radius;
			dy = -dy/1.2;

			// if its really low, set it to 0 so it doesn't get infinitely tiny.
			if (dy < 0.0001 && dy > 0)
				dy = 0;
		}
		return;
	}


#endif // !GAMEOBJECT