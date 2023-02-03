# Ball-Physics
Ball physics collision system. I'm slowly adding physics formulas to achieve a somewhat realistic collision.   My original goal was to recreate the code found in this youtube video https://www.youtube.com/watch?v=SqpIcsN0FTI&t=117s  I did this because I wanted to be able to explain how and why the "bug" is doing what its doing. I've successfully recreated it except for the collision system, it currently calculates physics in a repeatable order causing some object to push and never be pushed.

For those that want to visualize the collision math, I made these desmos graphs.  One is fixed on the origin to help mentally grasp it, the second is the floating point calculations.

[Fixed Position Collision](https://www.desmos.com/calculator/eufaxdhxzk)

[Floating Position Collision](https://www.desmos.com/calculator/qxiidphkfm)

This is a side project and will not be updated frequently and is merely for fun.


- gameObject.h is supossed to be a parent class for all objects to derive from but it will only be implimented when I start to use other shapes. Making it more than just a ball collision system and more of a engine.

- circle.h is gameObject but changed to allow me to quickly impliment collision for just balls. For this project, circle.h is all I will use. 

# Graphics is done by using the [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) and is not a work of my own.
![Ball Physics](https://github.com/BrandonJarrell/Ball-Physics/blob/main/Ball_collisionv2.gif)
