#pragma once
#include <iostream>

class Menu{
public:
	Menu(bool = true);
	void inline control_menu();
		void inline print_elements_menu() const;

private:
	bool menu_control_print{false};
	bool clear_screen;
		bool inline check_clean(bool&);

	int const elements{3};
		std::string *elements_list = new std::string[elements];

// error handling
	bool inline error_in_check(int& choice);
	void inline error_in_communicate();
};

