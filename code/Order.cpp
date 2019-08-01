class Order{
	private:
		int _order_number;
		string _date;
		Customer* _customer;
		Sales_associate* _sales_associate;
		Robot_model* _robot_model;
		int _status;
	public:
		Order(int order_number, string date, Customer* customer, Sales_associate* sales_associate, Robot_model* robot_model, int status){
			_order_number=order_number;
			_date=date;
			_customer=customer;
			_sales_associate=sales_associate;
			_robot_model=robot_model;
			_status=status;
		}
		int get_order_number(){
			return _order_number;
		}
		string get_date(){
			return _date;
		}
		Customer* get_customer(){
			return _customer;
		}
		Sales_associate* get_sales_associate(){
			return _sales_associate;
		}
		Robot_model* get_robot_model(){
			return _robot_model;
		}
		int get_status(){
			return _status;
		}
		void update_status(int n){
			_status=n;
		}
		void save(){
			ofstream file("Order.file", ios::app);
				file << _order_number << endl;
				file << _date << endl;
				file << _customer->get_customer_number() << endl;
				file << _sales_associate->get_employee_number() << endl;
				file << _robot_model->get_model_number() << endl;
				file << _status << endl;
			file.close();
		}
};
