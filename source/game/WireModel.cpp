//
// Created by thomas on 19-12-18.
//

#include <vector>
#include "../../include/game/WireModel.h"
#include "../../include/math/Matrix.h"
#include "../../include/math/Transform.h"

WireModel::WireModel(Mesh mesh, Mesh const &camera)
    : mesh_(mesh)
    , vertices_(sf::Lines, mesh_.numberOfEdges()*2),
	camera_{camera}{}

void WireModel::prepareDraw() {
	
}

void WireModel::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	auto cameraMatrix = Transform::cameraMatrix(camera_.origin, camera_.side, camera_.top, camera_.heading);
	auto projectionMatrix = Transform::perpMatrix(90., 800.f/600.f/*4:3*/, 10, 1000.);

	auto wm = projectionMatrix * cameraMatrix;

	sf::Uint8 r{}, g{}, b{};

	std::vector<Vector3> points(mesh_.getPoints());

	auto rotationMatrix = Transform::rotationMatrix(mesh_.side, mesh_.top, mesh_.heading);
	auto scalingMatrix = Transform::scalingMatrix(mesh_.scaling);


	for (auto &point : points) {
		auto n = toVector4(point);
		auto translationMatrix = Transform::translationMatrix(mesh_.origin);
		auto modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;
		n = projectionMatrix * cameraMatrix * modelMatrix * n;

		point.data[0] = (800 / 2) + (n.data[0] / n.data[3]) * (800 / 2);
		point.data[1] = (600 / 2) + (n.data[1] / n.data[3]) * (600 / 2);
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
