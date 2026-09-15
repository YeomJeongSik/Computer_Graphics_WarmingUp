//#include <iostream>
//#include <vector>
//#include <string>
//#include <fstream>
//#include <Windows.h>
//#include <cstdlib>
//
//void SetColor(int color) {
//	SetConsoleTextAttribute(
//		GetStdHandle(STD_OUTPUT_HANDLE),
//		color
//	);
//}
//
//void Print(const std::vector<std::string>& data) {
//	for (int i = 0; i < data.size(); i++) {
//		std::cout << data[i] << std::endl;
//	}
//}
//
//int main() {
//
//	std::vector<std::string> data;
//
//	// data.txt 파일 읽기
//	std::ifstream file("data.txt");
//
//	if (!file.is_open()) {
//		std::cout << "data.txt 파일을 찾을 수 없습니다." << std::endl;
//		return 0;
//	}
//
//	std::string line;
//
//	while (std::getline(file, line)) {
//		data.push_back(line);
//	}
//
//	file.close();
//
//	Print(data);
//
//	while (1) {
//
//		char order = '\0';
//
//		std::cout << std::endl;
//		std::cout << "input the command: ";
//		std::cin >> order;
//
//		//g에서는 화면을 지우지 않음
//		if (order != 'g') {
//			system("cls");
//		}
//
//		// a : 모든 문자의 대소문자 바꾸기
//		if (order == 'a') {
//
//			std::vector<std::string> dump = data;
//
//			for (int i = 0; i < dump.size(); i++) {
//				for (int j = 0; j < dump[i].size(); j++) {
//
//					if (dump[i][j] >= 'a' and dump[i][j] <= 'z') {
//						dump[i][j] = dump[i][j] - 'a' + 'A';
//					}
//					else if (dump[i][j] >= 'A' and dump[i][j] <= 'Z') {
//						dump[i][j] = dump[i][j] - 'A' + 'a';
//					}
//				}
//			}
//
//			while (1) {
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "a를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'a') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// b : 각 문장의 단어 개수 출력
//		else if (order == 'b') {
//
//			for (int i = 0; i < data.size(); i++) {
//
//				int count = 0;
//				bool word = false;
//
//				for (int j = 0; j < data[i].size(); j++) {
//
//					//공백이 아닌 경우
//					if (data[i][j] != ' ') {
//
//						//새로운 단어가 시작된 경우
//						if (word == false) {
//							count++;
//							word = true;
//						}
//					}
//					else {
//						word = false;
//					}
//				}
//
//				std::cout << data[i]
//					<< "\t단어 개수: "
//					<< count
//					<< std::endl;
//			}
//		}
//
//		// c : 대문자로 시작하는 단어 찾기
//		else if (order == 'c') {
//
//			while (1) {
//
//				int total_count = 0;
//
//				for (int i = 0; i < data.size(); i++) {
//
//					int j = 0;
//
//					while (j < data[i].size()) {
//
//						//공백이면 그대로 출력
//						if (data[i][j] == ' ') {
//							std::cout << data[i][j];
//							j++;
//							continue;
//						}
//
//						int start = j;
//
//						//단어의 끝 찾기
//						while (j < data[i].size()
//							and data[i][j] != ' ') {
//
//							j++;
//						}
//
//						//단어 첫 글자가 대문자인 경우
//						if (data[i][start] >= 'A'
//							and data[i][start] <= 'Z') {
//
//							total_count++;
//
//							SetColor(12);
//
//							for (int k = start; k < j; k++) {
//								std::cout << data[i][k];
//							}
//
//							SetColor(7);
//						}
//						else {
//
//							for (int k = start; k < j; k++) {
//								std::cout << data[i][k];
//							}
//						}
//					}
//
//					std::cout << std::endl;
//				}
//
//				std::cout << std::endl;
//				std::cout << "대문자로 시작하는 단어의 개수: "
//					<< total_count
//					<< std::endl;
//
//				char check = '\0';
//
//				std::cout << "c를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'c') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// d : 각 문장을 거꾸로 출력
//		else if (order == 'd') {
//
//			std::vector<std::string> dump = data;
//
//			for (int i = 0; i < dump.size(); i++) {
//
//				for (int j = 0; j < dump[i].size() / 2; j++) {
//
//					char temp = dump[i][j];
//
//					dump[i][j]
//						= dump[i][dump[i].size() - 1 - j];
//
//					dump[i][dump[i].size() - 1 - j]
//						= temp;
//				}
//			}
//
//			while (1) {
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "d를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'd') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// e : 모든 공백에 * 삽입
//		else if (order == 'e') {
//
//			std::vector<std::string> dump = data;
//
//			for (int i = 0; i < dump.size(); i++) {
//				for (int j = 0; j < dump[i].size(); j++) {
//
//					if (dump[i][j] == ' ') {
//						dump[i][j] = '*';
//					}
//				}
//			}
//
//			while (1) {
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "e를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'e') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// f : 각 단어의 문자를 거꾸로 출력
//		else if (order == 'f') {
//
//			std::vector<std::string> dump = data;
//
//			for (int i = 0; i < dump.size(); i++) {
//
//				int start = 0;
//
//				for (int j = 0; j <= dump[i].size(); j++) {
//
//					//공백, *, 문장의 끝을 단어 구분으로 판단
//					if (j == dump[i].size()
//						or dump[i][j] == ' '
//						or dump[i][j] == '*') {
//
//						int left = start;
//						int right = j - 1;
//
//						while (left < right) {
//
//							char temp = dump[i][left];
//
//							dump[i][left] = dump[i][right];
//							dump[i][right] = temp;
//
//							left++;
//							right--;
//						}
//
//						start = j + 1;
//					}
//				}
//			}
//
//			while (1) {
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "f를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'f') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// g : 특정 단어를 다른 단어로 변경
//		else if (order == 'g') {
//
//			std::vector<std::string> dump = data;
//
//			std::string change;
//			std::string input;
//
//			//g 실행 중에는 system("cls") 사용하지 않음
//			std::cout << "바꾸고싶은 단어: ";
//			std::cin >> change;
//
//			std::cout << "바꿀 단어: ";
//			std::cin >> input;
//
//			for (int i = 0; i < dump.size(); i++) {
//
//				std::string result = "";
//
//				int j = 0;
//
//				while (j < dump[i].size()) {
//
//					//공백이면 그대로 저장
//					if (dump[i][j] == ' ') {
//						result += ' ';
//						j++;
//						continue;
//					}
//
//					std::string word = "";
//
//					//공백이 나올 때까지 단어 저장
//					while (j < dump[i].size()
//						and dump[i][j] != ' ') {
//
//						word += dump[i][j];
//						j++;
//					}
//
//					//바꾸고 싶은 단어와 같은 경우
//					if (word == change) {
//						result += input;
//					}
//					else {
//						result += word;
//					}
//				}
//
//				dump[i] = result;
//			}
//
//			while (1) {
//
//				std::cout << std::endl;
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "g를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				//g에서는 화면 지우지 않음
//
//				if (check == 'g') {
//					std::cout << std::endl;
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// h : 숫자 뒤의 내용을 다음 줄로 이동
//		else if (order == 'h') {
//
//			std::vector<std::string> dump;
//
//			for (int i = 0; i < data.size(); i++) {
//
//				std::string temp = "";
//
//				for (int j = 0; j < data[i].size(); j++) {
//
//					temp += data[i][j];
//
//					//숫자를 찾은 경우
//					if (data[i][j] >= '0'
//						and data[i][j] <= '9') {
//
//						dump.push_back(temp);
//
//						temp = "";
//
//						//숫자 뒤의 공백 제거
//						while (j + 1 < data[i].size()
//							and data[i][j + 1] == ' ') {
//
//							j++;
//						}
//					}
//				}
//
//				//마지막에 남은 문장 저장
//				if (temp.size() > 0) {
//					dump.push_back(temp);
//				}
//			}
//
//			while (1) {
//
//				Print(dump);
//
//				char check = '\0';
//
//				std::cout << std::endl;
//				std::cout << "h를 다시 입력해주세요: ";
//				std::cin >> check;
//
//				system("cls");
//
//				if (check == 'h') {
//					Print(data);
//					break;
//				}
//			}
//		}
//
//		// i : 입력받은 단어 찾기
//		// 대소문자 구분하지 않음
//		else if (order == 'i') {
//
//			std::string search;
//
//			std::cout << "찾을 단어를 입력해주세요: ";
//			std::cin >> search;
//
//			system("cls");
//
//			// 검색할 단어를 소문자로 복사
//			std::string search_lower = search;
//
//			for (int i = 0; i < search_lower.size(); i++) {
//
//				if (search_lower[i] >= 'A'
//					and search_lower[i] <= 'Z') {
//
//					search_lower[i]
//						= search_lower[i] - 'A' + 'a';
//				}
//			}
//
//			int count = 0;
//
//			for (int i = 0; i < data.size(); i++) {
//
//				int j = 0;
//
//				while (j < data[i].size()) {
//
//					//공백은 그대로 출력
//					if (data[i][j] == ' ') {
//						std::cout << data[i][j];
//						j++;
//						continue;
//					}
//
//					int start = j;
//
//					//단어 끝 찾기
//					while (j < data[i].size()
//						and data[i][j] != ' ') {
//
//						j++;
//					}
//
//					std::string word = "";
//
//					for (int k = start; k < j; k++) {
//						word += data[i][k];
//					}
//
//					// 비교하기 위한 소문자 복사본
//					std::string word_lower = word;
//
//					for (int k = 0; k < word_lower.size(); k++) {
//
//						if (word_lower[k] >= 'A'
//							and word_lower[k] <= 'Z') {
//
//							word_lower[k]
//								= word_lower[k] - 'A' + 'a';
//						}
//					}
//
//					// 대소문자 무시하고 비교
//					if (word_lower == search_lower) {
//
//						SetColor(12);
//
//						//출력은 원래 대소문자 그대로
//						std::cout << word;
//
//						SetColor(7);
//
//						count++;
//					}
//					else {
//						std::cout << word;
//					}
//				}
//
//				std::cout << std::endl;
//			}
//
//			std::cout << std::endl;
//			std::cout << search
//				<< "의 개수: "
//				<< count
//				<< std::endl;
//		}
//
//		// j : 문장 순서 한 칸씩 이동
//		else if (order == 'j') {
//
//			if (data.size() > 1) {
//
//				//마지막 문장 임시 저장
//				std::string dump
//					= data[data.size() - 1];
//
//				//1번 -> 2번
//				//2번 -> 3번
//				//...
//				for (int i = data.size() - 1; i >= 1; i--) {
//					data[i] = data[i - 1];
//				}
//
//				//마지막 문장 -> 1번
//				data[0] = dump;
//			}
//
//			Print(data);
//		}
//
//		// q : 프로그램 종료
//		else if (order == 'q') {
//			break;
//		}
//
//		else {
//			std::cout << "Cannot excute" << std::endl;
//		}
//	}
//
//	return 0;
//}