#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include <ctime>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>

#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>

using namespace std;

#include "Robot_part.cpp"
#include "Robot_model.cpp"
#include "Customer.cpp"
#include "Sales_associate.cpp"
#include "Order.cpp"

void clear(){
	cout << "\033[2J" << "\033[0;0H" << endl;
	//system("cls");
}
string show_menu_head(){
	return R"(
===============================
       Robbie Robot Shop
===============================
)";
}
string show_menu(){
	return R"(
    Hi there!
    Welcome to Roobie Robot Shop.
First go to Create>Head to create head model.
Then create Torso, Locomotor, Battery and Arm
in same way.
    Then go ahead and create your first robot model.
Then create Customer and Employee/Sales_associate
in order to create or manage orders from Shop.
    To view what you've created, go to report and
click on what you want to see. Remember that all
weight are in pound, cost in dollar and so on
(meaning standard units used).
    To sell or manage orders, click on 'Shop'. To
You can restore or remove all data(BEAWARE)
by going to File>Restore. You can reload the data
in the same way(works if you paste the *.file in
current directory).
    To prevent program crash, never leave any input
field blank. If you want nothing, put some space
or 0. If it doesn't work by any chance, remove all
files with extension .file and run it again.
Use 'make purge' and then 'make' to build it again
for ease.
)";
}


string remove_nl(string str){
    string str2="\n";
    string str3="~";
    while ( str.find ("\n") != string::npos ){
        string temp_str=str;
        str.replace(str.find(str2),str2.length(),str3);
        if (temp_str==str) break;
    }
    return str;
}
string put_nl(string str){
    string str3="\n";
    string str2="~";
    while ( str.find (str2) != string::npos ){
        string temp_str=str;
        str.replace(str.find(str2),str2.length(),(str3));
        if (temp_str==str) break;
    }
    return str;
}

string remove_space(string str){
    string str2=" ";
    string str3="`";
    while ( str.find (" ") != string::npos ){
        string temp_str=str;
        str.replace(str.find(str2),str2.length(),str3);
        if (temp_str==str) break;
    }
    return str;
}
string put_space(string str){
    string str3=" ";
    string str2="`";
    while ( str.find (str2) != string::npos ){
        string temp_str=str;
        str.replace(str.find(str2),str2.length(),(str3));
        if (temp_str==str) break;
    }
    return str;
}

int str_to_int(string myString){
    istringstream buffer(myString);
    int value;
    buffer >> value;
    return value;
}
double str_to_double(string myString){
    istringstream buffer(myString);
    double value;
    buffer >> value;
    return value;
}
string pause(){
	cout << "\n\nPress enter to go back.";
	string temp;
	getline(cin, temp);
}
ifstream::pos_type file_size(string file_name){
	ifstream file(file_name.c_str(), std::ifstream::ate | std::ifstream::binary);
	return file.tellg();
}

vector<Head*> heads;
vector<Torso*> torsos;
vector<Locomotor*> locomotors;
vector<Battery*> batteries;
vector<Arm*> arms;

vector<Robot_model*> robots;
vector<Customer*> customers;
vector<Sales_associate*> sales_associates;
vector<Order*> orders;

