#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MyForm2.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace Project77;


double Calculatef(double x, double y, double z)
{
    return 5.0 * std::atan(x) - 0.25 * std::acos(x) * ((x + 3.0 * std::abs(x - y) + std::pow(x, 2)) / (std::abs(x - y) * z + std::pow(x, 2)));
}


inline System::Void Project77::MyForm::get_res_Click(System::Object^ sender, System::EventArgs^ e) 
{

	std::vector<double> xValues;
	for (double x = 1; x <= 23; x += 0.1)
	{
		xValues.push_back(x);
	}

	std::vector<double> yValues;
	for (double y = 1; y <= 23; y += 0.1)
	{
		yValues.push_back(y);
	}

	std::vector<double> zValues;
	for (double z = 1; z <= 23; z += 0.1)
	{
		zValues.push_back(z);
	}

	std::vector<double> fValues;
	for (int i = 0; i < xValues.size(); i++)
	{
		double x = xValues[i];
		double y = yValues[i];
		double z = zValues[i];
		double f = Calculatef(x, y, z);
		fValues.push_back(f);
	}

	chart->Series[0]->Points->Clear();
	for (int i = 0; i < xValues.size(); i++)
	{
		chart->Series[0]->Points->AddXY(xValues[i], fValues[i]);
	}

	chart->ChartAreas[0]->AxisX->Minimum = 0;
	chart->ChartAreas[0]->AxisX->Maximum = +200;
	chart->ChartAreas[0]->AxisX->Title = "X";
	chart->ChartAreas[0]->AxisY->Title = "Y";
	chart->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
}


[STAThreadAttribute]
int main(array<String^> ^args){;
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm form;
    Application::Run(% form);
}