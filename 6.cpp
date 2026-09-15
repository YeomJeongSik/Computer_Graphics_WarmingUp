#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct Vertex {
	double x, y, z;
};

struct Texture {
	double s, t;
};

struct Face {
	int vertex[3];
	int texture[3];

	bool hasTexture;
	bool valid;

	std::string error;
};

int main() {
	std::vector<Vertex> vertex;
	std::vector<Texture> texture;
	std::vector<Face> face;

	std::ifstream file("data_runtime.txt");

	if (!file.is_open()) {
		std::cout << "cannot open data6.txt" << std::endl;
		return 0;
	}

	std::string line;

	while (std::getline(file, line)) {

		//주석 제거
		size_t comment = line.find('#');

		if (comment != std::string::npos) {
			line = line.substr(0, comment);
		}

		std::stringstream ss(line);

		std::string type;

		if (!(ss >> type)) {
			continue;
		}

		//정점 좌표값
		if (type == "v") {
			Vertex temp;

			std::string extra;

			if (!(ss >> temp.x >> temp.y >> temp.z)) {
				std::cout << "Error: invalid character value" << std::endl;
				continue;
			}

			if (ss >> extra) {
				std::cout << "Error: invalid character value" << std::endl;
				continue;
			}

			//정점 좌표 범위 확인
			if (temp.x < -1.0 or temp.x > 1.0
				or temp.y < -1.0 or temp.y > 1.0
				or temp.z < -1.0 or temp.z > 1.0) {

				std::cout << "Error: vertex value out of range" << std::endl;
				continue;
			}

			vertex.push_back(temp);
		}

		//텍스처 좌표값
		else if (type == "vt") {
			Texture temp;

			std::string extra;

			if (!(ss >> temp.s >> temp.t)) {
				std::cout << "Error: invalid character value" << std::endl;
				continue;
			}

			if (ss >> extra) {
				std::cout << "Error: invalid character value" << std::endl;
				continue;
			}

			//텍스처 좌표 범위 확인
			if (temp.s < 0.0 or temp.s > 1.0
				or temp.t < 0.0 or temp.t > 1.0) {

				std::cout << "Error: texture value out of range" << std::endl;
				continue;
			}

			texture.push_back(temp);
		}

		//삼각형 면
		else if (type == "f") {
			Face temp = { {0,0,0}, {0,0,0}, false, true, "" };

			std::vector<std::string> data;
			std::string value;

			while (ss >> value) {
				data.push_back(value);
			}

			//삼각형 꼭짓점 3개 확인
			if (data.size() != 3) {
				temp.valid = false;
				temp.error = "triangle needs 3 vertices";

				face.push_back(temp);

				continue;
			}

			bool textureUse = false;
			bool textureNotUse = false;

			for (int i = 0; i < 3; i++) {

				size_t slash = data[i].find('/');

				//vertex index만 있는 경우
				if (slash == std::string::npos) {

					textureNotUse = true;

					std::stringstream valueStream(data[i]);

					int vertexIndex;
					char extra;

					if (!(valueStream >> vertexIndex)) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					if (valueStream >> extra) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					temp.vertex[i] = vertexIndex;
				}

				//vertex/texture index가 있는 경우
				else {

					textureUse = true;

					// /가 두 개 이상 있는 경우
					if (data[i].find('/', slash + 1) != std::string::npos) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					std::string vertexData = data[i].substr(0, slash);
					std::string textureData = data[i].substr(slash + 1);

					if (vertexData.empty() or textureData.empty()) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					std::stringstream vertexStream(vertexData);
					std::stringstream textureStream(textureData);

					int vertexIndex;
					int textureIndex;
					char extra;

					if (!(vertexStream >> vertexIndex)) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					if (vertexStream >> extra) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					if (!(textureStream >> textureIndex)) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					if (textureStream >> extra) {
						temp.valid = false;
						temp.error = "invalid character value";
						break;
					}

					temp.vertex[i] = vertexIndex;
					temp.texture[i] = textureIndex;
				}
			}

			//texture 사용 형식이 섞인 경우
			if (textureUse and textureNotUse) {
				temp.valid = false;
				temp.error = "invalid character value";
			}

			if (textureUse and !textureNotUse) {
				temp.hasTexture = true;
			}

			face.push_back(temp);
		}

		//허용되지 않는 문자값
		else {
			std::cout << "Error: invalid character value" << std::endl;
		}
	}

	file.close();

	//정점 좌표값 중복 확인
	bool duplicate = false;

	for (int i = 0; i < (int)vertex.size(); i++) {

		for (int j = i + 1; j < (int)vertex.size(); j++) {

			if (vertex[i].x == vertex[j].x
				and vertex[i].y == vertex[j].y
				and vertex[i].z == vertex[j].z) {

				duplicate = true;
			}
		}
	}

	//face 예외 처리
	for (int i = 0; i < (int)face.size(); i++) {

		if (!face[i].valid) {
			continue;
		}

		//같은 vertex index 확인
		if (face[i].vertex[0] == face[i].vertex[1]
			or face[i].vertex[0] == face[i].vertex[2]
			or face[i].vertex[1] == face[i].vertex[2]) {

			face[i].valid = false;
			face[i].error = "duplicate vertex index";

			continue;
		}

		//vertex index 범위 확인
		for (int j = 0; j < 3; j++) {

			if (face[i].vertex[j] < 1
				or face[i].vertex[j] > (int)vertex.size()) {

				face[i].valid = false;
				face[i].error = "vertex index out of range";

				break;
			}
		}

		if (!face[i].valid) {
			continue;
		}

		//texture index 범위 확인
		if (face[i].hasTexture) {

			for (int j = 0; j < 3; j++) {

				if (face[i].texture[j] < 1
					or face[i].texture[j] > (int)texture.size()) {

					face[i].valid = false;
					face[i].error = "texture index out of range";

					break;
				}
			}
		}

		if (!face[i].valid) {
			continue;
		}

		//삼각형 좌표값 중복 확인
		Vertex v1 = vertex[face[i].vertex[0] - 1];
		Vertex v2 = vertex[face[i].vertex[1] - 1];
		Vertex v3 = vertex[face[i].vertex[2] - 1];

		if ((v1.x == v2.x and v1.y == v2.y and v1.z == v2.z)
			or (v1.x == v3.x and v1.y == v3.y and v1.z == v3.z)
			or (v2.x == v3.x and v2.y == v3.y and v2.z == v3.z)) {

			face[i].valid = false;
			face[i].error = "duplicate vertex value";
		}
	}

	//face 출력
	for (int i = 0; i < (int)face.size(); i++) {

		if (!face[i].valid) {

			std::cout << "Face " << i + 1
				<< " Error: " << face[i].error
				<< std::endl;

			continue;
		}

		std::cout << "Face " << i + 1 << " ("
			<< face[i].vertex[0] << ", "
			<< face[i].vertex[1] << ", "
			<< face[i].vertex[2] << "): ";

		std::cout << "vertex ";

		for (int j = 0; j < 3; j++) {

			int index = face[i].vertex[j] - 1;

			std::cout << "("
				<< vertex[index].x << ", "
				<< vertex[index].y << ", "
				<< vertex[index].z << ") ";
		}


		//texture가 있는 경우
		if (face[i].hasTexture) {

			std::cout << "texture ";

			for (int j = 0; j < 3; j++) {

				int index = face[i].texture[j] - 1;

				std::cout << "("
					<< texture[index].s << ", "
					<< texture[index].t << ") ";
			}

		}

		std::cout << std::endl;
	}

	//중복 정점 출력
	if (!duplicate) {
		std::cout << "No duplicate vertex value" << std::endl;
	}
	else {
		std::cout << "Duplicate vertex value" << std::endl;
	}

	return 0;
}