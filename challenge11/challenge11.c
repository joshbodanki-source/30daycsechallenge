#include <stdio.h>

#define ZONES 5
#define DAYS 7

const char *getZoneName(int zone)
{
    switch(zone)
    {
        case 0: return "Academic Block";
        case 1: return "Hostel";
        case 2: return "Library";
        case 3: return "Cafeteria";
        case 4: return "Sports Complex";
        default: return "Unknown";
    }
}

/* Function to read and validate integer input */
int readNumber()
{
    int value;
    int result;
    int ch;

    while(1)
    {
        result = scanf("%d", &value);

        if(result == 1)
            return value;

        printf("Invalid input! Enter an integer: ");

        while((ch = getchar()) != '\n' && ch != EOF);
    } }

/* 1. Input water data */
void inputWaterData(int usage[ZONES][DAYS],
                    int dailyTarget[ZONES])
{
    int i, j;

    printf("\nNOTE: Enter authorised readings or clearly labelled simulated>

    for(i = 0; i < ZONES; i++)
    {
        printf("\nEnter water readings for %s:\n", getZoneName(i));

        for(j = 0; j < DAYS; j++)
        {
            do
            {
                printf("Day %d consumption: ", j + 1);
                usage[i][j] = readNumber();

                if(usage[i][j] < 0 || usage[i][j] > 50000)
                    printf("Invalid! Enter a value between 0 and 50000.\n");

            } while(usage[i][j] < 0 || usage[i][j] > 50000);
        }

        do
        {
            printf("Enter daily target: ");
            dailyTarget[i] = readNumber();

            if(dailyTarget[i] < 100 || dailyTarget[i] > 50000)
                printf("Invalid! Target must be between 100 and 50000.\n");

        } while(dailyTarget[i] < 100 || dailyTarget[i] > 50000);
    }
}

/* 2. Display water data */
void displayWaterData(int usage[ZONES][DAYS],
                      int dailyTarget[ZONES])
{
    int i, j;

    printf("\n========== WATER CONSUMPTION MATRIX ==========\n");

    printf("%-18s", "Zone");

    for(j = 0; j < DAYS; j++)
        printf("%10s%d", "Day ", j + 1);

    printf("%12s\n", "Target");

    for(i = 0; i < ZONES; i++)
    {
        printf("%-18s", getZoneName(i));

        for(j = 0; j < DAYS; j++)
            printf("%10d", usage[i][j]);

        printf("%12d\n", dailyTarget[i]);
    }
}

/* 3. Calculate zone statistics using pointers */
void calculateZoneStats(int *zoneUsage, int *total,
                        float *average, int *peakUsage,
 int *peakDay)
{
    int i;
    int sum = 0;

    *peakUsage = *zoneUsage;
    *peakDay = 1;

    for(i = 0; i < DAYS; i++)
    {
        sum = sum + *(zoneUsage + i);

        if(*(zoneUsage + i) > *peakUsage)
        {
            *peakUsage = *(zoneUsage + i);
            *peakDay = i + 1;
        }
    }

    *total = sum;
    *average = (float)sum / DAYS;
}

/* 4. Detect water alerts using pointers */
void detectWaterAlerts(int *zoneUsage, int dailyTarget,
                       int *overLimitDays, int *totalExcess,
                       int *spikeDays, int *alertDays)
{
    int i;
    int over, spike;

    *overLimitDays = 0;
    *totalExcess = 0;
    *spikeDays = 0;
    *alertDays = 0;
 for(i = 0; i < DAYS; i++)
    {
        over = 0;
        spike = 0;

        /* Check daily target */
        if(*(zoneUsage + i) > dailyTarget)
        {
            over = 1;
            (*overLimitDays)++;

            *totalExcess = *totalExcess +
                           (*(zoneUsage + i) - dailyTarget);
        }

        /* Check sudden spike from Day 2 */
        if(i > 0)
        {
            if(*(zoneUsage + i) * 100 >
               *(zoneUsage + i - 1) * 140)
            {
                spike = 1;
                (*spikeDays)++;
            }
        }

        /* Count each day only once */
        if(over == 1 || spike == 1)
            (*alertDays)++;
    }
}

/* 5. Generate complete audit report */
void generateAuditReport(int usage[ZONES][DAYS],
                         int dailyTarget[ZONES],
                         int excessByZone[ZONES],
   int overLimitByZone[ZONES],
                         int spikeByZone[ZONES],
                         int alertByZone[ZONES])
{
    int i;
    int total, peakUsage, peakDay;
    int overLimitDays, totalExcess;
    int spikeDays, alertDays;
    float average;

    printf("\n========== WATER AUDIT REPORT ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        calculateZoneStats(&usage[i][0], &total,
                           &average, &peakUsage, &peakDay);

        detectWaterAlerts(&usage[i][0], dailyTarget[i],
                          &overLimitDays, &totalExcess,
                          &spikeDays, &alertDays);

        excessByZone[i] = totalExcess;
        overLimitByZone[i] = overLimitDays;
        spikeByZone[i] = spikeDays;
        alertByZone[i] = alertDays;

        printf("\nZone: %s\n", getZoneName(i));

        printf("Weekly Total       : %d litres\n", total);
        printf("Daily Average      : %.2f litres\n", average);
        printf("Highest Consumption: %d litres\n", peakUsage);
        printf("Peak Day           : Day %d\n", peakDay);
        printf("Over-limit Days    : %d\n", overLimitDays);
        printf("Total Excess       : %d litres\n", totalExcess);
        printf("Sudden Spike Days  : %d\n", spikeDays);
        printf("Unique Alert Days  : %d\n", alertDays);
    }
  printf("\n========== AUDIT SUMMARY ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        printf("%-18s : %d litres excess\n",
               getZoneName(i), excessByZone[i]);
    }
}

