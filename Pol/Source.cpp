#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include<fstream>

using namespace std;

vector <pair<int, int> > Polynomial(string func); //push in 2 vector 2 function and return 2 vector of 2 int in order Parameter and the power
vector<pair<int, int>> sumation(vector<pair<int, int>>v1, vector<pair<int, int>>v2); //return the result in vector in order Parameter and the power
vector<pair<int, int>> subtraction(vector<pair<int, int>>v1, vector<pair<int, int>>v2);
vector<pair<int, int>> multiplication(vector<pair<int, int>>v1, vector<pair<int, int>>v2);
bool search_in_file(string s, string p, string o);
string sum_result(vector<pair<int, int>>v); //return the result in string in order Parameter and the power
string temp, character;
void Display(vector <pair <int, int> > v1, vector <pair <int, int> > v2, string op, string &res);
void input();
void new_run(string);
int main()
{
	input();
	system("pause");
	return 0;

}
bool search_in_file(string s, string p, string o)
{
	bool found = false;
	string s1, s2, operation;
	int counter1 = 1, counter2 = 2, counter3 = 3;
	fstream find;
	find.open("polynomial_calculator.txt");
	find >> temp;
	//bool t = temp.empty();	
	for (int i = 1; !find.eof() && !temp.empty(); i++) {

		if (found) {
			find.close();
			cout << "founded" << endl;
			cout << temp << endl;

			return true;
		}
		if (counter1 == i)
		{
			s1 = temp;
			counter1 += 4;
		}
		else if (counter2 == i)
		{
			s2 = temp;
			counter2 += 4;
		}
		else if (counter3 == i)
		{
			operation = temp;
			counter3 += 4;
			if ((operation == o&&s1 == s&&s2 == p) || (operation == o&&s1 == p&&s2 == s)) {
				found = true;
			}
		}
		find >> temp;
	}
	find.close();
	cout << "not founded" << endl;
	return false;
}
void insert_in_file(string s)
{
	ofstream Function_Data;
	Function_Data.open("polynomial_calculator.txt", ios::app);
	Function_Data << s << endl;
	Function_Data.close();
}

void input()
{
	int check, counter = 0;
	string p1, p2, operation, result;
	vector <pair <int, int> > v1, v2;
	cout << "Enter two equations : " << endl;
	cout << "1 : ";	 cin >> p1;
	cout << "2 : ";	 cin >> p2;
	do
	{
		if (counter > 0)
			cout << "Please enter correct choice : " << endl;
		cout << "Enter the number of Operation : " << endl;
		cout << "1- Multiplication  :" << endl << "2-Sumation : " << endl << "3-Subtraction : " << endl;
		cin >> check;
		if (check == 1)
			operation = "m";
		else if (check == 2)
			operation = "sumation";
		else if (check == 3)
			operation = "subtraction";
		counter++;

	} while (check != 1 && check != 2 && check != 3);

	//search section //search in file if the 2 fun is exist or not  bool fun called //exist(p1,p2) return 0 if not exist || empty and 1 if exist

	//if(exist(p1,p2)==1)cout the result in file

	//else if(exist(p1,p2)==0) {
	if (!search_in_file(p1, p2, operation)) {
		insert_in_file(p1);
		insert_in_file(p2);
		insert_in_file(operation);
		v1 = Polynomial(p1);
		v2 = Polynomial(p2);



		Display(v1, v2, operation, result);
	}
	else
		new_run(temp);
	//}
}
void new_input(string result)
{
	int check, counter = 0;
	string s;
	s = result;
	cout << s << endl;
	string p1, p2, operation, result1;
	vector <pair <int, int> > v1, v2;
	cout << "Enter new equations : " << endl;
	cout << "1 : ";	 cin >> p1;
	cout << "Enter the Operation : " << endl;
	do
	{
		if (counter > 0)
			cout << "Please enter correct choice : " << endl;
		cout << "Enter the number of Operation : " << endl;
		cout << "1- Multiplication  :" << endl << "2-Sumation : " << endl << "3-Subtraction : " << endl;
		cin >> check;
		if (check == 1)
			operation = "m";
		else if (check == 2)
			operation = "sumation";
		else if (check == 3)
			operation = "subtraction";
		counter++;

	} while (check != 1 && check != 2 && check != 3);


	//search section //search in file if the 2 fun is exist or not  bool fun called //exist(p1,p2) return 0 if not exist || empty and 1 if exist

	//if(exist(p1,p2)==1)cout the result in file

	//else if(exist(p1,p2)==0) {
	if (!search_in_file(s, p1, operation)) {
		insert_in_file(s);
		insert_in_file(p1);
		insert_in_file(operation);
		v1 = Polynomial(s);
		v2 = Polynomial(p1);



		Display(v1, v2, operation, result1);
	}
	else
		new_run(temp);
	//}
}

