/*
    ofstream file("TEST.txt", ios::app);
    file << c_robot->head()*10;
    file.close();
*/


/////////////////////////////////////Employee///////////////////////////////////////////////////////////

void create_employee_confirm(Fl_Widget* w, void* p);
void create_employee_cancel(Fl_Widget* w, void* p);
class Create_employee_gui{
    public:
        Create_employee_gui(){
            prompt=new Fl_Window(500,135,"Create Employee");

            prompt_name = new Fl_Input(150, 20, 300, 25, "  Employee name:");
            prompt_name->align(FL_ALIGN_LEFT);

            prompt_number = new Fl_Input(150, 55, 300, 25, "Employee number:");
            prompt_number->align(FL_ALIGN_LEFT);

            prompt_go = new Fl_Return_Button(50, 90, 130, 25, "Create");
            prompt_go->callback((Fl_Callback *)create_employee_confirm, 0);

            prompt_exit = new Fl_Button(320, 90, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)create_employee_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}
        string prompt_name_value(){return prompt_name->value();}
        int prompt_number_value(){
            string myString = prompt_number->value();
            istringstream buffer(myString);
            int value;
            buffer >> value;
            return value;
        }
    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Input *prompt_name;
        Fl_Input *prompt_number;
        Fl_Return_Button *prompt_go;
        Fl_Button *prompt_exit;
};

Create_employee_gui* c_emp_g;
void create_employee(Fl_Widget* w, void* p){
    c_emp_g=new Create_employee_gui();
    c_emp_g->show();
}
void create_employee_confirm(Fl_Widget* w, void* p){
    Sales_associate* sale=new Sales_associate(c_emp_g->prompt_number_value(), c_emp_g->prompt_name_value());
    sale->save();
    sales_associates.push_back(sale);
    c_emp_g->hide();
    delete c_emp_g;
}
void create_employee_cancel(Fl_Widget* w, void* p){
    c_emp_g->hide();
    delete c_emp_g;
}

//////////////////////////////////////??CUSTOMERRR/////////////////////////////////////////////////////////

void create_customer_confirm(Fl_Widget* w, void* p);
void create_customer_cancel(Fl_Widget* w, void* p);
class Create_customer_gui{
    public:
        Create_customer_gui(){
            prompt=new Fl_Window(500,200,"Create Customer");

            prompt_name = new Fl_Input(150, 20, 300, 25,   "  Customer name:");
            prompt_name->align(FL_ALIGN_LEFT);

            prompt_number = new Fl_Input(150, 55, 300, 25, "Customer number:");
            prompt_number->align(FL_ALIGN_LEFT);

            prompt_phone = new Fl_Input(150, 90, 300, 25,  "   Phone number:");
            prompt_phone->align(FL_ALIGN_LEFT);

            prompt_email = new Fl_Input(150, 125, 300, 25, "  Email Address:");
            prompt_email->align(FL_ALIGN_LEFT);

            prompt_go = new Fl_Return_Button(50, 160, 130, 25, "Create");
            prompt_go->callback((Fl_Callback *)create_customer_confirm, 0);

            prompt_exit = new Fl_Button(320, 160, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)create_customer_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}
        string prompt_name_value(){return prompt_name->value();}
        string prompt_phone_value(){return prompt_phone->value();}
        string prompt_email_value(){return prompt_email->value();}
        int prompt_number_value(){
            string myString = prompt_number->value();
            istringstream buffer(myString);
            int value;
            buffer >> value;
            return value;
        }
    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Input *prompt_name;
        Fl_Input *prompt_number;
        Fl_Input *prompt_phone;
        Fl_Input *prompt_email;
        Fl_Return_Button *prompt_go;
        Fl_Button *prompt_exit;
};

Create_customer_gui* c_cus_g;
void create_customer(Fl_Widget* w, void* p){
    c_cus_g=new Create_customer_gui();
    c_cus_g->show();
}
void create_customer_confirm(Fl_Widget* w, void* p){
    Customer* cust=new Customer(c_cus_g->prompt_number_value(), c_cus_g->prompt_name_value(), c_cus_g->prompt_phone_value(), c_cus_g->prompt_email_value());
    cust->save();
    customers.push_back(cust);
    c_cus_g->hide();
    delete c_cus_g;
}
void create_customer_cancel(Fl_Widget* w, void* p){
    c_cus_g->hide();
    delete c_cus_g;
}

