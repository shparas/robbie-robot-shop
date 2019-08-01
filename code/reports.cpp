/////////////////////////////////////Employee///////////////////////////////////////////////////////////

void employee_report_cancel(Fl_Widget* w, void* p);
class Employee_report{
    public:
        Employee_report(){
            prompt=new Fl_Window(500,700,"Employee Report");
            string val="";

            for(int i=0; i<sales_associates.size(); i++){
                Sales_associate* emp=sales_associates[i];
                if (i+1>99) val+=to_string(i+1)+".";
                else if (i+1>9) val+=to_string(i+1)+". ";
                else val+=to_string(i+1)+".   ";
                val+=" Name:  "+emp->get_name() +"\n       Number:  "+to_string(emp->get_employee_number())+"\n";
            }
            prompt_menu = new Fl_Multiline_Output(20, 20, 460, 630, "");
            prompt_menu->align(FL_ALIGN_LEFT);
            prompt_menu->value(val.c_str());


            prompt_exit = new Fl_Button(320, 660, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)employee_report_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}
    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Button *prompt_exit;
};

Employee_report* c_emp_report;
void report_employee(Fl_Widget* w, void* p){
    c_emp_report=new Employee_report();
    c_emp_report->show();
}
void employee_report_cancel(Fl_Widget* w, void* p){
    c_emp_report->hide();
    delete c_emp_report;
}

/////////////////////////////////////Employee///////////////////////////////////////////////////////////

