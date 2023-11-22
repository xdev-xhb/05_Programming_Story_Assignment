#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random(int min, int max) {
    // Random number in interval [min, max]
    return rand() % (max - min + 1) + min;
}

const char* weather_labels[] = {"clear", "partly cloudy", "rainy"};

int main() {
    // Number of records in the dataset
    const int DATASET_SIZE = 100;

    // Seed random number generator with current time
    srand(time(NULL));

    printf("%s\n", // Dataset header (must match the number of columns)
        "temperature,humidity,wind_speed,visibility,weather_condition"
    );

    for (int i = 0; i < DATASET_SIZE; i++) {
        int temperature = generate_random(-10, 35);
        int humidity = generate_random(30, 95);
        int wind_speed = generate_random(0, 20); // in km/h
        int visibility = generate_random(1, 20); // in km

        int weather_condition = generate_random(0, 2); // 0: clear, 1: partly cloudy, 2: rainy

        printf(
            "%d,%d,%d,%d,%s\n",
            temperature,
            humidity,
            wind_speed,
            visibility,
            weather_labels[weather_condition]
        );
    }

    return 0;
}
