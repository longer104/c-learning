#include <string>
using namespace std;
#include <iostream>
#define MAX 1000

	struct person{	//�����ṹ����ϵ��
		string m_Name;
		int m_Sex;
		int m_Age;
		string m_Phone;
		string m_Addr;
		
	};
	struct Addressbooks {	//����ͨ��¼
		struct person personArray[MAX];	//ͨ��¼�б�����ϵ�˽ṹ��
		int m_Size;
	};
//�����ϵ���Ƿ���ڣ�����ڣ����ؾ���λ�ã���������ڷ���-1
	int isExist(Addressbooks * abs, string name) {
		for (int i = 0; i < abs->m_Size; i++) {
			if (abs->personArray[i].m_Name == name) {
				return i;
			}				
			}			
		return -1;			
			
		}

//ɾ��ָ����ϵ����Ϣ
	void deletePerson(Addressbooks * abs) {
		cout << "������Ҫɾ������ϵ��������" << endl;
		string name;
		cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;			
		}
		else {
			cout << "���޴���" << endl;
		
		}
		system("pause");
		system("cls");

	
	}
//������ϵ��
	void findPerson(Addressbooks * abs) {
		cout << "��������Ҫ�ҵ���ϵ�ˣ�" << endl;
		string name;
		cin >> name;

		int ret = isExist(abs, name);
		if (ret != -1)
		{
			cout << "������" << abs->personArray[ret].m_Name << "\t";
			cout << "�Ա�" << abs->personArray[ret].m_Sex  << "\t";
			cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
			cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
	}


//��ʾ��ϵ��
	void showPerson(Addressbooks *abs) {
		if (abs->m_Size==0) { //�ж��Ƿ���ϵ��Ϊ��
			cout << "��ǰ��¼Ϊ��" << endl;
		}
		else
		{
			for (int i = 0; i < abs->m_Size; i++) {
				cout << "������" << abs->personArray[i].m_Name << "\t";
				cout << "�Ա�" << (abs->personArray[i].m_Sex==1 ? "Ů":"��") << "\t";
				cout << "���䣺" << abs->personArray[i].m_Age << "\t";
				cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
				cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
				
			}
		}
		system("pause");
		system("cls");
	
	}


//�����ϵ��
	void addPerson(Addressbooks *abs) {
		if (abs->m_Size == MAX) {
			cout << "ͨѶ¼�����޷��������" << endl;
			return;
		}
		else {
			//��������
			string name;
			cout << "������������" << endl;
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;

			//�����Ա�
			while (true)	//�ж��Ա�ֱ��������ȷ
			{
				cout << "�������Ա�" << endl;
				cout << "1--Ů" << endl;
				cout << "2--��" << endl;

				int sex;
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->personArray[abs->m_Size].m_Sex = sex;
					break;
				}
				cout << "������������������" << endl;
			}

			//��������
			cout << "���������䣺" << endl;
			int age;
			cin >> age;
			abs->personArray[abs->m_Size].m_Age = age;

			//����绰
			cout << "������绰��" << endl;
			string phone;
			cin >> phone;
			abs->personArray[abs->m_Size].m_Phone = phone;
			

			//�����ַ
			cout << "�������ַ��" << endl;
			string addr;
			cin >> addr;
			abs->personArray[abs->m_Size].m_Addr = addr;
			
			abs->m_Size++;
			cout << "��ӳɹ���" << endl;
			system("pause");
			system("cls");
		}
		
	}

	void showMenu() {  //չʾͨ��¼ѡ��
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

	int main() {
		
		int select = 0;
		struct Addressbooks abs;
		struct Addressbooks * abs_p = &abs;
		abs.m_Size = 0;
		
		while (true) //ֱ��ѡ��0���˳���ʾ�˵�
		{
			showMenu();
			cout << "������ѡ��" << endl;
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
			case 0: //ѡ��Ϊ0���˳�����
				cout << "����ʹ��" << endl;
				system("pause"); //���������
				return 0; //�������� 
				break;
			deafult:
				break;
			}
		}
		
		system("pause");
		return 0;
}