/////////////////////////////////////ROBOT PARTS///////////////////////////////////////////////////////////

void create_part_confirm(Fl_Widget* w, void* p);
void create_part_cancel(Fl_Widget* w, void* p);
class Create_part_gui{
    private:
        string _type;
        Fl_Window *prompt;
        Fl_Output *prompt_out;
        Fl_Input *prompt_name;
        Fl_Input *prompt_name2;
        Fl_Input *prompt_model;
        Fl_Input *prompt_cost;
        Fl_Input *prompt_weight;
        Fl_Input *prompt_desc;
        Fl_Input *prompt_image_name;
        Fl_Input *prompt_power;
        Fl_Input *prompt_speed;
        Fl_Input *prompt_max_power;
        Fl_Input *prompt_max_arms;
        Fl_Input *prompt_battery_compartments;
        Fl_Input *prompt_power_available;
        Fl_Input *prompt_max_energy;
        Fl_Return_Button *prompt_go;
        Fl_Button *prompt_exit;
    public:
        Create_part_gui(string type){
            string title = string("Create ")+type+string(" model");
            char *title2 = new char[title.length() + 1];
            strcpy(title2, title.c_str());

            prompt=new Fl_Window(550,420,title2);
            delete[] title2;
            _type=type;

            prompt_name2 = new Fl_Input(0, 0, 0, 0,                "                 :");
            prompt_name2->value(title.c_str());
            prompt_name = new Fl_Input(200, 20, 300, 25,                "                 Name:");
            prompt_name->align(FL_ALIGN_LEFT);
            prompt_model = new Fl_Input(200, 55, 300, 25,               "                Model:");
            prompt_model->align(FL_ALIGN_LEFT);
            prompt_cost = new Fl_Input(200, 90, 300, 25,                "                 Cost:");
            prompt_cost->align(FL_ALIGN_LEFT);
            prompt_weight = new Fl_Input(200, 125, 300, 25,                "               Weight:");
            prompt_weight->align(FL_ALIGN_LEFT);
            prompt_desc = new Fl_Multiline_Input(200, 160, 300, 70,      "          Description:");
            prompt_desc->align(FL_ALIGN_LEFT);
            prompt_image_name = new Fl_Input(200, 240, 300, 25,          "           Image File:");
            prompt_image_name->align(FL_ALIGN_LEFT);

            if(type=="head") head(200,275, 300,25);
            if(type=="torso") torso(200,275, 300,25);
            if(type=="arm") arm(200,275, 300,25);
            if(type=="locomotor") locomotor(200,275, 300,25);
            if(type=="battery") battery(200,275, 300,25);

            prompt_exit = new Fl_Button(30, 385, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)create_part_cancel, 0);

            prompt_go = new Fl_Return_Button(390, 385, 130, 25, "Create");
            prompt_go->callback((Fl_Callback *)create_part_confirm, 0);


