#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <ctime>
#include "olcPixelGameEngine.h"

class GameObject
{
public:
	
	/********* Variables *********/
	double posX;
	double posY;
	float mass;
	float dx;
	float dy;
	float rotation;


	// yes or no to apply gravity
	bool gravity;

	// gives each object a unique ID
	int objectID;

	// object category. Is it a enemy?  a friendly? prevents having to keep track of all friendly players ID
	std::string objectCat;
	
	// The object image
	/*olc::Pixel image2d[20][20] = {
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
		olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),olc::Pixel(255,255,255),
	};
	*/

	/***********************************
	* CONSTRUCTORS
	***********************************/
	GameObject();
	GameObject(double x, double y);
	~GameObject();
	/*****************************
	* FUNCTIONS
	******************************/

	void applyGravity(float fElapseTime);

}; // END OF GAME-OBJECT






/*****************************
* CONSTRUCTOR
******************************/
	GameObject :: GameObject()
	{
		objectCat = "None";
		srand(2345);  // Initialize random number generator.
		objectID = rand() % 100000; // give the object a random number
		// Its possible that multiple objects will get the same ID
		// But its extremely unlikely I believe.
		// Potential fix is to keep a list of all ID's and compare. but I'll do that later.

		gravity = false;
		posX = 10.0f;
		posY = 10.0f;
		mass = 1.0f;
		rotation = 0.0f;
		dx = 0.0f;
		dy = 0.0f;
	}

	/*****************************
	* CONSTRUCTORS
	******************************/
	GameObject :: GameObject(double x, double y)
	{
		std::cout << "something";
		objectCat = "None";
		srand(2345);  // Initialize random number generator.
		objectID = rand() % 100000; // give the object a random number
		// Its possible that multiple objects will get the same ID
		// But its extremely unlikely I believe.
		// Potential fix is to keep a list of all ID's and compare. but I'll do that later.

		gravity = false;
		posX = x;
		posY = y;
		mass = 1.0f;
		rotation = 0.0f;
		dx = 0.0f;
		dy = 0.0f;
	}

	/*****************************
	* CONSTRUCTORS
	******************************/
	GameObject :: ~GameObject()
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
	void  GameObject :: applyGravity(float fElapseTime)
	{
		posY -= 2 * fElapseTime;
		return;
	}


#endif // !GAMEOBJECT