void reload_new(Fl_Widget* w, void* p);
void restore(Fl_Widget* w, void* p);
void quit(Fl_Widget* w, void* p);

void create_head(Fl_Widget* w, void* p);
void create_locomotor(Fl_Widget* w, void* p);
void create_torso(Fl_Widget* w, void* p);
void create_arm(Fl_Widget* w, void* p);;
void create_battery(Fl_Widget* w, void* p);
void create_robot(Fl_Widget* w, void* p);
void create_employee(Fl_Widget* w, void* p);
void create_customer(Fl_Widget* w, void* p);

void report_head(Fl_Widget* w, void* p);
void report_locomotor(Fl_Widget* w, void* p);
void report_torso(Fl_Widget* w, void* p);
void report_arm(Fl_Widget* w, void* p);
void report_battery(Fl_Widget* w, void* p);
void report_model(Fl_Widget* w, void* p);
void report_employee(Fl_Widget* w, void* p);
void report_customer(Fl_Widget* w, void* p);
void report_sale(Fl_Widget* w, void* p);

void manage_order(Fl_Widget* w, void* p);
void create_order(Fl_Widget* w, void* p);

Fl_Menu_Item menuitems[] = {
     { "File", 0, 0, 0, FL_SUBMENU },
         { "Reload", 0, (Fl_Callback *)reload_new },
         { "Restore", 0, (Fl_Callback *)restore,0,FL_MENU_DIVIDER},
         { "Quit", 0, (Fl_Callback *)quit },
     { 0 },
     { "Create", 0, 0, 0, FL_SUBMENU },
         { "Head Model", 0, (Fl_Callback *)create_head },
         { "Locomotor Model", 0, (Fl_Callback *)create_locomotor },
         { "Torso Model", 0, (Fl_Callback *)create_torso },
         { "Arm Model", 0, (Fl_Callback *)create_arm },
         { "Battery Model", 0, (Fl_Callback *)create_battery,0,FL_MENU_DIVIDER },
         { "Robot Model", 0, (Fl_Callback *)create_robot,0,FL_MENU_DIVIDER},
         { "Add new Employee", 0, (Fl_Callback *)create_employee },
         { "Add new Customer", 0, (Fl_Callback *)create_customer },
     { 0 },
     { "Report", 0, 0, 0, FL_SUBMENU },
         { "Head Models", 0, (Fl_Callback *)report_head },
         { "Locomotor Models", 0, (Fl_Callback *)report_locomotor },
         { "Torso Models", 0, (Fl_Callback *)report_torso },
         { "Arm Models", 0, (Fl_Callback *)report_arm },
         { "Battery Models", 0, (Fl_Callback *)report_battery,0,FL_MENU_DIVIDER },
         { "Robot Models", 0, (Fl_Callback *)report_model,0,FL_MENU_DIVIDER},
         { "Employee Record", 0, (Fl_Callback *)report_employee },
         { "Customer Record", 0, (Fl_Callback *)report_customer },
         { "Sales Record", 0, (Fl_Callback *)report_sale },
     { 0 },
     { "Shop", 0, 0, 0, FL_SUBMENU },
         { "Create Order", 0, (Fl_Callback *)create_order},
         { "Manage Order", 0, (Fl_Callback *)manage_order},
     { 0 },
     { 0 }
};
#include "Robot_part_gui.cpp"
#include "reports.cpp"


class Main_Menu{
    public:
        Main_Menu(string out_str){
            prompt=new Fl_Window(500,550,"Main Menu");

            menubar = new Fl_Menu_Bar(0, 0, 500, 30);
            menubar->menu(menuitems);

            prompt_menu = new Fl_Multiline_Output(10, 40, 480, 460, '\0');
            prompt_menu->value(out_str.c_str());
            prompt_menu->align(FL_ALIGN_CENTER);

            prompt_exit = new Fl_Button(355, 510, 135, 25, "Quit");
            prompt_exit->callback((Fl_Callback *)exit, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}
    private:
        Fl_Window *prompt;
        Fl_Menu_Bar *menubar;
        Fl_Multiline_Output *prompt_menu;
        Fl_Button *prompt_exit;
};

Main_Menu *menu;

void reload_new(Fl_Widget *w, void* p){
    heads.clear();
    arms.clear();
    torsos.clear();
    locomotors.clear();
    batteries.clear();

    robots.clear();
    customers.clear();
    sales_associates.clear();
    orders.clear();
    loader();
}
void restore(Fl_Widget* w, void* p){
    fstream file;
	file.open("Head.file", ios::out);file.close();
	file.open("Arm.file", ios::out);file.close();
	file.open("Battery.file", ios::out);file.close();
	file.open("Torso.file", ios::out);file.close();
	file.open("Locomotor.file", ios::out);file.close();
	file.open("Customer.file", ios::out);file.close();
	file.open("Robot_model.file", ios::out);file.close();
	file.open("Sales_associate.file", ios::out);file.close();
	file.open("Order.file", ios::out);file.close();
	reload_new(w,p);
}
void quit(Fl_Widget* w, void* p){
    menu->hide();
    delete menu;
}