void Display(vector <pair <int, int> > v1, vector <pair <int, int> > v2, string op, string &res) //&res means that result in main fun is edited
{
	int check, counter = 0;
	if (op == "sumation" || op == "m" || op == "subtraction") {
		if (op == "sumation")
		{
			res = sum_result(sumation(v1, v2));
			cout << res << endl;
		}
		else if (op == "m")
		{
			res = sum_result(multiplication(v1, v2));
			cout << res << endl;
		}
		else if (op == "subtraction")
		{
			res = sum_result(subtraction(v1, v2));
			cout << res << endl;
		}
		new_run(res);
	}
	/*else
	{
	cout << "Not defined \n enter defined one\n";
	string op2; cin >> op2;
	Display(v1, v2, op2, res);
	}*/
}
void new_run(string res) {
	int check, counter = 0;
	do
	{
		if (counter > 0)
			cout << "Please enter correct choice" << endl;
		if (counter == 0) {
			cout << "Do you want another operation" << endl;
			cout << "1- Yes by using old result" << endl << "2- Yes by using new equations " << endl << "3- No" << endl;
		}
		cin >> check;
		if (check == 1)
			new_input(res);
		else if (check == 2)
			input();
		else if (check == 3)
			cout << "Thanks :)" << endl;
		counter++;
	} while (check != 1 && check != 2 && check != 3);

}
vector <pair<int, int> > Polynomial(string func)
{

	vector <pair<int, int> > coef_exp;
	for (int i = 0; i < func.size(); i++)
	{
		//case1(x+...||x^n+...||...+x^n+....)
		if ((func[i] >= 'a'&&func[i] <= 'z' && i == 0) || (func[i] >= 'a'&&func[i] <= 'z' && func[i - 1] == '+') || (func[i] >= 'A'&&func[i] <= 'Z' && i == 0) || (func[i] >= 'A'&&func[i] <= 'Z' && func[i - 1] == '+'))
		{
			character = func[i];
			if (i == func.size() - 1)
				coef_exp.push_back(make_pair(1, 1));
			else if (func[i + 1] == '+' || func[i + 1] == '-')
				coef_exp.push_back(make_pair(1, 1));
			//get exponent
			else if (func[i + 1] == '^')
			{
				int j = i + 2;
				string carry_exp;
				while (true)
				{
					carry_exp += func[j];
					j++;
					if (j == func.size())
						break;
					else if (func[j] == '+' || func[j] == '-')
						break;
				}
				//stringstream
				stringstream sso;
				int cary_exp;
				sso << carry_exp;
				sso >> cary_exp;
				coef_exp.push_back(make_pair(1, cary_exp));
			}
			//******************
		}
		//case2(-x^n..... || ...-x^n+.....)
		else if (func[i] >= 'A'&&func[i] <= 'Z'&& func[i - 1] == '-' || func[i] >= 'a'&&func[i] <= 'z'&& func[i - 1] == '-')
		{
			character = func[i];
			if (i == func.size() - 1)
				coef_exp.push_back(make_pair(-1, 1));
			else if (func[i + 1] == '+' || func[i + 1] == '-')
				coef_exp.push_back(make_pair(-1, 1));
			//get exponent
			else if (func[i + 1] == '^')
			{
				int j = i + 2;
				string carry_exp;
				while (true)
				{
					carry_exp += func[j];
					j++;
					if (j == func.size())
						break;
					else if (func[j] == '+' || func[j] == '-')
						break;
				}
				//stringstream
				stringstream sso;
				int cary_exp;
				sso << carry_exp;
				sso >> cary_exp;
				coef_exp.push_back(make_pair(-1, cary_exp));
			}
			//******************
		}
		//case3(mx^n || -mx^2)
		else if (func[i] >= 'A'&&func[i] <= 'Z' && func[i - 1] != '+' && func[i - 1] != '-' || func[i] >= 'a'&&func[i] <= 'z' && func[i - 1] != '+' && func[i - 1] != '-')
		{
			character = func[i];
			//get coefficient
			string carry_coef;
			int j = i - 1;
			while (true)
			{
				carry_coef += func[j];
				j--;
				if (j == -1)
					break;
				else if (func[j] == '+')
					break;
				else if (func[j] == '-')
				{
					carry_coef += '-';
					break;
				}
			}
			reverse(carry_coef.begin(), carry_coef.end());
			stringstream sso;
			int cary_coef;
			sso << carry_coef;
			sso >> cary_coef;
			//***************//
			//get exponent
			if (i == func.size() - 1)
				coef_exp.push_back(make_pair(cary_coef, 1));
			else if (func[i + 1] == '+' || func[i + 1] == '-')
				coef_exp.push_back(make_pair(cary_coef, 1));
			else if (func[i + 1] == '^')
			{
				int j = i + 2;
				string carry_exp;
				while (true)
				{
					carry_exp += func[j];
					j++;
					if (j == func.size())
						break;
					else if (func[j] == '+' || func[j] == '-')
						break;
				}
				//stringstream
				stringstream so;
				int cary_exp;
				so << carry_exp;
				so >> cary_exp;
				coef_exp.push_back(make_pair(cary_coef, cary_exp));
			}
			//********************
		}
	}
	//case4(get the number without x)
	string carry_coef;
	int ind = 0;
	for (int i = 0; i < func.size(); i++)
	{
		if ((func[i] == '+' && i != ind && i != 0) || (func[i] == '-' && i != ind && i != 0))
		{
			break;
		}
		carry_coef += func[i];
		if (func[i] >= 'A'&&func[i] <= 'Z' || func[i] >= 'a'&&func[i] <= 'z')
		{
			bool check = false;
			carry_coef = "";
			int j = i + 1;
			while (j != func.size())
			{
				if (func[j] == '+' || func[j] == '-')
				{
					check = true;
					ind = j;
					break;
				}
				j++;
			}
			if (check == false)
				break;
			i = ind - 1;
		}
	}
	if (carry_coef.size() > 0)
	{
		int cary_coef;
		stringstream sso;
		sso << carry_coef;
		sso >> cary_coef;
		coef_exp.push_back(make_pair(cary_coef, 0));
	}
	//***************
	return coef_exp;
}

