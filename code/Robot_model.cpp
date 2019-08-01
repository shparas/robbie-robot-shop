class Robot_model{
	private:
		string _name, _description;
		int _model_number;
		Torso* _torso;
		Head* _head;
		Locomotor* _locomotor;
		Arm* _arm;
		Battery* _battery;
		double _max_speed, _max_battery_life, _tag_price;

	public:
		Robot_model(string name, int model_number, double tag_price, string desc, Torso* torso, Head* head, Locomotor* locomotor, Arm* arm, Battery* battery){
			_name=name;
			_model_number=model_number;
			_torso=torso;
			_head=head;
			_locomotor=locomotor;
			_arm=arm;
			_battery=battery;
			_description=desc;
			_tag_price=tag_price;
		}
		void set_max_speed(double max_speed){
			_max_speed=max_speed;
		}
		void set_max_battery_life(double max_battery_life){
			_max_battery_life=max_battery_life;
		}
		string get_name(){
			return _name;
		}
		int get_model_number(){
			return _model_number;
		}
		Torso* get_torso(){
			return _torso;
		}
		Head* get_head(){
			return _head;
		}
		Locomotor* get_locomotor(){
			return _locomotor;
		}
		Arm* get_arm(){
			return _arm;
		}
		Battery* get_battery(){
			return _battery;
		}
		double get_cost(){
			return 1.2*(_torso->get_cost() + _head->get_cost() + _locomotor->get_cost() + _arm->get_cost() + _battery->get_cost());		//20% assembly charge
		}
		double get_max_speed(){
			double loc_wei=_locomotor->get_weight();
			double wei=get_weight();
			if(loc_wei<=wei){
                return _locomotor->get_max_speed();
			} else {
                return _locomotor->get_max_speed()*_locomotor->get_weight()*5/get_weight();
			}
		}
		double get_max_battery_life(){
			double pow= (_head->get_power()+15/100*_locomotor->get_max_power()+_torso->get_max_arms()*40/100*_arm->get_max_power());
            return _torso->get_battery_compartments()*_battery->get_max_energy()*1000/pow;
		}
        double get_tag_price(){
            return _tag_price;
        }
        string get_desc(){
            return _description;
        }
        double get_weight(){
            return _torso->get_weight()+_head->get_weight()+_arm->get_weight()*_torso->get_max_arms()+_battery->get_weight()*_torso->get_battery_compartments()+_locomotor->get_weight();
        }
        bool limited_power(){
            double pow=(_head->get_power()+_locomotor->get_max_power()+_torso->get_max_arms()*_arm->get_max_power());
            double pow2=_torso->get_battery_compartments()*_battery->get_power_available();
            if (pow> pow2) return true;
            else return true;
        }
        void save(){
        	ofstream file("Robot_model.file", ios::app);
				file  << remove_space(_name) << endl
			 		  << _model_number << endl
			 		  << _tag_price << endl
			 		  << remove_space(_description) << endl
					  << _torso->get_model_number() << endl
					  << _head->get_model_number() << endl
					  << _locomotor->get_model_number() << endl
					  << _arm->get_model_number() << endl
					  << _battery->get_model_number() << endl;
			file.close();
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


