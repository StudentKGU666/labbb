#include "MyForm.h"
#include <iostream>
#include <string>
#include <map>

#include <msclr/marshal_cppstd.h>



using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

[System::STAThreadAttribute()]
int main(array<String^>^ Args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Projectkontrosha::MyForm());

	return 0;
}

// std::string в System::string^
String^ Convert_string_to_String(std::string& os)
{
	System::String^ str = gcnew System::String(os.c_str());

	return str;
}

bool isAsciiSymbol(char c) 
{
	int ascii_code = static_cast<int>(c); 
	return (ascii_code >= 32 && ascii_code <= 126); 
}

System::Void Projectkontrosha::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{	
	textBox2->Text = "";
	textBox3->Text = "";
	
	String^ text = textBox1->Text;
	string str = marshal_as<std::string>(text);
	
	int count_once = 0;
	for (int i; i < str.length(); i++)
	{
		if (isAsciiSymbol((char)str[i])==false) 
		{
			count_once++;
		}
	}
	
	textBox3 -> Text = text;
	int totalLetters = 0; 
	string letter;
	map<char, int> letterCounts; 
	
	if (count_once == 0)
	{
		for (char c : str)
		{
			if (isalpha(c)) 
			{				
				c = tolower(c);
				letterCounts[c]++; 
				totalLetters++;
			}
		}
		if (totalLetters != 0)
		{
			for (auto p : letterCounts)
			{ 
				char c = p.first;
				int count = p.second; 
				letter = (char)c;
				double frequency = (double)count / totalLetters * 100; 
				textBox2->Text += Convert_string_to_String(letter) + ": " + Convert_string_to_String(string(count, '*')) + " (" + frequency + "%)" + "\r\n";
				textBox1->Text = "";
			}
		}
		else
		{
			textBox3->Text = textBox1->Text;
			textBox2->Text = "В тексте не найдены английские символы!";
			textBox1->Text = "";
		}
	}
	else 
	{
		textBox3->Text = textBox1->Text;
		textBox2->Text = "Кириллица недопустима!" + count_once;
		textBox1->Text = "";
	}
}

	

System::Void Projectkontrosha::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void Projectkontrosha::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
