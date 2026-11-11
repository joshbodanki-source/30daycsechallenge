
#include <stdio.h>

#define ZONES 5
#define DAYS 7

// Function declarations

void displayZoneName(int i);

void inputData(float temp[ZONES][DAYS],
               float humidity[ZONES][DAYS],
               int aqi[ZONES][DAYS]);

void displayData(float temp[ZONES][DAYS],
                 float humidity[ZONES][DAYS],
                 int aqi[ZONES][DAYS]);

void calculateAverages(float temp[ZONES][DAYS],
                       float humidity[ZONES][DAYS],
                       int aqi[ZONES][DAYS],
                       float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES]);

void detectRiskZones(float temp[ZONES][DAYS],
                     float humidity[ZONES][DAYS],
                     int aqi[ZONES][DAYS],
                     int riskDays[ZONES]);

void computeGreenIndex(float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES],
                       float greenIndex[ZONES]);

void displayRanking(float greenIndex[ZONES]);

void displayRecommendations(float avgTemp[ZONES],
                            float avgHumidity[ZONES],
                            float avgAQI[ZONES],
                            int riskDays[ZONES]);

int main()
{
    float temp[ZONES][DAYS];
    float humidity[ZONES][DAYS];
    int aqi[ZONES][DAYS];

    float avgTemp[ZONES];
    float avgHumidity[ZONES];
    float avgAQI[ZONES];
    float greenIndex[ZONES];

    int riskDays[ZONES] = {0};

    int choice, i;
    int dataReady = 0;

    do
    {
        printf("\n========== ECOGUARD ==========\n");
        printf("1. Input / Update Data\n");
        printf("2. Display Data\n");
        printf("3. Zone-wise Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index and Ranking\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                inputData(temp, humidity, aqi);
                dataReady = 1;
                printf("\nData entered successfully!\n");
                break;

            case 2:
                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    displayData(temp, humidity, aqi);
                }
                break;

            case 3:
                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    printf("\n========== ZONE-WISE AVERAGES ==========\n");

                    for(i = 0; i < ZONES; i++)
                    {
                        displayZoneName(i);

                        printf("\nAverage Temperature = %.2f\n", avgTemp[i]);
                        printf("Average Humidity = %.2f\n", avgHumidity[i]);
                        printf("Average AQI = %.2f\n", avgAQI[i]);
                    }
                }
                break;

            case 4:
                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    detectRiskZones(temp, humidity, aqi, riskDays);
                }
                break;

            case 5:
                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    computeGreenIndex(avgTemp, avgHumidity,
                                      avgAQI, greenIndex);

                    displayRanking(greenIndex);
                }
                break;

            case 6:
                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    detectRiskZones(temp, humidity, aqi, riskDays);

                    displayRecommendations(avgTemp, avgHumidity,
                                           avgAQI, riskDays);
                }
                break;

            case 7:
                printf("\nThank you for using ECOGUARD!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while(choice != 7);

    return 0;
}


// DISPLAY ZONE NAME

void displayZoneName(int i)
{
    if(i == 0)
        printf("\nAcademic Block");
    else if(i == 1)
        printf("\nHostel");
    else if(i == 2)
        printf("\nLibrary");
    else if(i == 3)
        printf("\nCafeteria");
    else
        printf("\nSports Area");
}


// 1. INPUT DATA

void inputData(float temp[ZONES][DAYS],
               float humidity[ZONES][DAYS],
               int aqi[ZONES][DAYS])
{
    int i, j;

    for(i = 0; i < ZONES; i++)
    {
        printf("\n========== ");
        displayZoneName(i);
        printf(" ==========\n");

        for(j = 0; j < DAYS; j++)
        {
            do
            {
                printf("Enter temperature for Day %d (10-50): ", j + 1);
                scanf("%f", &temp[i][j]);

                if(temp[i][j] < 10 || temp[i][j] > 50)
                {
                    printf("Invalid temperature! Try again.\n");
                }

            } while(temp[i][j] < 10 || temp[i][j] > 50);


            do
            {
                printf("Enter humidity for Day %d (0-100): ", j + 1);
                scanf("%f", &humidity[i][j]);

                if(humidity[i][j] < 0 || humidity[i][j] > 100)
                {
                    printf("Invalid humidity! Try again.\n");
                }

            } while(humidity[i][j] < 0 || humidity[i][j] > 100);


            do
            {
                printf("Enter AQI for Day %d (0-500): ", j + 1);
                scanf("%d", &aqi[i][j]);

                if(aqi[i][j] < 0 || aqi[i][j] > 500)
                {
                    printf("Invalid AQI! Try again.\n");
                }

            } while(aqi[i][j] < 0 || aqi[i][j] > 500);
        }
    }
}


// 2. DISPLAY DATA

