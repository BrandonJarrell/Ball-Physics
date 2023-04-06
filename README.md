# Ball-Physics
My goal was to prove and explain why the "bug" works like it does found in this youtube video https://www.youtube.com/watch?v=SqpIcsN0FTI&t=117s  I did this because I was very intrigued by what it was doing. I've successfully recreated it except for the collision system, it currently calculates physics in a repeatable order causing some object to push and never be pushed. It's now a simple ball physics collision system which I am slowly adding physics formulas to achieve a somewhat realistic collision.   

For those that want to visualize the collision math, I made these desmos graphs.  One is fixed on the origin to help mentally grasp it if needed, the second is the floating point calculations.

[Fixed Position Collision](https://www.desmos.com/calculator/eufaxdhxzk)

[Floating Position Collision](https://www.desmos.com/calculator/qxiidphkfm)

This is a side project and will not be updated frequently and is merely for fun. The gravity physics is not accurate, everything orbits for simplicity.


- gameObject.h is supossed to be a parent class for all objects to derive from but it will only be implimented when I start to use other shapes. Making it more than just a ball collision system and more of a engine.

- circle.h is gameObject but changed to allow me to quickly impliment collision for just balls. For this project, circle.h is all I will use. 

# Graphics are done by using a OpenGL tool [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) and is not a work of my own.
![Ball Physics](https://github.com/BrandonJarrell/Ball-Physics/blob/main/Ball_collisionv2.gif)
