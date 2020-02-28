#pragma once
// Techno's Library for VC++, version 0001
// (c) 2020 Frank G. Dahncke

// 0001 creation					11-FEB-2020
// 0002 CalculatorCLR functions		14-FEB-2020
// 0003	Randoms()					20-FEB-2020
// 0004 InputBox					28-FEB-2020

#include <string>
#include <ctime>

using namespace System;

namespace technolibCLR {
	public ref class TechnoClass
	{
		const unsigned technolibCLR_version = 4;

		//String^ ByteDisplay(UInt64 bytes) {
		//	const unsigned KB = 1024;
		//	const unsigned  MB = KB * 1024;
		//	const UInt64 GB = MB * 1024;
		//	const UInt64 TB = GB * 1024;
		//	const UInt64 PB = TB * 1024;

		//	if (bytes < KB) {
		//		return bytes.ToString & " bytes";
		//	}
		//	if (bytes < MB) {
		//		return (bytes / KB).ToString & " KB";
		//	}
		//	if (bytes < GB) {
		//		return (bytes / MB).ToString & " MB";
		//	}
		//	if (bytes < TB) {
		//		return (bytes / GB).ToString & (String^)" GB";
		//	}
		//	if (bytes < PB) {
		//		return (bytes / TB).ToString & (String^)" TB";
		//	}
		//	return (bytes / PB).ToString + " PB";
		//}
	public:
		void InitRNG() {
			srand((unsigned)time(0)); // seed the generator
		}

		// have you called InitRNG() yet?
		unsigned rollDie() { // one die (D6 in AD&D parlance)
			return 1 + (rand() % 6);
		};

		//AD&D style dice
		unsigned rollAD_D_Die(unsigned sides) {//how many sides the die has, 2...100, D2 to D100
			if (sides < 2 || sides >100) return 0;
			return 1 + (rand() % sides);
		};

		UInt64 faculty(unsigned int n)
		{
			if (n == 0)
				return 1;
			else
				return n * faculty(n - 1);
		}

		int fibunacci(int n)
		{
			if (n == 0)
				return 0;
			else if (n == 1)
				return 1;
			else
				return fibunacci(n - 1) + fibunacci(n - 2);
		}

		bool IsNumeric(String^ text) {
			double test;
			return double::TryParse(text, test);
		}

		String^ FillString(char c, unsigned amount) {
			String^ lsResult = "";
			for (unsigned i = 0; i < amount; i++) {
				lsResult += c;
			}
			return lsResult;
		}

		String^ Randoms(unsigned amount, unsigned  largest) {
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder;
			for (unsigned i = 1; i <= amount; i++) {
				sb->Append((1 + (rand() % largest)).ToString() + " ");
			}
			return sb->ToString();
		}
		String^ InputBox(String^ prompt, String^ title, String^ default) {
			return Microsoft::VisualBasic::Interaction::InputBox(prompt, title, default, -1, -1);
		}
		const String^ currentDECDate() { //like in VMS of the Digital Equipment Corporation
			DateTime localDate = DateTime::Now;
			//lblClock->Text = localDate.ToLongTimeString();
			String^ lsMON = "";

			switch (localDate.Month) {
			case 1:
				lsMON = "JAN";
				break;
			case 2:
				lsMON = "FEB";
				break;
			case 3:
				lsMON = "MAR";
				break;
			case 4:
				lsMON = "APR";
				break;
			case 5:
				lsMON = "MAY";
				break;
			case 6:
				lsMON = "JUN";
				break;
			case 7:
				lsMON = "JUL";
				break;
			case 8:
				lsMON = "AUG";
				break;
			case 9:
				lsMON = "SEP";
				break;
			case 10:
				lsMON = "OCT";
				break;
			case 11:
				lsMON = "NOV";
				break;
			case 12:
				lsMON = "DEC";
				break;
			default:
				lsMON = "NUL";
			}

			String^ zero = "";
			if (localDate.Day < 10) { zero = "0"; };
			return zero + localDate.Day.ToString() + "-" + lsMON + "-" + localDate.Year.ToString();
		}
	};
}
