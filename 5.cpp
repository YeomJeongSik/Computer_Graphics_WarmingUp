#include <iostream>
#include <vector>
#include <tuple>
#include <Windows.h>

void SetColor(int color) {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color
	);
}

struct Vertex {
	int x, y;
};

int board = 30;	//최대 크기 40 최소크기 20

void Print(int board, std::vector<std::tuple<Vertex, int, int>>& shape) {
	//field vector로 만들기
	std::vector<std::vector<char>> Field(
		board,
		std::vector<char>(board, '.')
	);

	// 도형 1 그리기
	for (int i = 0; i <= std::get<2>(shape[0]); i++) {

		for (int j = 0; j <= std::get<1>(shape[0]); j++) {

			int x = (std::get<0>(shape[0]).x + j) % board;
			int y = (std::get<0>(shape[0]).y + i) % board;

			//보드 범위 안에 있는 부분만 그림
			if (x >= 0 and x < board
				and y >= 0 and y < board) {

				Field[y][x] = '0';
			}
		}
	}

	// 도형 2 그리기
	for (int i = 0; i <= std::get<2>(shape[1]); i++) {

		for (int j = 0; j <= std::get<1>(shape[1]); j++) {

			int x = (std::get<0>(shape[1]).x + j) % board;
			int y = (std::get<0>(shape[1]).y + i) % board;

			//보드 범위 안에 있는 부분만 그림
			if (x >= 0 and x < board
				and y >= 0 and y < board) {

				//도형 1과 겹치는 경우
				if (Field[y][x] == '0') {
					Field[y][x] = '#';
				}
				else {
					Field[y][x] = 'x';
				}
			}
		}
	}

	// 보드 출력
	for (int i = 0; i < board; i++) {

		for (int j = 0; j < board; j++) {

			if (Field[i][j] == '#') {

				//충돌 부분 빨간색
				SetColor(12);

				std::cout << Field[i][j] << " ";

				SetColor(7);
			}
			else {
				std::cout << Field[i][j] << " ";
			}
		}

		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::tuple<Vertex, int, int>> shape(2, { {0,0}, 0,0 });//초반 좌표, 가로, 세로

	bool Reset = true;

	while (1) {
		if (Reset) {
			Vertex spot1, spot2, spot3, spot4;
			std::cout << "두 도형의 좌표값 4개를 적어주세요: ";
			std::cin >> spot1.x >> spot1.y >> spot2.x >> spot2.y >> spot3.x >> spot3.y >> spot4.x >> spot4.y;

			//도형 1 좌표 순서 정리
			if (spot1.x > spot2.x) {
				int temp = spot1.x;
				spot1.x = spot2.x;
				spot2.x = temp;
			}

			if (spot1.y > spot2.y) {
				int temp = spot1.y;
				spot1.y = spot2.y;
				spot2.y = temp;
			}

			//도형 2 좌표 순서 정리
			if (spot3.x > spot4.x) {
				int temp = spot3.x;
				spot3.x = spot4.x;
				spot4.x = temp;
			}

			if (spot3.y > spot4.y) {
				int temp = spot3.y;
				spot3.y = spot4.y;
				spot4.y = temp;
			}

			std::get<0>(shape[0]) = spot1;
			std::get<0>(shape[1]) = spot3;
			std::get<1>(shape[0]) = spot2.x - spot1.x;
			std::get<2>(shape[0]) = spot2.y - spot1.y;
			std::get<1>(shape[1]) = spot4.x - spot3.x;
			std::get<2>(shape[1]) = spot4.y - spot3.y;

			board = 30;

			Reset = false;

			Print(board, shape);
		}

		char order = '\0';

		std::cout << "Give Command: ";
		std::cin >> order;

		system("cls");

		// shape0 x축 -1 이동
		if (order == 'x') {
			if (std::get<0>(shape[0]).x <= 0) {
				std::get<0>(shape[0]).x = board-1;
			}
			else {
				std::get<0>(shape[0]).x -= 1;
			}
		}
		// shape0 x축 +1 이동
		else if (order == 'X') {
			if (std::get<0>(shape[0]).x >= board - 1) {
				std::get<0>(shape[0]).x = 0;
			}
			else {
				std::get<0>(shape[0]).x += 1;
			}
		}
		// shape0 y축 -1 이동
		else if (order == 'y') {
			if (std::get<0>(shape[0]).y <= 0) {
				std::get<0>(shape[0]).y = board-1;
			}
			else {
				std::get<0>(shape[0]).y -= 1;
			}
		}
		// shape0 y축 +1 이동
		else if (order == 'Y') {
			if (std::get<0>(shape[0]).y >= board - 1) {
				std::get<0>(shape[0]).y = 0;
			}
			else {
				std::get<0>(shape[0]).y += 1;
			}
		}
		// shape0 크기 줄이기
		else if (order == 's') {
			if (std::get<1>(shape[0]) >= 1) {
				std::get<1>(shape[0]) -= 1;
			}
			if (std::get<2>(shape[0]) >= 1) {
				std::get<2>(shape[0]) -= 1;
			}
		}
		// shape0 크기 늘리기
		else if (order == 'S') {
			if (std::get<1>(shape[0]) < board - 1) {
				std::get<1>(shape[0]) += 1;
			}
			if (std::get<2>(shape[0]) < board - 1) {
				std::get<2>(shape[0]) += 1;
			}
		}
		// shape0 x축 -1
		else if (order == 'i') {
			if (std::get<1>(shape[0]) >= 1) {
				std::get<1>(shape[0]) -= 1;
			}
		}
		// shape0 x축 +1
		else if (order == 'I') {
			if (std::get<1>(shape[0]) < board - 1) {
				std::get<1>(shape[0]) += 1;
			}
		}
		// shape0 y축 -1
		else if (order == 'j') {
			if (std::get<2>(shape[0]) >= 1) {
				std::get<2>(shape[0]) -= 1;
			}
		}
		// shape0 y축 +1
		else if (order == 'J') {
			if (std::get<2>(shape[0]) < board - 1) {
				std::get<2>(shape[0]) += 1;
			}
		}
		// shape0 x - 1 y + 1
		else if (order == 'a') {
			if (std::get<1>(shape[0]) >= 1) {
				std::get<1>(shape[0]) -= 1;
			}
			if (std::get<2>(shape[0]) < board - 1) {
				std::get<2>(shape[0]) += 1;
			}
		}
		// shape0 x + 1 y - 1
		else if (order == 'A') {
			if (std::get<1>(shape[0]) < board - 1) {
				std::get<1>(shape[0]) += 1;
			}
			if (std::get<2>(shape[0]) >= 1) {
				std::get<2>(shape[0]) -= 1;
			}
		}
		// shape1 x축 -1 이동
		else if (order == 'o') {
			if (std::get<0>(shape[1]).x <= 0) {
				std::get<0>(shape[1]).x = board-1;
			}
			else {
				std::get<0>(shape[1]).x -= 1;
			}
		}
		// shape1 x축 +1 이동
		else if (order == 'O') {
			if (std::get<0>(shape[1]).x >= board - 1) {
				std::get<0>(shape[1]).x = 0;
			}
			else {
				std::get<0>(shape[1]).x += 1;
			}
		}
		// shape1 y축 -1 이동
		else if (order == 'p') {
			if (std::get<0>(shape[1]).y <= 0) {
				std::get<0>(shape[1]).y = board-1;
			}
			else {
				std::get<0>(shape[1]).y -= 1;
			}
		}
		// shape1 y축 +1 이동
		else if (order == 'P') {
			if (std::get<0>(shape[1]).y >= board - 1) {
				std::get<0>(shape[1]).y = 0;
			}
			else {
				std::get<0>(shape[1]).y += 1;
			}
		}
		// shape1 크기 줄이기
		else if (order == 'k') {
			if (std::get<1>(shape[1]) >= 1) {
				std::get<1>(shape[1]) -= 1;
			}
			if (std::get<2>(shape[1]) >= 1) {
				std::get<2>(shape[1]) -= 1;
			}
		}
		// shape1 크기 늘리기
		else if (order == 'K') {
			if (std::get<1>(shape[1]) < board - 1) {
				std::get<1>(shape[1]) += 1;
			}
			if (std::get<2>(shape[1]) < board - 1) {
				std::get<2>(shape[1]) += 1;
			}
		}
		// shape1 x축 -1
		else if (order == 'l') {
			if (std::get<1>(shape[1]) >= 1) {
				std::get<1>(shape[1]) -= 1;
			}
		}
		// shape1 x축 +1
		else if (order == 'L') {
			if (std::get<1>(shape[1]) < board - 1) {
				std::get<1>(shape[1]) += 1;
			}
		}
		// shape1 y축 -1
		else if (order == 'n') {
			if (std::get<2>(shape[1]) >= 1) {
				std::get<2>(shape[1]) -= 1;
			}
		}
		// shape1 y축 +1
		else if (order == 'N') {
			if (std::get<2>(shape[1]) < board - 1) {
				std::get<2>(shape[1]) += 1;
			}
		}
		// shape1 x - 1 y + 1
		else if (order == 'm') {
			if (std::get<1>(shape[1]) >= 1) {
				std::get<1>(shape[1]) -= 1;
			}
			if (std::get<2>(shape[1]) < board - 1) {
				std::get<2>(shape[1]) += 1;
			}
		}
		// shape1 x + 1 y - 1
		else if (order == 'M') {
			if (std::get<1>(shape[1]) < board - 1) {
				std::get<1>(shape[1]) += 1;
			}
			if (std::get<2>(shape[1]) >= 1) {
				std::get<2>(shape[1]) -= 1;
			}
		}
		// ALL 사각형 면적 출력
		else if (order == 'b') {
			int s1, s2;

			s1 = (std::get<1>(shape[0]) + 1) * (std::get<2>(shape[0]) + 1);
			s2 = (std::get<1>(shape[1]) + 1) * (std::get<2>(shape[1]) + 1);

			std::cout << "도형 1 의 면적: " << s1 << ", 도형 2 의 면적: " << s2 << std::endl;
		}
		//보드칸 늘리기(최대 40까지)
		else if (order == 'c') {
			if (board < 40) {
				board++;
			}
		}
		//보드칸 줄이기(최대 20까지)
		else if (order == 'd') {
			if (board > 20) {
				board--;
			}
		}
		//모두 리셋
		else if (order == 'r') {
			Reset = true;
			continue;
		}
		//종료
		else if (order == 'q') {
			break;
		}
		else {
			std::cout << "cannot excute" << std::endl;
		}

		Print(board, shape);
	}

	return 0;
}