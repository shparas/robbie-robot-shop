class Customer{
	private:
		string _name;
		int _customer_number;
		string _phone_number;
		string _email_address;
	public:
		Customer(int customer_number, string name, string phone_number, string email_address){
			_name=name;
			_customer_number=customer_number;
			_phone_number=phone_number;
			_email_address=email_address;
		}
		string get_name(){
			return _name;
		}
		int get_customer_number(){
			return _customer_number;
		}
		string get_phone_number(){
			return _phone_number;
		}
		string get_email_address(){
			return _email_address;
		}

		void save(){
			ofstream file("Customer.file", ios::app);
				file << _customer_number << endl;
				file << remove_space(_name) << endl;
				file << _phone_number << endl;
				file << _email_address << endl;
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
