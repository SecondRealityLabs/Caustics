#pragma once

#include <vector>

#include "Coord.h"
#include "Edge.h"
#include "Face.h"
#include "Vertex.h"

class Mesh
{

	private:

		std::vector<Coord> coords;
		std::vector<Edge> indices;
		std::vector<Face> faces;
		std::vector<Vertex> vertices;

	public:
	
		Mesh();
		~Mesh();

		void addCoord();
		void addEdge();
		void addFace();
		void addVertex();

		void delCoord();
		void delEdge();
		void delFace();
		void delVertex();

};













