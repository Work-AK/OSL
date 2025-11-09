#include <stdio.h>
#include <limits.h>

void print(int frames[], int frcount)
{
    for(int i = 0; i < frcount; i++)
    {
        if(frames[i] == -1)
            printf("_");
        
        else
            printf("%d", frames[i]);
    }
    
}


int main()
{
    //variables
    int frames[20], pages[20],recency[20],recent=0, pgcount = 0, frcount = 0, totalfault = 0, next = 0,index=0;

    printf("Enter the number of frames available: ");
    scanf("%d", &frcount);
    printf("Frames: %d", frcount);
    printf("\nEnter the number of pages: ");
    scanf("%d", &pgcount);
    printf("Page count: %d", pgcount);
    printf("\nEnter the page requests: \n");
    for(int i = 0; i < pgcount; i++)
    {
        printf("page %d: ", i+1);
        scanf("%d", &pages[i]);
    }
    //initialize frames to -1
    for(int i = 0; i < frcount; i++)
    {
        frames[i] = -1;
    }
    printf("========Page replacement algorithm - FIFO========\n");
    for(int i = 0; i < pgcount; i++)
    {
        int found = 0;
        int min = INT_MAX;
        for(int j = 0; j < frcount; j++)
        {
            if(pages[i] == frames[j])
            {
                found = 1;
                recency[j] = i;
                break;
            }
        }
        if(!found)
        {
            if(i<frcount){
                frames[i] = pages[i];
                recency[i] = i;
                }
            else{
                
                for(int k=0;k<frcount;k++)
                {             
                    if(min > recency[k])
                    {
                        min = recency[k];
                        index = k;
                    }
                }
                
                frames[index] = pages[i];
                recency[index] = i;
                
            }
            totalfault++;
            printf("page %2d inserted: ", pages[i]);
            print(frames, frcount);
            printf("\t----> PageFault\n");
        }
        else
        {
            printf("page %2d inserted: ", pages[i]);
            print(frames, frcount);
            printf("\t----> No PageFault\n");
        }
        
        
        
        
    }   
    printf("Fault count: %d", totalfault);
    printf("\nFault Rate: %.2f %%", ((float)totalfault / (float)pgcount) * 100);
    printf("\nHit Rate: %.2f %%", (((float)pgcount - (float)totalfault) / (float)pgcount) * 100);
    printf("\n=================================================");
    
    return 0;
}
