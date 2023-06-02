#include "MyForm.h"
#include "vector"
using namespace My57;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}

//конвертируем std::string в System::string^
String^ Convert_string_to_String(std::string& os) {
	System::String^ str = gcnew System::String(os.c_str());

	return str;
}

struct JewelryInfo
{
	string name;
	double price;
	double gemstone_weight;
	string gemstone_name;
};

System::Void My57::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	vector<JewelryInfo> jewelry_list;
	double total_gemstone_weight = 0;
	double total_price = 0;
	int sapphire_count = 0;
	int diamond_count = 0;
	int emerald_count = 0;
	int ruby_count = 0;
	string str;

	jewelry_list.push_back({ "Кольцо с бриллиантом", 50000, 0.3, "Бриллиант" });
	jewelry_list.push_back({ "Ожерелье с сапфирами", 75000, 1.0, "Сапфир" });
	jewelry_list.push_back({ "Серьги с изумрудами", 60000, 0.5, "Изумруд" });
	jewelry_list.push_back({ "Браслет с рубинами", 90000, 0.7, "Рубин" });
	jewelry_list.push_back({ "Кольцо с изумрудом", 80000, 0.4, "Изумруд" });
	jewelry_list.push_back({ "Серьги с бриллиантами", 120000, 0.8, "Бриллиант" });

	for (int i = 0; i < jewelry_list.size(); i++) {
		total_price += jewelry_list[i].price;
		if (jewelry_list[i].gemstone_name != "")
		{
			total_gemstone_weight += jewelry_list[i].gemstone_weight;
		}
		if (jewelry_list[i].gemstone_name == "Сапфир")
		{
			sapphire_count++;
		}
		if (jewelry_list[i].gemstone_name == "Бриллиант")
		{
			diamond_count++;
		}
		if (jewelry_list[i].gemstone_name == "Изумруд")
		{
			emerald_count++;
		}
		if (jewelry_list[i].gemstone_name == "Рубин")
		{
			ruby_count++;
		}
		textBox4->Text += Convert_string_to_String(jewelry_list[i].name) + "\r\n" + " Стоимость: " + jewelry_list[i].price + "\r\n" + " Вес: " + jewelry_list[i].gemstone_weight + "\r\n";
	}
	textBox1->Text += total_gemstone_weight;
	textBox2->Text += total_price;
	textBox3->Text += sapphire_count;
	button1->Enabled = false;
}

System::Void My57::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void My57::MyForm::label3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}