vector<pair<int, int>> sumation(vector<pair<int, int>>v1, vector<pair<int, int>>v2)
{
	vector<pair<int, int>>v3;

	vector<pair<int, int>>::iterator it1;

	vector<pair<int, int>>::iterator it2;

	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{

		bool v1_isfound = false;

		for (it2 = v2.begin(); it2 != v2.end(); it2++)

		{

			if ((*it1).second == (*it2).second) //intersection between v1 and v2

			{

				v1_isfound = true;

				int sum = (*it1).first + (*it2).first;

				if (sum != 0)

					v3.push_back(make_pair(sum, (*it1).second));

			}

		}

		if (v1_isfound == false) //set of(v1) - set of(v2)

			v3.push_back(make_pair((*it1).first, (*it1).second));

	}


	for (it2 = v2.begin(); it2 != v2.end(); it2++)

	{

		bool  v2_isfound = false;

		for (it1 = v1.begin(); it1 != v1.end(); it1++)

		{

			if ((*it1).second == (*it2).second) //there are intersection between v1 and v2

				v2_isfound = true;

		}


		if (v2_isfound == false) //set of(v2) - set of(v1)

			v3.push_back(make_pair((*it2).first, (*it2).second));

	}
	return v3;
}
vector<pair<int, int>> subtraction(vector<pair<int, int>>v1, vector<pair<int, int>>v2)
{
	vector<pair<int, int>>v3;

	vector<pair<int, int>>::iterator it1;

	vector<pair<int, int>>::iterator it2;

	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{

		bool v1_isfound = false;

		for (it2 = v2.begin(); it2 != v2.end(); it2++)

		{

			if ((*it1).second == (*it2).second) //intersection between v1 and v2

			{

				v1_isfound = true;

				int sub = (*it1).first - (*it2).first;

				if (sub != 0)

					v3.push_back(make_pair(sub, (*it1).second));

			}

		}

		if (v1_isfound == false) //set of(v1) - set of(v2)

			v3.push_back(make_pair((*it1).first, (*it1).second));

	}


	for (it2 = v2.begin(); it2 != v2.end(); it2++)

	{

		bool  v2_isfound = false;

		for (it1 = v1.begin(); it1 != v1.end(); it1++)

		{

			if ((*it1).second == (*it2).second) //there are intersection between v1 and v2

				v2_isfound = true;

		}


		if (v2_isfound == false) //set of(v2) - set of(v1)

			v3.push_back(make_pair((*it2).first, (*it2).second));

	}
	return v3;
}
vector<pair<int, int>> multiplication(vector<pair<int, int>>v1, vector<pair<int, int>>v2)
{

	vector<pair<int, int>>v3;
	vector<pair<int, int>>v4;
	vector<pair<int, int>>v5;
	vector<pair<int, int>>::iterator it1;
	vector<pair<int, int>>::iterator it2;
	int temp;

	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{

		//bool v1_isfound = false;

		for (it2 = v2.begin(); it2 != v2.end(); it2++)

		{
			v3.push_back(make_pair((*it1).first*(*it2).first, (*it1).second + (*it2).second));

		}

	}
	for (int i = 0; i < v3.size(); i++) {
		swap(v3[i].first, v3[i].second);
	}
	sort(v3.begin(), v3.end());


	for (int i = 0, j = 0; i < v3.size(); i++)
	{
		bool v2_isfound = false;
		if (v4.empty())
		{
			v4.push_back(make_pair(v3[i].second, v3[i].first));
			v2_isfound = true;
		}



		else if (v3[i].first == v4[j].second)
		{

			v4[j].second = v3[i].first;
			v4[j].first += v3[i].second;
			v2_isfound = true;
		}




		if (v2_isfound == false)
		{

			v4.push_back(make_pair(v3[i].second, v3[i].first));
			j++;

		}

	}

	return v4;
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

string sum_result(vector<pair<int, int>>v)
{
	sort(v.begin(), v.end(), sortbysec);
	reverse(v.begin(), v.end());
	string result = "";
	vector<pair<int, int>>::iterator it3;
	for (it3 = v.begin(); it3 != v.end(); it3++)
	{
		if ((*it3).first > 0 && (*it3).second > 0) //there are positive parameter and power
		{
			if ((*it3).first == 1) //parameter
			{
				result += "+" + character;
			}
			else if ((*it3).first != 1) //parameter
			{
				result += "+" + to_string((*it3).first) + character;
			}
			if ((*it3).second != 1) //power
			{
				result += "^" + to_string((*it3).second);
			}

		}
		else if ((*it3).first < 0 && (*it3).second < 0)  //there are negative parameter and power
		{
			if ((*it3).first == -1)
			{
				result += "-" + character + "^" + to_string((*it3).second);
			}
			else
			{
				result += to_string((*it3).first) + character + "^" + to_string((*it3).second);
			}

		}
		else if ((*it3).first > 0 && (*it3).second == 0)   //only positive parameter
			result += "+" + to_string((*it3).first);
		else if ((*it3).first < 0 && (*it3).second == 0) //only nigative parameter
			result += " " + to_string((*it3).first);

	}
	if (result[0] == '+')
	{
		result.erase(0, 1);
	}
	insert_in_file(result);

	return result;
}


