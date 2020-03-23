#include <string>
using namespace std;
#include <iostream>
#define MAX 1000

	struct person{	//创建结构体联系人
		string m_Name;
		int m_Sex;
		int m_Age;
		string m_Phone;
		string m_Addr;
		
	};
	struct Addressbooks {	//创建通信录
		struct person personArray[MAX];	//通信录中保存联系人结构体
		int m_Size;
	};
//检查联系人是否存在，如存在，返回具体位置，如果不存在返回-1
	int isExist(Addressbooks * abs, string name) {
		for (int i = 0; i < abs->m_Size; i++) {
			if (abs->personArray[i].m_Name == name) {
				return i;
			}				
			}			
		return -1;			
			
		}

//删除指定联系人信息
	void deletePerson(Addressbooks * abs) {
		cout << "请输入要删除的联系人姓名：" << endl;
		string name;
		cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "删除成功" << endl;			
		}
		else {
			cout << "查无此人" << endl;
		
		}
		system("pause");
		system("cls");

	
	}
//查找联系人
	void findPerson(Addressbooks * abs) {
		cout << "请输入您要找的联系人：" << endl;
		string name;
		cin >> name;

		int ret = isExist(abs, name);
		if (ret != -1)
		{
			cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
			cout << "性别：" << abs->personArray[ret].m_Sex  << "\t";
			cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
			cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
			cout << "地址：" << abs->personArray[ret].m_Addr << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	}


//显示联系人
	void showPerson(Addressbooks *abs) {
		if (abs->m_Size==0) { //判断是否联系人为空
			cout << "当前记录为空" << endl;
		}
		else
		{
			for (int i = 0; i < abs->m_Size; i++) {
				cout << "姓名：" << abs->personArray[i].m_Name << "\t";
				cout << "性别：" << (abs->personArray[i].m_Sex==1 ? "女":"男") << "\t";
				cout << "年龄：" << abs->personArray[i].m_Age << "\t";
				cout << "电话：" << abs->personArray[i].m_Phone << "\t";
				cout << "地址：" << abs->personArray[i].m_Addr << endl;
				
			}
		}
		system("pause");
		system("cls");
	
	}


//添加联系人
	void addPerson(Addressbooks *abs) {
		if (abs->m_Size == MAX) {
			cout << "通讯录已满无法继续添加" << endl;
			return;
		}
		else {
			//输入姓名
			string name;
			cout << "请输入姓名：" << endl;
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;

			//输入性别
			while (true)	//判断性别，直到输入正确
			{
				cout << "请输入性别：" << endl;
				cout << "1--女" << endl;
				cout << "2--男" << endl;

				int sex;
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->personArray[abs->m_Size].m_Sex = sex;
					break;
				}
				cout << "输入有误，请重新输入" << endl;
			}

			//输入年龄
			cout << "请输入年龄：" << endl;
			int age;
			cin >> age;
			abs->personArray[abs->m_Size].m_Age = age;

			//输入电话
			cout << "请输入电话：" << endl;
			string phone;
			cin >> phone;
			abs->personArray[abs->m_Size].m_Phone = phone;
			

			//输入地址
			cout << "请输入地址：" << endl;
			string addr;
			cin >> addr;
			abs->personArray[abs->m_Size].m_Addr = addr;
			
			abs->m_Size++;
			cout << "添加成功！" << endl;
			system("pause");
			system("cls");
		}
		
	}

	void showMenu() {  //展示通信录选项
	cout << "***********************" << endl;
	cout << "*****1，添加联系人*****" << endl;
	cout << "*****2，显示联系人*****" << endl;
	cout << "*****3，删除联系人*****" << endl;
	cout << "*****4，查找联系人*****" << endl;
	cout << "*****0，退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

	int main() {
		
		int select = 0;
		struct Addressbooks abs;
		struct Addressbooks * abs_p = &abs;
		abs.m_Size = 0;
		
		while (true) //直到选择0，退出显示菜单
		{
			showMenu();
			cout << "请输入选项" << endl;
			cin >> select;
			switch (select) {
			case 1:
				addPerson(abs_p);
				break;
			case 2:
				showPerson(abs_p);
				break;
			case 3:
			{   
				deletePerson(abs_p);
				
				break;
			}
			case 4:
				findPerson(abs_p);
				break;
			case 0: //选择为0，退出程序
				cout << "结束使用" << endl;
				system("pause"); //按任意继续
				return 0; //结束函数 
				break;
			deafult:
				break;
			}
		}
		
		system("pause");
		return 0;
}