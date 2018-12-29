//
// Created by thomas on 19-12-18.
//

#include <vector>
#include "../../include/game/WireModel.h"
#include "../../include/math/Transform.h"

WireModel::WireModel(Mesh mesh, Camera const &camera)
    : mesh_(mesh)
    , vertices_(sf::Lines, mesh_.numberOfEdges()*2),
	camera_{camera}{}

void WireModel::prepareDraw() {
	
}

void WireModel::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	auto cameraMatrix = Transform::cameraMatrix(camera_);
	auto projectionMatrix = Transform::perpMatrix(90., 0.75/*4:3*/, 0.1, 1000.);

	auto wm = projectionMatrix * cameraMatrix;

	sf::Uint8 r{}, g{}, b{};

	std::vector<Vector3> points(mesh_.getPoints());

	auto rotationMatrix = Transform::rotationMatrix(mesh_.heading, mesh_.side, mesh_.top);
	auto scalingMatrix = Transform::scalingMatrix(mesh_.scaling);


	for (auto &point : points) {
		auto n = Vector4{ point.data[0], point.data[1], point.data[2], 1.0 };
		auto translationMatrix = Transform::translationMatrix(mesh_.origin);
		n = rotationMatrix * n;
		n = translationMatrix * n;
		n = wm * n;

		point.data[0] = (640 / 2) + (n.data[0] / n.data[3]) * (640 / 2);
		point.data[1] = (640 / 2) + (n.data[1] / n.data[3]) * (640 / 2);
		point.data[2] = -n.data[2];
	}

	size_t idx = 0;
	for (auto[from, to] : mesh_.getEdges()) {
		auto &from_point = points.at(from);
		auto &to_point = points.at(to);
		vertices_[idx].color = sf::Color{ r += 17, g += 37, b += 41 };
		vertices_[idx + 1].color = sf::Color{ r,g,b };
		vertices_[idx++].position = sf::Vector2f{ (float)(from_point.data[0]),(float)(from_point.data[1]) };
		vertices_[idx++].position = sf::Vector2f{ (float)(to_point.data[0]), (float)(to_point.data[1]) };
	}

	target.draw(vertices_, states);
}