            prompt->end();
            prompt->set_non_modal();
        }
        void head(int x, int y, int l, int b){
            prompt_power = new Fl_Input(x,y,l,b,               "                Power:");
            prompt_power->align(FL_ALIGN_LEFT);
        }
        void torso(int x, int y, int l, int b){
            prompt_max_arms = new Fl_Input(x,y,l,b,            "   Max number of Arms:");
            prompt_max_arms->align(FL_ALIGN_LEFT);
            prompt_battery_compartments = new Fl_Input(x,y+35,l,b," Battery Compartments:");
            prompt_battery_compartments->align(FL_ALIGN_LEFT);
        }
        void arm(int x, int y, int l, int b){
            prompt_max_power = new Fl_Input(x,y,l,b,           "            Max Power:");
            prompt_max_power->align(FL_ALIGN_LEFT);
        }
        void locomotor(int x, int y, int l, int b){
            prompt_max_power = new Fl_Input(x,y,l,b,           "            Max Power:");
            prompt_max_power->align(FL_ALIGN_LEFT);
            prompt_speed = new Fl_Input(x,y+35,l,b,           "            Max Speed:");
            prompt_speed->align(FL_ALIGN_LEFT);
        }
        void battery(int x, int y, int l, int b){
            prompt_power_available = new Fl_Input(x,y,l,b,     "      Power Available:");
            prompt_power_available->align(FL_ALIGN_LEFT);
            prompt_max_energy = new Fl_Input(x,y+35,l,b,          "           Max Energy:");
            prompt_max_energy->align(FL_ALIGN_LEFT);
        }

        void show() {prompt->show();}
        void hide() {prompt->hide();}
        int get_int(string myString){
            istringstream buffer(myString);
            int value;
            buffer >> value;
            return value;
        }
        double get_double(string myString){
            istringstream buffer(myString);
            double value;
            buffer >> value;
            return value;
        }
        string type(){return _type;}
        string name(){return prompt_name->value();}
        int model(){return get_int(prompt_model->value());}
        double cost(){return get_double(prompt_cost->value());}
        double weight(){return get_double(prompt_weight->value());}
        double speed(){return get_double(prompt_speed->value());}
        string desc(){return remove_nl(prompt_desc->value());}
        string image_name(){return prompt_image_name->value();}
        double power(){return get_double(prompt_power->value());}
        int battery_compartments(){return get_int(prompt_battery_compartments->value());}
        int max_arms(){return get_int(prompt_max_arms->value());}
        double max_power(){return get_double(prompt_max_power->value());}
        double power_available(){return get_double(prompt_power_available->value());}
        double max_energy(){return get_double(prompt_max_energy->value());}
};

Create_part_gui* c_part_g;

void create_head(Fl_Widget* w, void* p){
    c_part_g=new Create_part_gui("head");
    c_part_g->show();
}
void create_locomotor(Fl_Widget* w, void* p){
    c_part_g=new Create_part_gui("locomotor");
    c_part_g->show();
}
void create_torso(Fl_Widget* w, void* p){
    c_part_g=new Create_part_gui("torso");
    c_part_g->show();
}
void create_arm(Fl_Widget* w, void* p){
    c_part_g=new Create_part_gui("arm");
    c_part_g->show();
}
void create_battery(Fl_Widget* w, void* p){
    c_part_g=new Create_part_gui("battery");
    c_part_g->show();
}

void create_part_confirm(Fl_Widget* w, void* p){
    string t=c_part_g->type();
    if(t=="head"){
        Head* head=new Head(c_part_g->name(), c_part_g->model(), c_part_g->cost(), c_part_g->weight(), c_part_g->desc(), c_part_g->image_name(), c_part_g->power());
        head->save();
        heads.push_back(head);
    }else if (t=="torso"){
        Torso* torso=new Torso(c_part_g->name(), c_part_g->model(), c_part_g->cost(), c_part_g->weight(),  c_part_g->desc(), c_part_g->image_name(), c_part_g->battery_compartments(), c_part_g->max_arms());
        torso->save();
        torsos.push_back(torso);
    } else if (t=="locomotor"){
        Locomotor* locomotor=new Locomotor(c_part_g->name(), c_part_g->model(), c_part_g->cost(), c_part_g->weight(),  c_part_g->desc(), c_part_g->image_name(), c_part_g->max_power(), c_part_g->speed());
        locomotor->save();
		locomotors.push_back(locomotor);
    } else if (t=="arm"){
        Arm* arm=new Arm(c_part_g->name(), c_part_g->model(), c_part_g->cost(), c_part_g->weight(),  c_part_g->desc(), c_part_g->image_name(), c_part_g->max_power());
        arm->save();
        arms.push_back(arm);
    } else if (t=="battery"){
        Battery* battery = new Battery(c_part_g->name(), c_part_g->model(), c_part_g->cost(), c_part_g->weight(), c_part_g->desc(), c_part_g->image_name(), c_part_g->power_available(), c_part_g->max_energy());
        battery->save();
        batteries.push_back(battery);
    }
    c_part_g->hide();
    delete c_part_g;
}
void create_part_cancel(Fl_Widget* w, void* p){
    c_part_g->hide();
    delete c_part_g;
}













