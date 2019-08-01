class Sales_associate{
	private:
		string _name;
		int _employee_number;
	public:
		Sales_associate(int employee_number, string name){
			_name=name;
			_employee_number=employee_number;
		}
		string get_name(){
			return _name;
		}
		int get_employee_number(){
			return _employee_number;
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
		void save(){
			ofstream file("Sales_associate.file", ios::app);
				file << _employee_number << endl;
				file << remove_space(_name) << endl;
			file.close();
		}
};
