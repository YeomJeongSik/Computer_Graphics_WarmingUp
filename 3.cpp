//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <cmath>
//#include <algorithm>
//#include <tuple>
//
//struct Data {
//	int x, y, z;
//};
//
//void print(std::vector<std::pair<bool, Data>> list) {
//	for (int i = list.size()-1; i >=0; i--) {
//		std::cout << "[" << i << "]\t";
//		if (list[i].first == false) {
//			std::cout << "[빈칸]" << std::endl;
//		}
//		else {
//			std::cout << "[" << list[i].second.x << ", "<< list[i].second.y << ", " << list[i].second.z << "]" << std::endl;
//		}
//	}
//}
//
//int main() {
//	std::vector<std::pair<bool, Data>> list(10, { false,{0,0,0}});
//
//	while (1) {
//		print(list);
//		char order = '\0';
//
//		std::cout << "Give Order: ";
//
//		std::cin >> order; 
//
//		int a, b, c;
//		system("cls");
//
//		if (order == '+') {
//			std::cin >> a >> b >> c;
//			//값이 들어있지 않다면
//			if (list[9].first == false) {
//				list[9] = { true, {a, b, c} };
//			}
//			//값이 들어있다면
//			else {
//				for (int i = 1; i < 10; i++) {
//					list[i - 1] = list[i];
//				}
//				list[9] = { true, {a, b, c} };
//			}
//
//		}
//		else if (order == '-') {
//			for (int i = 9; i >= 1; i--) {
//				list[i] = list[i - 1];
//			}
//			list[0].first = false;
//		}
//		else if (order == 'e') {
//			std::cin >> a >> b >> c;
//			if (list[0].first == false) {
//				list[0] = { true, {a,b,c} };
//			}
//			else {
//				for (int i = 9; i >= 1; i--) {
//					list[i] = list[i - 1];
//				}
//				list[0] = { true, {a,b,c} };
//			}
//		}
//		//맨 아래 삭제
//		else if (order == 'd') {
//			for (int i = 1; i <=9; i++) {
//				list[i - 1] = list[i];
//			}
//			list[9].first = false;
//		}
//		//개수 출력
//		else if (order == 'a') {
//			int count = 0;
//			for (auto p : list) {
//				if (p.first == true)
//					count++;
//			}
//			std::cout << "개수: " << count << std::endl;
//		}
//		//리스트 내리기
//		else if (order == 'b') {
//			bool dump_b = list[0].first;
//			Data dump_d = list[0].second;
//			for (int i = 1; i <=9; i++) {
//				list[i - 1] = list[i];
//			}
//			list[9] = { dump_b, {dump_d} };
//		}
//		//초기화
//		else if (order == 'c') {
//			list.assign(10, { false, {0,0,0}});
//		}
//		//각점에서원점과의거리를계산후, 그값을정렬하여오름차순으로정렬하여출력한다. 인덱스0번부터빈칸없이저장하여출력한다.  리스트각칸의옆에는해당칸의점과원점과의거리를출력한다.다시누르면원래대로출력한다
//		else if (order == 'f') {
//			std::vector<std::pair<int, Data>> only_f;
//			for (auto p : list) {
//				if (p.first == true) {
//					only_f.push_back(
//						{ std::pow(p.second.x, 2) + std::pow(p.second.y, 2) + std::pow(p.second.z, 2), 
//						p.second });
//					
//				}
//			}
//			std::sort(only_f.begin(), only_f.end(),
//				[](const std::pair<int, Data>& a, const std::pair<int, Data>& b) {
//					return a.first < b.first;
//				});
//
//			while (1) {
//				for (int i = 0; i < only_f.size(); i++) {
//					std::cout << only_f[i].first << " [" << only_f[i].second.x << ", " << only_f[i].second.y << ", " << only_f[i].second.z << "]" << std::endl;
//				}
//				char back = '\0';
//				std::cout << "f를 다시 입력해주세요: ";
//				std::cin >> back;
//				system("cls");
//				if (back == 'f' or back == 'F') {
//					break;
//				}
//			}
//		}
//		//리스트에저장된점들에서두점간의모든조합에대한거리를계산하고가장먼두점, 가장가까운두점을출력한다.  이때, 두점의좌표 값과그점사이의거리, 가장먼두점, 가장가까운두점을출력하고그점간의거리도출력
//		else if (order == 'g') {
//			std::vector<std::tuple<double, Data, Data>> only_g;
//			std::vector<Data> crossway;
//			for (auto p : list) {
//				if (p.first == true)
//					crossway.push_back({p.second.x, p.second.y, p.second.z});
//			}
//			for (int i = 0; i < crossway.size(); i++) {
//				for (int j = i+1; j < crossway.size(); j++) {
//					double calculation = std::sqrt(
//						std::pow(crossway[i].x - crossway[j].x, 2) + std::pow(crossway[i].y - crossway[j].y, 2) + std::pow(crossway[i].z - crossway[j].z, 2));
//					only_g.push_back({ calculation, crossway[i], crossway[j] });
//				}
//			}
//			std::sort(only_g.begin(), only_g.end(),
//				[](const auto& a, const auto& b) {
//					return std::get<0>(a) < std::get<0>(b);
//				});
//			for (auto p : only_g) {
//				std::cout << "[" << std::get<0>(p) <<
//					"]\t[" << std::get<1>(p).x << ", " << std::get<1>(p).y << ", " << std::get<1>(p).z <<
//					"]\t[" << std::get<2>(p).x << ", " << std::get<2>(p).y << ", " << std::get<2>(p).z << "]" << std::endl;
//			}
//			std::cout << "가장 가까운 두 점:\t" << "[" << std::get<0>(only_g.front()) <<
//				"]\t[" << std::get<1>(only_g.front()).x << ", " << std::get<1>(only_g.front()).y << ", " << std::get<1>(only_g.front()).z <<
//				"]\t[" << std::get<2>(only_g.front()).x << ", " << std::get<2>(only_g.front()).y << ", " << std::get<2>(only_g.front()).z << "]" << std::endl;
//
//			std::cout << "가장 먼 두 점:\t" << "[" << std::get<0>(only_g.back()) <<
//				"]\t[" << std::get<1>(only_g.back()).x << ", " << std::get<1>(only_g.back()).y << ", " << std::get<1>(only_g.back()).z <<
//				"]\t[" << std::get<2>(only_g.back()).x << ", " << std::get<2>(only_g.back()).y << ", " << std::get<2>(only_g.back()).z << "]" << std::endl;
//		}
//		//종료
//		else if (order == 'q') {
//			break;
//		}
//		else {
//			std::cout << "cannot find order" << std::endl;
//		}
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
//	return 0;
//}