//#include <iostream>
//#include <vector>
//#include <random>
//#include <Windows.h>
//#include <cstdlib>
//const int Turn_Limits = 25;
//
//void SetColor(int color) {
//	if (color <= 0) {
//		SetConsoleTextAttribute(
//			GetStdHandle(STD_OUTPUT_HANDLE),
//			6
//		);
//	}
//	else {
//		SetConsoleTextAttribute(
//			GetStdHandle(STD_OUTPUT_HANDLE),
//			color
//		);
//	}
//}
//
//int CheckJoker(char first, char second) {
//	if (first == '@')
//		return 1;
//
//	if (second == '@')
//		return 2;
//
//	return 0;
//}
//
//void Print(const auto& board, auto Score, auto Turn, auto x, auto y, bool Show) {
//	std::cout << "남은 턴 수: " << Turn_Limits - Turn
//		<< " 현재 턴 수: " << Turn << std::endl;
//
//	std::cout << "Score: " << Score << std::endl;
//
//	//위쪽 알파벳
//	std::cout << "  ";
//	for (int j = 0; j < y; j++) {
//		std::cout << char('a' + j) << " ";
//	}
//	std::cout << std::endl;
//
//	//왼쪽 숫자 + 보드
//	for (int i = 0; i < x; i++) {
//
//		std::cout << i + 1 << " ";
//
//		for (int j = 0; j < y; j++) {
//
//			if (!Show) {
//				if (board[i][j].first == true) {
//					SetColor(board[i][j].second - 89);
//					std::cout << board[i][j].second << " ";
//					SetColor(7);
//				}
//				else {
//					std::cout << "* ";
//				}
//			}
//			else {
//				SetColor(board[i][j].second - 89);
//				std::cout << board[i][j].second << " ";
//				SetColor(7);
//			}
//		}
//
//		std::cout << std::endl;
//	}
//}
//
//int main() {
//
//	std::vector<std::vector<std::pair<bool, char>>> board;
//	bool Reset = true;
//	int Score = 0;
//	int Turn = 0;
//	int x, y;
//	while (1) {
//		//초기화 부분
//		if (Reset) {
//			board.clear();
//			while (1) {
//				std::cout << "보드의 크기를 입력해주세요: ";
//				std::cin >> x >> y;
//				if (x >= 3 and x <= 6 and y >= 3 and y <= 6) {
//					break;
//				}
//			}
//			int total = x * y;
//			board.resize(x, std::vector<std::pair<bool, char>>(y, {false, ' '}));
//
//			{
//				std::random_device r;
//				std::default_random_engine e1(r());
//				std::uniform_int_distribution dist_x(0, x-1);
//				std::uniform_int_distribution dist_y(0, y-1);
//
//				char Input = 'a';
//				int count = 0;
//
//				//조커 넣기
//				if ((x * y) % 2 == 1) {
//					board[dist_x(e1)][dist_y(e1)].second = '@';
//					total--;
//				}
//
//				for (int i = 0; i < x; i++) {
//					if (total <= 0)
//						break;
//					for (int j = 0; j < y; j++) {
//						if (total <= 0)
//							break;
//						int a = dist_x(e1);
//						int b = dist_y(e1);
//						if (board[a][b].second == ' ') {
//							board[a][b].second = Input;
//							count++;
//							if (count >= 2) {
//								count = 0;
//								Input += 1;
//							}
//							total--;
//						}
//						else
//							j--;
//					}
//				}
//
//			}
//
//			Reset = false;
//		}
//		
//		if (Turn < Turn_Limits) {
//			char order = ' ';
//
//			std::cout << "Enter: ";
//			std::cin >> order;
//
//			system("cls");
//
//			if (order >= 'a' and order <= 'a' + y - 1) {
//
//				int row1;
//				std::cin >> row1;
//
//				if (row1 >= 1 and row1 <= x) {
//
//					int x1 = row1 - 1;
//					int y1 = order - 'a';
//
//					//이미 열린 카드라면 선택 불가
//					if (board[x1][y1].first == true) {
//						std::cout << "이미 열린 카드입니다." << std::endl;
//						continue;
//					}
//
//					//첫 번째 카드 열기
//					board[x1][y1].first = true;
//
//					system("cls");
//					Print(board, Score, Turn, x, y, false);
//
//					// 두 번째 카드가 선택될 때까지 여기서 못 나감
//					while (1) {
//
//						char order2;
//						int row2;
//
//						std::cout << "두 번째 카드를 선택해주세요: ";
//						std::cin >> order2 >> row2;
//
//						//좌표 범위 확인
//						if (order2 < 'a' or order2 > 'a' + y - 1
//							or row2 < 1 or row2 > x) {
//
//							std::cout << "잘못된 위치입니다." << std::endl;
//							continue;
//						}
//
//						int x2 = row2 - 1;
//						int y2 = order2 - 'a';
//
//						//첫 번째와 같은 카드 선택 방지
//						if (x1 == x2 and y1 == y2) {
//							std::cout << "같은 카드는 선택할 수 없습니다." << std::endl;
//							continue;
//						}
//
//						//이미 열린 카드 선택 방지
//						if (board[x2][y2].first == true) {
//							std::cout << "이미 열린 카드입니다." << std::endl;
//							continue;
//						}
//
//						//두 번째 카드 열기
//						board[x2][y2].first = true;
//
//						system("cls");
//						Print(board, Score, Turn, x, y, false);
//
//						char firstCard = board[x1][y1].second;
//						char secondCard = board[x2][y2].second;
//
//						int Joker = CheckJoker(firstCard, secondCard);
//
//						// 1. 첫 번째 카드가 조커
//						if (Joker == 1) {
//
//							std::cout << "첫 번째 카드가 조커입니다." << std::endl;
//							std::cout << "매치 성공!" << std::endl;
//
//							//첫 번째 카드 = 조커
//							board[x1][y1].first = true;
//
//							//두 번째 일반 카드
//							char target = board[x2][y2].second;
//
//							board[x2][y2].first = true;
//
//							//두 번째 카드와 같은 짝 찾기
//							for (int i = 0; i < x; i++) {
//								for (int j = 0; j < y; j++) {
//
//									//선택한 자기 자신은 제외
//									if (i == x2 and j == y2)
//										continue;
//
//									if (board[i][j].second == target) {
//
//										//짝도 열기
//										board[i][j].first = true;
//
//										//두 일반 카드를 대문자로 변경
//										board[x2][y2].second =
//											board[x2][y2].second - 'a' + 'A';
//
//										board[i][j].second =
//											board[i][j].second - 'a' + 'A';
//
//										break;
//									}
//								}
//							}
//
//							Score+= 1000;
//						}
//
//						// 2. 두 번째 카드가 조커
//						else if (Joker == 2) {
//
//							std::cout << "두 번째 카드가 조커입니다." << std::endl;
//							std::cout << "매치 성공!" << std::endl;
//
//							//두 번째 카드 = 조커
//							board[x2][y2].first = true;
//
//							//첫 번째 일반 카드
//							char target = board[x1][y1].second;
//
//							board[x1][y1].first = true;
//
//							//첫 번째 카드와 같은 짝 찾기
//							for (int i = 0; i < x; i++) {
//								for (int j = 0; j < y; j++) {
//
//									//선택한 자기 자신은 제외
//									if (i == x1 and j == y1)
//										continue;
//
//									if (board[i][j].second == target) {
//
//										//짝도 열기
//										board[i][j].first = true;
//
//										//두 일반 카드를 대문자로 변경
//										board[x1][y1].second =
//											board[x1][y1].second - 'a' + 'A';
//
//										board[i][j].second =
//											board[i][j].second - 'a' + 'A';
//
//										break;
//									}
//								}
//							}
//
//							Score+= 1000;
//						}
//						// 3. 조커가 없는 경우
//						else {
//
//							if (firstCard == secondCard) {
//
//								std::cout << "매치 성공!" << std::endl;
//
//								//대문자로 변경
//								board[x1][y1].second =
//									board[x1][y1].second - 'a' + 'A';
//
//								board[x2][y2].second =
//									board[x2][y2].second - 'a' + 'A';
//
//								//계속 열린 상태
//								board[x1][y1].first = true;
//								board[x2][y2].first = true;
//
//								Score+= 1000;
//							}
//							else {
//
//								std::cout << "매치 실패!" << std::endl;
//
//								Sleep(1000);
//
//								//다시 뒤집기
//								board[x1][y1].first = false;
//								board[x2][y2].first = false;
//							}
//						}
//
//						Turn++;
//
//						system("cls");
//
//						//판정이 완료되었으므로 두 번째 카드 입력 루프 탈출
//						break;
//					}
//				}
//				else {
//					std::cout << "cannot find location" << std::endl;
//					continue;
//				}
//			}
//			//초기화 활성화
//			else if (order == 'r') {
//				Reset = true;
//				Turn = 0;
//				Score = 0;
//			}
//			//hint 보여주기(3초 정도)
//			else if (order == 'h') {
//				Print(board, Score, Turn, x, y, true);
//				Sleep(3000);
//				system("cls");
//			}
//			//종료
//			else if (order == 'q') {
//				break;
//			}
//			else {
//				std::cout << "cannot excute" << std::endl;
//			}
//		}
//		else {
//			std::cout << "턴이 종료되었습니다." << std::endl;
//			std::cout << "Score: " << Score << std::endl;
//		}
//
//		
//
//		Print(board, Score, Turn, x, y, false);
//	}
//	return 0;
//
//}