void customer_report_cancel(Fl_Widget* w, void* p);
class Customer_report{
    public:
        Customer_report(){
            prompt=new Fl_Window(500,700,"Customer Report");
            string val="";

            for(int i=0; i<customers.size(); i++){
                Customer* cust=customers[i];
                if (i+1>99) val+=to_string(i+1)+".";
                else if (i+1>9) val+=to_string(i+1)+". ";
                else val+=to_string(i+1)+".   ";
                val+=" Name:  "+cust->get_name() +"\n       Number:  "+to_string(cust->get_customer_number())
                                                 +"\n       Phone:  "+cust->get_phone_number()
                                                 +"\n       Email:  "+cust->get_email_address()+"\n";
            }

            prompt_menu = new Fl_Multiline_Output(20, 20, 460, 630, "");
            prompt_menu->align(FL_ALIGN_LEFT);
            prompt_menu->value(val.c_str());




            prompt_exit = new Fl_Button(320, 660, 130, 25, "Back");
            prompt_exit->callback((Fl_Callback *)customer_report_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void show() {prompt->show();}
        void hide() {prompt->hide();}
    private:
        Fl_Window *prompt;
        Fl_Multiline_Output *prompt_menu;
        Fl_Button *prompt_exit;
};

Customer_report* c_cust_report;
void report_customer(Fl_Widget* w, void* p){
    c_cust_report=new Customer_report();
    c_cust_report->show();
}
void customer_report_cancel(Fl_Widget* w, void* p){
    c_cust_report->hide();
    delete c_cust_report;
}



/////////////////////////////////////Parts///////////////////////////////////////////////////////////





void report_part_back(Fl_Widget* w, void* p);
void report_part_next(Fl_Widget* w, void* p);
void report_part_cancel(Fl_Widget* w, void* p);
class Report_part_gui{
    private:
        string _type;
        int _id=0;
        Fl_Window *prompt;
        Fl_Output *prompt_out;
        Fl_Output *prompt_name;
        Fl_Output *prompt_name2;
        Fl_Output *prompt_model;
        Fl_Output *prompt_cost;
        Fl_Output *prompt_weight;
        Fl_Multiline_Output *prompt_desc;
        Fl_Output *prompt_image_name;
        Fl_Output *prompt_power;
        Fl_Output *prompt_speed;
        Fl_Output *prompt_max_power;
        Fl_Output *prompt_max_arms;
        Fl_Output *prompt_battery_compartments;
        Fl_Output *prompt_power_available;
        Fl_Output *prompt_max_energy;
        Fl_Button *prompt_back;
        Fl_Button *prompt_next;
        Fl_Button *prompt_exit;
    public:
        Report_part_gui(string type, int id){
            string title = string("Report ")+type+string(" model");
            char *title2 = new char[title.length() + 1];
            strcpy(title2, title.c_str());

            prompt=new Fl_Window(550,385,title2);
            delete[] title2;

            prompt_name2 = new Fl_Output(0, 0, 0, 0,                "                 :");
            prompt_name2->value(title.c_str());

            _type=type;
            _id=id;

            Robot_part* rp;
            if(type=="head") rp=(Robot_part*) heads[id];
            if(type=="torso") rp=(Robot_part*) torsos[id];
            if(type=="arm") rp=(Robot_part*) arms[id];
            if(type=="locomotor") rp=(Robot_part*) locomotors[id];
            if(type=="battery") rp=(Robot_part*) batteries[id];

            prompt_name = new Fl_Output(200, 20, 300, 25,                "                 Name:");
            prompt_name->align(FL_ALIGN_LEFT);
            prompt_name->value((rp->get_name()).c_str());

            prompt_model = new Fl_Output(200, 55, 300, 25,               "                Model:");
            prompt_model->align(FL_ALIGN_LEFT);
            prompt_model->value((to_string(rp->get_model_number())).c_str());

            prompt_cost = new Fl_Output(200, 90, 300, 25,                "                 Cost:");
            prompt_cost->align(FL_ALIGN_LEFT);
            prompt_cost->value((to_string(rp->get_cost())).c_str());

            prompt_weight = new Fl_Output(200, 125, 300, 25,                "               Weight:");
            prompt_weight->align(FL_ALIGN_LEFT);
            prompt_weight->value((to_string(rp->get_weight())).c_str());

            prompt_desc = new Fl_Multiline_Output(200, 160, 300, 75,      "          Description:");
            prompt_desc->align(FL_ALIGN_LEFT);
            prompt_desc->value((put_nl(rp->get_desc())).c_str());

            prompt_image_name = new Fl_Output(200, 245, 300, 25,          "           Image File:");
            prompt_image_name->align(FL_ALIGN_LEFT);
            prompt_image_name->value((rp->get_img_name()).c_str());

            if(type=="head") head(200,280, 300,25);
            if(type=="torso") torso(200,280, 300,25);
            if(type=="arm") arm(200,280, 300,25);
            if(type=="locomotor") locomotor(200,280, 300,25);
            if(type=="battery") battery(200,280, 300,25);

            prompt_back = new Fl_Button(30, 350, 130, 25, "Previous");
            prompt_back->callback((Fl_Callback *)report_part_back, 0);

            prompt_next = new Fl_Button(180, 350, 130, 25, "Next");
            prompt_next->callback((Fl_Callback *)report_part_next, 0);

            prompt_exit = new Fl_Button(390, 350, 130, 25, "Cancel");
            prompt_exit->callback((Fl_Callback *)report_part_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        void head(int x, int y, int l, int b){
            prompt_power = new Fl_Output(x,y,l,b,               "                Power:");
            prompt_power->align(FL_ALIGN_LEFT);
            prompt_power->value((to_string(heads[_id]->get_power())).c_str());
        }
        void torso(int x, int y, int l, int b){
            prompt_max_arms = new Fl_Output(x,y,l,b,            "   Max number of Arms:");
            prompt_max_arms->align(FL_ALIGN_LEFT);
            prompt_max_arms->value((to_string(torsos[_id]->get_max_arms())).c_str());
            prompt_battery_compartments = new Fl_Output(x,y+35,l,b," Battery Compartments:");
            prompt_battery_compartments->align(FL_ALIGN_LEFT);
            prompt_battery_compartments->value((to_string(torsos[_id]->get_battery_compartments())).c_str());
        }
        void arm(int x, int y, int l, int b){
            prompt_max_power = new Fl_Output(x,y,l,b,           "            Max Power:");
            prompt_max_power->align(FL_ALIGN_LEFT);
            prompt_max_power->value((to_string(arms[_id]->get_max_power())).c_str());
        }
        void locomotor(int x, int y, int l, int b){
            prompt_max_power = new Fl_Output(x,y,l,b,           "            Max Power:");
            prompt_max_power->align(FL_ALIGN_LEFT);
            prompt_max_power->value((to_string(locomotors[_id]->get_max_power())).c_str());

            prompt_speed = new Fl_Output(x,y+35,l,b,           "            Max Speed:");
            prompt_speed->align(FL_ALIGN_LEFT);
            prompt_speed->value((to_string(locomotors[_id]->get_max_speed())).c_str());
        }
        void battery(int x, int y, int l, int b){
            prompt_power_available = new Fl_Output(x,y,l,b,     "      Power Available:");
            prompt_power_available->align(FL_ALIGN_LEFT);
            prompt_power_available->value((to_string(batteries[_id]->get_power_available())).c_str());

            prompt_max_energy = new Fl_Output(x,y+35,l,b,          "           Max Energy:");
            prompt_max_energy->align(FL_ALIGN_LEFT);
            prompt_max_energy->value((to_string(batteries[_id]->get_max_energy())).c_str());
        }
        int get_id(){return _id;}
        string type(){return _type;}
        void show() {prompt->show();}
        void hide() {prompt->hide();}
};

Report_part_gui* r_part_g;

void report_head(Fl_Widget* w, void* p){
    if (heads.size()==0){
        fl_message("There's no model created yet.");
        return;
    }
    r_part_g=new Report_part_gui("head",0);
    r_part_g->show();
}
void report_locomotor(Fl_Widget* w, void* p){
    if (locomotors.size()==0){
        fl_message("There's no model created yet.");
        return;
    }
    r_part_g=new Report_part_gui("locomotor",0);
    r_part_g->show();
}
void report_torso(Fl_Widget* w, void* p){
    if (torsos.size()==0){
        fl_message("There's no model created yet.");
        return;
    }
    r_part_g=new Report_part_gui("torso",0);
    r_part_g->show();
}
void report_arm(Fl_Widget* w, void* p){
    if (arms.size()==0) {
        fl_message("There's no model created yet.");
        return;
    }
    r_part_g=new Report_part_gui("arm",0);
    r_part_g->show();
}
void report_battery(Fl_Widget* w, void* p){
    if (batteries.size()==0) {
        fl_message("There's no model created yet.");
        return;
    }
    r_part_g=new Report_part_gui("battery",0);
    r_part_g->show();
}

void report_part_next(Fl_Widget* w, void* p){
    string t=r_part_g->type();
    int id=r_part_g->get_id();
    int max_id=0;
    if(t=="head") max_id=heads.size();
    if(t=="torso") max_id=torsos.size();
    if(t=="arm") max_id=arms.size();
    if(t=="locomotor") max_id=locomotors.size();
    if(t=="battery") max_id=batteries.size();

    if(id+1>=max_id) return;
    id++;
    r_part_g->hide();
    delete r_part_g;
    r_part_g=new Report_part_gui(t,id);
    r_part_g->show();
}
void report_part_back(Fl_Widget* w, void* p){
    string t=r_part_g->type();
    int id=r_part_g->get_id();

    if(id==0) return;
    id--;
    r_part_g->hide();
    delete r_part_g;
    r_part_g=new Report_part_gui(t,id);
    r_part_g->show();
}
void report_part_cancel(Fl_Widget* w, void* p){
    r_part_g->hide();
    delete r_part_g;
}





/////////////////////////////////////Model///////////////////////////////////////////////////////////


void report_model_back(Fl_Widget* w, void* p);
void report_model_next(Fl_Widget* w, void* p);
void report_model_cancel(Fl_Widget* w, void* p);
class Report_model_gui{
    private:
        string _type;
        int _id=0;
        Fl_Window *prompt;
        Fl_Output *prompt_out;
        Fl_Output *prompt_name;
        Fl_Output *prompt_model;
        Fl_Output *prompt_cost;
        Fl_Output *prompt_tag;
        Fl_Output *prompt_weight;
        Fl_Multiline_Output *prompt_desc;
        Fl_Output *prompt_max_speed;
        Fl_Output *prompt_max_battery_life;
        Fl_Output *prompt_limited_power;
        Fl_Output *prompt_head;
        Fl_Output *prompt_torso;
        Fl_Output *prompt_arm;
        Fl_Output *prompt_locomotor;
        Fl_Output *prompt_battery;
        Fl_Button *prompt_back;
        Fl_Button *prompt_next;
        Fl_Button *prompt_exit;
    public:
        Report_model_gui(int id){
            prompt=new Fl_Window(550,590,"Robot Model");
            _id=id;
            int i=10;

            Robot_model* r=robots[id];
            prompt_name = new Fl_Output(200, i+=5, 300, 25,                "                 Name:");
            prompt_name->value((r->get_name()).c_str());
            prompt_name->align(FL_ALIGN_LEFT);

            prompt_model = new Fl_Output(200, i+=35, 300, 25,                "                Model:");
            prompt_model->value((to_string(r->get_model_number())).c_str());
            prompt_model->align(FL_ALIGN_LEFT);

            prompt_tag = new Fl_Output(200, i+=35, 300, 25,                "            Tag Price:");
            prompt_tag->value((to_string(r->get_tag_price())).c_str());
            prompt_tag->align(FL_ALIGN_LEFT);

            prompt_cost = new Fl_Output(200, i+=35, 300, 25,                "           Parts Cost:");
            prompt_cost->value((to_string(r->get_cost())).c_str());
            prompt_cost->align(FL_ALIGN_LEFT);

            prompt_weight = new Fl_Output(200, i+=35, 300, 25,                "               Weight:");
            prompt_weight->value((to_string(r->get_weight())).c_str());
            prompt_weight->align(FL_ALIGN_LEFT);

            prompt_desc = new Fl_Multiline_Output(200, i+=35, 300, 75,                "          Description:");
            prompt_desc->value((put_nl(r->get_desc())).c_str());
            prompt_desc->align(FL_ALIGN_LEFT);

            prompt_max_speed = new Fl_Output(200, i+=85, 300, 25,                "            Max Speed:");
            prompt_max_speed->value((to_string(r->get_max_speed())).c_str());
            prompt_max_speed->align(FL_ALIGN_LEFT);

            prompt_max_battery_life = new Fl_Output(200, i+=35, 300, 25,                "     Max Battery Life:");
            prompt_max_battery_life->value((to_string(r->get_max_battery_life())).c_str());
            prompt_max_battery_life->align(FL_ALIGN_LEFT);

            prompt_limited_power= new Fl_Output(200, i+=35, 300, 25,                "        Limited Power:");
            string lim="Yes";
            if (r->limited_power()!=true) lim="False";
            prompt_limited_power->value((lim).c_str());
            prompt_limited_power->align(FL_ALIGN_LEFT);

            prompt_head = new Fl_Output(200, i+=35, 300, 25,                "           Head Model:");
            prompt_head->value((to_string(r->get_head()->get_model_number())).c_str());
            prompt_head->align(FL_ALIGN_LEFT);

            prompt_torso = new Fl_Output(200, i+=35, 300, 25,                "          Torso Model:");
            prompt_torso->value((to_string(r->get_torso()->get_model_number())).c_str());
            prompt_torso->align(FL_ALIGN_LEFT);

            prompt_arm = new Fl_Output(200, i+=35, 300, 25,                "           Arms Model:");
            prompt_arm->value((to_string(r->get_arm()->get_model_number())).c_str());
            prompt_arm->align(FL_ALIGN_LEFT);

            prompt_locomotor = new Fl_Output(200, i+=35, 300, 25,                "      Locomotor Model:");
            prompt_locomotor->value((to_string(r->get_locomotor()->get_model_number())).c_str());
            prompt_locomotor->align(FL_ALIGN_LEFT);

            prompt_battery = new Fl_Output(200, i+=35, 300, 25,                "        Battery Model:");
            prompt_battery->value((to_string(r->get_battery()->get_model_number())).c_str());
            prompt_battery->align(FL_ALIGN_LEFT);


            prompt_back = new Fl_Button(30, i+=35, 130, 25, "Previous");
            prompt_back->callback((Fl_Callback *)report_model_back, 0);

            prompt_next = new Fl_Button(180, i, 130, 25, "Next");
            prompt_next->callback((Fl_Callback *)report_model_next, 0);

            prompt_exit = new Fl_Button(390, i, 130, 25, "Cancel");
            prompt_exit->callback((Fl_Callback *)report_model_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        int get_id(){return _id;}
        void show() {prompt->show();}
        void hide() {prompt->hide();}
};

Report_model_gui* r_model_g;
void report_model(Fl_Widget* w, void* p){
    if (robots.size()==0){
        fl_message("There's no model created yet.");
        return;
    }
    r_model_g=new Report_model_gui(0);
    r_model_g->show();
}
void report_model_next(Fl_Widget* w, void* p){
    int id=r_model_g->get_id();
    int max_id=robots.size();

    if(id+1>=max_id) return;
    id++;
    r_model_g->hide();
    delete r_model_g;
    r_model_g=new Report_model_gui(id);
    r_model_g->show();
}
void report_model_back(Fl_Widget* w, void* p){
    int id=r_model_g->get_id();

    if(id==0) return;
    id--;
    r_model_g->hide();
    delete r_model_g;
    r_model_g=new Report_model_gui(id);
    r_model_g->show();
}
void report_model_cancel(Fl_Widget* w, void* p){
    r_model_g->hide();
    delete r_model_g;
}





/////////////////////////////////////Sales///////////////////////////////////////////////////////////


void report_sale_back(Fl_Widget* w, void* p);
void report_sale_next(Fl_Widget* w, void* p);
void report_sale_cancel(Fl_Widget* w, void* p);
class Report_sale_gui{
    private:
        string _type;
        int _id=0;
        Fl_Window *prompt;
        Fl_Output *prompt_order_number;
        Fl_Output *prompt_date;
        Fl_Output *prompt_customer;
        Fl_Output *prompt_sales_associate;
        Fl_Output *prompt_robot_model;
        Fl_Output *prompt_price;
        Fl_Output *prompt_status;
        Fl_Button *prompt_back;
        Fl_Button *prompt_next;
        Fl_Button *prompt_exit;
    public:
        Report_sale_gui(int id){
            prompt=new Fl_Window(550,295,"Sale Record");
            _id=id;
            int i=10;

            Order* r=orders[id];
            prompt_order_number = new Fl_Output(200, i+=5, 300, 25,                             "        Order Number:");
            prompt_order_number->value(to_string(r->get_order_number()).c_str());
            prompt_order_number->align(FL_ALIGN_LEFT);

            prompt_date = new Fl_Output(200, i+=35, 300, 25,                                    "                Date:");
            prompt_date->value(((r->get_date())).c_str());
            prompt_date->align(FL_ALIGN_LEFT);

            prompt_customer = new Fl_Output(200, i+=35, 300, 25,                                "       Customer Name:");
            prompt_customer->value(((r->get_customer()->get_name())).c_str());
            prompt_customer->align(FL_ALIGN_LEFT);

            prompt_sales_associate = new Fl_Output(200, i+=35, 300, 25,                         "Sales Associate Name:");
            prompt_sales_associate->value(((r->get_sales_associate()->get_name())).c_str());
            prompt_sales_associate->align(FL_ALIGN_LEFT);

            prompt_robot_model = new Fl_Output(200, i+=35, 300, 25,                             "         Robot Model:");
            prompt_robot_model->value((to_string(r->get_robot_model()->get_model_number())).c_str());
            prompt_robot_model->align(FL_ALIGN_LEFT);

            prompt_price = new Fl_Multiline_Output(200, i+=35, 300, 25,                         "              Price:");
            double pr=1.0825*r->get_robot_model()->get_tag_price()+r->get_robot_model()->get_weight()/100*15;

            prompt_price->value((to_string(pr)).c_str());
            prompt_price->align(FL_ALIGN_LEFT);

            prompt_status = new Fl_Multiline_Output(200, i+=35, 300, 25,                         "             Status:");
            string stat="";
            int status=r->get_status();
            if (status==0) stat="Pending";
            if (status==1) stat="Packaging";
            if (status==2) stat="Shipping";
            if (status==3) stat="Billing";
            if (status==4) stat="Accepting Payment";
            if (status==5) stat="Completed";
            if (status==6) stat="Canceled";
            prompt_status->value((stat).c_str());
            prompt_status->align(FL_ALIGN_LEFT);

            prompt_back = new Fl_Button(30, i+=35, 130, 25, "Previous");
            prompt_back->callback((Fl_Callback *)report_sale_back, 0);

            prompt_next = new Fl_Button(180, i, 130, 25, "Next");
            prompt_next->callback((Fl_Callback *)report_sale_next, 0);

            prompt_exit = new Fl_Button(390, i, 130, 25, "Cancel");
            prompt_exit->callback((Fl_Callback *)report_sale_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        int get_id(){return _id;}
        void show() {prompt->show();}
        void hide() {prompt->hide();}
};

Report_sale_gui* r_sale_g;
void report_sale(Fl_Widget* w, void* p){
    if (robots.size()==0){
        fl_message("There's no sale created yet.");
        return;
    }
    r_sale_g=new Report_sale_gui(0);
    r_sale_g->show();
}
void report_sale_next(Fl_Widget* w, void* p){
    int id=r_sale_g->get_id();
    int max_id=orders.size();

    if(id+1>=max_id) return;
    id++;
    r_sale_g->hide();
    delete r_sale_g;
    r_sale_g=new Report_sale_gui(id);
    r_sale_g->show();
}
void report_sale_back(Fl_Widget* w, void* p){
    int id=r_sale_g->get_id();
    if(id==0) return;
    id--;
    r_sale_g->hide();
    delete r_sale_g;
    r_sale_g=new Report_sale_gui(id);
    r_sale_g->show();
}
void report_sale_cancel(Fl_Widget* w, void* p){
    r_sale_g->hide();
    delete r_sale_g;
}







/////////////////////////////////////Sales///////////////////////////////////////////////////////////


void manage_sale_confirm(Fl_Widget* w, void* p);
void manage_sale_cancel(Fl_Widget* w, void* p);
class Manage_sale_gui{
    private:
        string _type;
        int _id=0;
        Fl_Window *prompt;
        Fl_Choice *prompt_order_number;
        Fl_Choice *prompt_status;
        Fl_Button *prompt_confirm;
        Fl_Button *prompt_exit;
    public:
        Manage_sale_gui(){
            prompt=new Fl_Window(550,295,"Manage Sale Record");
            int i=10;

            prompt_order_number = new Fl_Choice(200, i+=5, 300, 25,                             "        Order Number:");
            prompt_order_number->align(FL_ALIGN_LEFT);
            for(int i1=0;i1<orders.size(); i1++){
                string title=to_string(orders[i1]->get_order_number());
                prompt_order_number->add(title.c_str());
            }

            prompt_status = new Fl_Choice(200, i+=35, 300, 25,                             "              Status:");
            prompt_status->align(FL_ALIGN_LEFT);
            prompt_status->add("Begin");
            prompt_status->add("Packaged");
            prompt_status->add("Shipped");
            prompt_status->add("Billed");
            prompt_status->add("Paid");
            prompt_status->add("Completed");
            prompt_status->add("Cancel");

            prompt_confirm = new Fl_Button(180, i+=35, 130, 25, "Update");
            prompt_confirm->callback((Fl_Callback *)manage_sale_confirm, 0);

            prompt_exit = new Fl_Button(390, i, 130, 25, "Cancel");
            prompt_exit->callback((Fl_Callback *)manage_sale_cancel, 0);

            prompt->end();
            prompt->set_non_modal();
        }
        int get_order_number(){return prompt_order_number->value();}
        int get_status(){return prompt_status->value();}
        void show() {prompt->show();}
        void hide() {prompt->hide();}
};

Manage_sale_gui* m_sale_g;
void manage_order(Fl_Widget* w, void* p){
    if (orders.size()==0){
        fl_message("There's no sale created yet.");
        return;
    }
    m_sale_g=new Manage_sale_gui();
    m_sale_g->show();
}
void manage_sale_confirm(Fl_Widget* w, void* p){
    orders[m_sale_g->get_order_number()]->update_status(m_sale_g->get_status());
    m_sale_g->hide();
    delete m_sale_g;
    ofstream file;
    file.open("Order.file", ios::out);file.close();
    for(int i=0; i<orders.size(); i++){
        orders[i]->save();
    }
}
void manage_sale_cancel(Fl_Widget* w, void* p){
    m_sale_g->hide();
    delete m_sale_g;
}