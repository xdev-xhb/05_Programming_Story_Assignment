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

    // Open the file for writing
    FILE *file = fopen("data.csv", "w");

    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1; // Return an error code
    }

    // Write the header to the file
    fprintf(file, "%s\n",
        "temperature,humidity,wind_speed,visibility,weather_condition"
    );

    // Write data to the file
    for (int i = 0; i < DATASET_SIZE; i++) {
        int temperature = generate_random(-10, 35);
        int humidity = generate_random(30, 95);
        int wind_speed = generate_random(0, 20); // in km/h
        int visibility = generate_random(1, 20); // in km

        int weather_condition = generate_random(0, 2); // 0: clear, 1: partly cloudy, 2: rainy

        fprintf(
            file,
            "%d,%d,%d,%d,%s\n",
            temperature,
            humidity,
            wind_speed,
            visibility,
            weather_labels[weather_condition]
        );
    }

    // Close the file
    fclose(file);

    return 0;
}
