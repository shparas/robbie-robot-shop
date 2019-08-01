
class Robot_part{
    protected:
        string _name, _description, _image_filename;
        int _model_number;
        double _cost, _weight;
    public:
        Robot_part(string name, int model, double cost, double weight, string desc, string img_name){
            _name=name;
            _description=desc;
            _image_filename=img_name;
            _model_number=model;
            _cost=cost;
            _weight=weight;
        }
        virtual string get_name(){
            return _name;
        }
        virtual string get_desc(){
            return _description;
        }
        virtual string get_img_name(){
            return _image_filename;
        }
        virtual int get_model_number(){
            return _model_number;
        }
        virtual double get_cost(){
            return _cost;
        }
        virtual double get_weight(){
            return _weight;
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

};
class Head: public Robot_part{
    private:
        double _power;
    public:
        Head(string name, int model, double cost, double weight, string desc, string img_name, double power):
            Robot_part(name, model, cost, weight, desc, img_name){
            _power=power;
        }
        double get_power(){return _power;}
        void save(){
        	ofstream file("Head.file", ios::app);
				file << remove_space(_name) << endl << _model_number << endl << _cost << endl << _weight << endl << remove_space(_description) << endl << remove_space(_image_filename) << endl << _power << endl;
			file.close();
		}
};
class Locomotor: public Robot_part{
    private:
        double _max_power, _max_speed;
    public:
        Locomotor(string name, int model, double cost, double weight, string desc, string img_name, double max_power, double max_speed):
            Robot_part(name, model, cost, weight, desc, img_name){
            _max_power=max_power;
            _max_speed=max_speed;
        }
        double get_max_power(){return _max_power;}
        double get_max_speed(){return _max_speed;}
        void save(){
        	ofstream file("Locomotor.file", ios::app);
				file << remove_space(_name) << endl << _model_number << endl << _cost << endl << _weight << endl << remove_space(_description) << endl << remove_space(_image_filename) << endl << _max_power << endl << _max_speed << endl;
			file.close();
		}
};
class Torso: public Robot_part{
    private:
        int _battery_compartments, _max_arms;
    public:
        Torso(string name, int model, double cost, double weight, string desc, string img_name, int battery_compartments, int max_arms):
            Robot_part(name, model, cost, weight, desc, img_name){
            _battery_compartments=battery_compartments;
            _max_arms=max_arms;
        }
        int get_max_arms(){return _max_arms;}
        int get_battery_compartments(){return _battery_compartments;}
        void save(){
        	ofstream file("Torso.file", ios::app);
				file << remove_space(_name) << endl << _model_number << endl << _cost << endl << _weight << endl << remove_space(_description) << endl << remove_space(_image_filename) << endl << _battery_compartments << endl << _max_arms << endl;
			file.close();
		}
};
class Battery: public Robot_part{
    private:
        double _power_available, _max_energy;
    public:
        Battery(string name, int model, double cost, double weight, string desc, string img_name, double power_available, double max_energy):
            Robot_part(name, model, cost, weight, desc, img_name){
            _power_available=power_available;
            _max_energy=max_energy;
        }
        double get_power_available(){return _power_available;}
        double get_max_energy(){return _max_energy;}
        void save(){
        	ofstream file("Battery.file", ios::app);
				file << remove_space(_name) << endl << _model_number << endl << _cost << endl << _weight << endl << remove_space(_description) << endl << remove_space(_image_filename) << endl << _power_available << endl << _max_energy << endl;
			file.close();
		}
};
class Arm: public Robot_part{
    private:
        double _max_power;
    public:
        Arm(string name, int model, double cost, double weight, string desc, string img_name, double max_power):
            Robot_part(name, model, cost, weight, desc, img_name){
            _max_power=max_power;
        }
        double get_max_power(){return _max_power;}
        void save(){
        	ofstream file("Arm.file", ios::app);
				file << remove_space(_name)<< endl << _model_number << endl << _cost << endl << _weight << endl << remove_space(_description) << endl << remove_space(_image_filename) << endl << _max_power << endl;
			file.close();
		}
};