/* 6. Rank zones by total excess */
void rankZones(int excessByZone[ZONES])
{
    int i, j;
    int rank;

    printf("\n========== ZONE RANKING ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        rank = 1;

        for(j = 0; j < ZONES; j++)
        {
            if(excessByZone[j] > excessByZone[i])
                rank++;
        }

        printf("Rank %d : %-18s | Excess: %d litres\n",
               rank, getZoneName(i), excessByZone[i]);
    }

    /* Display zones with the greatest excess */
    int maximum = excessByZone[0];

    for(i = 1; i < ZONES; i++)
    {
        if(excessByZone[i] > maximum)
  maximum = excessByZone[i];
    }

    printf("\nZone(s) with greatest total excess:\n");

    for(i = 0; i < ZONES; i++)
    {
        if(excessByZone[i] == maximum)
            printf("%s\n", getZoneName(i));
    }
}

/* 7. Display conservation actions */
void displayConservationActions(int overLimitByZone[ZONES],
                                int spikeByZone[ZONES],
                                int excessByZone[ZONES])
{
    int i;

    printf("\n========== CONSERVATION ACTIONS ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        printf("\nZone: %s\n", getZoneName(i));

        printf("Total excess: %d litres\n", excessByZone[i]);

        if(spikeByZone[i] > 0)
        {
            printf("- Check for leaks or unexpected water usage "
                   "around the flagged days.\n");
        }

        if(overLimitByZone[i] >= 3)
        {
            printf("- Prioritise a water audit and prepare "
                   "a reduction plan.\n");
        }
        else if(overLimitByZone[i] == 1 ||
                overLimitByZone[i] == 2)
        {
            printf("- Monitor the over-limit days and inspect "
                   "taps or valves.\n");
        }

        if(overLimitByZone[i] == 0 && spikeByZone[i] == 0)
        {
            printf("- Maintain current good water-saving practices.\n");
        }
    }
}

/* Main function */
int main()
{
    int usage[ZONES][DAYS];
    int dailyTarget[ZONES];

    int excessByZone[ZONES] = {0};
    int overLimitByZone[ZONES] = {0};
    int spikeByZone[ZONES] = {0};
    int alertByZone[ZONES] = {0};

    int choice;
    int reportGenerated = 0;

    printf("========================================\n");
    printf("       WATERWISE WATER AUDIT SYSTEM\n");
    printf("========================================\n");

    /* Read all data once */
    inputWaterData(usage, dailyTarget);

    do
  {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Display Water Data\n");
        printf("2. Generate Audit Report\n");
        printf("3. Rank Zones by Excess\n");
        printf("4. Conservation Actions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        choice = readNumber();

        switch(choice)
        {
            case 1:
                displayWaterData(usage, dailyTarget);
                break;

            case 2:
                generateAuditReport(usage, dailyTarget,
                                    excessByZone,
                                    overLimitByZone,
                                    spikeByZone,
                                    alertByZone);

                reportGenerated = 1;
                break;

            case 3:
                if(reportGenerated == 1)
                    rankZones(excessByZone);
                else
                    printf("\nPlease generate the audit report first!\n");
                break;

            case 4:
                if(reportGenerated == 1)
                    displayConservationActions(overLimitByZone,
  spikeByZone,
                                               excessByZone);
                else
                    printf("\nPlease generate the audit report first!\n");
                break;

            case 5:
                printf("\nThank you for using WATERWISE!\n");
                break;

            default:
                printf("\nInvalid menu choice! Enter 1 to 5.\n");
        }

    } while(choice != 5);

    return 0;
}
