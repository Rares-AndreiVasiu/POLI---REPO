//we check if the user typed correct input
int checkOption(int x)
{
    if(x < 1 || x > 3)
    {
        return 0;
    }

    return 1;
}

int checkShapeOption(int x)
{
    if(x < 1 || x > 3)
    {
        return 0;
    }

    return 1;
}

//main menu declaration
void MainMenu()
{
    // system("clear");

    printf("== Welcome to Geometry! ==\n");
    
    printf("Add Shape: press 1\n");

    printf("Print Shapes: press 2\n");
    
    printf("Exit Geometry: press 3\n");
}

void ExitGeometry()
{
    // system("clear");

    printf("You are about to leave the programm\n");
    printf("Confirm: press 1\n");
    printf("Abort: press 0\n");

    int exit_option = 0;
    int x = 1; 

    if(scanf("%d[^\n]", &exit_option) == 1)
    {
        switch (exit_option)
        {
            case 0:
            {
                MainMenu(&x);
                break;
            }
            
            default:
            {
                exit(1);

                break;
            }
        }
    }
}

void ShapeSelectorMenu()
{
    // system("clear");

    printf("Add triangle: press 1\n");

    printf("Add circle: press 2\n");

    printf("Add rectangle: press 3\n");
}