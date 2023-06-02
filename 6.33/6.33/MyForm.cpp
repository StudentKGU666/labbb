#include "MyForm.h"
using namespace lab633;
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}
//конвертируем std::string в System::string^
String^ Convert_string_to_String(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}

System::Void lab633::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    string longestLine = ""; 
    ifstream file("f.txt"); 
    setlocale(LC_ALL, "Russian");
    if (file.is_open()) 
    { 
        string line;
        if (file.peek() == EOF)
        {
            textBox1->Text = "Пустой файл, строк не найдено";
        }
        else 
        {
            while (getline(file, line))
            {
                textBox2->Text += Convert_string_to_String(line) + "\r\n";
                if (line.length() > longestLine.length())
                {
                    longestLine = line;
                }
            }
            textBox1->Text += Convert_string_to_String(longestLine);
        }    
        file.close(); 
	}
    else 
    {
        textBox1->Text = "Ошибка! Текстовый файл не был открыт!";
    }
    button1->Enabled = false;
}

System::Void lab633::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void lab633::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void lab633::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
