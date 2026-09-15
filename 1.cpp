//#include <iostream>
//#include <random>
//#include <cstdlib>
//#include <cstring>
//
//void Print(int (&a)[][4], int (&b)[][4]) {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			std::cout << a[i][j] << " ";
//		}
//		std::cout << "\t";
//		for (int j = 0; j < 4; j++) {
//			std::cout << b[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//// 별도 함수 추가 없이 Diterminant 함수 내에서만 가우스 소거법 수행
//void Diterminant(const int(&a)[4][4], const int(&b)[4][4]) {
//	double det_a = 1.0;
//	double det_b = 1.0;
//
//	// 원본 a, b를 변경하지 않기 위해 복사본(double) 생성
//	double mat_a[4][4];
//	double mat_b[4][4];
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			mat_a[i][j] = static_cast<double>(a[i][j]);
//			mat_b[i][j] = static_cast<double>(b[i][j]);
//		}
//	}
//
//	// 1. 행렬 A의 행렬식 계산 (가우스 소거법)
//	int swap_a = 0;
//	for (int i = 0; i < 4; i++) {
//		int pivot = i;
//		for (int k = i + 1; k < 4; k++) {
//			if (std::abs(mat_a[k][i]) > std::abs(mat_a[pivot][i])) {
//				pivot = k;
//			}
//		}
//
//		if (pivot != i) {
//			for (int j = 0; j < 4; j++) {
//				std::swap(mat_a[i][j], mat_a[pivot][j]);
//			}
//			swap_a++;
//		}
//
//		if (std::abs(mat_a[i][i]) < 1e-9) {
//			det_a = 0.0;
//			break;
//		}
//
//		for (int k = i + 1; k < 4; k++) {
//			double factor = mat_a[k][i] / mat_a[i][i];
//			for (int j = i; j < 4; j++) {
//				mat_a[k][j] -= factor * mat_a[i][j];
//			}
//		}
//	}
//
//	if (det_a != 0.0) {
//		for (int i = 0; i < 4; i++) {
//			det_a *= mat_a[i][i];
//		}
//		if (swap_a % 2 != 0) {
//			det_a = -det_a;
//		}
//	}
//
//	// 2. 행렬 B의 행렬식 계산 (가우스 소거법)
//	int swap_b = 0;
//	for (int i = 0; i < 4; i++) {
//		int pivot = i;
//		for (int k = i + 1; k < 4; k++) {
//			if (std::abs(mat_b[k][i]) > std::abs(mat_b[pivot][i])) {
//				pivot = k;
//			}
//		}
//
//		if (pivot != i) {
//			for (int j = 0; j < 4; j++) {
//				std::swap(mat_b[i][j], mat_b[pivot][j]);
//			}
//			swap_b++;
//		}
//
//		if (std::abs(mat_b[i][i]) < 1e-9) {
//			det_b = 0.0;
//			break;
//		}
//
//		for (int k = i + 1; k < 4; k++) {
//			double factor = mat_b[k][i] / mat_b[i][i];
//			for (int j = i; j < 4; j++) {
//				mat_b[k][j] -= factor * mat_b[i][j];
//			}
//		}
//	}
//
//	if (det_b != 0.0) {
//		for (int i = 0; i < 4; i++) {
//			det_b *= mat_b[i][i];
//		}
//		if (swap_b % 2 != 0) {
//			det_b = -det_b;
//		}
//	}
//
//	// 결과 출력 (부동소수점 오차 보정을 위해 round 사용)
//	std::cout << "Matrix A Det: " << std::round(det_a) << std::endl;
//	std::cout << "Matrix B Det: " << std::round(det_b) << std::endl;
//	std::cout << std::endl;
//}
//
//int main() {
//	std::random_device r;
//	std::default_random_engine e1(r());
//	std::uniform_int_distribution<int> dist(0, 9);
//
//	int a[4][4](0), b[4][4](0);
//	char Inner = ' ';
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			a[i][j] = dist(e1);
//			b[i][j] = dist(e1);
//		}
//	}
//
//	Print(a, b);
//
//	while (1) {
//		Inner = '\0';
//		std::cout << "언어를 입력해주세요" << std::endl;
//		std::cin >> Inner;
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//		system("cls");
//
//		if (Inner == 'm') {
//			int answer[4][4](0);
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					for (int k = 0; k < 4; k++) {
//						answer[i][j] += a[i][k] * b[k][j];
//					}
//				}
//			}
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					std::cout << answer[i][j] << " ";
//				}
//				std::cout << std::endl;
//			}
//		}
//		else if (Inner == 'a') {
//			int result[4][4](0);
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					result[i][j] = a[i][j] + b[i][j];
//				}
//			}
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					std::cout << result[i][j] << " ";
//				}
//				std::cout << std::endl;
//			}
//			std::cout << std::endl;
//
//		}
//		else if (Inner == 'd') {
//			int result[4][4](0);
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					result[i][j] = a[i][j] - b[i][j];
//				}
//			}
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					std::cout << result[i][j] << " ";
//				}
//				std::cout << std::endl;
//			}
//			std::cout << std::endl;
//
//		}
//		else if (Inner == 'r') {
//			Diterminant(a, b);
//		}
//		//전치행렬
//		else if (Inner == 't') {
//			int dump[4][4](0);
//
//			memcpy(dump, a, sizeof(a));
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					a[i][j] = dump[j][i];
//				}
//			}
//
//			memcpy(dump, b, sizeof(b));
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					b[i][j] = dump[j][i];
//				}
//			}
//
//		}
//		//행에서 값 빼기(최솟값)
//		else if (Inner == 'e') {
//			int dump_a[4][4];
//			int dump_b[4][4];
//			for (int i = 0; i < 4; i++) {
//				int min_a = 10;
//				int min_b = 10;
//				for (int j = 0; j < 4; j++) {
//					if (a[i][j] < min_a)
//						min_a = a[i][j];
//					if (b[i][j] < min_b)
//						min_b = b[i][j];
//				}
//
//				for (int j = 0; j < 4; j++) {
//					dump_a[i][j] = a[i][j] - min_a;
//					dump_b[i][j] = b[i][j] - min_b;
//				}
//			}
//
//			while (1) {
//				Print(dump_a, dump_b);
//				char check;
//				std::cout << "e를 눌러주세요" << std::endl;
//				std::cin >> check;
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//				if (check == 'e') {
//					break;
//				}
//
//				system("cls");
//			}
//		}
//		//열에서 값 더학(최댓값)
//		else if (Inner == 'f') {
//			int dump_a[4][4];
//			int dump_b[4][4];
//			for (int i = 0; i < 4; i++) {
//				int max_a = -1;
//				int max_b = -1;
//				for (int j = 0; j < 4; j++) {
//					if (a[j][i] > max_a)
//						max_a = a[j][i];
//					if (b[j][i] > max_b)
//						max_b = b[j][i];
//				}
//
//				for (int j = 0; j < 4; j++) {
//					dump_a[j][i] = a[j][i] + max_a;
//					dump_b[j][i] = b[j][i] + max_b;
//				}
//			}
//
//			while (1) {
//				Print(dump_a, dump_b);
//				char check;
//				std::cout << "f를 눌러주세요" << std::endl;
//				std::cin >> check;
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//				if (check == 'f') {
//					break;
//				}
//
//				system("cls");
//			}
//		}
//		else if (Inner == '+') {
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					a[i][j] += 1;
//					b[i][j] += 1;
//
//					if (a[i][j] >= 10) {
//						a[i][j] = 0;
//					}
//					if (b[i][j] >= 10) {
//						b[i][j] = 0;
//					}
//
//				}
//			}
//		}
//		else if (Inner == '-') {
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					a[i][j] -= 1;
//					b[i][j] -= 1;
//
//					if (a[i][j] < 0) {
//						a[i][j] = 9;
//					}
//					if (b[i][j] < 0) {
//						b[i][j] = 9;
//					}
//
//				}
//			}
//		}
//		else if (Inner == 's') {
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					a[i][j] = dist(e1);
//					b[i][j] = dist(e1);
//				}
//			}
//		}
//		else if (Inner == 'q') {
//			break;
//		}
//		else {
//			std::cout << "Cannot excute" << std::endl;
//		}
//
//		Print(a, b);
//
//	}
//
//	return 0;
//}