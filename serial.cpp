#include <iostream>
#include "lib_code.h"
#include <signal.h>
#include <asm/termbits.h> /* struct termios2 */
#include "yaml-cpp/yaml.h"

 

int main(){

	

	char* tty_device = (char*) "/dev/ttyUSB0"; 
	// char *tty_ptr = &tty_device;


	signal(SIGTERM, sigterm);
  	signal(SIGHUP, sigterm);
  	signal(SIGINT, sigterm);




	CANUSB_SPEED speed=  canusb_int_to_speed(250000);

	int baudrate=115200;
	char* inject_id =  (char*)"244";
	char* inject_data = (char*) "aaffdd";


	int c, tty_fd;
	
	std::cout << " tty_device: " << tty_device << "\n Speed: " << speed <<"\n Baudrate: " << baudrate << "\n Inject_data: " <<inject_data << "\n ID: " <<inject_id  << "\n";

	tty_fd = adapter_init( tty_device , baudrate);


	
	// std::cout << command_settings(tty_fd, speed, CANUSB_MODE_NORMAL, CANUSB_FRAME_STANDARD) <<"\n"; 


	
	
	// std::cout << "\n tty_fd: " << tty_fd << "\n";

	inject_data_frame(tty_fd, inject_id , inject_data );

	// std::cout << "Gotovo" << "\n";

	
	
	
}