void loader(){
		string name;
		int model;
		double cost;
		double weight;
		string desc;
		string img_name;
		double power;
		int battery_compartments;
		int max_arms;
		double max_power;
		double power_available;
		double max_energy;
		double speed;
	fstream file;
	//parts
	file.open("Head.file", ios::app);file.close();
	file.open("Head.file", ios::in);
	while(!file.eof()  && file_size("Head.file")-file.tellp()>2){
		file >> name >> model >> cost >> weight >> desc >> img_name >> power;
		heads.push_back(new Head(put_space(name), model, cost, weight, put_space(desc), put_space(img_name), power));
	}
	file.close();

	file.open("Arm.file", ios::app);file.close();
	file.open("Arm.file", ios::in);
	while(!file.eof()  && file_size("Arm.file")-file.tellp()>2){
		file >> name >> model >> cost >> weight >> desc >> img_name >> max_power;
		arms.push_back(new Arm(put_space(name), model, cost, weight, put_space(desc), put_space(img_name), max_power));
	}
	file.close();

	file.open("Locomotor.file", ios::app);file.close();
	file.open("Locomotor.file", ios::in);
	while(!file.eof()  && file_size("Locomotor.file")-file.tellp()>2){
		file >> name >> model >> cost >> weight >> desc >> img_name >> power >> speed;
		locomotors.push_back(new Locomotor(put_space(name), model, cost, weight, put_space(desc), put_space(img_name), power, speed));
	}
	file.close();

	file.open("Torso.file", ios::app);file.close();
	file.open("Torso.file", ios::in);
	while(!file.eof()  && file_size("Torso.file")-file.tellp()>2){
		file >> name >> model >> cost >> weight >> desc >> img_name >> battery_compartments >> max_arms;
		torsos.push_back(new Torso(put_space(name), model, cost, weight, put_space(desc), put_space(img_name), battery_compartments, max_arms));
	}
	file.close();

	file.open("Battery.file", ios::app);file.close();
	file.open("Battery.file", ios::in);
	while(!file.eof()  && file_size("Battery.file")-file.tellp()>2){
		file >> name >> model >> cost >> weight >> desc >> img_name >> power_available >> max_energy;
		batteries.push_back(new Battery(put_space(name), model, cost, weight, put_space(desc), put_space(img_name), power_available, max_energy));
	}
	file.close();

	int customer_number;
	string phone_number, email_address;

	file.open("Customer.file", ios::app);file.close();
	file.open("Customer.file", ios::in);
	while(!file.eof() && file_size("Customer.file")-file.tellp()>2){
		file >> customer_number >> name >> phone_number >> email_address;
		customers.push_back(new Customer(customer_number, put_space(name), phone_number, email_address));
	}

	file.open("Sales_associate.file", ios::app);file.close();
	file.open("Sales_associate.file", ios::in);
	while(!file.eof() && file_size("Sales_associate.file")-file.tellp()>2){
		file >> customer_number >> name;
		sales_associates.push_back(new Sales_associate(customer_number, put_space(name)));
	}
	file.close();


	file.open("Robot_model.file", ios::app);file.close();
	file.open("Robot_model.file", ios::in);
	while(!file.eof()  && file_size("Robot_model.file")-file.tellp()>2){
		int torso_model, locomotor_model, arm_model, battery_model, head_model;
		double max_speed, max_battery_life;
		file  >> name
	 		  >> model
	 		  >> cost
	 		  >> desc
			  >> torso_model
			  >> head_model
			  >> locomotor_model
			  >> arm_model
			  >> battery_model;
		Torso* torso; Arm* arm; Head* head; Locomotor* locomotor; Battery* battery;
		int i=0;
		for (i=0; i<arms.size(); i++)
			if (arms[i]->get_model_number()==arm_model) arm=arms[i];
		for (i=0; i<heads.size(); i++)
			if (heads[i]->get_model_number()==head_model) head=heads[i];
		for (i=0; i<torsos.size(); i++)
			if (torsos[i]->get_model_number()==torso_model) torso=torsos[i];
		for (i=0; i<locomotors.size(); i++)
			if (locomotors[i]->get_model_number()==locomotor_model) locomotor=locomotors[i];
		for (i=0; i<batteries.size(); i++)
			if (batteries[i]->get_model_number()==battery_model) battery=batteries[i];
		Robot_model* robot_model=new Robot_model(put_space(name),model,cost, put_space(desc), torso, head, locomotor, arm, battery);
		robots.push_back(robot_model);
	}
	file.close();

	file.open("Order.file", ios::app);file.close();
	file.open("Order.file", ios::in);
	while(!file.eof()  && file_size("Order.file")-file.tellp()>2){
		int order_number, status, customer_number, employee_number, robot_model_number;
		string date;
		Customer* customer;
		Sales_associate* sales_associate;
		Robot_model* robot;
		file  >> order_number
	 		  >> date
			  >> customer_number
			  >> employee_number
			  >> robot_model_number
			  >> status;
		int i=0;
		for (i=0; i<customers.size(); i++)
			if (customers[i]->get_customer_number()==customer_number) customer=customers[i];
		for (i=0; i<sales_associates.size(); i++)
			if (sales_associates[i]->get_employee_number()==employee_number) sales_associate=sales_associates[i];
		for (i=0; i<robots.size(); i++)
			if (robots[i]->get_model_number()==robot_model_number) robot=robots[i];
		orders.push_back(new Order(order_number,date, customer, sales_associate, robot, status));
	}
	file.close();
}

#include "GUI.cpp"



int main(){
	loader();

	menu=new Main_Menu{show_menu_head()+show_menu()};
    menu->show();

    return Fl::run();

}
