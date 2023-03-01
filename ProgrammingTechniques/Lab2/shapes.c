#include  <stdio.h>
#include  <stdlib.h>

//enum for option GEOMETRIC SHAPE selector
enum shape_t{
	TRIANGLE = 1,
	CIRCLE = 2,
	RECTANGLE = 3
};

//structure to hold data required to process point
typedef struct _point
{
	float x;
	float y;
} point;

//structure to hold data required to process triangles
typedef struct _triangle
{
	point p1, p2, p3;
}triangle;


//structure to hold data required to process circles
typedef struct _circle
{
	point origin;
	float radius;
}circle;

//structure to hold data required to process rectangles
typedef struct _rectangle
{
	point A, B;
}rectangle;

// functions used for checking user input
int checkMainMenuOption(int opt)
{
	if(opt != 1 &&  opt != 2)
	{
		return 0;
	}

	return 1;
}

//structure to store user input shapes
struct geometricShape
{
	enum shape_t flag;

	union
	{
		triangle T;
		circle C;
		rectangle R;
	}shape;

}shapelist[101];

int checkShapeOption(int opt_shape)
{
	if(opt_shape > 3 || opt_shape < 1)
	{
		return 0;
	}

	return 1;

}

void TriangleMenu(int index)
{
	printf("Add 3 coordinates for the following triangle\n");
	printf("Add the coordinates separated with a single space\n");
	printf("for example: 3 4.6 5 6 8.01 7\n");

	float a, b, c, d, e, f;

	shapelist[index].flag = TRIANGLE;

	if(scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f) == 6)
	{
		shapelist[index].shape.T.p1.x = a;
		shapelist[index].shape.T.p1.y = b;
		shapelist[index].shape.T.p2.x = c;
		shapelist[index].shape.T.p2.y = d;
		shapelist[index].shape.T.p3.x = e;
		shapelist[index].shape.T.p3.y = f;
	}

	printf("%f %f %f %f %f %f\n", shapelist[index].shape.T.p1.x, shapelist[index].shape.T.p1.y, shapelist[index].shape.T.p2.x, shapelist[index].shape.T.p2.y, shapelist[index].shape.T.p3.x, 
			shapelist[index].shape.T.p3.y);
}

void CircleMenu()
{
	printf("Add the coordinates for the origin and the radius of the circle\n");
}

void RectangleMenu()
{
	printf("Add the coordinates for the origin and the radius of the circle\n");
}

void ShapeSelectorMenu(int index)
{
	printf("OK let's add a geometric Shape\n");
	printf("Press 1 to add a triangle\n");
	printf("Press 2 to add a circle\n");
	printf("Press 3 to add a rectangle\n");

	int shape_option = 0;

	if(scanf("%d", shape_option) == 1)
	{
		if(checkShapeOption(shape_option))
		{
			system("clear");
			
			index++;

			switch(shape_option)
			{
			
			case 1:
			{
				TriangleMenu(index);
				
			}
			case 2:
			{
				CircleMenu(index);
				
			}
			case 3:
			{
				RectangleMenu(index);
				
			}
			}
		}
	}
}


void Menu()
{
	int index = 0;

	int option_menu = 0;

	printf("Welcome to geometry class!\n");
	
	printf("if you want to exit the class, press 1, and if you want to add a shape press 2\n");
	
	if(scanf("%d", &option_menu) == 1)
	{
		if(checkMainMenuOption(option_menu))
		{
			system("clear");

			switch(option_menu)
			{
				case 1:{
					exit(1);
				       }
				case 2:
				       {
					       ShapeSelectorMenu(index);
					       
				       }
			}
		}
	}
				
}

int main()
{
	int index = 0;

	while(1)
	{
		Menu(index);

	}

	return 0;
}
