/*
 * input.c
 * Copyright 2017 dogol peezon <dogol@peezon>
 * 
 */

#include <stdio.h>

/*In accessable scope*/
GLboolean upPressed = false;

/*In the glutSpecialFuc()*/
void SpecialKeys(int key, int x, int y)
{
	//...
	//stuff
	//...
	if(GLUT_KEY_UP == key){
		upPressed = true;
	}
}

/*In the glutSpecialUpFunc()*/
void SpecialKeysUp(int keys, int x, int y)
{
	//...
	//stuf
	//...
	if(GLUT_KEY_UP == key){
		upPressed = false;
	}
}

/*In the glutIdleFunc()*/
void update()
{
	//...
	//stuff
	//...
	if(upPressed){
		//movement
	}
}
int main(int argc, char **argv)
{
	
	return 0;
}