/////////////////////////////////////ROBOT Model///////////////////////////////////////////////////////////

void create_robot_confirm(Fl_Widget* w, void* p);
void create_robot_cancel(Fl_Widget* w, void* p);
class Create_robot{
    public:
        Create_robot(){
            prompt=new Fl_Window(550,435,"Create Robot");

            prompt_name = new Fl_Input(200, 20, 300, 25,        "                  Name:");
            prompt_name->align(FL_ALIGN_LEFT);
            prompt_model = new Fl_Input(200, 55, 300, 25,               "                Model:");
            prompt_model->align(FL_ALIGN_LEFT);
            prompt_cost = new Fl_Input(200, 350, 300, 25,               "             Tag Price:");
            prompt_cost->align(FL_ALIGN_LEFT);
            prompt_desc = new Fl_Multiline_Input(200, 265, 300, 75,     "          Description:");
            prompt_desc->align(FL_ALIGN_LEFT);


            head_model = new Fl_Choice(200, 90, 300, 25,        "     Select Head Model:");
            head_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<heads.size(); i++){
                string title=heads[i]->get_name() + "   " + to_string(heads[i]->get_model_number());
                head_model->add(title.c_str());
            }
            torso_model = new Fl_Choice(200, 125, 300, 25,       "    Select Torso Model:");
            torso_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<torsos.size(); i++){
                string title=torsos[i]->get_name() + "   " + to_string(torsos[i]->get_model_number());
                torso_model->add(title.c_str());
            }
            arm_model = new Fl_Choice(200, 160, 300, 25,        "     Select Arms Model:");
            arm_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<arms.size(); i++){
                string title=arms[i]->get_name() + "   " + to_string(arms[i]->get_model_number());
                arm_model->add(title.c_str());
            }
            locomotor_model = new Fl_Choice(200, 195, 300, 25,  "Select Locomotor Model:");
            locomotor_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<locomotors.size(); i++){
                string title=locomotors[i]->get_name() + "   " + to_string(locomotors[i]->get_model_number());
                locomotor_model->add(title.c_str());
            }
            battery_model = new Fl_Choice(200, 230, 300, 25,     "  Select Battery Model:");
            battery_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<batteries.size(); i++){
                string title=batteries[i]->get_name() + "   " + to_string(batteries[i]->get_model_number());
                battery_model->add(title.c_str());
            }

            prompt_go = new Fl_Return_Button(50, 400, 130, 25, "Create");
            prompt_go->callback((Fl_Callback *)create_robot_confirm, 0);

            prompt_exit = new Fl_Button(320, 400, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)create_robot_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}

        string name(){return prompt_name->value();}
        int model(){return str_to_int(prompt_model->value());}
        string desc(){return remove_nl(prompt_desc->value());}
        double tag(){
            return str_to_double(prompt_cost->value());
        }
        int head(){return head_model->value();}
        int torso(){return torso_model->value();}
        int arm(){return arm_model->value();}
        int locomotor(){return locomotor_model->value();}
        int battery(){return battery_model->value();}
    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Input *prompt_name;
        Fl_Input *prompt_model;
        Fl_Input *prompt_cost;
        Fl_Input *prompt_desc;

        Fl_Choice* head_model;
        Fl_Choice* torso_model;
        Fl_Choice* arm_model;
        Fl_Choice* locomotor_model;
        Fl_Choice* battery_model;
        Fl_Return_Button *prompt_go;
        Fl_Button *prompt_exit;
};

Create_robot* c_robot;
void create_robot(Fl_Widget* w, void* p){
    c_robot=new Create_robot();
    c_robot->show();
}
void create_robot_confirm(Fl_Widget* w, void* p){
    string name=c_robot->name();
    int model=c_robot->model();
    double tag=c_robot->tag();
    string desc=c_robot->desc();
    int head=c_robot->head();
    int torso=c_robot->torso();
    int arm=c_robot->arm();
    int locomotor=c_robot->locomotor();
    int battery=c_robot->battery();

    Robot_model* robot_model=new Robot_model(name,model,tag,desc, torsos[torso], heads[head], locomotors[locomotor], arms[arm], batteries[battery]);
    robot_model->save();
    robots.push_back(robot_model);

    c_robot->hide();
    delete c_robot;
}
void create_robot_cancel(Fl_Widget* w, void* p){
    c_robot->hide();
    delete c_robot;
}










