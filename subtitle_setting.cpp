#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <locale>
#include "data.h"
#include "kr2utf8.h"

using namespace std;

int main(void)
{
	int cmd = 0;
	string appdatapath = getenv("appdata");
	string htmlpath = appdatapath + "\\worship_subtitle\\subtitles\\index.html";
	string date, sermonTitle, bible;
	wstring wdate, wsermonTitle, wbible;
	metadata data(htmlpath);

	while (1) {
		cout << "영상예배 자막 프로그램\n"
			<< "v 1.0.0\n"
			<< "=============================" << endl;
		cout << "1. 자막 편집 마법사\n"
			<< "2. 날짜 및 예배 명칭 수정\n"
			<< "3. 설교 제목 수정\n"
			<< "4. 성경 본문 수정\n"
			<< "5. OBS Studio 설정 방법\n"
			<< "6. 자막 프로그램 웹사이트\n"
			<< "7. 프로그램 종료\n"
			<< "\n원하시는 메뉴의 숫자를 입력하십시오." << endl;
		cin >> cmd;

		switch (cmd) {
		case 1:
			system("cls");
			cout << "1. 자막 편집 마법사\n"
				<< "=============================" << endl;

			cout << "현재 날짜 및 예배 명칭: ";
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getDate() << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "현재 설교 제목: ";
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getSermonTitle() << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "현재 성경 본문: ";
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getBible() << '\n'
				<< "=============================" << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "수정할 [날짜 및 예배 명칭]을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;
			cin.ignore();
			getline(cin, date);
			cout << "=============================" << endl;

			cout << "수정할 [설교 제목]을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;
			getline(cin, sermonTitle);
			cout << "=============================" << endl;

			cout << "수정할 [성경 본문]을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;
			getline(cin, bible);
			cout << "=============================" << endl;

			if (date != "-1") data.setDate(kr2utf8(date));
			if (sermonTitle != "-1") data.setSermonTitle(kr2utf8(sermonTitle));
			if (bible != "-1") data.setBible(kr2utf8(bible));

			system("cls");
			break;
		case 2:
			system("cls");
			cout << "2. 날짜 및 예배 명칭 수정\n"
				<< "=============================" << endl;

			cout << "현재 날짜 및 예배 명칭" << endl;
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getDate() << '\n'
				<< "=============================" << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "수정할 내용을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;
			
			cin.ignore();
			getline(cin, date);
			
			if (date != "-1") data.setDate(kr2utf8(date));
			
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "3. 설교 제목 수정\n"
				<< "=============================" << endl;

			cout << "현재 설교 제목" << endl;
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getSermonTitle() << '\n'
				<< "=============================" << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "수정할 내용을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;

			cin.ignore();
			getline(cin, sermonTitle);
			
			if (sermonTitle != "-1") data.setSermonTitle(kr2utf8(sermonTitle));
			
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "4. 성경 본문 수정\n"
				<< "=============================" << endl;

			cout << "현재 성경 본문" << endl;
			SetConsoleOutputCP(CP_UTF8);	//UTF-8로 출력
			cout << data.getBible() << '\n'
				<< "=============================" << endl;
			SetConsoleOutputCP(949);	//EUC-KR(MS949)로 출력

			cout << "수정할 내용을 입력하십시오. 수정하지 않으시려면 -1이라고 입력하십시오." << endl;

			cin.ignore();
			getline(cin, bible);

			if (bible != "-1") data.setBible(kr2utf8(bible));
			
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "5. OBS Studio 설정 방법\n"
				<< "=============================" << endl;
			cout << "OBS Studio에서 소스 목록 아래의 [+] 버튼을 클릭→브라우저 클릭→새로 만들기 확인→아래와 같이 설정합니다.\n"
				<< "[v] 로컬 파일\n"
				<< "URL: %appdata%\\worship_subtitle\\subtitles\\index.html\n"
				<< "너비: 1920\n"
				<< "높이: 1080\n"
				<< "[확인]을 클릭한 다음 해당 브라우저 소스가 선택된 상태에서 [필터] 클릭→효과 필터 '크로마키' 추가(#0000ff 유사성 248로 설정)\n"
				<< "=============================" << endl;
			break;
		case 6:
			system("cls");
			cout << "6. 자막 프로그램 웹사이트\n"
				<< "=============================" << endl;
			system("explorer \"https://github.com/sooseongcom/worship_subtitle.git\"");
			system("cls");
			break;
		case 7:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "존재하지 않는 명령어입니다. 다시 입력해 주세요.\n"
				<< "=============================" << endl;
			break;
		}
	}

	return 0;
}