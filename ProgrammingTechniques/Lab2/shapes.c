#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "utils.h"

#define DBG 0

// enum for option GEOMETRIC SHAPE selector
enum shape_t
{
    TRIANGLE = 1,
    CIRCLE = 2,
    RECTANGLE = 3
};

// structure to hold data required to process point
typedef struct _point
{
    float x;
    float y;
} point;

// structure to hold data required to process triangles
typedef struct _triangle
{
    point p1, p2, p3;
} triangle;

// structure to hold data required to process circles
typedef struct _circle
{
    point origin;
    float radius;
} circle;

// structure to hold data required to process rectangles
typedef struct _rectangle
{
    point A, B;
} rectangle;

// structure to store user input shapes
typedef struct _geometricShape
{
    enum shape_t flag : 2;

    union
    {
        triangle T;
        circle C;
        rectangle R;
    } shape;

} geometricShape_t;

geometricShape_t shapelist[101];

void PrintAllShapes(int n)
{
    #if DBG == 1
        printf("Here we print stuff\n");
    #endif

    int countT = 0, countC = 0, countR = 0;

    for(int i = 0; i < n; ++ i)
    {
        switch (shapelist[i].flag)
        {
            //we print a triangle
            case 1:
            {
                countT++;

                printf("\n%d-th triangle", countT);

                printf("P1(%f, %f)\n", shapelist[i].shape.T.p1.x, shapelist[i].shape.T.p1.y);
                printf("P2(%f, %f)\n", shapelist[i].shape.T.p2.x, shapelist[i].shape.T.p2.y);
                printf("P3(%f, %f)\n", shapelist[i].shape.T.p3.x, shapelist[i].shape.T.p3.y);

                break;
            }   

            //we print a circle
            case 2:
            {
                countC ++;
                
                printf("\n%d-th circle", countC);

                printf("Origin(%f, %f)\n", shapelist[i].shape.C.origin.x, shapelist[i].shape.C.origin.y);
                printf("Radius of the circle: %f\n", shapelist[i].shape.C.radius);

                break;
            }

            //we print a rectangle
            case 3:
            {
                countR++;

                printf("\n%d-th rectangle", countR);

                printf("P1(%f, %f)\n", shapelist[i].shape.R.A.x, shapelist[i].shape.R.A.y);
                printf("P2(%f, %f)\n", shapelist[i].shape.R.B.x, shapelist[i].shape.R.B.y);

                break;
            }
        }
    }
}

geometricShape_t initTriangle(geometricShape_t p)
{
    p.flag = 0;

    p.shape.T.p1.x = 0;
    p.shape.T.p1.y = 0;

    p.shape.T.p2.x = 0;
    p.shape.T.p2.x = 0;

    p.shape.T.p3.x = 0;
    p.shape.T.p3.x = 0;

    return p;
}

geometricShape_t initCircle(geometricShape_t p)
{
    p.flag = 0;

    p.shape.C.origin.x = 0;
    p.shape.C.origin.y = 0;
    
    p.shape.C.radius = 0;

    return p;
}

geometricShape_t initRectangle(geometricShape_t p)
{
    p.flag = 0;

    p.shape.R.A.x = 0;
    p.shape.R.A.y = 0;

    p.shape.R.B.x = 0;
    p.shape.R.B.y = 0;

    return p;
}

int main()
{
    int index = 0;

    do
    {
        int userOption = -1;

        while(userOption == -1)
        {
            MainMenu();

            if(scanf("%d[^\n]", &userOption) == 1)
            {
                if(!checkOption(userOption))
                {
                    userOption = -1;
                }
            }
        }

        #if DBG == 1
            printf("User options inputed: %d\n", userOption);
        #endif

        switch (userOption)
        {
            case 1:
            {
                //in this case we let the user to choose what shape to be entered

                ShapeSelectorMenu();

                int shapeOption = 0;

                if(scanf("%d[^\n]", &shapeOption) == 1)
                {
                    if(checkOption(shapeOption))
                    {
                        switch (shapeOption)
                        {
                            case 1:
                            {
                                shapelist[index] = initTriangle(shapelist[index]);

                                puts("=== Let's add a triangle! ===");

                                puts("Introduce 3 points in 2D");

                                float x1, x2, x3;
                                float y1, y2, y3;

                                shapelist[index].flag = TRIANGLE;

                                printf("P1(x, y): ");

                                if(scanf("%f %f[^\n]", &x1, &y1) == 2)
                                {
                                    shapelist[index].shape.T.p1.x = x1;
                                    shapelist[index].shape.T.p1.y = y1;
                                }

                                printf("P2(x, y): ");
                                
                                if(scanf("%f %f[^\n]", &x2, &y2) == 2)
                                {
                                    shapelist[index].shape.T.p1.x = x2;
                                    shapelist[index].shape.T.p1.y = y2;
                                }
                                
                                printf("P3(x, y): ");

                                if(scanf("%f %f[^\n]", &x3, &y3) == 2)
                                {
                                    shapelist[index].shape.T.p1.x = x3;
                                    shapelist[index].shape.T.p1.y = y3;
                                }

                                index++;

                                break;
                            }

                            case 2:
                            {
                                puts("=== Let's add a circle! ===");

                                puts("Introduce the center in 2D");
                                puts("Introduce the radius");

                                shapelist[index] = initCircle(shapelist[index]);

                                float x, y, r;

                                shapelist[index].flag = CIRCLE;

                                printf("O(x, y): ");

                                if(scanf("%f %f[^\n]", &x, &y) == 2)
                                {
                                    shapelist[index].shape.C.origin.x = x;
                                    shapelist[index].shape.C.origin.y = y;
                                }

                                printf("Radius: ");

                                if(scanf("%f[^\n]", &r) == 1)
                                {
                                    shapelist[index].shape.C.radius = r;
                                }

                                index++;
                                break;
                            }
                            
                            case 3:
                            {
                                puts("=== Let's add a rectangle! ===");

                                puts("Introduce 2 points in 2D");

                                shapelist[index] = initCircle(shapelist[index]);

                                float x1, y1, x2, y2;

                                shapelist[index].flag = RECTANGLE;

                                printf("P1(x, y): ");

                                if(scanf("%f %f[^\n]", &x1, &y1) == 2)
                                {
                                    shapelist[index].shape.R.A.x = x1;
                                    shapelist[index].shape.R.A.y = y1;
                                }

                                printf("P2(x, y): ");
                                
                                if(scanf("%f %f[^\n]", &x2, &y2) == 2)
                                {
                                    shapelist[index].shape.R.B.x = x2;
                                    shapelist[index].shape.R.B.y = y2;
                                }
                            
                                index++;

                                break;
                            }
                        }
                    }
                }

                break;
            }

            case 2:
            {
                //print all stored shapes in shapelist

                PrintAllShapes(index);

                break;
            }

            case 3:
            {
                //double check if the user 100% wants to exit
                ExitGeometry();

                break;
            }
        }
        
    } while (1);
    

    return 0; 
}
