// #include <stdio.h>
// #include <string.h>

// void fatal(char *msg)
// {
//     fputs(msg, stderr);

//     exit(1);
// }
// int occurances(const char *s, const char *word)
// {
//     int counter = 0;

//     char *pw = strstr(s, word);

//     while(pw)
//     {
//         counter++;

//         pw = strstr(pw + strlen(word), word);
//     }
//     return counter;
// }

// int main(int argc, char *argv[])
// {
//     if(argc >= 2)
//     {
//         char s[101]="", aux[101], *ptr;

//         //we take the word we're looking for as argv[1]

//         int counter = 0;

//         if(scanf("%100s", aux) != 1)
//         {
//             fatal("Error reading");
//         }

//         ptr = aux;

//         counter += p=occurances(aux, argv[1]);

//         while((scanf("%100s",s)) == 1)
//         {
//             counter += occurances(s, argv[1]);
//         }
//         printf("%s appears: %d times in %s\n", argv[1], counter, s);
//     }

//     return 0;
// }

//problem 6 , pb2 

#include <stdio.h>
#include <string.h>
#include <math.h>

//prototype
void makeTimeDifference(int h1, int m1, int s1, int h2, int m2, int s2)
{
    char buff[101] = "";

    int hour_diff = 0, minute_diff = 0, seconds_diff = 0;

    int total_seconds = abs(h2 - h1) * 3600 + abs(m2 - m1) * 60 + abs(s2 - s1);

    
    sprintf(buff, "%d:%d:%d", hour_diff, minute_diff, seconds_diff);

    fputs(buff, stdout);
}

int main()
{
    int time[101][4], n = 0, h, m, s;

    while((scanf("%d:%d:%d", &h, &m, &s) == 3))
    {
        // printf("%d %d %d\n", h, m, s);

        //time[n][0] = hours, time[n][1] = minutes, time[n][2] = seconds, time[n][3] = s + m * 60 + h * 3600
        time[0][]
    }

    return 0;
}
