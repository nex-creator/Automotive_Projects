#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep()

#define SPEED_LIMIT 60

int get_sensor_speed(){
	return rand()%101; // Generate random speed (0-100)mph
}

int main(){
	srand(time(0)); //initalize random speed
	
	while(1){
		int speed = get_sensor_speed();
		FILE *file = fopen("speed_data.txt","w"); //open file for writing
		if (file == NULL){
			printf("Error: Cannot open file\n");
			return 1;
		}
		fprintf(file, "%d\n",speed); //write speed to speed_data.txt
		fclose(file); //close file
		
		printf("Speed written: %d mph\n", speed);
		sleep(2);
	
	}
	return 0;
}