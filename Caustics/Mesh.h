#pragma once

#include <vector>

#include "Coord.h"
#include "Edge.h"
#include "Face.h"
#include "Vertex.h"

class Mesh
{

	private:

		std::vector<Edge> indices;
		std::vector<Vertex> vertices;
		std::vector<Face> faces;
		std::vector<Coord> texcoords;


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



