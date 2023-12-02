#include <stdio.h>
#include <time.h>

void displayTime(int seconds) {
    int hours, minutes;
    

    hours = seconds / 3600;
    seconds %= 3600;

    minutes = seconds / 60;
    seconds %= 60;
    if(hours ==0 && minutes>0 && seconds == 0)
        printf("Last %d minutes left!!\n", minutes);
    else
        printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}
int main() {
    int duration,duration1,duration2, remaining;
    time_t start, end;

    printf("Enter countdown duration in seconds: ");
    scanf("%d", &duration);
    printf("Enter countdown duration in minutes ");
    scanf("%d", &duration1);
    printf("Enter countdown duration in hours: ");
    scanf("%d", &duration2);

    time(&start);
    end = start + duration + duration1*60+ duration2*60*60;

    printf("Countdown Started: \n");

    while (1) {
        time(&start);
        remaining = end - start;

        if (remaining <= 0) {
            printf("\nCountdown Finished! \n");
            break;
        }

        displayTime(remaining);
        sleep(1);
    }
    return 0;
}