void displayData(float temp[ZONES][DAYS],
                 float humidity[ZONES][DAYS],
                 int aqi[ZONES][DAYS])
{
    int i, j;

    printf("\n========== TEMPERATURE DATA ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        printf("\n");

        for(j = 0; j < DAYS; j++)
        {
            printf("%.1f  ", temp[i][j]);
        }

        printf("\n");
    }


    printf("\n========== HUMIDITY DATA ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        printf("\n");

        for(j = 0; j < DAYS; j++)
        {
            printf("%.1f  ", humidity[i][j]);
        }

        printf("\n");
    }


    printf("\n========== AQI DATA ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        printf("\n");

        for(j = 0; j < DAYS; j++)
        {
            printf("%d  ", aqi[i][j]);
        }

        printf("\n");
    }
}


// 3. CALCULATE AVERAGES

void calculateAverages(float temp[ZONES][DAYS],
                       float humidity[ZONES][DAYS],
                       int aqi[ZONES][DAYS],
                       float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES])
{
    int i, j;
    float sumT, sumH, sumA;

    for(i = 0; i < ZONES; i++)
    {
        sumT = 0;
        sumH = 0;
        sumA = 0;

        for(j = 0; j < DAYS; j++)
        {
            sumT = sumT + temp[i][j];
            sumH = sumH + humidity[i][j];
            sumA = sumA + aqi[i][j];
        }

        avgTemp[i] = sumT / DAYS;
        avgHumidity[i] = sumH / DAYS;
        avgAQI[i] = sumA / DAYS;
    }
}


// 4. DETECT RISK DAYS

void detectRiskZones(float temp[ZONES][DAYS],
                     float humidity[ZONES][DAYS],
                     int aqi[ZONES][DAYS],
                     int riskDays[ZONES])
{
    int i, j;

    printf("\n========== RISK REPORT ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        riskDays[i] = 0;

        displayZoneName(i);
        printf("\nRisk days: ");

        for(j = 0; j < DAYS; j++)
        {
            if(aqi[i][j] > 150 ||
               temp[i][j] > 35 ||
               humidity[i][j] > 80)
            {
                riskDays[i]++;

                printf("%d ", j + 1);
            }
        }

        if(riskDays[i] == 0)
        {
            printf("No risk days");
        }

        printf("\nTotal risk days = %d\n", riskDays[i]);
    }
}


// 5. COMPUTE GREEN INDEX

void computeGreenIndex(float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES],
                       float greenIndex[ZONES])
{
    int i;

    float aqiScore;
    float tempScore;
    float humidityScore;
    float difference;

    for(i = 0; i < ZONES; i++)
    {
        aqiScore = 100 - (avgAQI[i] / 5);

        difference = avgTemp[i] - 25;

        if(difference < 0)
        {
            difference = -difference;
        }

        tempScore = 100 - (4 * difference);


        difference = avgHumidity[i] - 50;

        if(difference < 0)
        {
            difference = -difference;
        }

        humidityScore = 100 - (2 * difference);


        if(aqiScore < 0)
        {
            aqiScore = 0;
        }

        if(tempScore < 0)
        {
            tempScore = 0;
        }

        if(humidityScore < 0)
        {
            humidityScore = 0;
        }


        greenIndex[i] = (0.4 * aqiScore) +
                        (0.3 * tempScore) +
                        (0.3 * humidityScore);
    }
}


// 6. DISPLAY RANKING

void displayRanking(float greenIndex[ZONES])
{
    int i, j, rank;

    printf("\n========== GREEN INDEX RANKING ==========\n");

    for(rank = 1; rank <= ZONES; rank++)
    {
        for(i = 0; i < ZONES; i++)
        {
            int currentRank = 1;

            for(j = 0; j < ZONES; j++)
            {
                if(greenIndex[j] > greenIndex[i])
                {
                    currentRank++;
                }
            }

            if(currentRank == rank)
            {
                printf("\nRank %d: ", rank);
                displayZoneName(i);

                printf("\nGreen Index = %.2f\n", greenIndex[i]);
            }
        }
    }

    printf("\nHigher Green Index means better condition.\n");
}


// 7. DISPLAY RECOMMENDATIONS

void displayRecommendations(float avgTemp[ZONES],
                            float avgHumidity[ZONES],
                            float avgAQI[ZONES],
                            int riskDays[ZONES])
{
    int i;
    int issue;

    printf("\n========== RECOMMENDATIONS ==========\n");

    for(i = 0; i < ZONES; i++)
    {
        issue = 0;

        displayZoneName(i);
        printf("\n");

        if(avgAQI[i] > 150)
        {
            printf("- Reduce vehicle idling or improve ventilation.\n");
            issue = 1;
        }

        if(avgTemp[i] > 35)
        {
            printf("- Increase shade and plant more trees.\n");
            issue = 1;
        }

        if(avgHumidity[i] > 80)
        {
            printf("- Improve ventilation and check stagnant water.\n");
            issue = 1;
        }

        if(issue == 0 && riskDays[i] > 0)
        {
            printf("- Review the individual risk days.\n");
            issue = 1;
        }

        if(issue == 0)
        {
            printf("- No major risk detected. Continue monitoring.\n");
        }
    }
}
