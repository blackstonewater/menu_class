#include "Menu.h"

Menu::Menu(bool clear_choice){
	clear_screen = clear_choice;

	*(elements_list + 0) = "play";
	*(elements_list + 1) = "settings";
	*(elements_list + 2) = "exit";

	control_menu();
}

void inline Menu::control_menu(){
	do{
		check_clean(clear_screen);
		print_elements_menu();
		int choice{};
			if(!(std::cin >> choice) || error_in_check(choice))
				error_in_communicate();
			else{
				if(choice == 1){
					std::cout << "function_play() \n";
					system("pause");
				}
				else if(choice == 2){
					std::cout << "function_settings \n";
					system("pause");
				}
				else if(choice == 3)
					exit(0);
			}


		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n' );	
		//system("pause");
	}while(true);
}
	void inline Menu::print_elements_menu() const{
		for(int i{0}; i < elements; i++){
			std::cout << (i+1) << " " << *(elements_list + i) << "\n";
		}
	}

bool Menu::check_clean(bool& clear_screen){
	if(clear_screen){
		system("clear");
		return 1;
	}
	else{
		//std::cout << "false \n";
		return 0;
	}
}

bool inline Menu::error_in_check(int& choice){
	if(choice > elements || choice < 1){
		std::cout << "give me number 1.." << elements << "\n";
		clear_screen = false;
	}
	else{
		//std::cout << "good \n";
		clear_screen = true;
	}
	return false;
}

void inline Menu::error_in_communicate(){
	std::cout << "error data \n";
	clear_screen = false;
}