/////////////////////////////////////ROBOT Model///////////////////////////////////////////////////////////

void create_order_confirm(Fl_Widget* w, void* p);
void create_order_cancel(Fl_Widget* w, void* p);
class Create_order{
    public:
        Create_order(){
            prompt=new Fl_Window(550,435,"Sell Robot");

            order_number= new Fl_Input(200, 20, 300, 25,                "        Order Number:");
            order_number->align(FL_ALIGN_LEFT);
            order_number->value(to_string(orders.size()).c_str());

            date = new Fl_Input(200, 55, 300, 25,                       "                Date:");
            date->align(FL_ALIGN_LEFT);

            date->value(time().c_str());

            customer = new Fl_Choice(200, 90, 300, 25,                  "            Customer:");
            customer->align(FL_ALIGN_LEFT);
            for(int i=0;i<customers.size(); i++){
                string title=customers[i]->get_name() + "   " + to_string(customers[i]->get_customer_number());
                customer->add(title.c_str());
            }
            sales_associate = new Fl_Choice(200, 125, 300, 25,          "     Sales Associate:");
            sales_associate->align(FL_ALIGN_LEFT);
            for(int i=0;i<sales_associates.size(); i++){
                string title=sales_associates[i]->get_name() + "   " + to_string(sales_associates[i]->get_employee_number());
                sales_associate->add(title.c_str());
            }
            robot_model = new Fl_Choice(200, 160, 300, 25,              "               Robot:");
            robot_model->align(FL_ALIGN_LEFT);
            for(int i=0;i<robots.size(); i++){
                string title=robots[i]->get_name() + "   " + to_string(robots[i]->get_model_number());
                robot_model->add(title.c_str());
            }

            prompt_status = new Fl_Choice(200, 195, 300, 25,                             "              Status:");
            prompt_status->align(FL_ALIGN_LEFT);
            prompt_status->add("Begin");
            prompt_status->add("Packaged");
            prompt_status->add("Shipped");
            prompt_status->add("Billed");
            prompt_status->add("Paid");
            prompt_status->add("Completed");
            prompt_status->add("Cancel");
            prompt_status->value(0);

            prompt_go = new Fl_Return_Button(50, 400, 130, 25, "Create");
            prompt_go->callback((Fl_Callback *)create_order_confirm, 0);

            prompt_exit = new Fl_Button(320, 400, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)create_order_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}

        string time() {
            time_t now = std::time(0);
            struct tm  tstruct;
            char       buf[80];
            tstruct = *localtime(&now);
            strftime(buf, sizeof(buf), "%Y-%m-%d,%X", &tstruct);

            return buf;
        }
        int get_order_number(){return str_to_int(order_number->value());}
        string get_date(){return date->value();}
        int get_sales_associate(){return sales_associate->value();}
        int get_customer(){return customer->value();}
        int get_robot_model(){return robot_model->value();}
        int get_status(){return prompt_status->value();}

    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Input *order_number;
        Fl_Input *date;
        Fl_Choice *customer;
        Fl_Choice *sales_associate;
        Fl_Choice* robot_model;
        Fl_Choice* prompt_status;

        Fl_Return_Button *prompt_go;
        Fl_Button *prompt_exit;
};

Create_order* c_order;
void create_order(Fl_Widget* w, void* p){
    c_order=new Create_order();
    c_order->show();
}
void create_order_confirm(Fl_Widget* w, void* p){
    string date=c_order->get_date();
    int order_number=c_order->get_order_number();
    int sales_associate=c_order->get_sales_associate();
    int robot_model=c_order->get_robot_model();
    int customer=c_order->get_customer();
    int status=c_order->get_status();

    Order* order=new Order(order_number, date, customers[customer], sales_associates[sales_associate], robots[robot_model], status);
    order->save();
    orders.push_back(order);

    c_order->hide();
    delete c_order;
}
void create_order_cancel(Fl_Widget* w, void* p){
    c_order->hide();
    delete c_order;
}






